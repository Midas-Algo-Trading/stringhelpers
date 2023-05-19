#include <sstream>
#include "StringHelpers.h"
#include <iostream>
#include <utility>

std::string strh::capitalize(std::string string)
{
    string[0] = static_cast<char>(toupper(string[0]));
    return string;
}

std::string strh::align(std::string string, Alignment alignment, size_t target_len, char fill)
{
    return align(std::move(string), alignment, target_len, std::string(1, fill));
}

std::string strh::align(std::string string, Alignment alignment, size_t target_len, const
                        std::string &fill)
{
    if (fill.empty())
        throw std::invalid_argument("fill cannot be empty");

    switch (alignment) {
    case LEFT:
        return priv_helpers::align_left(string, target_len, fill);
    case CENTER:
        return priv_helpers::align_center(string, target_len, fill);
    case RIGHT:
        return priv_helpers::align_right(string, target_len, fill);
    default:
        throw std::invalid_argument("Invalid alignment");
    }
}

std::string strh::priv_helpers::align_left(std::string string, size_t target_len, std::string fill)
{
    size_t fill_amount = target_len - string.length();
    fill = strh::multiply(fill, fill_amount / fill.size());
    string = fill + string;
    return string;
}

std::string strh::priv_helpers::align_center(std::string string, size_t target_len, std::string fill)
{
    size_t fill_amount = target_len - string.length();
    fill = strh::multiply(fill, (fill_amount / fill.size()) / 2);
    string = fill + string + fill;
    return string;
}

std::string strh::priv_helpers::align_right(std::string string, size_t target_len, std::string fill)
{
    size_t fill_amount = target_len - string.length();
    fill = strh::multiply(fill, fill_amount / fill.size());
    string = string + fill;
    return string;
}

std::string strh::multiply(std::string string, size_t amount)
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

size_t strh::count(std::string_view string, char key)
{
    int ret = 0;
    for (char ch: string)
    {
        if (ch == key)
            ret++;
    }
    return ret;
}

size_t strh::count(std::string_view string, std::string_view key)
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

bool strh::ends_with(std::string_view string, char key)
{
    if (string.empty())
        return false;

    return string[string.length() - 1] == key;
}

bool strh::ends_with(std::string_view string, std::string_view key)
{
    size_t start_idx = string.length() - key.length();
    return string.substr(start_idx, key.length()) == key;
}

bool strh::is_in(std::string_view string, char key)
{
    return count(string, key) != 0;
}

bool strh::is_in(std::string_view string, std::string_view key)
{
    return count(string, key) != 0;
}

bool strh::all_nums(std::string_view string)
{
    if (string.empty())
        throw std::invalid_argument("string cannot be empty");

    for (char ch: string)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }

    if (string.empty())
    {
        return false;
    }

    return true;
}

bool strh::all_alphabetical(std::string_view string)
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

bool strh::all_lowercase(std::string_view string)
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

bool strh::all_uppercase(std::string_view string)
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

bool strh::all_spaces(std::string_view string)
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

std::vector<std::string> strh::split(std::string_view string, char delimiter)
{
    std::vector<std::string> ret;
    std::stringstream ss = std::stringstream(std::string(string));
    std::string split;
    while (std::getline(ss, split, delimiter))
        ret.push_back(split);
    return ret;
}

std::vector<std::string> strh::split_lines(std::string_view string)
{
    return split(string, '\n');
}

std::vector<std::string> strh::split(std::string_view string, std::string_view delimiter)
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

std::string strh::strip(std::string string)
{
    size_t front_whitespaces_end_idx = string.find_first_not_of(" \t\n");
    if (front_whitespaces_end_idx == std::string::npos)
        front_whitespaces_end_idx = 0;

    size_t end_whitespaces_start_idx = string.find_last_not_of(" \t\n");

    size_t new_string_len = end_whitespaces_start_idx - front_whitespaces_end_idx;
    string = string.substr(front_whitespaces_end_idx, new_string_len + 1);
    return string;
}

std::string strh::swap_cases(std::string string)
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

int strh::find_first(std::string_view string, char key)
{
    return find_first(string, std::string(1, key));
}

int strh::find_first(std::string_view string, std::string_view key)
{
    if (key.empty())
        throw std::invalid_argument("key cannot be empty");

    size_t found_idx = string.find(key);
    return found_idx <= string.length() ? static_cast<int>(found_idx) : -1;
}

int strh::find_last(std::string_view string, char key)
{
    return find_last(string, std::string(1, key));
}

int strh::find_last(std::string_view string, std::string_view key)
{
    if (key.empty())
        throw std::invalid_argument("key cannot be empty");

    size_t found_idx = string.find_last_of(key);
    return found_idx != std::string::npos ? static_cast<int>(found_idx) : -1;
}

std::vector<size_t> strh::find(std::string_view string, char key)
{
    return strh::find(string, std::string(1, key));
}

std::vector<size_t> strh::find(std::string_view string, std::string_view key)
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

std::string strh::replace(std::string string, std::string_view from, std::string_view to)
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

std::string strh::replace(std::string string, std::string_view from, char to)
{
    return strh::replace(std::move(string), from, std::string(1, to));
}

std::string strh::replace(std::string string, char from, std::string_view to)
{
    return strh::replace(std::move(string), std::string(1, from), to);
}

std::string strh::replace(std::string string, char from, char to)
{
    return strh::replace(std::move(string), std::string(1, from), std::string(1, to));
}

std::string strh::remove_nums(std::string string)
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

std::string strh::remove_alphabetical(std::string string)
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

std::vector<std::string> strh::split_alphabetical(std::string_view string)
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

template<typename... T>
std::string strh::from_parameter_pack(T... params)
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

template<typename T>
std::string strh::from_vector(const std::vector<T> &vector)
{
        std::stringstream ss;
        for (size_t i = 0; i < vector.size(); i++)
        {
                ss << vector[i];
                if (i != vector.size()-1)
                        ss << ", ";
        }
        return ss.str();
}
