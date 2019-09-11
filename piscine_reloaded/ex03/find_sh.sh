#!/bin/sh
find . -type f -name '*.sh' -print | cut -d. -f2 | rev | cut -d/ -f1 | rev
