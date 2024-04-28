#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Automate the setup of directories for coding contest problems.

Expected folder structure:
- comprog-ss24
    |- contest-xx
        |- prob-yy.pdf
        |- prob-yy.pdf
        |- …
        |- samples-yy
            |- 1.in
            |- 1.ans
            |- …
        |- samples-yy
            |- …
    |- contest-xx
    |- …

Usage:
Run the script in the directory 'contest-xx' containing the problem files prefixed with 'prob-':
$ python ../setup.py
"""

import os
import shutil

problems = [f for f in os.listdir('.') if f.startswith('prob-')]
samples = [f for f in os.listdir('.') if f.startswith('samples-')]

for problem in problems:
    dirname = problem.replace('.pdf', '')
    os.makedirs(dirname, exist_ok=True)
    shutil.move(problem, f"{dirname}/{problem}")
    shutil.copy('../templates/solve.cpp', f"{dirname}/solve.cpp")
    os.makedirs(f"{dirname}/samples", exist_ok=True)

for sample in samples:
    problem = sample.replace('samples-', '')
    samplefiles = [f for f in os.listdir(f'./samples-{problem}') if f.endswith('.in') or f.endswith('.ans')]
    for samplefile in samplefiles:
        shutil.move(f'samples-{problem}/{samplefile}', f'prob-{problem}/samples/{samplefile}')
    shutil.rmtree(f'samples-{problem}')

os.symlink('../templates/Makefile', 'Makefile')
os.symlink('../templates/validator.py', 'validator.py')
