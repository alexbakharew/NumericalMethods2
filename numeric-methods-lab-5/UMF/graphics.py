import matplotlib.pyplot as plt
import math

def func(x, t):
    return math.sin(t) * math.cos(x)

def main():
    # N = int()
    # K = int()
    # l = int()
    # T = int()

    COUNT = 3 # Amount of graphics
    vec = []
    with open("res.txt") as input:
        N, K = input.readline().strip("\n").split(" ")
        l, T = input.readline().strip("\n").split(" ")
        curr_str = input.readline()
        str_count = 1
        while len(curr_str) != 0:
            if str_count % (int(int(K) / COUNT)) == 0:
                vec.append(curr_str)
            curr_str = input.readline()
            str_count += 1

    h = float(l) / float(N)
    x = []
    y = []
    for i in range(int(N)):
        x.append(h * i)
        y.append(func(h * i, int(T)))
    plt.plot(x, y)
    for i in range(COUNT):
        y.clear()
        y = [float(val) for val in vec[i].strip("\n").split(" ", "")]
        plt.plot(x, y)
    plt.show()
    print(vec)

if __name__ == "__main__":
    main()