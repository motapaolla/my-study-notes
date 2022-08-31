# git

### Add global user

`git config --global user.email "motapaolla@gmail.com"`

### Dar rollback

- git checkout

### List all commits that changed a specific file:

`$ git log --follow -- filename`

### Stash commits:

- Ver os stashs: `$ git stash list`
- Trazer o mais recente: `$ git stash apply`
- Trazer qualquer um: `$ git stash apply stash@{2}`

### Remove commit:

- Soft: `$ git reset --soft HEAD^`
- Hard: `$ git reset --hard HEAD^`

### Remove commit from cloud:

- Remove commits locally
- Then force push by:

```
git push origin +branchName --force
```

### Check difference between commits:

`$ git log -p -2`

`$ git diff <commit-name>`

### Rename local commits:

- Last commit: `$ git commit --amend`
- All: https://help.github.com/en/articles/changing-a-commit-message

### Delete a branch:

```
$ git branch -D <branch-name>
$ git push origin :feature/add_fairness
```

### Get modifications from upstream:

```
git fetch upstream
git merge upstream/dev
```

Or you can try a very much more forced way: `$ git pull ssh://git-codecommit.us-east2.amazonaws.com/v1/repos/matthew-scikit dev`

### Change history of commits

https://www.adamdehaven.com/blog/update-commit-history-author-information-for-git-repository/#editing-multiple-commits-with-interactive-rebase

### Configure user for a repository only

```
git config user.name "Your Name Here"
git config user.email your@email.com
```

---

# Git alias

### Aliases created by me:

```
git rslast  # reset soft o ultimo commit
git rslasth  # reset HARD o ultimo commit
```

### Create alias

```
git config --global alias.rslast 'reset --soft HEAD~1'
```

### List aliases

```
git config --get-regexp alias
```

### Remove alias

```
git config --global --unset alias.trololo
```

### Verify which alias are created

```
vim ~/.gitconfig
```

### Set alias in commit

```
git config --global alias.commithub "commit --author='Paolla Mota <motapaolla@gmail.com>'"
git config --global alias.commithub "-c user.name='Paolla Mota' -c user.email=motapaolla@gmail.com commit"
```

### Commit with alias username