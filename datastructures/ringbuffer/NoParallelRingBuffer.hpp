#include "IRingBuffer.hpp"

template <typename T> class NoParallelRingBuffer : public IRingBuffer<T> {
public:
  virtual ~NoParallelRingBuffer() = default;

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
};