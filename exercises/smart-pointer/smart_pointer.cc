#include "smart_pointer.h"
#include <iostream>

smart_pointer::smart_pointer() noexcept {
    ptr_ = nullptr;
}

smart_pointer::smart_pointer(int* raw_pointer) {
    ptr_ = raw_pointer;
}

smart_pointer::smart_pointer(const smart_pointer& pointer) {
    copy(pointer);
}

// Move constructor
smart_pointer::smart_pointer(smart_pointer&& pointer) noexcept {
    ptr_ = pointer.ptr_;
    pointer.ptr_ = nullptr;
    std::cout << "Used move constructor" << std::endl;
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

smart_pointer& smart_pointer::operator=(smart_pointer&& pointer) noexcept {
    ptr_ = pointer.ptr_;
    pointer.ptr_ = nullptr;
    std::cout << "Used move assignment" << std::endl;
    return *this;
}

int& smart_pointer::operator*() {
    return *ptr_;
}

int* smart_pointer::operator->() {
    return ptr_;
}

bool smart_pointer::operator!() const {
    return ptr_ == nullptr;
}

bool smart_pointer::operator==(const smart_pointer& pointer) const {
    return ptr_ == pointer.ptr_;
}

bool smart_pointer::operator==(int* pointer) const {
    return ptr_ == pointer;
}

bool smart_pointer::operator!=(const smart_pointer& pointer) const {
    return ptr_ != pointer.ptr_;
}

bool smart_pointer::operator!=(int * pointer) const {
    return ptr_ != pointer;
}

void smart_pointer::copy(const smart_pointer & pointer) {
    // Copy On Create/Assign
    ptr_ = new int { *(pointer.ptr_) };
}
