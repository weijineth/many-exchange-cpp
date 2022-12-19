#pragma once

#include <stdio.h>
#include <assert.h>

#include "../src/base64.h"

using namespace solana;

TEST_CASE("Encode base64") {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  int length = base64::encode("hello", 5, buffer, sizeof(buffer));
  assert(length == 8);
  std::cout << buffer << std::endl;
  assert(memcmp(buffer, "aGVsbG8=", 8) == 0);
}

TEST_CASE("Decode base64") {
  char buffer[1024];
  int length = base64::decode("aGVsbG8=", 8, buffer, sizeof(buffer));
  assert(length == 5);
  assert(memcmp(buffer, "hello", 5) == 0);
}