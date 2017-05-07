#!/bin/bash

CUR_DIR=$(pwd)
cd ~/idao/Linux-network-programming

git pull origin master
git add $(git ls-files -o)
git add $(git ls-files -m)
git rm  --ignore-unmatch [--] $(git ls-files -d)

echo "git status"
git status

echo "Please enter the commit message:"    
read COMMIT_MESSAGE
if [ "$COMMIT_MESSAGE" == "" ]; then
    export COMMIT_MESSAGE = "some update"
fi

git commit -m "${COMMIT_MESSAGE}"
git push origin master

cd $CUR_DIR
