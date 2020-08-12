#include <iostream>

class CopyObject{
    private:
        int* val;

    public:
        CopyObject(int val){
            this->val = new int(val);
        }
        ~CopyObject(){}
        void setVal(int val){
            *(this->val) = val;
        }
        void showVal(){
            std::cout << *(this->val) << std::endl;
        }
};

int main(){
    CopyObject a(0), b(1);

    b = a;

    b.setVal(2);

    a.showVal();
    b.showVal();
    return 0;
}
