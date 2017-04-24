#!/bin/sh

git add $(git ls-files -o)
git add $(git ls-files -m)
git rm --ignore-unmatch $(git ls-files --deleted)
git commit -m 'some update'
git push origin master
