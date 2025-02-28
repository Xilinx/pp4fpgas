#!/bin/bash  
# create_branch.sh  
#  
# This script prompts the user to select a branch type by number (1 for feature,  
# 2 for bugfix, 3 for hotfix), then asks for a branch description. It converts  
# spaces to dashes, appends the current date (YYYY-MM-DD), and creates the branch  
# using the git command.  
  
# Function to show branch type menu and map user input  
select_branch_type() {  
  echo "Select the branch type:"  
  echo "  1) feature"  
  echo "  2) bugfix"  
  echo "  3) hotfix"  
  read -p "Enter number (1, 2, or 3): " branch_choice  
  
  case "$branch_choice" in  
      1) branch_type="feature" ;;  
      2) branch_type="bugfix" ;;  
      3) branch_type="hotfix" ;;  
      *) echo "Invalid selection. Exiting." ; exit 1 ;;  
  esac  
  
  echo "Branch type selected: $branch_type"  
}  
  
# Prompt for branch description and format it  
read_branch_description() {  
  read -p "Enter the branch description (e.g., user authentication): " branch_desc  
  # Trim whitespace, convert to lowercase, and replace spaces with dashes.  
  branch_desc=$(echo "$branch_desc" | awk '{$1=$1;print}' | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')  
  echo "$branch_desc"  
}  
  
main() {  
  # Ensure we are inside a Git repository  
  if ! git rev-parse --is-inside-work-tree > /dev/null 2>&1; then  
      echo "This directory is not a Git repository."  
      exit 1  
  fi  
  
  # Select branch type based on numeric input  
  select_branch_type  
  
  # Read branch description from the user  
  branch_desc=$(read_branch_description)  
  
  # Get the current date in YYYY-MM-DD format  
  current_date=$(date +%Y-%m-%d)  
  
  # Construct the full branch name  
  full_branch="${branch_type}/${current_date}-${branch_desc}"  
  
  # Create the branch  
  echo "Creating branch: $full_branch"  
  git checkout -b "$full_branch"  
  
  if [ $? -eq 0 ]; then  
      echo "Branch '$full_branch' created successfully."  
  else  
      echo "Error creating branch. Please check your git status."  
  fi  
}  
  
main  
