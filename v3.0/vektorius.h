/**
 * @file Vector.h
 * @brief Implementation of a templated dynamic array class similar to std::vector.
 * 
 * This file contains the definition of the Vector class template, which provides a
 * dynamic array with similar functionality to std::vector.
 */

#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include <limits>

/**
 * @brief A templated dynamic array class.
 * 
 * This class provides a dynamic array similar to std::vector.
 * 
 * @tparam T Type of the elements.
 */
template <typename T>
class Vector {
public:
    // MEMBER TYPE
    typedef size_t size_type;            ///< Size type for the vector.
    typedef T value_type;                ///< Value type of the elements.
    typedef T& reference;                ///< Reference type to an element.
    typedef const T& const_reference;    ///< Constant reference type to an element.
    typedef T* iterator;                 ///< Iterator type.
    typedef const T* const_iterator;     ///< Constant iterator type.

    // MEMBER FUNCTIONS

    /// @name Constructors
    /// @{
    /**
     * @brief Default constructor.
     * 
     * Constructs an empty Vector.
     */
    Vector() { create(); }

    /**
     * @brief Fill constructor.
     * 
     * Constructs a Vector with `n` elements, each initialized to `t`.
     * 
     * @param n Number of elements.
     * @param t Value to initialize elements with.
     */
    explicit Vector(size_type n, const T& t = T{}) { create(n, t); }

    /**
     * @brief Copy constructor.
     * 
     * Constructs a Vector by copying another Vector.
     * 
     * @param v Vector to copy.
     */
    Vector(const Vector& v) { create(v.begin(), v.end()); }

    /**
     * @brief Range constructor.
     * 
     * Constructs a Vector with elements from the range [first, last).
     * 
     * @tparam InputIterator Iterator type.
     * @param first Start of the range.
     * @param last End of the range.
     */
    template <class InputIterator>
    Vector(InputIterator first, InputIterator last) { create(first, last); }

    /**
     * @brief Move constructor.
     * 
     * Constructs a Vector by moving another Vector.
     * 
     * @param v Vector to move.
     */
    Vector(Vector&& v) {
        create();
        swap(v);
        v.uncreate();
    }

    /**
     * @brief Initializer list constructor.
     * 
     * Constructs a Vector with elements from an initializer list.
     * 
     * @param il Initializer list.
     */
    Vector(const std::initializer_list<T> il) { create(il.begin(), il.end()); }
    /// @}

    /**
     * @brief Destructor.
     * 
     * Destructs the Vector and releases resources.
     */
    ~Vector() { uncreate(); }

    /// @name Assignment Operators
    /// @{
    /**
     * @brief Copy assignment operator.
     * 
     * Assigns the contents of another Vector to this Vector.
     * 
     * @param other Vector to copy.
     * @return Reference to this Vector.
     */
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            uncreate();
            create(other.begin(), other.end());
        }
        return *this;
    }

    /**
     * @brief Move assignment operator.
     * 
     * Moves the contents of another Vector to this Vector.
     * 
     * @param other Vector to move.
     * @return Reference to this Vector.
     */
    Vector& operator=(Vector&& other) {
        if (this != &other) {
            uncreate();
            swap(other);
            other.uncreate();
        }
        return *this;
    }
    /// @}

    /// @name Assign Functions
    /// @{
    /**
     * @brief Assigns a range of elements to the Vector.
     * 
     * @tparam InputIterator Iterator type.
     * @param first Start of the range.
     * @param last End of the range.
     */
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last) {
        uncreate();
        create(first, last);
    }

    /**
     * @brief Assigns `n` elements of value `val` to the Vector.
     * 
     * @param n Number of elements.
     * @param val Value to assign.
     */
    void assign(size_type n, const value_type& val) {
        uncreate();
        create(n, val);
    }

    /**
     * @brief Assigns elements from an initializer list to the Vector.
     * 
     * @param il Initializer list.
     */
    void assign(std::initializer_list<value_type> il) {
        uncreate();
        create(il.begin(), il.end());
    }
    /// @}

    // Element access
    /**
     * @brief Accesses the element at position `n` with bounds checking.
     * 
     * @param n Position of the element.
     * @return Constant reference to the element.
     * @throws std::out_of_range If `n` is out of range.
     */
    const_reference at(size_type n) const {
        if (n >= size() || n < 0)
            throw std::out_of_range("Index out of range");
        return dat[n];
    }

    /**
     * @brief Accesses the element at position `n`.
     * 
     * @param n Position of the element.
     * @return Reference to the element.
     */
    reference operator[](size_type n) { return dat[n]; }

    /**
     * @brief Accesses the element at position `n`.
     * 
     * @param n Position of the element.
     * @return Constant reference to the element.
     */
    const_reference operator[](size_type n) const { return dat[n]; }

    /**
     * @brief Accesses the element at position `n` with bounds checking.
     * 
     * @param n Position of the element.
     * @return Reference to the element.
     * @throws std::out_of_range If `n` is out of range.
     */
    reference at(size_type n) {
        if (n >= size() || n < 0)
            throw std::out_of_range("Index out of range");
        return dat[n];
    }

    /**
     * @brief Accesses the first element.
     * 
     * @return Reference to the first element.
     */
    reference front() { return dat[0]; }

    /**
     * @brief Accesses the first element.
     * 
     * @return Constant reference to the first element.
     */
    const_reference front() const { return dat[0]; }

    /**
     * @brief Accesses the last element.
     * 
     * @return Reference to the last element.
     */
    reference back() { return dat[size() - 1]; }

    /**
     * @brief Accesses the last element.
     * 
     * @return Constant reference to the last element.
     */
    const_reference back() const { return dat[size() - 1]; }

    /**
     * @brief Returns a pointer to the underlying data.
     * 
     * @return Pointer to the underlying data.
     */
    value_type* data() noexcept { return dat; }

    /**
     * @brief Returns a constant pointer to the underlying data.
     * 
     * @return Constant pointer to the underlying data.
     */
    const value_type* data() const noexcept { return dat; }

    // Iterators
    /**
     * @brief Returns an iterator to the beginning.
     * 
     * @return Iterator to the beginning.
     */
    iterator begin() { return dat; }

    /**
     * @brief Returns a constant iterator to the beginning.
     * 
     * @return Constant iterator to the beginning.
     */
    const_iterator begin() const { return dat; }

    /**
     * @brief Returns an iterator to the end.
     * 
     * @return Iterator to the end.
     */
    iterator end() { return avail; }

    /**
     * @brief Returns a constant iterator to the end.
     * 
     * @return Constant iterator to the end.
     */
    const_iterator end() const { return avail; }

    // Capacity
    /**
     * @brief Returns the number of elements.
     * 
     * @return Number of elements.
     */
    size_type size() const { return avail - dat; }

    /**
     * @brief Returns the maximum possible number of elements.
     * 
     * @return Maximum number of elements.
     */
    size_type max_size() const { return std::numeric_limits<size_type>::max(); }

    /**
     * @brief Resizes the vector to contain `sz` elements.
     * 
     * @param sz New size of the vector.
     */
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

    /**
     * @brief Resizes the vector to contain `sz` elements, each initialized to `value`.
     * 
     * @param sz New size of the vector.
     * @param value Value to initialize elements with.
     */
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

    /**
     * @brief Returns the number of elements that can be held in currently allocated storage.
     * 
     * @return Capacity of the vector.
     */
    size_type capacity() const { return limit - dat; }

    /**
     * @brief Checks if the vector is empty.
     * 
     * @return `true` if the vector is empty, `false` otherwise.
     */
    bool empty() const noexcept { return size() == 0; }

    /**
     * @brief Requests that the vector capacity be at least enough to contain `n` elements.
     * 
     * @param n Minimum capacity requested.
     */
    void reserve(size_type n) {
        if (n > capacity()) {
            grow(n);
        }
    }

    /**
     * @brief Reduces capacity to fit the size.
     */
    void shrink_to_fit() {
        if (limit > avail) {
            limit = avail;
        }
    }

    // Modifiers
    /**
     * @brief Clears the contents.
     */
    void clear() noexcept {
        uncreate();
    }

    /**
     * @brief Inserts `val` before `position`.
     * 
     * @param position Position to insert before.
     * @param val Value to insert.
     * @return Iterator pointing to the inserted value.
     */
    iterator insert(const_iterator position, const value_type& val) {
        return insert(position, 1, val);
    }

    /**
     * @brief Inserts `n` elements of `val` before `position`.
     * 
     * @param position Position to insert before.
     * @param n Number of elements to insert.
     * @param val Value to insert.
     * @return Iterator pointing to the first inserted value.
     * @throws std::out_of_range If `position` is out of range.
     */
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

    /**
     * @brief Erases the element at `position`.
     * 
     * @param position Position of the element to erase.
     * @return Iterator pointing to the next element.
     * @throws std::out_of_range If `position` is out of range.
     */
    iterator erase(iterator position) {
        if (position < dat || position >= avail) {
            throw std::out_of_range("Index out of range");
        }
        std::move(position + 1, avail, position);
        alloc.destroy(--avail);

        return position;
    }

    /**
     * @brief Erases elements in the range [first, last).
     * 
     * @param first Start of the range.
     * @param last End of the range.
     * @return Iterator pointing to the next element.
     * @throws std::out_of_range If the range is invalid.
     */
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

    /**
     * @brief Appends `t` to the end.
     * 
     * @param t Value to append.
     */
    void push_back(const value_type& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }

    /**
     * @brief Appends `val` to the end.
     * 
     * @param val Value to append.
     */
    void push_back(value_type&& val) {
        if (avail == limit)
            grow();
        unchecked_append(std::move(val));
    }

    /**
     * @brief Removes the last element.
     */
    void pop_back() {
        if (avail != dat)
            alloc.destroy(--avail);
    }

    /**
     * @brief Swaps the contents with another Vector.
     * 
     * @param x Vector to swap with.
     */
    void swap(Vector& x) {
        std::swap(dat, x.dat);
        std::swap(avail, x.avail);
        std::swap(limit, x.limit);
    }

    // NON-MEMBER FUNCTIONS

    /**
     * @brief Checks if two Vectors are equal.
     * 
     * @param other Vector to compare.
     * @return `true` if the Vectors are equal, `false` otherwise.
     */
    bool operator==(const Vector<T>& other) const {
        if (size() != other.size()) {
            return false;
        }

        return std::equal(begin(), end(), other.begin());
    }

    /**
     * @brief Checks if two Vectors are not equal.
     * 
     * @param other Vector to compare.
     * @return `true` if the Vectors are not equal, `false` otherwise.
     */
    bool operator!=(const Vector<T>& other) const {
        return !(*this == other);
    }

    /**
     * @brief Checks if this Vector is less than another Vector.
     * 
     * @param other Vector to compare.
     * @return `true` if this Vector is less than the other Vector, `false` otherwise.
     */
    bool operator<(const Vector<T>& other) const {
        return std::lexicographical_compare(begin(), end(), other.begin(), other.end());
    }

    /**
     * @brief Checks if this Vector is less than or equal to another Vector.
     * 
     * @param other Vector to compare.
     * @return `true` if this Vector is less than or equal to the other Vector, `false` otherwise.
     */
    bool operator<=(const Vector<T>& other) const {
        return !(other < *this);
    }

    /**
     * @brief Checks if this Vector is greater than another Vector.
     * 
     * @param other Vector to compare.
     * @return `true` if this Vector is greater than the other Vector, `false` otherwise.
     */
    bool operator>(const Vector<T>& other) const {
        return std::lexicographical_compare(other.begin(), other.end(), begin(), end());
    }

    /**
     * @brief Checks if this Vector is greater than or equal to another Vector.
     * 
     * @param other Vector to compare.
     * @return `true` if this Vector is greater than or equal to the other Vector, `false` otherwise.
     */
    bool operator>=(const Vector<T>& other) const {
        return !(other > *this);
    }

private:
    iterator dat;    ///< Pointer to the beginning of the data.
    iterator avail;  ///< Pointer to the end of the available data.
    iterator limit;  ///< Pointer to the end of the allocated storage.
    std::allocator<T> alloc; ///< Allocator for the elements.

    /**
     * @brief Allocates and initializes storage to zero size.
     */
    void create() { dat = avail = limit = nullptr; }

    /**
     * @brief Allocates and initializes storage with `n` elements of value `val`.
     * 
     * @param n Number of elements.
     * @param val Value to initialize elements with.
     */
    void create(size_type n, const T& val) {
        dat = alloc.allocate(n);
        limit = avail = dat + n;
        std::uninitialized_fill(dat, limit, val);
    }

    /**
     * @brief Allocates and initializes storage with elements from range [i, j).
     * 
     * @param i Start of the range.
     * @param j End of the range.
     */
    void create(const_iterator i, const_iterator j) {
        dat = alloc.allocate(j - i);
        limit = avail = std::uninitialized_copy(i, j, dat);
    }

    /**
     * @brief Deallocates storage and destroys elements.
     */
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

    /**
     * @brief Grows the storage to accommodate `new_capacity` elements.
     * 
     * @param new_capacity New capacity of the storage.
     */
    void grow(size_type new_capacity = 0) {
        size_type new_size = std::max(new_capacity, 2 * capacity());
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(std::make_move_iterator(dat), std::make_move_iterator(avail), new_data);
        uncreate();
        dat = new_data;
        avail = new_avail;
        limit = dat + new_size;
    }

    /**
     * @brief Appends `val` without checking capacity.
     * 
     * @param val Value to append.
     */
    void unchecked_append(const T& val) {
        alloc.construct(avail++, val);
    }

    /**
     * @brief Appends `val` without checking capacity (move version).
     * 
     * @param val Value to append.
     */
    void unchecked_append(T&& val) {
        alloc.construct(avail++, std::move(val));
    }
};
