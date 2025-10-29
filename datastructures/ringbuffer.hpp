enum class RINGBUFFER_TYPE{
    NO_MULTITHREADING,
    LOCKFULL,
    LOCKLESS_NO_ALIGN, // false sharing case
    LOCKLESS_SIMPLE_ALIGN
    LOCKLESS_COMPLEX_ALIGN
}

// temporary interface (possibly should use CRTP?)
struct IRingBuffer{
    std::pair<bool, T> get() = 0;
    bool push(const T&) = 0;
    bool push(T&&) = 0;
    bool isEmpty() = 0;
}

template <typename T, RINGBUFFER_TYPE RbType=NO_MULTITHREADING>
struct RingBuffer{    
    std::pair<bool, T> get();
    bool push(const T&);
    bool push(T&&);
}