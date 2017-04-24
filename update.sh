#!/bin/sh

git pull origin master
git add $(git ls-files -o)
git add $(git ls-files -m)
git rm  --ignore-unmatch [--] $(git ls-files -d)
git commit -m 'some update'
git push origin master
