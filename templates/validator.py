import os

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
os.system(f"cd .. && make {curr_dir}/solve && cd {curr_dir}")

for test_file in test_files:
    base_name = test_file[:-3]
    output_file = "./samples/" + base_name + ".out"
    answer_file = "./samples/" + base_name + ".ans"

    os.system("touch " + output_file)
    os.system(f"./solve < ./samples{test_file} > {output_file}")

    if validate(output_file, answer_file):
        print(f"{test_file}: PASS")
    else:
        print(f"{test_file}: FAIL")

    os.remove(output_file)
