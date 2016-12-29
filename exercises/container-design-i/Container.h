/*
 * Container.h
 */
#ifndef CONTAINER_H
#define CONTAINER_H

#include <algorithm>
#include <cstdlib>  // std::size_t
#include <new>  // std::bad_alloc
#include <limits>

template <typename T>
class Container
{
   public:
      typedef std::size_t size_type;

      Container() : start_(nullptr), finish_(nullptr), 
                    end_of_storage_(nullptr) {

      }

      Container(const Container& other) {
         if (other.size() > 0) {
            start_ = allocate_and_copy_(other);
            finish_ = start_ + other.size();
            end_of_storage_ = finish_;
         }
      }

      Container(Container &&other) : start_(other.start_),
                                     finish_(other.finish_),
                                     end_of_storage_(other.end_of_storage_) {
         other.start_ = nullptr;
         other.finish_ = nullptr;
         other.end_of_storage_ = nullptr;
      }

      Container(const size_t n)  {
         if (n > 0) {
            start_ = allocate_(n);
            finish_ = start_;
            end_of_storage_ = start_ + n;
         }
      }

      virtual ~Container() {
         deallocate_(start_);
      }

      size_type size() const noexcept {
         return finish_ - start_;
      }

      size_type max_size() const noexcept {
         return std::numeric_limits<size_type>::max() / sizeof(T);
      }

      size_type capacity() const noexcept {
         return end_of_storage_ - start_;
      }

      bool empty() const noexcept {
         return start_ == finish_;
      }

      Container<T>& operator=(const Container& rhs) {
         if (this != &rhs) {
            if (rhs.size() > 0) {
               auto new_start = allocate_and_copy_(rhs);

               deallocate_(start_);

               start_ = new_start;
               finish_ = start_ + rhs.size();
               end_of_storage_ = finish_;
            } else {
               deallocate_(start_);
               start_ = nullptr;
               finish_ = nullptr;
               end_of_storage_ = nullptr;
            }
         }
         return *this;
      }

      Container<T>& operator=(Container&& rhs) noexcept {
         if (this != *rhs) {
            start_ = rhs.start_;
            finish_ = rhs.finish_;
            end_of_storage_ = rhs.end_of_storage_;

            rhs.start_ = nullptr;
            rhs.finish_ = nullptr;
            rhs.end_of_storage = nullptr;
         }
         return *this;
      }

   private:
      T* start_ { nullptr };
      T* finish_ { nullptr };
      T* end_of_storage_ { nullptr };

      T* allocate_(size_type n) {
         if (n > max_size())
            throw std::bad_alloc();

         if (n > 0)
            return new T[n];
         else
            return nullptr;
      }

      void deallocate_(T* p) {
         delete[] p;
      }

      T* allocate_and_copy_(const Container& c) {
         if (c.empty()) {
            return nullptr;
         } else {
            
            auto new_start = allocate_(c.size());

            try {
               std::copy(c.start_, c.finish_, new_start);  // can fail, calls contructors
            } catch (...) {
               deallocate_(new_start);  // cannot fail
               throw;
            }

            return new_start;
         }
      }
};

#endif
