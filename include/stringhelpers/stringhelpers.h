/**
 * Various std::string helper functions.
 */

#ifndef STRINGHELPERS_STRINGHELPERS_H
#define STRINGHELPERS_STRINGHELPERS_H

#include <string>
#include <vector>
#include <sstream>

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
inline std::string capitalize(std::string string)
{
        string[0] = static_cast<char>(toupper(string[0]));
        return string;
}

/**
 * Multiply 'string'.
 *
 * @param string the string to multiply.
 * @param amount the amount of times to multiply 'string'.
 *
 * @return multiplied 'string'
 */
inline std::string multiply(std::string string, size_t amount)
{
        std::string multiplied_string;
        while (amount > 0)
        {
                multiplied_string += string;
                amount--;
        }
        string = multiplied_string;
        return string;
}

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
inline std::string align_left(std::string string, size_t target_len, std::string fill)
{
        size_t fill_amount = target_len - string.length();
        fill = strh::multiply(fill, fill_amount / fill.size());
        string = fill + string;
        return string;
}

/**
 * Adds characters to the right of 'string' to align 'string' to a target length.
 *
 * @param string the string to align.
 * @param target_len the length to set 'string' to.
 * @param fill the character to add to 'string' to align it.
 *
 * @return 'string' aligned to the right.
 */
inline std::string align_center(std::string string, size_t target_len, std::string fill)
{
        size_t fill_amount = target_len - string.length();
        fill = strh::multiply(fill, (fill_amount / fill.size()) / 2);
        string = fill + string + fill;
        return string;
}

/**
 * Adds characters to the left and right of 'string' to align 'string' to a target length.
 *
 * @param string the string to align.
 * @param target_len the length to set 'string' to.
 * @param fill the character to add to 'string' to align it.
 *
 * @return 'string' aligned to the center.
 */
inline std::string align_right(std::string string, size_t target_len, std::string fill)
{
        size_t fill_amount = target_len - string.length();
        fill = strh::multiply(fill, fill_amount / fill.size());
        string = string + fill;
        return string;
}
}

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
inline std::string align(std::string string, Alignment alignment, size_t target_len,
                  const std::string &fill)
{
        if (fill.empty())
                throw std::invalid_argument("fill cannot be empty");

        switch (alignment) {
        case LEFT:
                return strh::priv_helpers::align_left(std::move(string), target_len, fill);
        case CENTER:
                return priv_helpers::align_center(std::move(string), target_len, fill);
        case RIGHT:
                return priv_helpers::align_right(std::move(string), target_len, fill);
        default:
                throw std::invalid_argument("Invalid alignment");
        }
}

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
inline std::string align(std::string string, Alignment alignment, size_t target_len, char fill)
{
        return align(std::move(string), alignment, target_len, std::string(1, fill));
}


/**
 * Counts the number of times 'key' is in 'string'
 *
 * @param string the string to search.
 * @param key the character to count the occurrences of.
 *
 * @return the number of times 'key' is in 'string'.
 */
inline size_t count(std::string_view string, char key)
{
        int ret = 0;
        for (char ch: string)
        {
                if (ch == key)
                        ret++;
        }
        return ret;
}

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
inline size_t count(std::string_view string, std::string_view key)
{
        if (key.empty())
                throw std::invalid_argument("key cannot be empty");

        int ret = 0;
        size_t pos = 0;
        while ((pos = string.find(key, pos)) != std::string::npos)
        {
                ret++;
                pos += key.length();
        }
        return ret;
}

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
inline bool ends_with(std::string_view string, char key)
{
        if (string.empty())
                throw std::invalid_argument("string cannot be empty");

        return string[string.length() - 1] == key;
}

/**
 * Checks if 'string' ends with 'key'.
 *
 * @param string the string to check.
 * @param key the string to search for at the end of the string.
 *
 * @return 'true' if 'string' ends with 'key', 'false' otherwise.
 */
inline bool ends_with(std::string_view string, std::string_view key)
{
        size_t start_idx = string.length() - key.length();
        return string.substr(start_idx, key.length()) == key;
}

/**
 * Checks if 'string' starts with 'key'.
 *
 * @param string the string to check.
 * @param key the character to search for at the start of the string.
 *
 * @return 'true' if 'string' starts with 'key', 'false' otherwise.
 *
 * @throw std::invalid_argument Thrown if 'string' is empty.
 */
inline bool starts_with(std::string_view string, char key)
{
    if (string.empty())
        throw std::invalid_argument("string cannot be empty");

    return string[0] == key;
}

/**
 * Checks if 'string' starts with 'key'.
 *
 * @param string the string to check.
 * @param key the string to search for at the start of the string.
 *
 * @return 'true' if 'string' starts with 'key', 'false' otherwise.
 */
inline bool starts_with(std::string_view string, std::string_view prefix)
{
    if (string.length() < prefix.length())
        return false;

    return string.substr(0, prefix.length()) == prefix;
}

/**
 * Checks if 'key' is in 'string'.
 *
 * @param string the string to check.
 * @param key the character to search for in 'string'.
 *
 * @return 'true' if 'key' is in 'string', 'false' otherwise.
 */
inline bool is_in(std::string_view string, char key)
{
        return count(string, key) != 0;
}

/**
 * Checks if 'key' is in 'string'.
 *
 * @param string the string to check.
 * @param key the string to search for in 'string'.
 *
 * @return 'true' if 'key' is in 'string', 'false' otherwise.
 */
inline bool is_in(std::string_view string, std::string_view key)
{
        return count(string, key) != 0;
}

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
inline bool all_nums(std::string_view string)
{
        if (string.empty())
                throw std::invalid_argument("string cannot be empty");

        for (char ch: string)
        {
                if (!isdigit(ch))
                        return false;
        }

        if (string.empty())
                return false;

        return true;
}

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
inline bool all_alphabetical(std::string_view string)
{
        if (string.empty())
        {
                throw std::invalid_argument("string cannot be empty");
        }

        for (char ch: string)
        {
                if (!isalpha(ch))
                        return false;
        }

        if (string.empty())
                return false;

        return true;
}

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
inline bool all_lowercase(std::string_view string)
{
        if (string.empty())
                throw std::invalid_argument("string cannot be empty");

        for (char ch: string)
        {
                if (!islower(ch))
                        return false;
        }

        if (string.empty())
                return false;

        return true;
}

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
inline bool all_uppercase(std::string_view string)
{
        if (string.empty())
                throw std::invalid_argument("string cannot be empty");

        for (char ch: string)
        {
                if (!isupper(ch))
                        return false;
        }

        if (string.empty())
                return false;

        return true;
}


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
inline bool all_spaces(std::string_view string)
{
        if (string.empty())
                throw std::invalid_argument("string cannot be empty");

        for (char ch: string)
        {
                if (!isspace(ch))
                        return false;
        }

        if (string.empty())
                return false;

        return true;
}

/**
 * Splits 'string' into substrings separated by 'delimiter'.
 *
 * @param string the string to split.
 * @param delimiter the character to split 'string' by.
 *
 * @return a vector of the substrings of 'string'.
 */
inline std::vector<std::string> split(std::string_view string, char delimiter)
{
        std::vector<std::string> ret;
        std::stringstream ss = std::stringstream(std::string(string));
        std::string split;
        while (std::getline(ss, split, delimiter))
                ret.push_back(split);
        return ret;
}

/**
 * Splits 'string' into substrings separated by 'delimiter'.
 *
 * @param string the string to split.
 * @param delimiter the string to split 'string' by.
 *
 * @return a vector of the substrings of 'string'.
 */
inline std::vector<std::string> split(std::string_view string, std::string_view delimiter)
{
        if (delimiter.empty())
                throw std::invalid_argument("delimiter cannot be empty");

        std::vector<std::string> ret;
        size_t start = 0;
        size_t end;
        while ((end = string.find(delimiter, start)) != std::string::npos)
        {
                ret.emplace_back(string.substr(start, end - start));
                start = end + delimiter.length();
        }

        if (!string.substr(start).empty())
                ret.emplace_back(string.substr(start));

        return ret;
}

/**
 * Splits 'string' into substrings separated by '\n'.
 *
 * @param string the string to split.
 *
 * @return a vector of the substrings of 'string'.
 */
inline std::vector<std::string> split_lines(std::string_view string)
{
        return split(string, '\n');
}

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
inline std::string strip(std::string string)
{
        size_t front_whitespaces_end_idx = string.find_first_not_of(" \t\n");
        if (front_whitespaces_end_idx == std::string::npos)
                front_whitespaces_end_idx = 0;

        size_t end_whitespaces_start_idx = string.find_last_not_of(" \t\n");

        size_t new_string_len = end_whitespaces_start_idx - front_whitespaces_end_idx;
        string = string.substr(front_whitespaces_end_idx, new_string_len + 1);
        return string;
}

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
inline std::string swap_cases(std::string string)
{
        for (char &ch: string)
        {
                if (isupper(ch))
                        ch = static_cast<char>(tolower(ch));
                else if (islower(ch))
                        ch = static_cast<char>(toupper(ch));
        }
        return string;
}

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
inline int find_first(std::string_view string, std::string_view key)
{
        if (key.empty())
                throw std::invalid_argument("key cannot be empty");

        size_t found_idx = string.find(key);
        return found_idx <= string.length() ? static_cast<int>(found_idx) : -1;
}

/**
 * Finds the index of the first occurrence of 'key' in 'string'.
 *
 * @param string the string to search.
 * @param key the character to search for in 'string'.
 *
 * @return the index of the first occurrence of 'key' in 'string'. If 'key' is not in 'string',
 * will return '-1'.
 */
inline int find_first(std::string_view string, char key)
{
        return strh::find_first(string, std::string(1, key));
}

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
inline int find_last(std::string_view string, std::string_view key)
{
        if (key.empty())
                throw std::invalid_argument("key cannot be empty");

        size_t found_idx = string.find_last_of(key);
        return found_idx != std::string::npos ? static_cast<int>(found_idx) : -1;
}

/**
 * Finds the index of the last occurrence of 'key' in 'string'.
 *
 * @param string the string to search.
 * @param key the character to search for in 'string'.
 *
 * @return the index of the last occurrence of 'key' in 'string'. If 'key' is not in 'string',
 * will return -1.
 */
inline int find_last(std::string_view string, char key)
{
        return find_last(string, std::string(1, key));
}

/**
 * Finds the indexes 'key' occurs in 'string'.
 *
 * @param string the string to search.
 * @param key the string to search for in 'string'.
 *
 * @return a vector of the indexes 'key' occurred in 'string'. If 'key' is not in 'string', will
 * return an empty vector.
 */
inline std::vector<size_t> find(std::string_view string, std::string_view key)
{
        if (key.empty())
                throw std::invalid_argument("key cannot be empty");

        std::vector<size_t> ret;
        size_t pos = string.find(key);
        while (pos != std::string::npos)
        {
                ret.push_back(pos);
                pos = string.find(key, pos + 1);
        }

        return ret;
}

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
inline std::vector<size_t> find(std::string_view string, char key)
{
        return strh::find(string, std::string(1, key));
}

/**
 * Replaces all occurrences of 'from' to 'to' in 'string'.
 *
 * @param string the string to replace character(s) in.
 * @param from the string to replace with 'to'.
 * @param to the string to replace 'from'.
 *
 * @return 'string' with all occurrences of 'from' replaced with 'to'.
 */
inline std::string replace(std::string string, std::string_view from, std::string_view to)
{
        if (from.empty())
        {
                std::string new_string = std::string(to);
                new_string = strh::multiply(new_string, string.length());
                string = new_string;
                return string;
        }

        size_t idx = 0;
        while ((idx = string.find(from, idx)) != std::string::npos)
        {
                string.replace(idx, from.length(), to);
                idx += to.length();
        }
        return string;
}

/**
 * Replaces all occurrences of 'from' to 'to' in 'string'.
 *
 * @param string the string to replace character(s) in.
 * @param from the character to replace with 'to'.
 * @param to the string to replace 'from'.
 *
 * @return 'string' with all occurrences of 'from' replaced with 'to'.
 */
inline std::string replace(std::string string, char from, std::string_view to)
{
        return strh::replace(std::move(string), std::string(1, from), to);
}

/**
 * Replaces all occurrences of 'from' to 'to' in 'string'.
 *
 * @param string the string to replace character(s) in.
 * @param from the string to replace with 'to'.
 * @param to the character to replace 'from'.
 *
 * @return 'string' with all occurrences of 'from' replaced with 'to'.
 */
inline std::string replace(std::string string, std::string_view from, char to)
{
        return strh::replace(std::move(string), from, std::string(1, to));
}

/**
 * Replaces all occurrences of 'from' to 'to' in 'string'.
 *
 * @param string the string to replace character(s) in.
 * @param from the character to replace with 'to'.
 * @param to the character to replace 'from'.
 *
 * @return 'string' with all occurrences of 'from' replaced with 'to'.
 */
inline std::string replace(std::string string, char from, char to)
{
        return strh::replace(std::move(string), std::string(1, from), std::string(1, to));
}

/**
 * Removes all numbers in 'string'.
 *
 * @param string the string to remove numbers from.
 *
 * @return 'string' with all numbers removed.
 */
inline std::string remove_nums(std::string string)
{
        std::string new_string;
        for (char ch: string)
        {
                if (!isdigit(ch))
                        new_string += ch;
        }
        string = new_string;
        return string;
}

/**
 * Removes all alphabetical (letters) in 'string'.
 *
 * @param string the string to remove numbers from.
 *
 * @return 'string' with all alphabetical (letters) removed.
 */
inline std::string remove_alphabetical(std::string string)
{
        std::string new_string;
        for (char ch: string)
        {
                if (!isalpha(ch))
                        new_string += ch;
        }
        string = new_string;
        return string;
}

/**
 * Splits 'string' into substrings separated by any alphabetical (letter) characters.
 *
 * @param string the string to split.
 *
 * @return a vector of the substrings of 'string'.
 */
inline std::vector<std::string> split_alphabetical(std::string_view string)
{
        std::vector<std::string> ret;
        std::string temp;
        for (char ch : string)
        {
                if (isdigit(ch))
                        temp += ch;
                else if (!temp.empty())
                {
                        ret.push_back(temp);
                        temp.clear();
                }
        }

        if (!temp.empty())
                ret.push_back(temp);

        // If string view consists of all alphabetic characters, the resulting array should be {"",
        // "", "", ...} to match the case of the split function.
        if (ret.empty())
        {
                while (ret.size() < string.length())
                        ret.emplace_back("");
        }

        return ret;
}

/**
 * Converts parameter pack 'parameters' into a formatted string.
 *
 * @tparam T the parameter type.
 *
 * @param params the parameters pack to convert into a formatted string.
 *
 * @return a formatted string of 'parameters' delimitated by commas.
 */
template<typename... T>
inline std::string from_parameter_pack(T... params)
{
        std::stringstream ss;

        size_t idx = 1;
        auto add_parameters_to_ss = [&](const auto& parameter, size_t idx)
        {
                ss << parameter;
                if (idx < sizeof...(params))
                        ss << ", ";
        };

        (add_parameters_to_ss(params, idx++), ...);
        return ss.str();
}

/**
 * Converts vector 'vector' into a formatted string.
 *
 * @tparam T the vector type.
 *
 * @param vector the vector to convert into a formatted string.
 * @param delimiter the string separating each value of 'vector'. (default ", ")
 *
 * @return a formatted string of 'vector' delimitated by commas.
 */
template<typename T>
inline std::string from_vector(const std::vector<T>& vector, std::string_view delimiter = ", ")
{
        std::stringstream ss;
        for (size_t i = 0; i < vector.size(); i++)
        {
                ss << vector[i];
                if (i != vector.size()-1)
                        ss << delimiter;
        }
        return ss.str();
}

inline std::string format(int number)
{
    std::stringstream ss;
    ss.imbue(std::locale(""));
    ss << std::fixed << number;
    return ss.str();
}
}

#endif //STRINGHELPERS_STRINGHELPERS_H