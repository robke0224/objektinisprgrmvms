#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include <limits>

template <typename T>
class Vector {
public:
    // MEMBER TYPE
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;

    // MEMBER FUNCTIONS

    /// Constructors
    //// default
    Vector() { create(); }
    //// fill
    explicit Vector(size_type n, const T& t = T{}) { create(n, t); }
    //// copy constructor
    Vector(const Vector& v) { create(v.begin(), v.end()); }
    //// range constructor
    template <class InputIterator>
    Vector(InputIterator first, InputIterator last) { create(first, last); }
    //// move constructor
    Vector(Vector&& v) {
        create();
        swap(v);
        v.uncreate();
    }
    //// initializer list constructor
    Vector(const std::initializer_list<T> il) { create(il.begin(), il.end()); }

    /// Destructor
    ~Vector() { uncreate(); }

    /// Operator =
    //// copy assignment
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            uncreate();
            create(other.begin(), other.end());
        }
        return *this;
    }

    //// move assignment
    Vector& operator=(Vector&& other) {
        if (this != &other) {
            uncreate();
            swap(other);
            other.uncreate();
        }
        return *this;
    }

    /// Assign
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last) {
        uncreate();
        create(first, last);
    }
    void assign(size_type n, const value_type& val) {
        uncreate();
        create(n, val);
    }
    void assign(std::initializer_list<value_type> il) {
        uncreate();
        create(il.begin(), il.end());
    }

    // Element access
    const_reference at(size_type n) const {
        if (n >= size() || n < 0)
            throw std::out_of_range("Index out of range");
        return dat[n];
    }

    reference operator[](size_type n) { return dat[n]; }
    const_reference operator[](size_type n) const { return dat[n]; }
    reference at(size_type n) {
        if (n >= size() || n < 0)
            throw std::out_of_range("Index out of range");
        return dat[n];
    }

    reference front() { return dat[0]; }
    const_reference front() const { return dat[0]; }
    reference back() { return dat[size() - 1]; }
    const_reference back() const { return dat[size() - 1]; }
    value_type* data() noexcept { return dat; }
    const value_type* data() const noexcept { return dat; }

    // Iterators
    iterator begin() { return dat; }
    const_iterator begin() const { return dat; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    // Capacity
    size_type size() const { return avail - dat; }
    size_type max_size() const { return std::numeric_limits<size_type>::max(); }
    void resize(size_type sz) {
        if (sz < size()) {
            iterator it = dat + sz;
            while (it != avail) {
                alloc.destroy(it++);
            }
            avail = dat + sz;
        } else if (sz > capacity()) {
            grow(sz);
            std::uninitialized_fill(avail, dat + sz, value_type());
            avail = dat + sz;
        } else if (sz > size()) {
            std::uninitialized_fill(avail, dat + sz, value_type());
            avail = dat + sz;
        }
    }

    void resize(size_type sz, const value_type& value) {
        if (sz > capacity()) {
            grow(sz);
        }

        if (sz > size()) {
            insert(end(), sz - size(), value);
        } else if (sz < size()) {
            avail = dat + sz;
        }
    }

    size_type capacity() const { return limit - dat; }
    bool empty() const noexcept { return size() == 0; }
    void reserve(size_type n) {
        if (n > capacity()) {
            grow(n);
        }
    }
    void shrink_to_fit() {
        if (limit > avail) {
            limit = avail;
        }
    }

    // Modifiers
    void clear() noexcept {
        uncreate();
    }

    iterator insert(const_iterator position, const value_type& val) {
        return insert(position, 1, val);
    }
    iterator insert(iterator position, size_type n, const value_type& val) {
        if (position < begin() || position > end()) {
            throw std::out_of_range("Index out of range");
        }
        if (avail + n > limit) {
            size_type index = position - begin();
            grow(n);
            position = begin() + index;
        }
        for (iterator it = end() + n - 1; it != position + n - 1; --it) {
            *it = std::move(*(it - n));
        }
        std::uninitialized_fill(position, position + n, val);
        avail += n;

        return position;
    }

    iterator erase(iterator position) {
        if (position < dat || position >= avail) {
            throw std::out_of_range("Index out of range");
        }
        std::move(position + 1, avail, position);
        alloc.destroy(--avail);

        return position;
    }

    iterator erase(iterator first, iterator last) {
        if (first < dat || last > avail || first > last) {
            throw std::out_of_range("Index out of range");
        }
        iterator new_avail = std::move(last, avail, first);
        for (iterator it = new_avail; it != avail; ++it) {
            alloc.destroy(it);
        }
        avail = new_avail;

        return first;
    }

    void push_back(const value_type& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }

    void push_back(value_type&& val) {
        if (avail == limit)
            grow();
        unchecked_append(std::move(val));
    }

    void pop_back() {
        if (avail != dat)
            alloc.destroy(--avail);
    }

    void swap(Vector& x) {
        std::swap(dat, x.dat);
        std::swap(avail, x.avail);
        std::swap(limit, x.limit);
    }

    // NON-MEMBER FUNCTIONS

    bool operator==(const Vector<T>& other) const {
        if (size() != other.size()) {
            return false;
        }

        return std::equal(begin(), end(), other.begin());
    }
    bool operator!=(const Vector<T>& other) const {
        return !(*this == other);
    }
    bool operator<(const Vector<T>& other) const {
        return std::lexicographical_compare(begin(), end(), other.begin(), other.end());
    }
    bool operator<=(const Vector<T>& other) const {
        return !(other < *this);
    }
    bool operator>(const Vector<T>& other) const {
        return std::lexicographical_compare(other.begin(), other.end(), begin(), end());
    }
    bool operator>=(const Vector<T>& other) const {
        return !(other > *this);
    }

private:
    iterator dat;
    iterator avail;
    iterator limit;
    std::allocator<T> alloc;

    void create() { dat = avail = limit = nullptr; }
    void create(size_type n, const T& val) {
        dat = alloc.allocate(n);
        limit = avail = dat + n;
        std::uninitialized_fill(dat, limit, val);
    }
    void create(const_iterator i, const_iterator j) {
        dat = alloc.allocate(j - i);
        limit = avail = std::uninitialized_copy(i, j, dat);
    }
    void uncreate() {
        if (dat) {
            iterator it = avail;
            while (it != dat) {
                alloc.destroy(--it);
            }
            alloc.deallocate(dat, limit - dat);
        }
        dat = limit = avail = nullptr;
    }
    void grow(size_type new_capacity = 0) {
        size_type new_size = std::max(new_capacity, 2 * capacity());
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(std::make_move_iterator(dat), std::make_move_iterator(avail), new_data);
        uncreate();
        dat = new_data;
        avail = new_avail;
        limit = dat + new_size;
    }
    void unchecked_append(const T& val) {
        alloc.construct(avail++, val);
    }
    void unchecked_append(T&& val) {
        alloc.construct(avail++, std::move(val));
    }
};
