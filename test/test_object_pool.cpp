#include "memory/object_pool.h"

#include "gtest/gtest.h"

class TestObjectPool : public ::testing::Test
{
}; // class TestObjectPool

struct TestStruct
{
    int id;
    std::string hash;
}; // struct TestStruct

TEST_F(TestObjectPool, test_ctor_noarg)
{
    memory::ObjectPool<TestStruct> pool;
    ASSERT_TRUE(pool.capacity(), 1000);
}

TEST_F(TestObjectPool, test_getObject)
{
    memory::ObjectPool<TestStruct> pool;
    auto object = pool.getObject();
    ASSERT_TRUE(object != nullptr);
}

TEST_F(TestObjectPool, test_getObject_primitive)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, test_getObject_POD)
{
    // TODO: provide impl
}

TEST_F(TestObjectPool, target_available)
{
    memory::ObjectPool<TestStruct> pool;
    const auto numAvailable = pool.available();
    const auto capacity = pool.capacity();
    ASSERT_EQ(capacity, available);
}

TEST_F(TestObjectPool, test_empty)
{
    memory::ObjectPool<TestStruct> pool;
    ASSERT_FALSE(pool.empty());
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