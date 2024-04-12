import os

def validate(output_file, answer_file):
    with open(output_file, 'r') as output, open(answer_file, 'r') as answer:
        output_lines = output.readlines()
        answer_lines = answer.readlines()

        if len(output_lines) != len(answer_lines):
            return False

        for output_line, answer_line in zip(output_lines, answer_lines):
            if output_line.strip() != answer_line.strip():
                return False

    return True


test_files = [f for f in os.listdir('.') if f.endswith('.in')]
test_files.sort()

for test_file in test_files:
    base_name = test_file[:-3]
    output_file = base_name + '.out'
    answer_file = base_name + '.ans'

    if not os.path.exists('./solve'):
        os.system('cd .. && make && cd -')
    os.system(f"./solve < {test_file} > {output_file}")

    if validate(test_file, output_file, answer_file):
        print(f"{test_file}: PASS")
    else:
        print(f"{test_file}: FAIL")

    os.remove(output_file)
