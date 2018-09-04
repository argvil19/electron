// Copyright (c) 2018 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_API_FILE_OUTPUT_STREAM_H_
#define ATOM_COMMON_API_FILE_OUTPUT_STREAM_H_

#include "base/files/file.h"
#include "base/files/file_path.h"
#include "v8/include/v8-profiler.h"

namespace atom {

class FileOutputStream : public v8::OutputStream {
 public:
  explicit FileOutputStream(const base::FilePath& file_path);

  bool IsValid() const;
  bool IsComplete() const;

  // v8::OutputStream
  virtual int GetChunkSize();
  virtual void EndOfStream();
  virtual v8::OutputStream::WriteResult WriteAsciiChunk(char* data, int size);

 private:
  base::File file_;
  bool is_complete_ = false;
};

}  // namespace atom

#endif  // ATOM_COMMON_API_FILE_OUTPUT_STREAM_H_
