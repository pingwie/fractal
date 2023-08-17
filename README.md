# Fractal
This is a very simple project to draw fractals (Julia and mandel sets, and burning ship fractal)

It uses the <a name="https://github.com/codam-coding-college/MLX42">MLX42</a> library.

## Table of contents
1. [Project](#project)
2. [Installation](#dataset)
3. [Files](#files)
4. [ETL Pipeline](#elt)
5. [ML Pipeline](#ml)
6. [Flask Web App](#webapp)
7. [Instructions](#instructions)

## Project <a name="project"></a>
The Goal of this project is to build a program that can draw some fractals. The fractals chousen are Julia, Mandel and Burning Ship. All of them are "time scape" fractals, this is, for every point, time of scape is compute, and then translate into a color.

## Installation <a name="Installation"></a>
- Just clone the repo, and run make.
```
git clone https://github.com/pingwie/fractal
```
- Compile the program.
```
make
```
- Execute the program (available fractals: julia, mandel, burning).
```
./fractal <fractal>
```

