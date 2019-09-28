#!/bin/bash
commit_str=$1
if [ -z "$1" ]; then
commit_str="commit"
fi
git add .
git commit -m "${commit_str}"
git push origin master
echo "github push finish!"
