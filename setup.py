import os

problems = [f for f in os.listdir('.') if f.startswith('prob-')]

for problem in problems:
    dirname = problem.replace('prob-', '').replace('.pdf', '')
    os.system(f"mkdir -p {dirname}")
    os.system(f"mv {problem} {dirname}/{problem}")
    os.system(f"cp ../templates/solve.cpp {dirname}/solve.cpp")
    os.system(f"mkdir -p {dirname}/samples")

os.system(f"ln -sf ../templates/Makefile ./Makefile")
os.system(f"ln -sf ../templates/validator.py ./validator.py")
