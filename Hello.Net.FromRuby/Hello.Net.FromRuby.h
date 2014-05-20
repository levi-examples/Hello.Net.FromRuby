#pragma once

using namespace System;

extern "C" {
  _declspec(dllexport) void Hello_DotNet_FromRuby(const char* message);
}
