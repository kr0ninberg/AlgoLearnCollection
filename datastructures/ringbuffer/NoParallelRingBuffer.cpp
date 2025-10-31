#include "NoParallelRingBuffer.hpp"

template <typename T>
T &NoParallelRingBuffer<T>::front() {
    // TODO: Implement front() method
}

template <typename T>
const T &NoParallelRingBuffer<T>::front() const {
    // TODO: Implement const front() method
}

template <typename T>
T &NoParallelRingBuffer<T>::back() {
    // TODO: Implement back() method
}

template <typename T>
const T &NoParallelRingBuffer<T>::back() const {
    // TODO: Implement const back() method
}

template <typename T>
void NoParallelRingBuffer<T>::pop_front() {
    // TODO: Implement pop_front() method
}

template <typename T>
bool NoParallelRingBuffer<T>::push_back(const T &value) {
    // TODO: Implement push_back() method for const reference
    return false;
}

template <typename T>
bool NoParallelRingBuffer<T>::push_back(T &&value) {
    // TODO: Implement push_back() method for rvalue reference
    return false;
}

template <typename T>
bool NoParallelRingBuffer<T>::empty() const noexcept {
    // TODO: Implement empty() method
    return true;
}

template <typename T>
bool NoParallelRingBuffer<T>::full() const noexcept {
    // TODO: Implement full() method
    return false;
}

template <typename T>
std::size_t NoParallelRingBuffer<T>::size() const noexcept {
    // TODO: Implement size() method
    return 0;
}