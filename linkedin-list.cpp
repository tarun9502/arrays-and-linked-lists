// By Tarun Goud
#include <iostream>

struct MatrixNode
{
    int rowIdx;
    int colIdx;
    int elementValue;
    MatrixNode *nextNode;
};

class SparseMatrix
{
private:
    MatrixNode *matrixHead;

public:
    SparseMatrix()
    {
        matrixHead = nullptr;
    }

    void addElement(int rowIdx, int colIdx, int elementValue)
    {
        if (elementValue != 0)
        {
            MatrixNode *newMatrixNode = new MatrixNode;
            newMatrixNode->rowIdx = rowIdx;
            newMatrixNode->colIdx = colIdx;
            newMatrixNode->elementValue = elementValue;
            newMatrixNode->nextNode = nullptr;

            if (matrixHead == nullptr)
            {
                matrixHead = newMatrixNode;
            }
            else
            {
                MatrixNode *tempNode = matrixHead;
                while (tempNode->nextNode != nullptr)
                {
                    tempNode = tempNode->nextNode;
                }
                tempNode->nextNode = newMatrixNode;
            }
        }
    }

    void displayMatrix()
    {
        if (matrixHead == nullptr)
        {
            std::cout << "Sparse Matrix is empty" << std::endl;
        }
        else
        {
            MatrixNode *tempNode = matrixHead;
            while (tempNode != nullptr)
            {
                std::cout << "Row: " << tempNode->rowIdx << ", Column: " << tempNode->colIdx << ", Value: " << tempNode->elementValue << std::endl;
                tempNode = tempNode->nextNode;
            }
        }
    }
};

int main()
{
    SparseMatrix sparseMatrix;

    int numRows, numCols;
    std::cout << "Enter the number of rows in the matrix: ";
    std::cin >> numRows;

    std::cout << "Enter the number of columns in the matrix: ";
    std::cin >> numCols;

    std::cout << "Enter the elements of the matrix:" << std::endl;

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            int elementValue;
            std::cout << "Element at position (" << i << ", " << j << "): ";
            std::cin >> elementValue;

            sparseMatrix.addElement(i, j, elementValue);
        }
    }

    std::cout << "\nSparse Matrix:" << std::endl;
    sparseMatrix.displayMatrix();

    return 0;
}
