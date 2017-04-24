#!/bin/sh

git add 'git ls-files -o'
git add $(git ls-files -m)
git rm 'git ls-files -d'
git commit -m 'some update'
git push origin master


