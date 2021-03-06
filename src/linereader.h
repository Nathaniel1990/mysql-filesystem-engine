#include <my_global.h>
#include <sys/types.h>
#include <sys/stat.h>

class String;

class LineReader {
  const char *path_;
  byte *buffer_;
  off_t buffer_size_;
  off_t current_offset_;
  off_t _NextLineOffset(off_t whence);

 public:
  LineReader(const char *path) : path_(path), buffer_(NULL), 
				 buffer_size_(0), current_offset_(-1) { };
  ~LineReader() { delete[] buffer_; };

  int Open();
  int Opened() const { return buffer_ != NULL; };
  void Advance();
  void CurrentLine(String *into);
  void LineAt(off_t offset, String *into);
  off_t CurrentOffset();
  off_t LastOffset();
};
