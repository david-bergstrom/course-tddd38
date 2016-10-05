#ifndef SMART_POINTER_H
#define SMART_POINTER_H

class smart_pointer {
    public:
        smart_pointer() noexcept;
        smart_pointer(int*);
        smart_pointer(const smart_pointer&);
        smart_pointer(smart_pointer&&) noexcept;
        ~smart_pointer();

        smart_pointer& operator=(const smart_pointer&);
        smart_pointer& operator=(smart_pointer&&) noexcept;

        bool operator!() const;
        bool operator==(const smart_pointer&) const;
        bool operator==(int*) const;
        bool operator!=(const smart_pointer&) const;
        bool operator!=(int*) const;

        int& operator*() { return *ptr_; }
        int  operator*() const { return *ptr_; }

        int*       operator->() { return ptr_; }
        const int* operator->() const { return ptr_; }

    private:
        int* ptr_;
        void copy(const smart_pointer&);
};

#endif
