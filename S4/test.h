class CMatrix {
public:
    class CRow {
        friend class CMatrix;
    public:
        int& operator[](int col)
        {
            return parent.arr[row][col];
        }
    private:
        CRow(CMatrix &parent_, int row_) :
            parent(parent_),
            row(row_)
        {}

        CMatrix& parent;
        int row;
    };

    CRow operator[](int row)
    {
        return CRow(*this, row);
    }
private:
    int rows, cols;
    int **arr;
};
