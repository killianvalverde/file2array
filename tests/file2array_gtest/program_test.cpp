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
 * @file        file2array_gtest/program_test.cpp
 * @brief       program unit test.
 * @author      Killian Valverde
 * @date        2024/10/25
 */

#include <gtest/gtest.h>

#include "file2array/program.hpp"


TEST(file2array_program, execute)
{
    int ret = -1;
    file2array::program_args prog_args;
    prog_args.input_file_pth = "HoYoverse - 018.png";
    prog_args.output_file_pth = "array.txt";
    
    file2array::program prog(std::move(prog_args));
    
    EXPECT_NO_THROW(ret = prog.execute());
    EXPECT_TRUE(ret == 0);
}
