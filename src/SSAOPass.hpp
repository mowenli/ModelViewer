#pragma once
#include <Eigen/Core>
#include <sokol_gfx.h>
#include <vector>

struct SSAOPass {
  sg_pass pass{};
  sg_pass_action pass_action{};
  sg_pipeline pipeline{};
  sg_bindings bindings{};
  sg_image ao_map{};
  sg_image fake_ao_map{}; // use this if disable ao

  float screen_width = 0.0f;
  float screen_height = 0.0f;
  std::vector<Eigen::Vector3f> ssao_kernel;

  SSAOPass(uint32_t width, uint32_t height, const sg_image &position,
           const sg_image &normal);
  void run(const Eigen::Matrix4f &view_matrix,
           const Eigen::Matrix4f &projection_matrix) const;
};
