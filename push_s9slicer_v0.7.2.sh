#!/bin/bash

# This script will push S9Slicer v0.7.2 to GitHub
# Ensure you are in a network environment with SSH access to GitHub

ZIP_NAME="S9Slicer_v0.7.2_20250719_033658.zip"
WORK_DIR="S9Slicer"
REPO_URL="git@github.com:khelix1/S9Slicer.git"

# Unpack and prepare
rm -rf $WORK_DIR
unzip $ZIP_NAME -d $WORK_DIR
cd $WORK_DIR

# Initialize and push
git init
git remote add origin $REPO_URL
git checkout -b main
git add .
git commit -m "Release v0.7.2: Added dynamic SmartFanControl logic"
git push -u origin main

# Tag release
git tag v0.7.2
git push origin v0.7.2

echo "✅ Pushed S9Slicer v0.7.2 to GitHub."
