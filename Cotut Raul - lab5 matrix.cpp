#include <iostream>
#include <memory>

class Matrix {
private:
    int rows;
    int cols;
    std::unique_ptr<int[]> data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols), data(new int[rows * cols]) {}

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(new int[rows * cols]) {
        std::copy(other.data.get(), other.data.get() + (rows * cols), data.get());
    }

    void setData(int el[]) {
      for(int i = 0; i < rows * cols; i++) {
        data[i] = el[i];
      }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i * cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix a(2, 3);
    int adata[10]= {1,2,3,4,5,6};
    a.setData(adata);
    a.display();
    std::cout << std::endl;

    Matrix b(2, 3);
    int bdata[10]= {6,5,4,3,2,1};
    b.setData(bdata);
    b.display();
    std::cout << std::endl;

    Matrix c(b);
    c.display();
    std::cout << std::endl;

    Matrix d = a;
    d.display();
    std::cout << std::endl;

    Matrix e = a + b;
    e.display();
    std::cout << std::endl;

    return 0;
}
