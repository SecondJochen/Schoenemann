/*
  This file is part of the Schoenemann chess engine written by Jochengehtab

  Copyright (C) 2024-2025 Jochengehtab

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "tt.h"

#include <cstring>

void tt::storeHash(const std::uint64_t key, const std::uint8_t depth, const std::uint8_t type,
                         const std::int16_t score, const Move move,
                         const std::int16_t eval) const noexcept {
    // Get the HashNode
    Hash *node = table + key % size;

    // Store the entry
    node->setEntry(key, depth, type, score, move, eval);
}

Hash *tt::getHash(const std::uint64_t zobristKey) const noexcept {
    // Check if we got the key in our Hash
    if (Hash *node = table + zobristKey % size; node->key == zobristKey) {
        return node;
    }

    // Returns a nullptr if nothing was found in the hash
    return nullptr;
}

void tt::clear() const {
    memset(table, 0, size * sizeof(Hash));
}

void tt::init(const std::uint64_t MB) {
    const std::uint64_t bytes = MB << 20;
    size = bytes / sizeof(Hash);

    table = static_cast<Hash *>(calloc(size, sizeof(Hash)));
}

void tt::setSize(const std::uint64_t MB) {
    free(table);
    init(MB);
}

int tt::estimateHashfull() const noexcept {
    int used = 0;

    for (std::uint16_t i = 0; i < 1000; i++) {
        used += table[i].move == Move::NO_MOVE;
    }

    return used;
}

tt::tt(const std::uint64_t MB) {
    init(MB);
}

tt::~tt() {
    free(table);
}
