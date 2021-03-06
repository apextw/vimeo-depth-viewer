#ifndef _MONITOR_WINDOW_H_
#define _MONITOR_WINDOW_H_

// STD
#include <string>
#include <mutex>
#include <unordered_map>
#include <thread>
#include <atomic>
#include <sstream>
#include <cmath>
#include <iomanip>

#include <GLFW/glfw3.h>

// Eigen
#include <Eigen/Core>

// NanoGUI
#include <nanogui/common.h>
#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/label.h>
#include <nanogui/button.h>
#include <nanogui/checkbox.h>
#include <nanogui/messagedialog.h>
#include <nanogui/entypo.h>
#include <nanogui/slider.h>
#include <nanogui/textbox.h>

// Realsense
#include <librealsense2/rs.hpp>

#include "VideoView.h"

class MonitorWindow : public nanogui::Screen
{
public:
  MonitorWindow(const Eigen::Vector2i & size, const std::string & caption);
  bool keyboardEvent(int key, int scancode, int action, int modifiers) override;
  bool resizeEvent(const Eigen::Vector2i & size) override;
  void draw(NVGcontext *ctx) override;
  void setVideoFrame(rs2::frame _color, rs2::frame _depth);

private:
  VideoView *_videoview;
};

#endif //_MONITOR_WINDOW_H_
