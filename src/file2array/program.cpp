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
 * @file        file2array/program.cpp
 * @brief       program class implementation.
 * @author      Killian Valverde
 * @date        2024/10/25
 */
 
#include <fstream>

#include "program.hpp"


namespace file2array {


program::program(program_args&& prog_args) 
        : prog_args_(std::move(prog_args))
{
}


int program::execute()
{
    std::ifstream ifs(prog_args_.input_file_pth, std::ios::binary);
    std::ofstream ofs(prog_args_.output_file_pth, std::ios::binary);
    std::size_t input_file_size = spd::sys::fsys::get_file_size(prog_args_.input_file_pth.c_str());
    std::ifstream::char_type ch;
    std::uint8_t n_printed_chars = 4;
    
    if (!ifs || !ofs || input_file_size == -1)
    {
        std::cout << spd::ios::set_light_red_text
                  << "Fatal file error."
                  << spd::ios::set_default_text
                  << std::endl;
        
        return 1;
    }
    
    prog_args_.array_nme = sanitize_identifier(prog_args_.array_nme);
    if (prog_args_.array_nme.empty())
    {
        prog_args_.array_nme = sanitize_identifier(remove_extension(
                prog_args_.input_file_pth.filename().native()));
    }
    if (prog_args_.array_nme.empty())
    {
        prog_args_.array_nme = "dat";
    }
    
    if (prog_args_.right_margin_len < 80)
    {
        prog_args_.right_margin_len = 100;
    }
    
    ofs << "std::array<std::uint8_t, " << input_file_size << "> "
        << prog_args_.array_nme
        << "{\n   ";
    
    ofs << std::hex << std::setfill('0');
    
    while (ifs.get(ch))
    {
        if (n_printed_chars >= 95)
        {
            ofs << "\n   ";
            n_printed_chars = 4;
        }
        
        ofs << " 0x" << std::setw(2) << (static_cast<std::uint16_t>(ch) & 0x00FF) << ",";
        n_printed_chars += 6;
    }
    
    ofs.seekp(-1, std::ios_base::cur);
    ofs << "\n};\n";
    
    ifs.close();
    ofs.close();
    
    return 0;
}


}
