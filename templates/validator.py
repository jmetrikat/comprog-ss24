#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Validate the output of your solution with this script.

Expected folder structure:
- contest-xx
  |- prob-yy
     |- prob-yy.pdf
     |- solve.cpp
     |- samples
        |- 1.in
        |- 1.ans
        |- ...

Usage:
Navigate to the 'prob-yy' directory and run:
$ python ../validator.py
"""

import os, re , subprocess

def validate(output_file, answer_file):
    with open(output_file, "r") as output, open(answer_file, "r") as answer:
        output_lines = output.readlines()
        answer_lines = answer.readlines()

        if len(output_lines) != len(answer_lines):
            return False

        for output_line, answer_line in zip(output_lines, answer_lines):
            if output_line.strip() != answer_line.strip():
                return False

    return True


test_files = [f for f in os.listdir("./samples") if f.endswith(".in")]
test_files.sort()
curr_dir = os.getcwd()
status = os.system(f"cd ..; make {curr_dir}/solve")
os.chdir(curr_dir)

if status != 0:
    print("Compilation failed")
    exit(1)

for test_file in test_files:
    base_name = test_file[:-3]
    output_file = "./samples/" + base_name + ".out"
    answer_file = "./samples/" + base_name + ".ans"

    os.system("touch " + output_file)
    result = subprocess.run(f"time ./solve < ./samples/{test_file} > {output_file}", shell=True, capture_output=True, text=True)
    output = result.stderr
    match = re.search(r"real\s+([\d\.]+)m([\d\.]+)s", output)

    if validate(output_file, answer_file):
        print(f"{test_file}: PASS {match.group(2)}s")
    else:
        print(f"{test_file}: FAIL {match.group(2)}s")
        print(f"Expected:")
        with open(answer_file, "r") as f:
            print(f.read())
        print(f"Found:")
        with open(output_file, "r") as f:
            print(f.read())

    os.remove(output_file)
