#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if (n == 1 || m == 1)
        return;

    int iStart = 0, iEnd = n - 1, jStart = 0, jEnd = m - 1;
    while (iStart < iEnd && jStart < jEnd)
    {
        for (int j = jStart; j <= jEnd; j++)
        {
            if (mat[iStart][jStart] == mat[iStart][j])
                continue;
            mat[iStart][jStart] ^= mat[iStart][j] ^= mat[iStart][jStart] ^= mat[iStart][j];
        }

        for (int i = iStart + 1; i <= iEnd; i++)
        {
            if (mat[iStart][jStart] == mat[i][jEnd])
                continue;
            mat[iStart][jStart] ^= mat[i][jEnd] ^= mat[iStart][jStart] ^= mat[i][jEnd];
        }

        for (int j = jEnd - 1; j >= jStart; j--)
        {
            if (mat[iStart][jStart] == mat[iEnd][j])
                continue;
            mat[iStart][jStart] ^= mat[iEnd][j] ^= mat[iStart][jStart] ^= mat[iEnd][j];
        }

        for (int i = iEnd - 1; i >= iStart + 1; i--)
        {
            if (mat[iStart][jStart] == mat[i][jStart])
                continue;
            mat[iStart][jStart] ^= mat[i][jStart] ^= mat[iStart][jStart] ^= mat[i][jStart];
        }

        iStart++, jStart++, iEnd--, jEnd--;
    }
}