#include <iostream>
#include <utility>

template <typename T>
class scoped_ptr {

	T * ptr_;

public:

	scoped_ptr (T * ptr = nullptr) {
		ptr_ = ptr;
	}

	~scoped_ptr () {
		delete ptr_;
	}

	scoped_ptr (const scoped_ptr&) = delete;
	operator= (const scoped_ptr&) = delete;

	T & operator* () const {
		return *ptr_;
	}

	T* operator-> () const {
		return ptr_;
	}

	void swap ( scoped_ptr& another) {
		std::swap (ptr_, another.ptr_);
	}

	void reset ( T * p = nullptr ) {
		delete ptr_;
		ptr_ = p;
	}

	T* get () const {
		return ptr_;
	}
};
