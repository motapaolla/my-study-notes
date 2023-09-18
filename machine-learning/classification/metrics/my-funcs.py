import numpy as np


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


def calculate_roc(y_true, y_proba, partitions=100):
    tpr_arr, fpr_arr = np.array([]), np.array([])

    for i in range(partitions + 1):
        y_pred = np.greater_equal(y_proba, i / partitions).astype(int)
        tpr = calculate_tpr(y_true, y_pred)
        tpr_arr = np.append(tpr_arr, tpr)
        fpr = calculate_fpr(y_true, y_pred)
        fpr_arr = np.append(fpr_arr, fpr)

    return tpr_arr, fpr_arr
