[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6969809&assignment_repo_type=AssignmentRepo)
You will use this exact `Makefile` for your Homework 1. Failure to do so will result in *deduction* of points.

To compile on terminal, type:

```bash
make clean
make all
```


To delete executables and object files, type:

```bash
make clean
```

To run, type:

```bash
./test_points3d
```

## Providing Input from Standard Input

To run with a given file that is redirected to standard input:

```bash
./test_points3d < test_input_file.txt
```
one issue i had was in the copy constructor , when i tried to set the first index of sequence into std::array.
I did this so i can copy the std::array being passed to this point.
My problem was that the copy wasn't happening in the for loop and i was getting some garbage values in the watch.
after stepping into  I noticed I didnt refrence the point which wasn't allowing the copy.