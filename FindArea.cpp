#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3) {
        cout << "usage FindArea.exe <input file path> <output file path>";
        return 1;
    }

    ifstream infile (argv[1]);
    ofstream outfile(argv[2]);

    int n;
    double area = 0;
    if (infile.is_open()) {
        infile >> n;

        

        int firstX, firstY, lastX, lastY, x, y, x2, y2;
        int prearea1(0), prearea2(0);
        infile >> firstX >> firstY;
        x = firstX;
        y = firstY;
        for (size_t i = 1; i < n-1; i++)
        {
            infile >> x2 >> y2;
            area += (x * y2 - x2 * y);
            x = x2;
            y = y2;

        }
        infile >> lastX >> lastY;

        area += (x2 * lastY - y2 * lastX) + (lastX * firstY - lastY * firstX);
        area = (area < 0) ? (area/(-2)) : (area/2);
    
    
    }
    outfile << area;




    return 0;
}

