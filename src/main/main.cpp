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
 * @file        main/main.hpp
 * @brief       main entry point.
 * @author      Killian Valverde
 * @date        2024/10/25
 */

#define SPEED_MULTIPLATFORM_MAIN_WITH_UNICODE_SUPPORT
#include <speed/speed.hpp>

#include "../file2array/program.hpp"


int main(int argc, char* argv[])
{
    std::string messge;
    int retv;
    
    try 
    {
        file2array::program_args prog_args;
        spd::ap::arg_parser ap("file2array");
        
        ap.add_help_menu()
                .description("Generates a C++ header file that includes an array representing the "
                             "byte-by-byte content of a specified regular file.");

        ap.add_keyless_arg("INPUT-FILE")
                .description("Input file.")
                .store_into(&prog_args.input_file_pth);

        ap.add_keyless_arg("OUTPUT-FILE")
                .description("Output file.")
                .store_into(&prog_args.output_file_pth);
        
        ap.add_key_value_arg("--array-name", "-n")
                .description("The name of the array in the output file.")
                .store_into(&prog_args.array_nme);
        
        ap.add_key_value_arg("--right-margin-length", "-r")
                .description("The maximum number of columns the output file can contain.")
                .store_into(&prog_args.right_margin_len);
        
        ap.add_help_arg("--help", "-h")
                .description("Display this help and exit.");
                
        ap.add_version_arg("--version", "-v")
                .description("Output version information and exit.")
                .gplv3_version_information("0.0.0", "2024", "Killian Valverde");

        ap.parse_args(argc, argv);
        
        file2array::program prog(std::move(prog_args));
                
        return prog.execute();
    }
    catch (const file2array::exception_base& e)
    {
        messge = e.what();
        retv = 1;
    }
    catch (const std::exception& e)
    {
        messge = e.what();
        retv = -1;
    }
    catch (...)
    {
        messge = "Unknown error";
        retv = -1;
    }
    
    std::cerr << spd::ios::newl
              << spd::ios::set_light_red_text << "file2array: "
              << spd::ios::set_default_text << messge
              << std::endl;

    return retv;
}
