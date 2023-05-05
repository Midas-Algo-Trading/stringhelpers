/**
 * Various std::string helper functions.
 */

#ifndef STRINGHELPERS_STRINGHELPERS_H
#define STRINGHELPERS_STRINGHELPERS_H

#include <string>
#include <vector>

namespace strh
{

/**
 * Specifies the alignment of a string for the align function.
 *
 * @see align
 */
enum Alignment { LEFT, CENTER, RIGHT };

/**
 * Capitalizes 'string'.
 *
 * Capitalizes the first character in 'string'.
 *
 * @param string the string to capitalize
 *
 * @return capitalized 'string'.
 */
std::string capitalize(std::string string);

/**
 * Adds characters to 'string' to align 'string' to a target length.
 *
 * @param string the string to align.
 * @param alignment which side(s) to align 'string' to.
 * @param target_len the length to set 'string' to.
 * @param fill the character to add to 'string' to align it.
 *
 * @return aligned 'string'.
 *
 * @throws std::invalid_argument Thrown if 'fill' is empty.
 */
std::string align(std::string string, Alignment alignment, size_t target_len, char fill);

/**
 * Adds characters to 'string' to align 'string' to a target length.
 *
 * @param string the string to align.
 * @param alignment which side(s) to align 'string' to.
 * @param target_len the length to set 'string' to.
 * @param fill the character to add to 'string' to align it.
 *
 * @return aligned 'string'.
 */
std::string align(std::string string, Alignment alignment, size_t target_len,
                  const std::string &fill);

/**
 * Multiply 'string'.
 *
 * @param string the string to multiply.
 * @param amount the amount of times to multiply 'string'.
 *
 * @return multiplied 'string'
 */
std::string multiply(std::string string, size_t amount);

/**
 * Counts the number of times 'key' is in 'string'
 *
 * @param string the string to search.
 * @param key the character to count the occurrences of.
 *
 * @return the number of times 'key' is in 'string'.
 */
size_t count(std::string_view string, char key);

/**
 * Counts the number of times 'key' is in 'string'
 *
 * @param string the string to search.
 * @param key the string to count the occurrences of.
 *
 * @return the number of times 'key' is in 'string'.
 *
 * @throws std::invalid_argument Thrown if 'key' is empty.
 */
size_t count(std::string_view string, std::string_view key);

/**
 * Checks if 'string' ends with 'key'.
 *
 * @param string the string to check.
 * @param key the character to search for at the end of the string.
 *
 * @return 'true' if 'string' ends with 'key', 'false' otherwise.
 *
 * @throw std::invalid_argument Thrown if 'string' is empty.
 */
bool ends_with(std::string_view string, char key);

/**
 * Checks if 'string' ends with 'key'.
 *
 * @param string the string to check.
 * @param key the string to search for at the end of the string.
 *
 * @return 'true' if 'string' ends with 'key', 'false' otherwise.
 */
bool ends_with(std::string_view string, std::string_view key);

/**
 * Checks if 'key' is in 'string'.
 *
 * @param string the string to check.
 * @param key the character to search for in 'string'.
 *
 * @return 'true' if 'key' is in 'string', 'false' otherwise.
 */
bool is_in(std::string_view string, char key);

/**
 * Checks if 'key' is in 'string'.
 *
 * @param string the string to check.
 * @param key the string to search for in 'string'.
 *
 * @return 'true' if 'key' is in 'string', 'false' otherwise.
 */
bool is_in(std::string_view string, std::string_view key);

/**
 * Checks if all characters in 'string' are numbers.
 *
 * @param string the string to check.
 *
 * @return 'true' if all characters in 'string' are numbers, 'false' otherwise or if 'string' is
 * empty.
 *
 * @throw std::invalid_argument Thrown if 'string' is empty.
 */
bool all_nums(std::string_view string);

/**
 * Checks if all characters in 'string' are alphabetical (letters).
 *
 * @param string the string to check.
 *
 * @return 'true' if all characters in 'string' are alphabetical (letters), 'false' otherwise or if 'string' is
 * empty.
 *
 * @throw std::invalid_argument Thrown if 'string' is empty.
 */
bool all_alphabetical(std::string_view string);

/**
 * Checks if all characters in 'string' are lowercase.
 *
 * @param string the string to check.
 *
 * @return 'true' if all characters in 'string' are lowercase, 'false' otherwise or if 'string' is
 * empty.
 *
 * @throw std::invalid_argument Thrown if 'string' is empty.
 */
bool all_lowercase(std::string_view string);

/**
 * Checks if all characters in 'string' are uppercase.
 *
 * @param string the string to check.
 *
 * @return 'true' if all characters in 'string' are uppercase, 'false' otherwise or if 'string' is
 * empty.
 *
 * @throw std::invalid_argument Thrown if 'string' is empty.
 */
bool all_uppercase(std::string_view string);

/**
 * Checks if all characters in 'string' are spaces.
 *
 * @param string the string to check.
 *
 * @return 'true' if all characters in 'string' are spaces, 'false' otherwise or if 'string' is
 * empty.
 *
 * @throw std::invalid_argument Thrown if 'string' is empty.
 */
bool all_spaces(std::string_view string);

/**
 * Splits 'string' into substrings separated by 'delimiter'.
 *
 * @param string the string to split.
 * @param delimiter the character to split 'string' by.
 *
 * @return a vector of the substrings of 'string'.
 */
std::vector<std::string> split(std::string_view string, char delimiter);

/**
 * Splits 'string' into substrings separated by 'delimiter'.
 *
 * @param string the string to split.
 * @param delimiter the string to split 'string' by.
 *
 * @return a vector of the substrings of 'string'.
 */
std::vector<std::string> split(std::string_view string, std::string_view delimiter);

/**
 * Splits 'string' into substrings separated by '\n'.
 *
 * @param string the string to split.
 *
 * @return a vector of the substrings of 'string'.
 */
std::vector<std::string> split_lines(std::string_view string);

/**
 * Removes whitespaces at the beginning and end of 'string'.
 *
 * @param string the string to remove white spaces of.
 *
 * @return 'string' with no whitespaces at the beginning nor end.
 *
 * @note whitespaces are ' ', '\t'. '\n'.
 * @note whitespaces will be removed at the beginning and end until a non-whitespace character is
 * met.
 */
std::string strip(std::string string);

/**
 * Swaps the cases of each of character in 'string'
 *
 * Lowercase characters are switched to their uppercase counterpart and uppercase characters are
 * switched to their lowercase counterpart.
 *
 * @param string the string to swap the cases of.
 *
 * @return 'string' with swapped characters.
 */
std::string swap_cases(std::string string);

/**
 * Finds the index of the first occurrence of 'key' in 'string'.
 *
 * @param string the string to search.
 * @param key the character to search for in 'string'.
 *
 * @return the index of the first occurrence of 'key' in 'string'. If 'key' is not in 'string',
 * will return '-1'.
 */
int find_first(std::string_view string, char key);

/**
 * Finds the index of the first occurrence of 'key' in 'string'.
 *
 * @param string the string to search.
 * @param key the string to search for in 'string'.
 *
 * @return the index of the first occurrence of 'key' in 'string'. If 'key' is not in 'string',
 * will return '-1'.
 *
 * @throw std::invalid_argument Thrown if 'key' is empty.
 */
int find_first(std::string_view string, std::string_view key);

/**
 * Finds the index of the last occurrence of 'key' in 'string'.
 *
 * @param string the string to search.
 * @param key the character to search for in 'string'.
 *
 * @return the index of the last occurrence of 'key' in 'string'. If 'key' is not in 'string',
 * will return -1.
 */
int find_last(std::string_view string, char key);

/**
 * Finds the index of the last occurrence of 'key' in 'string'.
 *
 * @param string the string to search.
 * @param key the string to search for in 'string'.
 *
 * @return the index of the last occurrence of 'key' in 'string'. If 'key' is not in 'string',
 * will return -1.
 *
 * @throw std::invalid_argument Thrown if 'key' is empty.
 */
int find_last(std::string_view string, std::string_view key);

/**
 * Finds the indexes 'key' occurs in 'string'.
 *
 * @param string the string to search.
 * @param key the character to search for in 'string'.
 *
 * @return a vector of the indexes 'key' occurred in 'string'. If 'key' is not in 'string', will
 * return an empty vector.
 *
 * @throw std::invalid_argument Thrown if 'key' is empty.
 */
std::vector<size_t> find(std::string_view string, char key);

/**
 * Finds the indexes 'key' occurs in 'string'.
 *
 * @param string the string to search.
 * @param key the string to search for in 'string'.
 *
 * @return a vector of the indexes 'key' occurred in 'string'. If 'key' is not in 'string', will
 * return an empty vector.
 */
std::vector<size_t> find(std::string_view string, std::string_view key);

/**
 * Replaces all occurrences of 'from' to 'to' in 'string'.
 *
 * @param string the string to replace character(s) in.
 * @param from the string to replace with 'to'.
 * @param to the string to replace 'from'.
 *
 * @return 'string' with all occurrences of 'from' replaced with 'to'.
 */
std::string replace(std::string string, std::string_view from, std::string_view to);

/**
 * Replaces all occurrences of 'from' to 'to' in 'string'.
 *
 * @param string the string to replace character(s) in.
 * @param from the character to replace with 'to'.
 * @param to the string to replace 'from'.
 *
 * @return 'string' with all occurrences of 'from' replaced with 'to'.
 */
std::string replace(std::string string, char from, std::string_view to);

/**
 * Replaces all occurrences of 'from' to 'to' in 'string'.
 *
 * @param string the string to replace character(s) in.
 * @param from the string to replace with 'to'.
 * @param to the character to replace 'from'.
 *
 * @return 'string' with all occurrences of 'from' replaced with 'to'.
 */
std::string replace(std::string string, std::string_view from, char to);

/**
 * Replaces all occurrences of 'from' to 'to' in 'string'.
 *
 * @param string the string to replace character(s) in.
 * @param from the character to replace with 'to'.
 * @param to the character to replace 'from'.
 *
 * @return 'string' with all occurrences of 'from' replaced with 'to'.
 */
std::string replace(std::string string, char from, char to);

/**
 * Removes all numbers in 'string'.
 *
 * @param string the string to remove numbers from.
 *
 * @return 'string' with all numbers removed.
 */
std::string remove_nums(std::string string);

/**
 * Removes all alphabetical (letters) in 'string'.
 *
 * @param string the string to remove numbers from.
 *
 * @return 'string' with all alphabetical (letters) removed.
 */
std::string remove_alphabetical(std::string string);

/**
 * Helper functions for the String Helper functions.
 *
 * @relatealso strh
 */
namespace priv_helpers
{

/**
 * Adds characters to the left of 'string' to align 'string' to a target length.
 *
 * @param string the string to align.
 * @param target_len the length to set 'string' to.
 * @param fill the character to add to 'string' to align it.
 *
 * @return 'string' aligned to the left.
 */
std::string align_left(std::string string, size_t target_len, std::string fill);

/**
 * Adds characters to the right of 'string' to align 'string' to a target length.
 *
 * @param string the string to align.
 * @param target_len the length to set 'string' to.
 * @param fill the character to add to 'string' to align it.
 *
 * @return 'string' aligned to the right.
 */
std::string align_center(std::string string, size_t target_len, std::string fill);

/**
 * Adds characters to the left and right of 'string' to align 'string' to a target length.
 *
 * @param string the string to align.
 * @param target_len the length to set 'string' to.
 * @param fill the character to add to 'string' to align it.
 *
 * @return 'string' aligned to the center.
 */
std::string align_right(std::string string, size_t target_len, std::string fill);
}
}

#endif //STRINGHELPERS_STRINGHELPERS_H
