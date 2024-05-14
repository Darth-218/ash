/* change-pos.cpp --- change your position in the directory tree
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: alchemistsGestalt
 * Maintaner: alchemistsGestalt
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 * Homepage: https://github.com/darth-218/ash
 *
 * Code:
 */

#include "ash.hpp"

auto change_pos(std::string new_dir) -> int {
    std::filesystem::current_path(new_dir);
    /* Is that it? */

     /* NOTE: my IDE is giving me a warning that `std` has no member named
      *       `filesystem`.
      */
    return 0;
}
