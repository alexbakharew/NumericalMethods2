import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import math
import os
import sys
def ParabolicAnalyticFunction(a, x, t):
    return math.exp( - a * t) * math.cos(x)

def HyperbolicAnalyticFunction(x, t):
    return math.cos(x) * math.sin(2 * t)

def ElepticalAnalyticFunction(x,y):
    return float(x) + y

def print_usage():
    print("TaskType N K l T a PlotName")
    print("TaskType N1 N2 PlotName")

colors = ["b", "g", "r", "c", "y", "b"]
config_file = "res.txt"
COUNT = 3 # Amount of graphics

def main():
    if (len(sys.argv) != 8) and (len(sys.argv)!= 5):
        print_usage()
        exit(-1)
    x = []
    y = []
    handles = []
    plot_title = str()
    task_type = int(sys.argv[1])
    N = K = l = T = a = N1 = N2 = h = plot_name = str()
    if (task_type == 1) or (task_type == 2):
        N = int(sys.argv[2])
        K = int(sys.argv[3])
        l = float(sys.argv[4])
        T = int(sys.argv[5])
        a = float(sys.argv[6])
        plot_name = sys.argv[7]
        h = float(l / N)
        plot_title = "Parabolic" if task_type == 1 else "Hyperbolic"
    elif task_type == 3:
        N1 = int(sys.argv[2])
        N2 = int(sys.argv[3])
        plot_name = sys.argv[4]
        h = 1 / N2
        plot_title = "Eleptical"
    else:
        print("unsupported task type. Exit")
        exit(-2)
    color_count = 0
    def analytic_drawer(N, K, l, T, a, N1, N2, task_type):
        bound = N if task_type <=2 else N2
        for i in range(bound):
            x.append(h * i)
            value = float()
            if task_type == 1:
                value = ParabolicAnalyticFunction(a, h * i, T)
            elif task_type == 2:
                value = HyperbolicAnalyticFunction(h * i, T)
            elif task_type == 3:
                value = ElepticalAnalyticFunction(float(h * i), 1)  
            y.append(value)
    #------------------------------------------------
    # Draw analytic function
    analytic_drawer(N, K, l, T, a, N1, N2, task_type)
    plt.plot(x, y, color=colors[color_count])
    plot_label = mpatches.Patch(color=colors[color_count], label='Analytic')
    handles.append(plot_label)
    color_count += 1
    #------------------------------------------------
    # Draw numeric function from config file

    if os.stat(config_file).st_size == 0:
        exit(-3)

    with open(config_file) as input:
        curr_str = input.readline()
        str_count = 0
        time_count = int(K) if task_type <= 2 else int(N1)
        while len(curr_str) != 0:
            if str_count % (time_count / COUNT) == 0:
                y.clear()
                for val in curr_str.strip("\n").split(" "):
                    if val != "":
                        y.append(float(val)) # append y values
                plt.plot(x, y, color=colors[color_count]) # add plot to scene with unique color
                plot_label = mpatches.Patch(color=colors[color_count], label='Numeric_' + str(color_count))
                handles.append(plot_label) # append plot name to a legend
                color_count += 1 # change further plot color
            curr_str = input.readline() # read next line
            str_count += 1 # increase count
    
    plt.title(plot_title + "_" + plot_name)
    plt.ylabel('value')
    plt.xlabel('length')
    plt.legend(handles=handles)
    plt.show()
    

if __name__ == "__main__":
    main()