/* file2array
 * Copyright (C) 2024 Killian Valverde.
 *
 * This file is part of file2array.
 *
 * file2array is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * file2array is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with file2array. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file        file2array/program.hpp
 * @brief       program class header.
 * @author      Killian Valverde
 * @date        2024/10/25
 */
 
#ifndef FILE2ARRAY_PROGRAM_HPP
#define FILE2ARRAY_PROGRAM_HPP

#include <speed/speed.hpp>

#include "exception.hpp"
#include "program_args.hpp"


/**
 * @brief       Contians all file2array resources.
 */
namespace file2array {


class program
{
public:
    /**
     * @brief       Constructor with parameters.
     * @param       prog_args : The program arguments.
     */
    explicit program(program_args&& prog_args);
    
    /**
     * @brief       Execute the program.
     * @return      The value that represents if the program succeed.
     */
    int execute();

private:
    template <typename TpChar_>
    std::basic_string<TpChar_> remove_extension(const std::basic_string<TpChar_>& filename)
    {
        using string_type = std::basic_string<TpChar_>;
        
        typename string_type::size_type dot_pos = filename.find_last_of('.');
        
        if (dot_pos != string_type::npos && dot_pos > 0)
        {
            return filename.substr(0, dot_pos);
        }
        
        return filename;
    }
    
    template <typename TpChar_>
    std::string sanitize_identifier(const std::basic_string<TpChar_>& inpt)
    {
        std::string res;
        bool is_first_char = true;
        
        for (TpChar_ ch : inpt)
        {
            if (std::isalnum(ch) || ch == '_')
            {
                if (is_first_char && std::isdigit(ch))
                {
                    continue;
                }
    
                res += (std::string::value_type)ch;
                is_first_char = false;
            }
        }
    
        return res;
    }

private:
    /** The program arguments. */
    program_args prog_args_;
};


}


#endif
