//
// Copyright 2021 Santanu Sen. All Rights Reserved.
//
// Licensed under the Apache License 2.0 (the "License").  You may not use
// this file except in compliance with the License.  You can obtain a copy
// in the file LICENSE in the source distribution.
//

#ifndef __CRYPTCPP_SSL_EXCEPTION_HPP__
#define __CRYPTCPP_SSL_EXCEPTION_HPP__

#include "cryptcpp_cpp_std.hpp"
#include <exception>
#include <string>

namespace cryptcpp {

//@{
// @class crypt_exception
// @brief Base class for all exceptions thrown from the cryptcpp library.
//@}
class crypt_exception : public std::exception {

protected:
  //@{
  // Error message associated with the exception.
  //@}
  std::string _M_err_msg;

public:
  //@{
  // @brief Constructor. Initializes the error message.
  // @param msg the string to initialize the error message.
  //@}
  explicit crypt_exception(const std::string &msg) : _M_err_msg(msg) {}

  //@{
  // @brief Returns the error message associated with this exception.
  // @return the error message associated with this exception.
  //@}
  const char *what() const NOEXCEPT OVERRIDE { return _M_err_msg.c_str(); }

  // =============================================================
  //@{
  // @brief Polymorphic base class.
  //@}
  // =============================================================
  virtual ~crypt_exception() NOEXCEPT DFLTDSTR;
};

// =============================================================
//@{
// @brief Exception reporting mechanism. Throw if exceptions
//        are enabled. Else call application provided
//        report_exception function.
//@}
// =============================================================
#ifdef __cpp_exceptions
inline void report_exception(const crypt_exception &cryptexcep) {
  throw cryptexcep;
}
#else
extern void report_exception(const crypt_exception &cryptexcep);
#endif

} // namespace cryptcpp
#endif
