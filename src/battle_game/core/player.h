#pragma once
#include "buff.h"
#include "cstdint"
#include "input_data.h"

namespace battle_game {
class GameCore;
class Player {
 public:
  Player(GameCore *game_core, uint32_t id);
  [[nodiscard]] uint32_t GetId() const {
    return id_;
  }
  void SetInputData(const InputData &input_data) {
    input_data_ = input_data;
  }
  [[nodiscard]] const InputData &GetInputData() const {
    return input_data_;
  }
  [[nodiscard]] uint32_t GetPrimaryUnitId() const {
    return primary_unit_id_;
  }
  int &SelectedUnit() {
    return selected_unit_;
  }
  bool InBuff(int buff) {
    return !(buffs_.find(buff) == buffs_.end()) && buffs_[buff].size();
  }
  int GetBuffLayer(int buff) {
    return buffs_[buff].size();
  }
  uint32_t GetBuffTime(int buff, int layer) {
    return buffs_[buff][layer];
  }

  void RebirthUpdateBuff();
  void UpdateBuff();
  void AddBuff(int buff);
  void Update();
  [[nodiscard]] uint32_t GetResurrectionCountDown() const {
    return resurrection_count_down_;
  }

 private:
  GameCore *game_core_{};
  uint32_t id_{};
  InputData input_data_{};
  uint32_t primary_unit_id_{};
  uint32_t resurrection_count_down_{1};
  int selected_unit_{0};
  std::map<int, std::vector<uint32_t>> buffs_;
  std::vector<battle_game::Buff> bufflist_;
};
}  // namespace battle_game