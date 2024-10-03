sudoku:
	g++ -std=c++11 main.cpp -o sudoku
fast:
	g++ -std=c++11 -o1 main.cpp -o sudoku
faster:
	g++ -std=c++11 -o2 main.cpp -o sudoku
clean:
	del sudoku.exe
