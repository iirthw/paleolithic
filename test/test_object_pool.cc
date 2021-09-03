#include "memory/object_pool.h"

#include "gtest/gtest.h"

class TestObjectPool : public ::testing::Test
{
}; // class TestObjectPool

struct TestStruct
{
    int id;
    float score;

    TestStruct(int id = 0, float score = 0.0f) : id(id), score(score) {}
}; // struct TestStruct

TEST_F(TestObjectPool, test_ctor_noarg)
{
    // FIXME: fix the test.
//    memory::ObjectPool<TestStruct> pool;
//    ASSERT_EQ(pool.capacity(), 1000);
}

TEST_F(TestObjectPool, test_dtor)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_getObject_int)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_getObject_float)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_getObject_char)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_getObject_pod)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, target_available)
{
    // FIXME: fix the test.
//    memory::ObjectPool<TestStruct> pool;
//    const auto available = pool.available();
//    const auto capacity = pool.capacity();
//    ASSERT_EQ(capacity, available);
}

TEST_F(TestObjectPool, test_empty)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_relaseObject)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_noDefaultConstructible)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_noAvailable)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_releaseNull)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_releaseForeignObject)
{
    // TODO: provide impl
}