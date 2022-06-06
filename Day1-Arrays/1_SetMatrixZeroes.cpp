#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    bool firstRowZero = false;
    for (int i = 0; i < matrix.size(); i++)
        if (!matrix[i][0])
        {
            firstRowZero = true;
            break;
        }

    bool firstColZero = false;
    for (int j = 0; j < matrix[0].size(); j++)
        if (!matrix[0][j])
        {
            firstColZero = true;
            break;
        }

    for (int i = 1; i < matrix.size(); i++)
        for (int j = 1; j < matrix[0].size(); j++)
            if (!matrix[i][j])
                matrix[i][0] = matrix[0][j] = 0;

    vector<int> zeroCols;
    for (int j = 1; j < matrix[0].size(); j++)
        if (!matrix[0][j])
            zeroCols.emplace_back(j);

    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
            matrix[i] = vector<int>(matrix[0].size(), 0);
        else
        {
            for (int j = 0; j < zeroCols.size(); j++)
                matrix[i][zeroCols[j]] = 0;
        }

        if (firstRowZero)
            matrix[i][0] = 0;
    }

    if (firstColZero)
        matrix[0] = vector<int>(matrix[0].size(), 0);
}