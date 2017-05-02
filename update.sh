#!/bin/sh

git pull origin master
git add $(git ls-files ~/idao/Linux-network-programming -o)
git add $(git ls-files ~/idao/Linux-network-programming -m)
git rm  --ignore-unmatch [--] $(git ls-files ~/idao/Linux-network-programming -d)
git commit -m 'some update'
git push origin master
