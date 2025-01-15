#!/bin/bash
# Finder test script for Assignment 2

set -e

WRITER="./finder-app/writer"
TESTFILE="/tmp/testfile"
TESTSTRING="Test string for Assignment 2"

# Clean up from previous runs
rm -f "$TESTFILE"

# Run the writer utility
$WRITER "$TESTFILE" "$TESTSTRING"

# Verify the file contains the string
if grep -q "$TESTSTRING" "$TESTFILE"; then
    echo "Success: The string was written to the file."
else
    echo "Failure: The string was not found in the file."
    exit 1
fi
