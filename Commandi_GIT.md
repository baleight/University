# Git Comandi

```git
cd C:\Users\baleo\Documents\
git init
git config --global user.name 'baleight'
git config --global user.email 'baleight2@gmail.com'
git remote add origin 'https://github.com/baleight/Uni.git'
git pull origin main #prendi i file da github ed inseriscili nella cartella

git status #controllare lo stato dei file, capire se sono aggiunti a git
git add . #aggiungi tutti
git add file.txt
git commit -m 'first release'

git push -u origin main
git branch -a
```

    git fetch origin
    git reset --hard origin/main
    git push origin main --force

```git
cd C:\Users\baleo\Pictures\GitUni
git add .
git commit -m 'new-release'
git push -u origin main
```
