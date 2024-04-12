#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Automate the setup of directories for coding contest problems.

Usage:
Run the script in the directory 'contest-xx' containing the problem files prefixed with 'prob-':
$ python ../setup.py
"""

import os
import shutil

problems = [f for f in os.listdir('.') if f.startswith('prob-')]

for problem in problems:
    dirname = problem.replace('.pdf', '')
    os.makedirs(dirname, exist_ok=True)
    shutil.move(problem, f"{dirname}/{problem}")
    shutil.copy('../templates/solve.cpp', f"{dirname}/solve.cpp")
    os.makedirs(f"{dirname}/samples", exist_ok=True)

os.symlink('../templates/Makefile', 'Makefile')
os.symlink('../templates/validator.py', 'validator.py')
