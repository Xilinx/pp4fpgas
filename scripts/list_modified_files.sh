#!/bin/bash
# filepath: \proj\rdi\staff\mpettigr\projects\reorg_pp4fpgas_github\pp4fpgas\scripts\list_modified_files.sh

# This script lists files modified by a specific user between two commit hashes

usage() {
    echo "Usage: $0 [-p|--paths-only] <start_commit> <end_commit> <userid> [branch]"
    echo ""
    echo "Arguments:"
    echo "  -p, --paths-only - Output only the file paths (no commit info)"
    echo "  start_commit     - Starting commit hash (older)"
    echo "  end_commit       - Ending commit hash (newer)"
    echo "  userid           - User ID to filter by"
    echo "  branch           - Optional: Branch name to limit search (default: current branch)"
    exit 1
}

# Default values
PATHS_ONLY=false

# Parse options
while [[ $# -gt 0 ]]; do
    case $1 in
        -p|--paths-only)
            PATHS_ONLY=true
            shift
            ;;
        -h|--help)
            usage
            ;;
        *)
            break
            ;;
    esac
done

# Check if required arguments are provided
if [ $# -lt 3 ] || [ $# -gt 4 ]; then
    usage
fi

START_COMMIT=$1
END_COMMIT=$2
USERID=$3
BRANCH=""

# If branch is provided, use it
if [ $# -eq 4 ]; then
    BRANCH=$4
    if [ "$PATHS_ONLY" = false ]; then
        echo "Listing files modified by user '$USERID' between commits '$START_COMMIT' and '$END_COMMIT' on branch '$BRANCH':"
        echo "--------------------------------------------------------------------------------"
    fi
else
    if [ "$PATHS_ONLY" = false ]; then
        echo "Listing files modified by user '$USERID' between commits '$START_COMMIT' and '$END_COMMIT':"
        echo "--------------------------------------------------------------------------------"
    fi
fi

# Get the list of commits by the specific user within the commit range
if [ -n "$BRANCH" ]; then
    # Use the branch name to limit the search
    COMMITS=$(git log --author="$USERID" --format="%H" $START_COMMIT..$END_COMMIT $BRANCH)
else
    COMMITS=$(git log --author="$USERID" --format="%H" $START_COMMIT..$END_COMMIT)
fi

if [ -z "$COMMITS" ]; then
    if [ "$PATHS_ONLY" = false ]; then
        echo "No commits found for user '$USERID' in the specified range."
    fi
    exit 0
fi

# Track unique file paths
declare -A all_files

# For each commit by the user, get the files modified
for COMMIT in $COMMITS; do
    if [ "$PATHS_ONLY" = false ]; then
        COMMIT_DATE=$(git show -s --format="%cd" --date=format:"%Y-%m-%d %H:%M:%S" $COMMIT)
        COMMIT_MSG=$(git show -s --format="%s" $COMMIT)
        
        echo "Commit: $COMMIT"
        echo "Date:   $COMMIT_DATE"
        echo "Msg:    $COMMIT_MSG"
        echo "Files:"
        
        # List the files modified in this commit
        git diff-tree --no-commit-id --name-only -r $COMMIT | sed 's/^/  - /'
        
        echo ""
    else
        # Just collect the file paths for later output
        while read -r file; do
            all_files["$file"]=1
        done < <(git diff-tree --no-commit-id --name-only -r $COMMIT)
    fi
done

if [ "$PATHS_ONLY" = true ]; then
    # Output just the unique file paths
    for file in "${!all_files[@]}"; do
        echo "$file"
    done
else
    echo "--------------------------------------------------------------------------------"
    if [ -n "$BRANCH" ]; then
        echo "Summary: $(echo "$COMMITS" | wc -l) commits by $USERID found between $START_COMMIT and $END_COMMIT on branch $BRANCH"
    else
        echo "Summary: $(echo "$COMMITS" | wc -l) commits by $USERID found between $START_COMMIT and $END_COMMIT"
    fi
fi