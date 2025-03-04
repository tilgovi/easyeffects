/*
 *  Copyright © 2017-2022 Wellington Wallace
 *
 *  This file is part of EasyEffects.
 *
 *  EasyEffects is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  EasyEffects is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with EasyEffects.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef BASS_LOUDNESS_HPP
#define BASS_LOUDNESS_HPP

#include "lv2_wrapper.hpp"
#include "plugin_base.hpp"

class BassLoudness : public PluginBase {
 public:
  BassLoudness(const std::string& tag,
               const std::string& schema,
               const std::string& schema_path,
               PipeManager* pipe_manager);
  BassLoudness(const BassLoudness&) = delete;
  auto operator=(const BassLoudness&) -> BassLoudness& = delete;
  BassLoudness(const BassLoudness&&) = delete;
  auto operator=(const BassLoudness&&) -> BassLoudness& = delete;
  ~BassLoudness() override;

  void setup() override;

  void process(std::span<float>& left_in,
               std::span<float>& right_in,
               std::span<float>& left_out,
               std::span<float>& right_out) override;

  auto get_latency_seconds() -> float override;

 private:
  std::unique_ptr<lv2::Lv2Wrapper> lv2_wrapper;
};

#endif
