#pragma once
#include "Person.h"

using namespace System;

extern "C" {
  _declspec(dllexport) void Hello_DotNet_FromRuby(const char* message);
  __declspec(dllexport) PersonPtr Get_Information();
}
