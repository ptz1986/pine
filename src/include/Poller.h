/**
 * @file Poller.h
 * @author 冯岳松 (yuesong-feng@foxmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-04
 *
 * @copyright Copyright (冯岳松) 2022
 *
 */
#pragma once

#define OS_LINUX

#ifdef OS_LINUX
#include <sys/epoll.h>
#endif

#ifdef OS_MACOS
#include <sys/event.h>
#endif

#include "Macros.h"

#include <vector>

class Channel;
class Poller {
 public:
  Poller();
  ~Poller();

  DISALLOW_COPY_AND_MOVE(Poller);

  void UpdateChannel(Channel *ch);
  void DeleteChannel(Channel *ch);

  std::vector<Channel *> Poll(int timeout = -1);

 private:
  int fd_{1};
#ifdef OS_LINUX
  struct epoll_event *events_{nullptr};
#endif
};