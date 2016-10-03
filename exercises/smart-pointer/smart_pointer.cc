#include "smart_pointer.h"

smart_pointer::smart_pointer() {
    ptr_ = nullptr;
}

smart_pointer::smart_pointer(int* raw_pointer) {
    ptr_ = raw_pointer;
}

smart_pointer::smart_pointer(const smart_pointer& pointer) {
    copy(ptr_);
}

// Move constructor
smart_pointer::smart_pointer(smart_pointer&& pointer) {
    ptr_ = pointer.ptr_;
    pointer.ptr_ = nullptr;
}

smart_pointer::~smart_pointer() {
    if (ptr_ != nullptr) {
        delete ptr_;
    }
}

smart_pointer& smart_pointer::operator=(const smart_pointer& pointer) {
    copy(pointer);
    return *this;
}

smart_pointer& smart_pointer::operator=(smart_pointer&& pointer) {
    ptr_ = pointer.ptr_;
    pointer.ptr_ = nullptr;
    return *this;
}

int& smart_pointer::operator*() {
    return *ptr_;
}

int* smart_pointer::operator->() {
    return ptr_;
}

void smart_pointer::copy(const smart_pointer & pointer) {
    // Copy On Create/Assign
    ptr_ = new int { *(pointer.ptr_) };
}


