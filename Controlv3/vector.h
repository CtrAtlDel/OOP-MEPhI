#ifndef CONTROLV3_VECTOR_H
#define CONTROLV3_VECTOR_H

#include <stdexcept>
#include <iostream>


namespace templates {
    template<typename T>
    class iterator {
    private:
        T *iteratorVector;
    public:
        iterator() : iteratorVector(nullptr) {};

        iterator(T *tmp) : iteratorVector(tmp) {};

        bool operator==(const iterator &tmp) const;

        bool operator!=(const iterator &tmp) const;

        //---------------LikeGetters---------------//
        T *operator->();

        T &operator*();

        iterator<T> &operator++();
    };

    template<typename T>
    bool iterator<T>::operator==(const iterator &tmp) const {
        if (iteratorVector != tmp.iteratorVector)
            return false;
        return true;
    }

    template<typename T>
    bool iterator<T>::operator!=(const iterator &tmp) const {
        if (iteratorVector == tmp.iteratorVector)
            return false;
        return true;
    }

    template<typename T>
    iterator<T> &iterator<T>::operator++() {
        iteratorVector++;
        return *this;
    }

    template<typename T>
    T *iterator<T>::operator->() {
        return iteratorVector;
    }

    template<typename T>
    T &iterator<T>::operator*() {
        return *iteratorVector;
    }

    template<typename T>
    class vector {
    private:
        int sizes;
        T *array;
    public:

        friend class iterator<T>;

        typedef iterator<T> iterator;

        vector();

        explicit vector(int size);

        vector(int size, T value);

        iterator begin() const;

        iterator end() const;

        [[nodiscard]]
        int size() const { return sizes; }

        [[nodiscard]]
        bool empty() const { return sizes <= 0; }

        T &front();

        T &back();

        void set(int index, T value) const;

        T get(int index) const;

        void push_back(T value);

        void erase(int index);

        void pop_back(T value);

        T &operator[](int index);

        T operator[](int index) const;

        ~vector() {
            delete[] array;
        };
    };

    template<typename T>
    vector<T>::vector(int size) {
        if (size < 0)
            throw std::invalid_argument("Index out of range");
        this->sizes = size;
        array = new T[size];
    }

    template<typename T>
    vector<T>::vector(int size, T value) {
        if (size < 0)
            throw std::invalid_argument("Index out of range");
        this->sizes = size;
        array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = value;
        }
    }

    template<typename T>
    T &vector<T>::operator[](int index) {
        if (index < 0 || index > sizes - 1)
            throw std::invalid_argument("Index out of range");
        iterator iterator(this->array);
        for (int i = 0; i < sizes; ++i) {
            if (i == index) { return *iterator; }
            ++iterator;
        }
    }


    template<typename T>
    void vector<T>::push_back(T value) {
        T *tmp = new T[sizes + 1];
        for (int i = 0; i < sizes; ++i) {
            tmp[i] = this->array[i];
        }
        tmp[sizes] = value;
        T *cnt = this->array;
        this->array = tmp;
        delete cnt;
        this->sizes++;

    }

    template<typename T>
    void vector<T>::erase(int index) { //delete element
        if (index < 0 || (index > sizes - 1))
            throw std::invalid_argument("Index out of range");
        if (this->sizes == 1) {
            T *tmp = this->array;
            this->array = nullptr;
            delete tmp;
            sizes--;
        } else {
            T *tmp = new T[sizes - 1];
            unsigned int j = 0;
            for (int i = 0; i < sizes; ++i) {
                if (i == index)
                    continue;
                tmp[j] = this->array[i];
                j++;
            }
        }
    }

    template<typename T>
    T &vector<T>::front() {
        return array;
    }

    template<typename T>
    T &vector<T>::back() {
        return array + sizes;
    }

    template<typename T>
    void vector<T>::pop_back(T value) {
        erase(this->size - 1);
    }

    template<typename T>
    vector<T>::vector() {
        sizes = 0;
        this->array = nullptr;
    }

    template<typename T>
    T vector<T>::get(int index) const {
        if (index < 0 || (index > sizes - 1)) {
            throw std::invalid_argument("Index out of range");
        }
        iterator it;
        int i;
        iterator testIt = this->end();
        for (it = this->begin(), i = 0; it != testIt; ++it, i++) {
            if (i == index) {
                return *it;
            }
        }

    }

    template<typename T>
    void vector<T>::set(int index, T value) const {
        if (index < 0 || (index > sizes - 1)) {
            throw std::invalid_argument("Index out of range");
        }
        this->array[index] = value;
    }

    template<typename T>
    iterator<T> vector<T>::begin() const {
        if (this->sizes == 0) {
            throw std::invalid_argument("Size == 0");
        }
        iterator it = this->array;
        return it;
    }

    template<typename T>
    iterator<T> vector<T>::end() const {
        return this->array + sizes;
    }

    template<typename T>
    T vector<T>::operator[](const int index) const {
        if (index < 0 || index > sizes - 1)
            throw std::invalid_argument("Index out of range");
        iterator iterator(this->array);
        for (int i = 0; i < sizes; ++i) {
            if (i == index) { return *iterator; }
            ++iterator;
        }

    }
}

#endif
