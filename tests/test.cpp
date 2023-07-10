#include <lib/CCircularBuffer.h>
#include <gtest/gtest.h>

TEST(BufferTestSuite, CreateStaticBufferTest) {
    CCircularBuffer<int> buffer(15);
    ASSERT_TRUE(buffer.max_size() == 15);
}

TEST(BufferTestSuite, SizeStaticBufferTest) {
    CCircularBuffer<int> buffer = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(buffer.size() == 6);
    ASSERT_TRUE(buffer.max_size() == 6);
}

TEST(BufferTestSuite, EmptyStaticBufferTest) {
    CCircularBuffer<int> buffer(6);
    ASSERT_TRUE(buffer.size() == 0);
    ASSERT_TRUE(buffer.empty());
}

TEST(BufferTestSuite, SubstrictStaticBufferTest_1) {
    CCircularBuffer<int> int_buffer = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < int_buffer.size(); ++i) {
        ASSERT_TRUE(int_buffer[i] == i + 1);
    }
}

TEST(BufferTestSuite, PushInStaticBufferTest_1) {
    CCircularBuffer<int> int_buffer(15);
    for (int i = 0; i < 12; ++i) {
        int_buffer.push_back(i);
    }
    int i = 0;
    for (CCircularBuffer<int>::iterator it = int_buffer.begin(); it != int_buffer.end(); ++it, ++i) {
        ASSERT_TRUE(*it == i);
    }
    ASSERT_TRUE(int_buffer.size() == 12);
    ASSERT_TRUE(int_buffer.max_size() == 15);
    ASSERT_TRUE(int_buffer.empty() == false);
}

TEST(BufferTestSuite, PushBackInStaticBufferTest_2) {
    CCircularBuffer<int> int_buffer(4);
    for (int i = 0; i < 12; ++i) {
        int_buffer.push_back(i);
    }
    for (int i = 0; i < 4; ++i) {
        ASSERT_TRUE(int_buffer[i] == i + 8);
    }

    ASSERT_TRUE(int_buffer.size() == 4);
    ASSERT_TRUE(int_buffer.max_size() == 4);
    ASSERT_TRUE(int_buffer.empty() == false);
}

TEST(BufferTestSuite, PopFrontInStaticBufferTest_1) {
    CCircularBuffer<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    int_buffer_1.pop_front();
    int_buffer_1.pop_front();
    int_buffer_1.pop_front();

    ASSERT_TRUE(int_buffer_1.size() == 5);
    ASSERT_TRUE(int_buffer_1.max_size() == 8);
}

TEST(BufferTestSuite, SubstrictInStaticBufferTest_2) {
    CCircularBuffer<int> int_buffer = {1, 2, 3, 4, 5, 6, 7, 8};
    int_buffer.pop_front();
    int_buffer.pop_front();
    int_buffer.pop_front();
    int_buffer.push_back(9);
    int_buffer.push_back(10);
    int_buffer.push_back(11);

    for(int i = 0; i < int_buffer.size(); ++i) {
        ASSERT_TRUE(int_buffer[i] == i + 4);
    }
}

TEST(BufferTestSuite, SwapInStaticBufferTest_1) {
    CCircularBuffer<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBuffer<int> int_buffer_2 = {10, 11, 12};
    int_buffer_1.swap(int_buffer_2);

    for (int i = 0; i < int_buffer_1.size(); ++i) {
        ASSERT_TRUE(int_buffer_1[i] == i + 10);
    }

    for (int i = 0; i < int_buffer_2.size(); ++i) {
        ASSERT_TRUE(int_buffer_2[i] == i + 1);
    }
}

TEST(BufferTestSuite, SwapInStaticBufferTest_2) {
    CCircularBuffer<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBuffer<int> int_buffer_2 = {10, 11, 12};
    CCircularBuffer<int>::swap(int_buffer_1, int_buffer_2);

    for (int i = 0; i < int_buffer_1.size(); ++i) {
        ASSERT_TRUE(int_buffer_1[i] == i + 10);
    }

    for (int i = 0; i < int_buffer_2.size(); ++i) {
        ASSERT_TRUE(int_buffer_2[i] == i + 1);
    }
}

TEST(BufferTestSuite, AssignmentAndCopyInStaticBufferTest) {
    CCircularBuffer<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBuffer<int> int_buffer_2 = {10, 11, 12};
    CCircularBuffer<int> int_buffer_3 = CCircularBuffer<int>(int_buffer_2);
    int_buffer_2 = int_buffer_1;
    for (int i = 0; i < int_buffer_2.size(); ++i) {
        ASSERT_TRUE(int_buffer_2[i] == i + 1);
    }
    ASSERT_TRUE(int_buffer_2.size() == 8);
    ASSERT_TRUE(int_buffer_2.size() == 8);
    for (int i = 0; i < int_buffer_3.size(); ++i) {
        ASSERT_TRUE(int_buffer_3[i] == i + 10);
    }
    ASSERT_TRUE(int_buffer_3.size() == 3);
}

TEST(BufferTestSuite, EqualInStaticBuffer) {
    CCircularBuffer<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBuffer<int> int_buffer_2 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBuffer<int> int_buffer_3 = {13, 14, 15, 16};

    ASSERT_TRUE(int_buffer_1 == int_buffer_2);
    ASSERT_FALSE(int_buffer_1 == int_buffer_3);
}


TEST(BufferTestSuite, InEqualInStaticBuffer) {
    CCircularBuffer<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBuffer<int> int_buffer_2 = {1, 2, 3};

    ASSERT_TRUE(int_buffer_1 != int_buffer_2);
    int_buffer_2 = int_buffer_1;
    ASSERT_FALSE(int_buffer_1 != int_buffer_2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(BufferTestSuite, CreateExtBufferTest) {
    CCircularBufferExt<int> buffer(15);
    ASSERT_TRUE(buffer.max_size() == 15);
}

TEST(BufferTestSuite, SizeExtBufferTest) {
    CCircularBufferExt<int> buffer = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(buffer.size() == 6);
    ASSERT_TRUE(buffer.max_size() == 12);
}

TEST(BufferTestSuite, EmptyExtBufferTest) {
    CCircularBufferExt<int> buffer(6);
    ASSERT_TRUE(buffer.size() == 0);
    ASSERT_TRUE(buffer.empty());
}

TEST(BufferTestSuite, SubstrictExtBufferTest_1) {
    CCircularBufferExt<int> int_buffer = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < int_buffer.size(); ++i) {
        ASSERT_TRUE(int_buffer[i] == i + 1);
    }
}

TEST(BufferTestSuite, PushInExtBufferTest_1) {
    CCircularBufferExt<int> int_buffer(15);
    for (int i = 0; i < 12; ++i) {
        int_buffer.push_back(i);
    }
    int i = 0;
    for (CCircularBufferExt<int>::iterator it = int_buffer.begin(); it != int_buffer.end(); ++it, ++i) {
        ASSERT_TRUE(*it == i);
    }
    ASSERT_TRUE(int_buffer.size() == 12);
    ASSERT_TRUE(int_buffer.max_size() == 15);
    ASSERT_TRUE(int_buffer.empty() == false);
}

TEST(BufferTestSuite, PushBackInExtBufferTest_2) {
    CCircularBufferExt<int> int_buffer(4);
    for (int i = 0; i < 12; ++i) {
        int_buffer.push_back(i);
    }
    for (int i = 0; i < 12; ++i) {
        ASSERT_TRUE(int_buffer[i] == i);
    }

    ASSERT_TRUE(int_buffer.size() == 12);
    ASSERT_TRUE(int_buffer.max_size() == 19);
    ASSERT_TRUE(int_buffer.empty() == false);
}

TEST(BufferTestSuite, PopFrontInExtBufferTest_1) {
    CCircularBufferExt<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    int_buffer_1.pop_front();
    int_buffer_1.pop_front();
    int_buffer_1.pop_front();

    ASSERT_TRUE(int_buffer_1.size() == 5);
    ASSERT_TRUE(int_buffer_1.max_size() == 16);
}

TEST(BufferTestSuite, SubstrictInExtBufferTest_2) {
    CCircularBufferExt<int> int_buffer = {1, 2, 3, 4, 5, 6, 7, 8};
    int_buffer.pop_front();
    int_buffer.pop_front();
    int_buffer.pop_front();
    int_buffer.push_back(9);
    int_buffer.push_back(10);
    int_buffer.push_back(11);

    for(int i = 0; i < int_buffer.size(); ++i) {
        ASSERT_TRUE(int_buffer[i] == i + 4);
    }
}

TEST(BufferTestSuite, SwapInExtBufferTest_1) {
    CCircularBufferExt<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBufferExt<int> int_buffer_2 = {10, 11, 12};
    int_buffer_1.swap(int_buffer_2);

    for (int i = 0; i < int_buffer_1.size(); ++i) {
        ASSERT_TRUE(int_buffer_1[i] == i + 10);
    }

    for (int i = 0; i < int_buffer_2.size(); ++i) {
        ASSERT_TRUE(int_buffer_2[i] == i + 1);
    }
}

TEST(BufferTestSuite, SwapInExtBufferTest_2) {
    CCircularBufferExt<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBufferExt<int> int_buffer_2 = {10, 11, 12};
    CCircularBufferExt<int>::swap(int_buffer_1, int_buffer_2);

    for (int i = 0; i < int_buffer_1.size(); ++i) {
        ASSERT_TRUE(int_buffer_1[i] == i + 10);
    }

    for (int i = 0; i < int_buffer_2.size(); ++i) {
        ASSERT_TRUE(int_buffer_2[i] == i + 1);
    }
}

TEST(BufferTestSuite, AssignmentAndCopyInExtBufferTest) {
    CCircularBufferExt<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBufferExt<int> int_buffer_2 = {10, 11, 12};
    CCircularBufferExt<int> int_buffer_3 = CCircularBufferExt<int>(int_buffer_2);
    int_buffer_2 = int_buffer_1;
    for (int i = 0; i < int_buffer_2.size(); ++i) {
        ASSERT_TRUE(int_buffer_2[i] == i + 1);
    }
    ASSERT_TRUE(int_buffer_2.size() == 8);
    ASSERT_TRUE(int_buffer_2.size() == 8);
    for (int i = 0; i < int_buffer_3.size(); ++i) {
        ASSERT_TRUE(int_buffer_3[i] == i + 10);
    }
    ASSERT_TRUE(int_buffer_3.size() == 3);
}

TEST(BufferTestSuite, EqualInExtBuffer) {
    CCircularBufferExt<int> int_buffer_1 = {8, 9, 10, 11, 12, 13, 14, 15};
    CCircularBufferExt<int> int_buffer_2 = {8, 9, 10, 11, 12, 13, 14, 15};
    CCircularBufferExt<int> int_buffer_3 = {13, 14, 15, 16};
    CCircularBufferExt<int> int_buffer_4(4, 5);
    CCircularBufferExt<int> int_buffer_5(4, 5);

    ASSERT_TRUE(int_buffer_1 == int_buffer_2);
    ASSERT_FALSE(int_buffer_1 == int_buffer_3);
    ASSERT_TRUE(int_buffer_4 == int_buffer_5);
}

TEST(BufferTestSuite, InEqualInExtBuffer) {
    CCircularBufferExt<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    CCircularBufferExt<int> int_buffer_2 = {1, 2, 3};

    ASSERT_TRUE(int_buffer_1 != int_buffer_2);
    int_buffer_2 = int_buffer_1;
    ASSERT_FALSE(int_buffer_1 != int_buffer_2);
}

TEST(BufferTestSuite, InsertInExtBuffer_1) {
    CCircularBufferExt<int> int_buffer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CCircularBufferExt<int>::iterator iter = int_buffer.insert(4, 5);
    CCircularBufferExt<int> other = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    ASSERT_TRUE(int_buffer == other);
    ASSERT_TRUE(*iter == 5);
}

TEST(BufferTestSuite, InsertInExtBuffer_2) {
    CCircularBufferExt<int> int_buffer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CCircularBufferExt<int>::iterator iter = int_buffer.insert(4, 5, 6);
    CCircularBufferExt<int> other = {1, 2, 3, 4, 6, 6, 6, 6, 6, 5, 6, 7, 8, 9, 10};
    ASSERT_TRUE(int_buffer == other);
    ASSERT_TRUE(*iter == 6);
}

TEST(BufferTestSuite, InsertInExtBuffer_3) {
    CCircularBufferExt<int> int_buffer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CCircularBufferExt<int>::iterator iter = int_buffer.insert(4, {1337, 228, 69, 420});
    CCircularBufferExt<int> other = {1, 2, 3, 4, 1337, 228, 69, 420, 5, 6, 7, 8, 9, 10};
    ASSERT_TRUE(int_buffer == other);
    ASSERT_TRUE(*iter == 1337);
}

TEST(BufferTestSuite, AssignExtBuffer_1) {
    CCircularBufferExt<int> int_buffer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int_buffer.assign(150, 5);
    CCircularBufferExt<int> other = {150, 150, 150, 150, 150};
    ASSERT_TRUE(int_buffer == other);
}

TEST(BufferTestSuite, AssignExtBuffer_2) {
    CCircularBufferExt<int> int_buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CCircularBufferExt<int> int_buffer_2(int_buffer_1);
    CCircularBufferExt<int>::iterator iter1 = int_buffer_1.begin()[2];
    CCircularBufferExt<int>::iterator iter2 = int_buffer_1.begin()[6];
    int_buffer_2.assign(iter1, iter2);
    CCircularBufferExt<int> other = {3, 4, 5, 6};
    ASSERT_TRUE(int_buffer_2 == other);
}

TEST(BufferTestSuite, AssignExtBuffer_3) {
    CCircularBufferExt<int> int_buffer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int_buffer.assign({228, 1337, 69, 420});
    CCircularBufferExt<int> other = {228, 1337, 69, 420};
    ASSERT_TRUE(int_buffer == other);
}

TEST(BufferTestSuite, ClearExtBuffer) {
    CCircularBufferExt<int> int_buffer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int_buffer.clear();
    ASSERT_TRUE(int_buffer.empty());
}
