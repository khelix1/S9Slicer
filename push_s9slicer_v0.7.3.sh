#!/bin/bash

# Push S9Slicer v0.7.3 to GitHub

ZIP_NAME="S9Slicer_v0.7.3_20250719_034635.zip"
WORK_DIR="S9Slicer"
REPO_URL="git@github.com:khelix1/S9Slicer.git"

rm -rf $WORK_DIR
unzip $ZIP_NAME -d $WORK_DIR
cd $WORK_DIR

git init
git remote add origin $REPO_URL
git checkout -b main
git add .
git commit -m "Release v0.7.3: Fully polished core modules"
git push -u origin main

git tag v0.7.3
git push origin v0.7.3

echo "✅ Pushed S9Slicer v0.7.3 to GitHub."
