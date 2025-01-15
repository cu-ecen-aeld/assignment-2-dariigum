#!/bin/bash
# Full test script for Assignment 2

set -e

# Build the writer program
make -C finder-app clean
make -C finder-app

# Run the finder test script
./finder-test.sh

echo "All tests passed!"
