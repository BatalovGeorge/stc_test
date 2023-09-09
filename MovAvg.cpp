// MovAvg.cpp : Defines the entry point for the application.
//

#include "MovAvg.h"

#include <iostream>
#include <vector>
#include <chrono>


#define WINDOW_STP 7

using namespace std;

void MovAvg(vector <float>& vals, int& window)
{
    if (vals.size() >= window && window > 0)
    {
        vector<float>::iterator it;
        it = vals.begin();
        advance(it, window - 1);
        float buff = 0;
        vector <float> buff_vals;
        for (int i = 1; i < vals.size(); i++)
        {
            for (int j = 1; j <= window; j++)
            {
                buff += *it;
                if (j == window) break;
                advance(it, -1);
            }
            buff = buff / window;
            buff_vals.push_back(buff);
            buff = 0;
            if (it < (vals.end() - (window)))
            {
                advance(it, window);
            }
            else break;
        }
    }
    else if (window) cout << "Error!The size of the window is larger than the number of samples!" << endl;
    else cout << "Error!Size of the window equal 0!" << endl;
}

void MovAvg(vector <double>& vals, int& window)
{
    if (vals.size() >= window && window > 0)
    {
        vector<double>::iterator it;
        it = vals.begin();
        advance(it, window - 1);
        float buff = 0;
        vector <double> buff_vals;
        for (int i = 1; i < vals.size(); i++)
        {
            for (int j = 1; j <= window; j++)
            {
                buff += *it;
                if (j == window) break;
                advance(it, -1);
            }
            buff = buff / window;
            buff_vals.push_back(buff);
            buff = 0;
            if (it < (vals.end() - (window))) {
                advance(it, window);
            }
            else break;
        }
    }
    else if (window) cout << "Error!The size of the window is larger than the number of samples!" << endl;
    else cout << "Error!Size of the window equal 0!" << endl;
}

void show_result(vector <double>& D_double, vector <float>& D_float)
{
    int window_sz = 4;

    for (int count = 1; count < WINDOW_STP; count++)
    {
        cout << window_sz << endl;
        auto start_f = chrono::high_resolution_clock::now();

        MovAvg(D_float, window_sz);
        auto end_f = chrono::high_resolution_clock::now();

        chrono::duration<float> duration_f = end_f - start_f;

        cout << "Exec time float: " << duration_f.count() << "sec" << endl;


        auto start_d = chrono::high_resolution_clock::now();

        MovAvg(D_double, window_sz);
        auto end_d = chrono::high_resolution_clock::now();

        chrono::duration<float> duration_d = end_d - start_d;

        cout << "Exec time double: " << duration_d.count() << "sec" << endl;

        window_sz *= 2;
    }
}


int main()
{

    setlocale(LC_ALL, "RU");
    vector <float> D_float;
    vector <double> D_double;

    int vals = 1000000;

    for (int i = 1; i <= vals; i++)
    {
        D_float.push_back(rand() % 100);
        D_double.push_back(rand() % 100);
    }

    show_result(D_double, D_float);


    return 0;
}
