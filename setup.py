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
        |- samples-yy.zip
        |- samples-yy.zip
        |- …
    |- contest-xx
    |- …

Usage:
Run the script in the directory 'contest-xx' containing the problem files prefixed with 'prob-':
$ python ../setup.py
"""

import os
import shutil
import zipfile


def create_directory(path) -> None:
    try:
        os.makedirs(os.path.join('.', path), exist_ok=True)
    except OSError as e:
        print(f"Failed to create directory: {e}")


def move_file(src, dst) -> None:
    try:
        shutil.move(os.path.join('.', src), dst)
    except OSError as e:
        print(f"Failed to move file: {e}")


os.system("/bin/zsh -c '{}'".format("source ~/.zshrc; told"))

problems = [f for f in os.listdir('.') if f.startswith('prob-') and os.path.isfile(f)]
samples = [f for f in os.listdir('.') if f.startswith('samples-') and os.path.isfile(f)]

if not problems:
    print("No problem files found.")
if not samples:
    print("No sample files found.")

# unzip sample files
for sample in samples:
    target_dir = sample.replace('.zip', '')
    with zipfile.ZipFile(os.path.join('.', sample), 'r') as zip_ref:
        zip_ref.extractall(target_dir)
        os.remove(sample)

os.system("/bin/zsh -c '{}'".format("source ~/.zshrc; told"))

# create folder hierarchy for each problem including problem description and template
for problem_name in problems:
    dirname = problem_name.replace('.pdf', '')
    create_directory(dirname)
    create_directory(os.path.join('.', dirname, 'samples'))
    move_file(problem_name, os.path.join('.', dirname, problem_name))
    shutil.copy('../templates/solve.cpp', os.path.join('.', dirname, 'solve.cpp'))

# extract samples from zip archive and move to problem target folders
for sample in samples:
    target_dir = sample.replace('.zip', '')
    problem_name = target_dir.replace('samples-', '')
    samplefiles = [f for f in os.listdir(os.path.join('.', 'samples-' + problem_name)) if f.endswith('.in') or f.endswith('.ans')]

    for samplefile in samplefiles:
        move_file(os.path.join('.', 'samples-' + problem_name, samplefile), os.path.join('.', 'prob-' + problem_name, 'samples', samplefile))

    shutil.rmtree(f'samples-{problem_name}')

# symlink Makefile and validator.py
if os.path.islink('makefile'):
    os.remove('makefile')
try:
    os.symlink('../templates/Makefile', 'Makefile')
except OSError as e:
    print(f"Failed to create symlink: {e}")

if os.path.islink('validator.py'):
    os.remove('validator.py')
try:
    os.symlink('../templates/validator.py', 'validator.py')
except OSError as e:
    print(f"Failed to create symlink: {e}")

print("Setup complete.")
