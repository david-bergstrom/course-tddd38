#ifndef SMART_POINTER_H
#define SMART_POINTER_H

class smart_pointer {
    public:
        smart_pointer();
        smart_pointer(int*);
        smart_pointer(const smart_pointer&);
        smart_pointer(smart_pointer&&);
        ~smart_pointer();
        smart_pointer& operator=(const smart_pointer&);
        smart_pointer& operator=(smart_pointer&&);
        int& operator*();
        int* operator->();
        void debug();
    private:
        int* ptr_;
        void copy(const smart_pointer&);
};

#endif