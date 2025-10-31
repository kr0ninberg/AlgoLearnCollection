#include "IRingBuffer.hpp"
#include <cstddef>
#include <vector>

template <typename T>
class NoParallelRingBuffer : public IRingBuffer<T> {
public:
    virtual ~NoParallelRingBuffer() = default;
    NoParallelRingBuffer(std::size_t size) : _buffer(size), _size(size) {}

    // Element access
    virtual T &front() override;
    virtual const T &front() const override;
    virtual T &back() override;
    virtual const T &back() const override;

    // Modifiers
    virtual void pop_front() override;
    virtual bool push_back(const T &value) override;
    virtual bool push_back(T &&value) override;

    // Capacity
    virtual bool empty() const noexcept override;
    virtual bool full() const noexcept override;
    virtual std::size_t size() const noexcept override;

private:
    std::size_t _r = 0;
    std::size_t _w = 0;
    std::size_t _size;
    std::vector<T> _buffer;
    bool isFull = false;
};

// Template method implementations
template <typename T>
T &NoParallelRingBuffer<T>::front() {
    return _buffer[_r];
}

template <typename T>
const T &NoParallelRingBuffer<T>::front() const {
    return _buffer[_r];
}

template <typename T>
T &NoParallelRingBuffer<T>::back() {
    return _buffer[(_w + _size - 1) % _size];
}

template <typename T>
const T &NoParallelRingBuffer<T>::back() const {
    return _buffer[(_w + _size - 1) % _size];
}

template <typename T>
void NoParallelRingBuffer<T>::pop_front() {
    if (empty()) return;
    if (isFull) isFull = false;
    _r = (_r + 1) % _size;
}

template <typename T>
bool NoParallelRingBuffer<T>::push_back(const T &value) {
    if (full())
        return false;
    _buffer[_w] = value;
    _w = (_w + 1) % _size;
    if (_r == _w) isFull = true;
    return true;
}

template <typename T>
bool NoParallelRingBuffer<T>::push_back(T &&value) {
    if (full())
        return false;
    _buffer[_w] = std::move(value);
    _w = (_w + 1) % _size;
    if (_r == _w) isFull = true;
    return true;
}

template <typename T>
bool NoParallelRingBuffer<T>::empty() const noexcept {
    return _r == _w && !isFull;
}

template <typename T>
bool NoParallelRingBuffer<T>::full() const noexcept {
    return isFull;
}

template <typename T>
std::size_t NoParallelRingBuffer<T>::size() const noexcept {
    return _size;
}