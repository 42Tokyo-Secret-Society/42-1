import os

path = "src"
c_files = [os.path.join(path, f) for f in os.listdir(path) if os.path.isfile(os.path.join(path, f)) and f.endswith(".c")]

for i in range(0, len(c_files)):
    print("\t\t\t{} {}".format(c_files[i], "\\" if i is not len(c_files) - 1 else ""))
    
path = "src-bonus"
c_files = [os.path.join(path, f) for f in os.listdir(path) if os.path.isfile(os.path.join(path, f)) and f.endswith(".c")]

for i in range(0, len(c_files)):
    print("\t\t\t{} {}".format(c_files[i], "\\" if i is not len(c_files) - 1 else ""))