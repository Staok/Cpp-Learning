#include <assert.h>
#include <iostream>
#include <sstream>
#include "thread_pool.hpp"

namespace sola 
{
  std::unique_ptr<logger_iface> active_logger = nullptr;


  static const char black[]  = {0x1b, '[', '1', ';', '3', '0', 'm', 0};
  static const char red[]    = {0x1b, '[', '1', ';', '3', '1', 'm', 0};
  static const char yellow[] = {0x1b, '[', '1', ';', '3', '3', 'm', 0};
  static const char blue[]   = {0x1b, '[', '1', ';', '3', '4', 'm', 0};
  static const char normal[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0};

  logger::logger(log_level level):
  :m_level(level) {}

  void
  logger::info()



}