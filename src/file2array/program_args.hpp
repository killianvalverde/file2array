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
 * @file        file2array/program_args.hpp
 * @brief       program_args struct header.
 * @author      Killian Valverde
 * @date        2024/10/25
 */
 
#ifndef FILE2ARRAY_PROGRAM_ARGS_HPP
#define FILE2ARRAY_PROGRAM_ARGS_HPP

#include <speed/speed.hpp>


namespace file2array {


/**
 * @brief       All the arguments that are forwarded to the program class.
 */
struct program_args
{
    spd::fsys::r_regular_file_path input_file_pth;
    spd::fsys::output_regular_file_path output_file_pth;
    std::string array_nme;
    std::uint8_t right_margin_len = 100;
};


}


#endif
