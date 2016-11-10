// The MIT License (MIT)
// 
// Copyright (c) 2016 Northeastern University
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in 
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "dnnmark.h"
#include "utitlity.h"
#include "dnn_config_keywords.h"

namespace dnnmark {

//
// Internal data type. Code courtesy of Caffe
//

float DataType<TestType>::oneval = 1.0;
float DataType<TestType>::zeroval = 0.0;
const void* DataType<TestType>::one =
    static_cast<void *>(&DataType<TestType>::oneval);
const void* DataType<TestType>::zero =
    static_cast<void *>(&DataType<TestType>::zeroval);


//
// DNNMark class definition
//

DNNMark::DNNMark()
: run_mode_(NONE) {

}

int DNNMark::ParseAllConfig(string &config_file) {
  std::ifstream is;
  is.open(config_file.c_str(), std::ifstream::in);

  // TODO: insert assert regarding run_mode_

  // TODO: use multithread in the future
  // Parse DNNMark config
  std::string s;
  while (!is.eof()) {
    // Obtain the string in one line
    std::getline(is, s);
    TrimStr(&s);

    // Check the specific configuration section markers
    if (isDNNMarkSection(s))
      continue;
    else if (isSection(s))
      break;

    // Obtain the acutal variable and value
    std::string var;
    std::string val;
    SplitStr(s, &var, &val);
    
  }

  // Parse Data config

  // Parse Conv config

  is.close();
  return 0;
}

// Explicit instantiation
template class DNNMark<TestType>;

} // namespace dnnmark
