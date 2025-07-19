#!/bin/bash

# Push S9Slicer v0.7.3-final to GitHub

ZIP_NAME="S9Slicer_v0.7.3-final_20250719_035231.zip"
WORK_DIR="S9Slicer"
REPO_URL="git@github.com:khelix1/S9Slicer.git"

rm -rf $WORK_DIR
unzip $ZIP_NAME -d $WORK_DIR
cd $WORK_DIR

git init
git remote add origin $REPO_URL
git checkout -b main
git add .
git commit -m "Release v0.7.3-final: Fully documented and polished core engine"
git push -u origin main

git tag v0.7.3-final
git push origin v0.7.3-final

echo "✅ Pushed S9Slicer v0.7.3-final to GitHub."
