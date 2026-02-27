#include <cstddef>

// ringbuffer types gonna be
// NO_MULTITHREADING
// LOCKFULL
// LOCKLESS_NO_ALIGN // false sharing case
// LOCKLESS_SIMPLE_ALIGN 
// LOCKLESS_COMPLEX_ALIGN

template <typename T> class IRingBuffer {
public:
    virtual ~IRingBuffer() = default;

    // Element access
    virtual T &front() = 0;
    virtual const T &front() const = 0;
    virtual T &back() = 0;
    virtual const T &back() const = 0;

    // Modifiers
    virtual void pop_front() = 0;
    virtual bool push_back(const T &value) = 0;
    virtual bool push_back(T &&value) = 0;

    // Capacity
    virtual bool empty() const noexcept = 0;
    virtual bool full() const noexcept = 0;
    virtual std::size_t size() const noexcept = 0;
};
