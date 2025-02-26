#!/bin/bash

# Fetch the latest tags
git fetch --tags

# Get the latest tag on the next branch
LATEST_TAG=$(git describe --tags $(git rev-list --tags --max-count=1))

# Create a new branch named release/<latest-tag> from the next branch
git checkout next
git pull origin next
git checkout -b release/$LATEST_TAG

# Push the new branch to the remote repository
git push origin release/$LATEST_TAG