#include "IRingBuffer.hpp"
#include <cstddef>
#include <vector>

template <typename T> class NoParallelRingBuffer : public IRingBuffer<T> {
public:
    virtual ~NoParallelRingBuffer() = default;
    NoParallelRingBuffer(std::size_t size) : _size(size), 
                                             _buffer(size)
    {}

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
    std::size_t _r = 0 ,
                _w = 0 ,
                _size = 0,
                _length = 0; 
    std::vector<T> _buffer;
};