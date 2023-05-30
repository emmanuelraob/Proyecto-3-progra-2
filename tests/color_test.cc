#include "color.hh"
#include "vec3.hh"
#include "gtest/gtest.h"
#include <sstream>
// Keylor
// Este test fue hecho completamente por Chatgpt, literalmente se copio y se
// pego el codigo, el test fue valido y correcto
TEST(Color_Test, Test_Write_Color_Chatgpt) {
  std::ostringstream out;
  color pixel_color(0.7, 0.6, 0.5);
  write_color(out, pixel_color, 100);

  int r = static_cast<int>(256 * clamp(sqrt(0.7 / 100), 0.0, 0.999));
  int g = static_cast<int>(256 * clamp(sqrt(0.6 / 100), 0.0, 0.999));
  int b = static_cast<int>(256 * clamp(sqrt(0.5 / 100), 0.0, 0.999));

  std::string expected_output = std::to_string(r) + " " + std::to_string(g) +
                                " " + std::to_string(b) + "\n";
  EXPECT_EQ(out.str(), expected_output);
}
