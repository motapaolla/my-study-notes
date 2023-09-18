import numpy as np

### xROC

# Auxiliar
def get_confusion_matrix(y_true, y_pred):
    tp = np.equal(y_true, 1) & np.equal(y_pred, 1)
    fp = np.equal(y_true, 0) & np.equal(y_pred, 1)
    tn = np.equal(y_true, 0) & np.equal(y_pred, 0)
    fn = np.equal(y_true, 1) & np.equal(y_pred, 0)

    return tp, fp, tn, fn


def calculate_tpr(y_true, y_pred):
    tp, _, _, fn = get_confusion_matrix(y_true, y_pred)

    return tp.sum() / (tp.sum() + fn.sum())


def calculate_fpr(y_true, y_pred):
    _, fp, tn, _ = get_confusion_matrix(y_true, y_pred)

    return fp.sum() / (fp.sum() + tn.sum())


# xROC
def calculate_xroc(y_true, y_proba, prot_attr, pos_label=1, partitions=1000):
    """
    Calculate xROC curve
    :param y_true: pandas series containing the indexes and the true labels
    :param y_proba: pandas series containing the indexes and the probabilities
    :param prot_attr: pandas series containing the indexes and values for the protected attribute
    :param pos_label: value for the positive outcome label
    :param partitions: number of partitions used to build the thresholds
    :return: the tpr for unpriviledged and fpr for priviledged values
    """
    tpr_arr, fpr_arr = np.array([]), np.array([])

    for i in range(partitions + 1):
        y_pred_priv = np.greater_equal(y_proba[prot_attr == pos_label].to_numpy(), i / partitions).astype(int)
        y_pred_unpriv = np.greater_equal(y_proba[prot_attr != pos_label].to_numpy(), i / partitions).astype(int)

        tpr = calculate_tpr(y_true[prot_attr != pos_label].to_numpy(), y_pred_unpriv)
        tpr_arr = np.append(tpr_arr, tpr)
        fpr = calculate_fpr(y_true[prot_attr == pos_label].to_numpy(), y_pred_priv)
        fpr_arr = np.append(fpr_arr, fpr)

    return tpr_arr, fpr_arr
