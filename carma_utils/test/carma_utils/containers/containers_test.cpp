/*
 * Copyright (C) 2019-2021 LEIDOS.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <carma_utils/containers/containers.h>

namespace carma_utils
{
namespace containers
{
TEST(containers_test, downsample_vector_test)
{
  std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9,10};
  std::vector<int> out = downsample_vector(vec, 3);
  
  ASSERT_EQ(4, out.size());
  ASSERT_EQ(0, out[0]);
  ASSERT_EQ(3, out[1]);
  ASSERT_EQ(6, out[2]);
  ASSERT_EQ(9, out[3]);

  out = downsample_vector(vec, 0);
  ASSERT_EQ(0, out.size());
  out = downsample_vector<int>({}, 4);
  ASSERT_EQ(0, out.size());
}
}  // namespace containers
}  // namespace carma_utils