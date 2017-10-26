class Vector {
public:
    float* r;
    Vector(float x, float y)
    {
        r = new float [2];
        r[0] = x;
        r[1] = y;
    }
    Vector(float x, float y, float z)
    {
        r = new float [3];
        r[0] = x;
        r[1] = y;
        r[2] = z;
    }
    ~Vector(){
        delete[] r;
    }

    Vector operator+(Vector lhs, const Vector& rhs){
        
    }
}
