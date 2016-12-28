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

      Container(const Container& c) : start_(allocate_and_copy_(c)),
                                      finish_(start_ + c.size()),
                                      end_of_storage_(finish_) {
      }

      Container(Container &&c) : start_(c.start_),
                                 finish_(c.finish_),
                                 end_of_storage_(c.end_of_storage_) {
         c.start_ = nullptr;
         c.finish_ = nullptr;
         c.end_of_storage_ = nullptr;

      }

      Container(size_t n) : start_(allocate_(n)), finish_(start_), 
                            end_of_storage_(start_ + n) {
      }

      virtual ~Container() {
         deallocate_(start_);
      }

      size_type size() const {
         return finish_ - start_;
      }

      size_type max_size() {
         return std::numeric_limits<size_type>::max() / sizeof(T);
      }

      size_type capacity() {
         return end_of_storage_ - finish_;
      }

      bool empty() const {
         return start_ == finish_;
      }

      // TODO: The return type is wrong, we don't deallocate the current help
      // memory
      void operator=(Container& rhs) {
         start_ = allocate_(rhs.size());
         finish_ = start_ + rhs.size();
         end_of_storage_ = finish_;

         std::copy(rhs.start_, rhs.finish_, start_);
      }

      // TODO: The return type is wrong, we don't deallocate the current help
      // memory
      void operator=(Container&& rhs) {
         if (this != *rhs) {

         }
         start_ = rhs.start_;
         finish_ = rhs.finish_;
         end_of_storage_ = rhs.end_of_storage_;
      }

   private:
      T* start_ { nullptr };
      T* finish_ { nullptr };
      T* end_of_storage_ { nullptr };

      T* allocate_(size_type n) {
         if (n > max_size())
            throw std::bad_alloc();

         return new T[n];
      }

      void deallocate_(T* p) {
         delete[] p;
      }

      T* allocate_and_copy_(const Container& c) {
         if (c.empty()) {
            return nullptr;
         } else {
            
            auto p = allocate_(c.size());

            try {
               std::copy(c.start_, c.finish_, p);
            } catch (...) {
               deallocate_(p);
               throw;
            }

            return p;
         }
      }
};

#endif
