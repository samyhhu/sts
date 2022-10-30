#pragma once

#include <spdlog/spdlog.h>

namespace common
{

class logger_t
{
public:
  logger_t()
  {
    logger_ = spdlog::default_logger();
    logger_->set_pattern("[%Y-%m-%d %H:%M:%S.%F][%L] %v",
                         spdlog::pattern_time_type::utc);
    logger_->set_level(spdlog::level::info);
  }
  // TODO: delete any assignment / copy operator
  static logger_t& instance()
  {
    static std::unique_ptr<logger_t> logger;
    if (logger == nullptr) {
      logger = std::make_unique<logger_t>();
    }
    return *logger.get();
  }
  template<typename T>
  inline void debug(const T& msg) const
  {
    logger_->debug(msg);
  }
  template<typename... T>
  inline void debug(std::string_view fmt, const T&... args) const
  {
    logger_->debug(fmt, args...);
  }
  template<typename T>
  inline void info(const T& msg) const
  {
    logger_->info(msg);
  }
  template<typename... T>
  inline void info(std::string_view fmt, const T&... args) const
  {
    logger_->info(fmt, args...);
  }
  template<typename T>
  inline void error(const T& msg) const
  {
    logger_->error(msg);
  }
  template<typename... T>
  inline void error(std::string_view fmt, const T&... args) const
  {
    logger_->error(fmt, args...);
  }
  template<typename T>
  inline void critical(const T& msg) const
  {
    logger_->critical(msg);
  }
  template<typename... T>
  inline void critical(std::string_view fmt, const T&... args) const
  {
    logger_->critical(fmt, args...);
  }
  std::shared_ptr<spdlog::logger> logger_;
};

#define LOG_DEBUG(...) common::logger_t::instance().debug(__VA_ARGS__)
#define LOG_INFO(...) common::logger_t::instance().info(__VA_ARGS__)
#define LOG_ERROR(...) common::logger_t::instance().error(__VA_ARGS__)
#define LOG_CRITICAL(...) common::logger_t::instance().critical(__VA_ARGS__)

}  // namespace common
