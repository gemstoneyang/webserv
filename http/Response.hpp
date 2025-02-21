#ifndef __RESPONSE_HPP__
#define __RESPONSE_HPP__

#include <cstring>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#include "../utils/Config.hpp"
#include "../utils/Enum.hpp"
#include "../utils/StatusException.hpp"

// HTTP Response 클래스
class Response {
 private:
  std::string _responseContent;
  size_t _startIndex;

  std::string _httpVersion;
  int _statusCode;
  std::map<std::string, std::string> _header;
  std::string _body;

 public:
  Response(void);
  Response(Response const& response);
  ~Response(void);

  Response& operator=(Response const& response);

  void print(void) const;  // debug

  std::string const& getHttpVersion(void) const;
  int const& getStatusCode(void) const;
  std::map<std::string, std::string> const& getHeader(void) const;
  std::string const& getBody(void) const;
  size_t getStartIndex(void) const;

  std::string const& toString(void) const;

  void makeResponseContent(void);

  void setHttpVersion(std::string const& httpVersion);
  void setStatusCode(int const& statusCode);
  void setStartIndex(size_t const& startIndex);

  void addHeader(std::string const& fieldName, std::string const& fieldValue);
  void appendBody(std::string const& body);

  void clear(void);

  bool isHeaderFieldNameExists(std::string const& fieldName) const;

 private:
};

#endif
