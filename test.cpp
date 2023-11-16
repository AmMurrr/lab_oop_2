#include <gtest/gtest.h>
#include "Five.hpp"

TEST(FiveInit,default_construct) {
    Five five;

    size_t size = five.get_size();
    size_t exp_size = 0;
    unsigned char* value = five.get_value();
    unsigned char* exp_value = nullptr;

    ASSERT_EQ(size, exp_size);
    ASSERT_EQ(value, exp_value);
}

TEST(FiveInit,fill_construct) {
    Five five(4, '3');

    size_t size = five.get_size();
    size_t exp_size = 4;
    unsigned char* value = five.get_value();
    unsigned char exp_value[] = {'3','3','3','3'};

    ASSERT_EQ(size, exp_size);
    for(size_t i = 0; i < size; i++)
        ASSERT_EQ(value[i],exp_value[i]);
}

TEST(FiveInit,initlist_construct) {
    Five five{'2','0','0','1'};

    size_t size = five.get_size();
    size_t exp_size = 4;
    unsigned char* value = five.get_value();
    unsigned char exp_value[] = {'2','0','0','1'};

    ASSERT_EQ(size, exp_size);
    for(size_t i = 0; i < size; i++)
        ASSERT_EQ(value[i],exp_value[i]);
}

TEST(FiveInit,string_construct) {
    Five five("1234");

    size_t size = five.get_size();
    size_t exp_size = 4;
    unsigned char* value = five.get_value();
    unsigned char exp_value[] = {'1','2','3','4'};

    ASSERT_EQ(size, exp_size);
    for(size_t i = 0; i < size; i++)
        ASSERT_EQ(value[i],exp_value[i]);
}

TEST(FiveInit,error_fill_construct) {
    EXPECT_ANY_THROW(Five five(3,'5'));
}

TEST(FiveInit,error_list_construct) {
    EXPECT_ANY_THROW(Five five({'1','5'}));
}

TEST(FiveInit,error_string_construct) {
    EXPECT_ANY_THROW(Five five("425aa78"));
}

TEST(FiveCopy,copy_construct) {
    Five five("2311");
    Five new_five(five);

    size_t size = new_five.get_size();
    size_t exp_size = 4;
    unsigned char* value = new_five.get_value();
    unsigned char exp_value[] = {'2','3','1','1'};

    ASSERT_EQ(size, exp_size);
    for(size_t i = 0; i < size; i++)
        ASSERT_EQ(value[i],exp_value[i]);
}

TEST(Operators,Add_op) {
    Five five1("104");
    Five five2("4");

    Five res = five1 + five2;
    size_t size = res.get_size();
    size_t exp_size = 3;
    unsigned char* value = res.get_value();
    unsigned char exp_value[] = {'0','1','4'};

    ASSERT_EQ(size, exp_size);
    for(size_t i = 0; i < size; i++)
        ASSERT_EQ(value[i],exp_value[i]);
}

TEST(Operators,diff_op) {
    Five five1("104");
    Five five2("4");

    Five res = five1 - five2;
    size_t size = res.get_size();
    size_t exp_size = 3;
    unsigned char* value = res.get_value();
    unsigned char exp_value[] = {'2','4','3'};

    ASSERT_EQ(size, exp_size);
    for(size_t i = 0; i < size; i++)
        ASSERT_EQ(value[i],exp_value[i]);
}

TEST(Operators,diff_op_resize) {
    Five five1("10000001");
    Five five2("2");

    Five res = five1 - five2;
    size_t size = res.get_size();
    size_t exp_size = 7;
    unsigned char* value = res.get_value();
    unsigned char exp_value[] = {'4','4','4','4','4','4','4'};

    ASSERT_EQ(size, exp_size);
    for(size_t i = 0; i < size; i++)
        ASSERT_EQ(value[i],exp_value[i]);
}

TEST(Operators, error_diff) {
    Five five2("10000001");
    Five five1("2");
    EXPECT_ANY_THROW(five1 - five2);
}

TEST(Operators,assign){
    Five five("4321");
    Five new_five;
    new_five = five;

    size_t size = new_five.get_size();
    size_t exp_size = 4;
    unsigned char* value = new_five.get_value();
    unsigned char exp_value[] = {'4','3','2','1'};

    ASSERT_EQ(size, exp_size);
    for(size_t i = 0; i < size; i++)
        ASSERT_EQ(value[i],exp_value[i]);
}

TEST(Bool_operators,bigger) {
    Five five_stand("1234");
    Five five_less("0234");
    Five five_bigger("2234");
    Five five_equal("1234");

    ASSERT_TRUE(five_stand > five_less);
    ASSERT_FALSE(five_stand > five_bigger);
    ASSERT_FALSE(five_stand > five_equal);
}

TEST(Bool_operators,less) {
    Five five_stand("1234");
    Five five_less("0234");
    Five five_bigger("2234");
    Five five_equal("1234");

    ASSERT_TRUE(five_stand < five_bigger);
    ASSERT_FALSE(five_stand < five_less);
    ASSERT_FALSE(five_stand < five_equal);
}

TEST(Bool_operators,bigger_equal) {
    Five five_stand("1234");
    Five five_less("0234");
    Five five_bigger("2234");
    Five five_equal("1234");

    ASSERT_TRUE(five_stand >= five_less);
    ASSERT_FALSE(five_stand >= five_bigger);
    ASSERT_TRUE(five_stand >= five_equal);
}

TEST(Bool_operators,less_equal) {
    Five five_stand("1234");
    Five five_less("0234");
    Five five_bigger("2234");
    Five five_equal("1234");

    ASSERT_TRUE(five_stand <= five_bigger);
    ASSERT_FALSE(five_stand <= five_less);
    ASSERT_TRUE(five_stand <= five_equal);
}

TEST(Bool_operators,equal) {
    Five five_stand("1234");
    Five five_less("0234");
    Five five_bigger("2234");
    Five five_equal("1234");

    ASSERT_FALSE(five_stand == five_less);
    ASSERT_FALSE(five_stand == five_bigger);
    ASSERT_TRUE(five_stand == five_equal);
}

TEST(Bool_operators,not_equal) {
    Five five_stand("1234");
    Five five_less("0234");
    Five five_bigger("2234");
    Five five_equal("1234");

    ASSERT_TRUE(five_stand != five_less);
    ASSERT_TRUE(five_stand != five_bigger);
    ASSERT_FALSE(five_stand != five_equal);
}