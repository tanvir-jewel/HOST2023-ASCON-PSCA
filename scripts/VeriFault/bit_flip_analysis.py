import matplotlib.pyplot as plt

def read_binary_file(file_name):
    with open(file_name, 'r') as file:
        binary_lines = [line.strip() for line in file]
    return binary_lines

def calculate_bit_flips(binary_lines):
    flip_counts = [0] * len(binary_lines[0])
    for line in binary_lines:
        for i, bit in enumerate(line):
            if bit == '1':
                flip_counts[i] += 1
    return flip_counts

def plot_bit_flips(flip_counts):
    plt.bar(range(len(flip_counts)), flip_counts)
    plt.xlabel('Bit Position')
    plt.ylabel('Bit Flips')
    plt.title('Bit Flips per Position')
    plt.show()

file_name = 'Tag-binary.txt'
binary_lines = read_binary_file(file_name)
flip_counts = calculate_bit_flips(binary_lines)
plot_bit_flips(flip_counts)

