#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

echo

if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Cannot find compiler at path ${compiler}. Terminating."
    exit
fi

working_dec="test_deliverable/test_cases"

tests_passed=0
tests_run=0

for f in ${working_dec}/*; do  # will specify to look at folder - folder name should be same as test program (with .c obvs)
    basename=${f##*/}
    echo "Testing ${basename}..."
    ${compiler} -S ${f}/${basename}.c -o ${f}/${basename}.s #&>/dev/null
    mips-linux-gnu-gcc -mfp32 -o ${f}/${basename}.o -c ${f}/${basename}.s #&>/dev/null
    mips-linux-gnu-gcc -mfp32 -static -o ${f}/${basename} ${f}/${basename}.o ${f}/${basename}_driver.c #&>/dev/null
    timeout 5 qemu-mips ${f}/${basename} #&>/dev/null
    result=$?
    rm -rf ${f}/${basename}.s ${f}/${basename}.o ${f}/${basename}
    tests_run=$((tests_run+1))

    if (( ${result} == 0 )); then
        echo -e "Pass.\n"
        tests_passed=$((tests_passed+1))
    else
        echo -e "Failed. Exited with code ${result}.\n"
    fi

done

echo -e "Passed ${tests_passed} out of ${tests_run} tests.\n"
