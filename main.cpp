#include "util.h"

// ************ FUNCTION DECLARATIONS ************
bool solve(int (*grid)[9][9], int* backtracks);
void print(int (*grid)[9][9]);
bool findNextEmpty(int (*grid)[9][9], int* r, int* c);

// const so things aren't accidentally changed while verifying
bool isValid(int const (*grid)[9][9], int const &r, int const &c, int i);
bool readPuzzle(int (*grid)[9][9], std::string filename);


// ************ MAIN ************
int main(int argc, char* argv[])
{
    if (argc != 2) { throw CommandLineException(); }
    
    std::string filename = argv[1];

    int grid[9][9];
    readPuzzle(&grid, filename);
    
    // Used for benchmarking
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    int backtracks = 0;

    auto t1 = high_resolution_clock::now();
    if (solve(&grid, &backtracks))
    {
        std::cout << "Solution found:" << std::endl;
        print(&grid);
    }
    else {std::cout << "No solutions found" << std::endl;}
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << "Process finished in " << ms_double.count() << "ms with " << backtracks << " backtracks." << std::endl;
    return 0;
}


// ************ FUNCTION DEFINITIONS ************

bool solve(int (*grid)[9][9], int* backtracks)
{
    int r = 0, c = 0;

    // Base case
    // Check if there are any empty cells remaining, if not, return true
    if (!findNextEmpty(grid, &r, &c)) {return 1;}

    
    //Try each digit 1 - 9
    for (int i=1;i<10;i++)
    {
        if (isValid(grid, r, c, i))
        {
            // do
            (*grid)[r][c]=i;
            // recurse
            if(solve(grid, backtracks)){return 1;}
            // undo
            (*grid)[r][c]=0;
            
        }
    }
    // increment the number of backtracks for performance tracking
    (*backtracks)++;
    return 0;
}

// Scans the grid, finds the next empty in cell, and stores it's coordinates at r, c
bool findNextEmpty(int (*grid)[9][9], int* r, int* c)
{
    for (int i = 0; i < 9; i++)
        for (int j=0;j<9;j++)
        {
            if ((*grid)[i][j] == 0) 
            {
                *r = i;
                *c = j;
                return 1;
            }
        }

    return 0;
}

// checks if a digit i placed in a cell (r,c) satisfies the row/column/box constraints
bool isValid(int const (*grid)[9][9], int const &r, int const &c, int i)
{
    for (int j = 0;j<9;j++)
    {
        // Scan row for conflicts
        if ((*grid)[j][c] == i){return 0;}
        // Scan column for conflicts
        if((*grid)[r][j]==i){return 0;}
    }

    // scan box for conflicts
    for (int j=0;j<3;j++)
    {
        for(int k=0;k<3;k++)
        {
            if ((*grid)[j + r-(r%3)][k + c-c%3] == i){return 0;}
        }
    }
    // If we've made it this far, no conflicts were found. Return true
    return 1;
}

void print(int (*grid)[9][9])
{
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            std::cout << (*grid)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool readPuzzle(int (*grid)[9][9], std::string filename)
{
    std::ifstream infile(filename);

    if(infile.fail()){ throw FileException(filename); return 0;}
    
    for (int r=0;r<9;r++)
    {
        for (int c=0;c<9;c++)
        {
            infile >> (*grid)[r][c];
        }
    }
    return 1;
}