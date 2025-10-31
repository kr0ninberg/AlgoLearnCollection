#include <gtest/gtest.h>
#include "datastructures/ringbuffer/NoParallelRingBuffer.hpp"

TEST(Ringbuffer, Basic) {
    NoParallelRingBuffer<int> q(10);

    for (int i = 1 ; i <= 3 ; ++i)
        EXPECT_TRUE(q.push_back(i));
    
    for (int i = 1 ; i <= 3 ; ++i)
    {
        EXPECT_EQ(q.front(), i);
        q.pop_front();
    }
}

TEST(Ringbuffer, SimpleFull) {
    NoParallelRingBuffer<int> q(3);

    for (int i = 1 ; i <= 3 ; ++i)
        EXPECT_TRUE(q.push_back(i));
    
    for (int i = 1 ; i <= 3 ; ++i)
    {
        EXPECT_EQ(q.front(), i);
        q.pop_front();
    }
}

TEST(Ringbuffer, SimpleOverflow) {
    NoParallelRingBuffer<int> q(3);

    for (int i = 1 ; i <= 3 ; ++i)
        EXPECT_TRUE(q.push_back(i));
    
    EXPECT_FALSE(q.push_back(4));
    EXPECT_FALSE(q.push_back(5));

    for (int i = 1 ; i <= 3 ; ++i)
    {
        EXPECT_EQ(q.front(), i);
        q.pop_front();
    }
}

TEST(Ringbuffer, Full) {
    NoParallelRingBuffer<int> q(4);

    for (int i = 1 ; i <= 4 ; ++i)
        EXPECT_TRUE(q.push_back(i));

    for (int i = 1 ; i <= 2 ; ++i)
    {
        EXPECT_EQ(q.front(), i);
        q.pop_front();
    }

    for (int i = 1 ; i <= 2 ; ++i)
        EXPECT_TRUE(q.push_back(i));

    for (int i = 3 ; i <= 4 ; ++i)
    {
        EXPECT_EQ(q.front(), i);
        q.pop_front();
    }
    for (int i = 1 ; i <= 2 ; ++i)
    {
        EXPECT_EQ(q.front(), i);
        q.pop_front();
    }
}