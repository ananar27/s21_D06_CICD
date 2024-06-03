#!/bin/bash

cp ../materials/linters/.clang-format .
RESULT=$(clang-format -n ./cat/*.c ./cat/*.h ./grep/*.c ./grep/*.h 2>&1)
if [[ $RESULT ]];
then
echo "Style check failed. $RESULT"
rm -rf .clang-format
exit 1
fi

rm -rf .clang-format
exit 0
