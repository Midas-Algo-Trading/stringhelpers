#include "gtest/gtest.h"
#include "stringhelpers/stringhelpers.h"

TEST(capitalize, basic)
{
    std::string string = "test";
    string = strh::capitalize(string);
    ASSERT_EQ(string, "Test");
}

TEST(capitalize, empty_string)
{
    std::string string;
    string = strh::capitalize(string);
    ASSERT_EQ(string, "");
}

TEST(align, target_len)
{
    std::string string = "test";
    string = strh::align(string, strh::Alignment::LEFT, 7, '*');
    ASSERT_EQ(string, "***test");
    string = strh::align(string, strh::Alignment::LEFT, 8, '*');
    ASSERT_EQ(string, "****test");
}

TEST(align, fill)
{
    std::string string = "test";
    string = strh::align(string, strh::Alignment::LEFT, 7, '*');
    ASSERT_EQ(string[0], '*');
}

TEST(align, align_left)
{
    std::string string = "test";
    string = strh::align(string, strh::Alignment::LEFT, 7, '*');
    ASSERT_EQ(string, "***test");
}

TEST(align, align_right)
{
    std::string string = "test";
    string = strh::align(string, strh::Alignment::RIGHT, 7, '*');
    ASSERT_EQ(string, "test***");
}

TEST(align, align_center_even)
{
    std::string string = "test";
    string = strh::align(string, strh::Alignment::CENTER, 8, '*');
    ASSERT_EQ(string, "**test**");
}

TEST(align, align_center_odd)
{
    std::string string = "test";
    string = strh::align(string, strh::Alignment::CENTER, 9, '*');
    ASSERT_EQ(string, "**test**");
}

TEST(align, empty_string)
{
    std::string string;
    string = strh::align(string, strh::Alignment::CENTER, 5, '*');
    ASSERT_EQ(string, "****");
}

TEST(align, empty_fill_throws_invalid_argument)
{
    std::string string = "test";
    ASSERT_THROW(strh::align(string, strh::Alignment::CENTER, 6, ""), std::invalid_argument);
}

TEST(multiply, basic)
{
    std::string string = "test ";
    string = strh::multiply(string, 3);
    ASSERT_EQ(string, "test test test ");
}

TEST(multiply, zero)
{
    std::string string = "test";
    string = strh::multiply(string, 0);
    ASSERT_EQ(string, "");
}

TEST(multiply, empty_string)
{
    std::string string;
    string = strh::multiply(string, 3);
    ASSERT_EQ(string, "");
}


TEST(count, character)
{
    std::string string = "test";
    size_t t_count = strh::count(string, 't');
    ASSERT_EQ(t_count, 2);
}

TEST(count, string)
{
    std::string string = "test";
    size_t st_count = strh::count(string, "st");
    ASSERT_EQ(st_count, 1);
}

TEST(count, not_in)
{
    std::string string = "test";
    size_t x_count = strh::count(string, 'x');
    ASSERT_EQ(x_count, 0);
}

TEST(count, all)
{
    std::string string = "www";
    size_t w_count = strh::count(string, 'w');
    ASSERT_EQ(w_count, 3);
}

TEST(count, empty_string)
{
    std::string string;
    size_t count = strh::count(string, 'x');
    ASSERT_EQ(count, 0);
}

TEST(count, empty_key_throws_invalid_argument)
{
    std::string string;
    ASSERT_THROW(strh::count(string, ""), std::invalid_argument);
}

TEST(ends_with, character)
{
    std::string string = "test";
    bool ends_with_t = strh::ends_with(string, 't');
    ASSERT_TRUE(ends_with_t);
}

TEST(ends_with, string)
{
    std::string string = "test";
    bool ends_with_est = strh::ends_with(string, "est");
    ASSERT_TRUE(ends_with_est);
}

TEST(ends_with, not_in)
{
    std::string string = "test";
    bool ends_with_x = strh::ends_with(string, 'x');
    ASSERT_FALSE(ends_with_x);
}

TEST(ends_with, all)
{
    std::string string = "test";
    bool ends_with_test = strh::ends_with(string, "test");
    ASSERT_TRUE(ends_with_test);
}

TEST(ends_with, empty_string)
{
    std::string string;
    ASSERT_THROW(strh::ends_with(string, 'x'), std::invalid_argument);
}

TEST(ends_with, empty_key)
{
    std::string string = "test";
    bool ends_with_empty = strh::ends_with(string, "");
    ASSERT_TRUE(ends_with_empty);
}

TEST(is_in, character)
{
    std::string string = "test";
    bool t_is_in = strh::is_in(string, 't');
    ASSERT_TRUE(t_is_in);
}

TEST(is_in, string)
{
    std::string string = "test";
    bool st_is_in = strh::is_in(string, "st");
    ASSERT_TRUE(st_is_in);
}

TEST(is_in, all)
{
    std::string string = "test";
    bool test_is_in = strh::is_in(string, "test");
    ASSERT_TRUE(test_is_in);
}

TEST(is_in, not_in)
{
    std::string string = "test";
    bool x_is_in = strh::is_in(string, 'x');
    ASSERT_FALSE(x_is_in);
}

TEST(is_in, empty_string)
{
    std::string string;
    bool x_is_in = strh::is_in(string, 'x');
    ASSERT_FALSE(x_is_in);
}

TEST(is_in, empty_key_throws_invalid_argument)
{
    std::string string = "test";
    ASSERT_THROW(strh::is_in(string, ""), std::invalid_argument);
}

TEST(all_nums, no_nums)
{
    std::string string = "test";
    bool all_nums = strh::all_nums(string);
    ASSERT_FALSE(all_nums);
}

TEST(all_nums, some_nums)
{
    std::string string = "test123";
    bool all_nums = strh::all_nums(string);
    ASSERT_FALSE(all_nums);
}

TEST(all_nums, all_nums)
{
    std::string string = "123";
    bool all_nums = strh::all_nums(string);
    ASSERT_TRUE(all_nums);
}

TEST(all_nums, empty_string_throws_invalid_arguments)
{
    std::string string;
    ASSERT_THROW(strh::all_nums(string), std::invalid_argument);
}

TEST(all_alphabetical, no_alphabetical)
{
    std::string string = "123";
    bool all_alphabetical = strh::all_alphabetical(string);
    ASSERT_FALSE(all_alphabetical);
}

TEST(all_alphabetical, some_alphabetical)
{
    std::string string = "test123";
    bool all_alphabetical = strh::all_alphabetical(string);
    ASSERT_FALSE(all_alphabetical);
}

TEST(all_alphabetical, all_alphabetical)
{
    std::string string = "test";
    bool all_alphabetical = strh::all_alphabetical(string);
    ASSERT_TRUE(all_alphabetical);
}

TEST(all_alphabetical, empty_string_throws_invalid_arguments)
{
    std::string string;
    ASSERT_THROW(strh::all_alphabetical(string), std::invalid_argument);
}

TEST(all_lowercase, no_lowercase)
{
    std::string string = "TEST";
    bool all_lowercase = strh::all_lowercase(string);
    ASSERT_FALSE(all_lowercase);
}

TEST(all_lowercase, some_lowercase)
{
    std::string string = "teST";
    bool all_lowercase = strh::all_lowercase(string);
    ASSERT_FALSE(all_lowercase);
}

TEST(all_lowercase, all_lowercase)
{
    std::string string = "test";
    bool all_lowercase = strh::all_lowercase(string);
    ASSERT_TRUE(all_lowercase);
}

TEST(all_lowercase, empty_string_throws_invalid_arguments)
{
    std::string string;
    ASSERT_THROW(strh::all_lowercase(string), std::invalid_argument);
}

TEST(all_uppercase, no_uppercase)
{
    std::string string = "test";
    bool all_uppercase = strh::all_uppercase(string);
    ASSERT_FALSE(all_uppercase);
}

TEST(all_uppercase, some_uppercase)
{
    std::string string = "teST";
    bool all_uppercase = strh::all_uppercase(string);
    ASSERT_FALSE(all_uppercase);
}

TEST(all_uppercase, all_uppercase)
{
    std::string string = "TEST";
    bool all_uppercase = strh::all_uppercase(string);
    ASSERT_TRUE(all_uppercase);
}

TEST(all_uppercase, empty_string_throws_invalid_arguments)
{
    std::string string;
    ASSERT_THROW(strh::all_uppercase(string), std::invalid_argument);
}

TEST(all_spaces, no_spaces)
{
    std::string string = "test";
    bool all_spaces = strh::all_spaces(string);
    ASSERT_FALSE(all_spaces);
}

TEST(all_spaces, some_spaces)
{
    std::string string = " test ";
    bool all_spaces = strh::all_spaces(string);
    ASSERT_FALSE(all_spaces);
}

TEST(all_spaces, all_spaces)
{
    std::string string = "   ";
    bool all_spaces = strh::all_spaces(string);
    ASSERT_TRUE(all_spaces);
}

TEST(all_spaces, empty_string_throws_invalid_arguments)
{
    std::string string;
    ASSERT_THROW(strh::all_spaces(string), std::invalid_argument);
}

TEST(split, character)
{
    std::string string = "test.test";
    std::vector<std::string> splits = strh::split(string, '.');
    std::vector<std::string> expected = {"test", "test"};
    ASSERT_EQ(splits, expected);
}

TEST(split, string)
{
    std::string string = "test";
    std::vector<std::string> splits = strh::split(string, "es");
    std::vector<std::string> expected = {"t", "t"};
    ASSERT_EQ(splits, expected);
}

TEST(split, no_delimiters)
{
    std::string string = "test";
    std::vector<std::string> splits = strh::split(string, '.');
    std::vector<std::string> expected = {"test"};
    ASSERT_EQ(splits, expected);
}

TEST(split, some_delimiters)
{
    std::string string = "test.test";
    std::vector<std::string> splits = strh::split(string, '.');
    std::vector<std::string> expected = {"test", "test"};
    ASSERT_EQ(splits, expected);
}

TEST(split, all_delimiters)
{
    std::string string = "...";
    std::vector<std::string> splits = strh::split(string, '.');
    std::vector<std::string> expected = {"", "", ""};
    ASSERT_EQ(splits, expected);
}

TEST(split, char_equals_string)
{
    std::string string = "...";
    std::vector<std::string> char_splits = strh::split(string, '.');
    std::vector<std::string> string_splits = strh::split(string, ".");
    ASSERT_EQ(char_splits, string_splits);
}

TEST(split, empty_string)
{
    std::string string;
    std::vector<std::string> splits = strh::split(string, '.');
    std::vector<std::string> expected = {};
    ASSERT_EQ(splits, expected);
}

TEST(split, empty_delimiter_throws_invalid_argument)
{
    std::string string = "test";
    ASSERT_THROW(strh::split(string, ""), std::invalid_argument);
}

TEST(split_lines, no_new_lines)
{
    std::string string = "test";
    std::vector<std::string> splits = strh::split_lines(string);
    std::vector<std::string> expected = {"test"};
    ASSERT_EQ(splits, expected);
}

TEST(split_lines, some_new_lines)
{
    std::string string = "test\ntest";
    std::vector<std::string> splits = strh::split_lines(string);
    std::vector<std::string> expected = {"test", "test"};
    ASSERT_EQ(splits, expected);
}

TEST(split_lines, all_new_lines)
{
    std::string string = "\n\n\n";
    std::vector<std::string> splits = strh::split_lines(string);
    std::vector<std::string> expected = {"", "", ""};
    ASSERT_EQ(splits, expected);
}

TEST(split_lines, empty_string)
{
    std::string string;
    std::vector<std::string> splits = strh::split_lines(string);
    std::vector<std::string> expected = {};
    ASSERT_EQ(splits, expected);
}

TEST(strip, nothing_to_strip)
{
    std::string string = "test";
    string = strh::strip(string);
    ASSERT_EQ(string, "test");
}

TEST(strip, something_to_strip)
{
    std::string string = " \ntest\n ";
    string = strh::strip(string);
    ASSERT_EQ(string, "test");
}

TEST(strip, all_to_strip)
{
    std::string string = "\n";
    string = strh::strip(string);
    ASSERT_EQ(string, "");
}

TEST(strip, left)
{
    std::string string = " \ntest";
    string = strh::strip(string);
    ASSERT_EQ(string, "test");
}

TEST(strip, right)
{
    std::string string = "test\n ";
    string = strh::strip(string);
    ASSERT_EQ(string, "test");
}

TEST(strip, space)
{
    std::string string = " test";
    string = strh::strip(string);
    ASSERT_EQ(string, "test");
}

TEST(strip, new_line)
{
    std::string string = "\ntest";
    string = strh::strip(string);
    ASSERT_EQ(string, "test");
}

TEST(strip, tab)
{
    std::string string = "\ttest";
    string = strh::strip(string);
    ASSERT_EQ(string, "test");
}

TEST(strip, empty_string)
{
    std::string string;
    string = strh::strip(string);
    ASSERT_EQ(string, "");
}

TEST(swap_cases, all_lowercase)
{
    std::string string = "test";
    string = strh::swap_cases(string);
    ASSERT_EQ(string, "TEST");
}

TEST(swap_cases, mix_case)
{
    std::string string = "TeSt";
    string = strh::swap_cases(string);
    ASSERT_EQ(string, "tEsT");
}

TEST(swap_cases, all_uppercase)
{
    std::string string = "TEST";
    string = strh::swap_cases(string);
    ASSERT_EQ(string, "test");
}

TEST(swap_cases, no_cases)
{
    std::string string = "123";
    string = strh::swap_cases(string);
    ASSERT_EQ(string, "123");
}

TEST(swap_cases, empty_string)
{
    std::string string;
    string = strh::swap_cases(string);
    ASSERT_EQ(string, "");
}


TEST(find_first, character)
{
    std::string string = "test";
    size_t found_idx = strh::find_first(string, 't');
    ASSERT_EQ(found_idx, 0);
}

TEST(find_first, string)
{
    std::string string = "test";
    size_t found_idx = strh::find_first(string, "es");
    ASSERT_EQ(found_idx, 1);
}

TEST(find_first, not_in)
{
    std::string string = "test";
    size_t found_idx = strh::find_first(string, 'x');
    ASSERT_EQ(found_idx, -1);
}

TEST(find_first, in)
{
    std::string string = "test";
    size_t found_idx = strh::find_first(string, 't');
    ASSERT_EQ(found_idx, 0);
}

TEST(find_first, all)
{
    std::string string = "www";
    size_t found_idx = strh::find_first(string, 'w');
    ASSERT_EQ(found_idx, 0);
}

TEST(find_first, empty_string)
{
    std::string string;
    size_t found_idx = strh::find_first(string, 'x');
    ASSERT_EQ(found_idx, -1);
}

TEST(find_first, empty_key_throw_invalid_argument)
{
    std::string string = "test";
    ASSERT_THROW(strh::find_first(string, ""), std::invalid_argument);
}

TEST(find_last, character)
{
    std::string string = "test";
    size_t found_idx = strh::find_last(string, 't');
    ASSERT_EQ(found_idx, 3);
}

TEST(find_last, string)
{
    std::string string = "test";
    size_t found_idx = strh::find_last(string, "es");
    ASSERT_EQ(found_idx, 2);
}

TEST(find_last, not_in)
{
    std::string string = "test";
    size_t found_idx = strh::find_last(string, 'x');
    ASSERT_EQ(found_idx, -1);
}

TEST(find_last, in)
{
    std::string string = "test";
    size_t found_idx = strh::find_last(string, 't');
    ASSERT_EQ(found_idx, 3);
}

TEST(find_last, all)
{
    std::string string = "www";
    size_t found_idx = strh::find_last(string, 'w');
    ASSERT_EQ(found_idx, 2);
}

TEST(find_last, empty_string)
{
    std::string string;
    size_t found_idx = strh::find_last(string, 'x');
    ASSERT_EQ(found_idx, -1);
}

TEST(find_last, empty_key_throw_invalid_argument)
{
    std::string string = "test";
    ASSERT_THROW(strh::find_last(string, ""), std::invalid_argument);
}

TEST(find, character)
{
    std::string string = "test";
    std::vector<size_t> found_idxs = strh::find(string, 't');
    std::vector<size_t> expected = {0, 3};
    ASSERT_EQ(found_idxs, expected);
}

TEST(find, string)
{
    std::string string = "test";
    std::vector<size_t> found_idxs = strh::find(string, "es");
    std::vector<size_t> expected = {1};
    ASSERT_EQ(found_idxs, expected);
}

TEST(find, not_in)
{
    std::string string = "test";
    std::vector<size_t> found_idxs = strh::find(string, 'x');
    std::vector<size_t> expected = {};
    ASSERT_EQ(found_idxs, expected);
}

TEST(find, in)
{
    std::string string = "test";
    std::vector<size_t> found_idxs = strh::find(string, 't');
    std::vector<size_t> expected = {0, 3};
    ASSERT_EQ(found_idxs, expected);
}

TEST(find, all)
{
    std::string string = "www";
    std::vector<size_t> found_idxs = strh::find(string, 'w');
    std::vector<size_t> expected = {0, 1, 2};
    ASSERT_EQ(found_idxs, expected);
}

TEST(find, empty_string)
{
    std::string string;
    std::vector<size_t> found_idxs = strh::find(string, 'x');
    std::vector<size_t> expected;
    ASSERT_EQ(found_idxs, expected);
}

TEST(find, empty_key_throw_invalid_argument)
{
    std::string string;
    ASSERT_THROW(strh::find(string, ""), std::invalid_argument);
}

TEST(replace, character_character)
{
    std::string string = "test";
    string = strh::replace(string, 't', 'x');
    ASSERT_EQ(string, "xesx");
}

TEST(replace, string_string)
{
    std::string string = "test";
    string = strh::replace(string, "es", "se");
    ASSERT_EQ(string, "tset");
}

TEST(replace, character_string)
{
    std::string string = "test";
    string = strh::replace(string, 't', "xx");
    ASSERT_EQ(string, "xxesxx");
}

TEST(replace, string_character)
{
    std::string string = "test";
    string = strh::replace(string, "es", 'x');
    ASSERT_EQ(string, "txt");
}

TEST(replace, not_in)
{
    std::string string = "test";
    string = strh::replace(string, 'x', 'y');
    ASSERT_EQ(string, "test");
}

TEST(replace, in)
{
    std::string string = "test";
    string = strh::replace(string, 't', 'x');
    ASSERT_EQ(string, "xesx");
}

TEST(replace, all)
{
    std::string string = "www";
    string = strh::replace(string, 'w', 'y');
    ASSERT_EQ(string, "yyy");
}

TEST(replace, empty_string)
{
    std::string string;
    string = strh::replace(string, 'x', 'y');
    ASSERT_EQ(string, "");
}

TEST(replace, empty_from)
{
    std::string string = "test";
    string = strh::replace(string, "", 'x');
    ASSERT_EQ(string, "xxxx");
}

TEST(replace, empty_to)
{
    std::string string = "test";
    string = strh::replace(string, 't', "");
    ASSERT_EQ(string, "es");
}


TEST(remove_nums, not_in)
{
    std::string string = "test";
    string = strh::remove_nums(string);
    ASSERT_EQ(string, "test");
}

TEST(remove_nums, in)
{
    std::string string = "123test123";
    string = strh::remove_nums(string);
    ASSERT_EQ(string, "test");
}

TEST(remove_nums, all)
{
    std::string string = "123";
    string = strh::remove_nums(string);
    ASSERT_EQ(string, "");
}

TEST(remove_nums, empty_string)
{
    std::string string;
    string = strh::remove_nums(string);
    ASSERT_EQ(string, "");
}

TEST(remove_alphabetical, not_in)
{
    std::string string = "123";
    string = strh::remove_alphabetical(string);
    ASSERT_EQ(string, "123");
}

TEST(remove_alphabetical, in)
{
    std::string string = "123test";
    string = strh::remove_alphabetical(string);
    ASSERT_EQ(string, "123");
}

TEST(remove_alphabetical, all)
{
    std::string string = "test";
    string = strh::remove_alphabetical(string);
    ASSERT_EQ(string, "");
}

TEST(remove_alphabetical, empty_string)
{
    std::string string;
    string = strh::remove_alphabetical(string);
    ASSERT_EQ(string, "");
}

TEST(split_alphabetical, no_alphabetical)
{
    std::string string = "123";
    std::vector<std::string> splits = strh::split_alphabetical(string);
    std::vector<std::string> expected = {"123"};
    ASSERT_EQ(splits, expected);
}

TEST(split_alphabetical, some_alphabetical)
{
    std::string string = "12.34";
    std::vector<std::string> splits = strh::split_alphabetical(string);
    std::vector<std::string> expected = {"12", "34"};
    ASSERT_EQ(splits, expected);
}

TEST(split_alphabetical, all_alphabetical)
{
    std::string string = "abc";
    std::vector<std::string> splits = strh::split_alphabetical(string);
    std::vector<std::string> expected = {"", "", ""};
    ASSERT_EQ(splits, expected);
}

TEST(split_alphabetical, empty_string)
{
    std::string string;
    std::vector<std::string> splits = strh::split_alphabetical(string);
    std::vector<std::string> expected = {};
    ASSERT_EQ(splits, expected);
}

TEST(from_parameter_pack, basic)
{
        std::string from_parameter_pack = strh::from_parameter_pack(1, 2, 3);
        ASSERT_EQ(from_parameter_pack, "1, 2, 3");
}

TEST(from_vector, basic)
{
        std::vector test_vector = {1, 2, 3};
        std::string test_as_str = strh::from_vector(test_vector);
        ASSERT_EQ(test_as_str, "1, 2, 3");
}

TEST(format, no_comma)
{
    std::string formatted = strh::format(100);
    ASSERT_EQ(formatted, "100");
}

TEST(format, one_comma)
{
    std::string formatted = strh::format(1'000);
    ASSERT_EQ(formatted, "1,000");
}

TEST(format, multiple_comma)
{
    std::string formatted = strh::format(10'000'000);
    ASSERT_EQ(formatted, "10,000,000");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
