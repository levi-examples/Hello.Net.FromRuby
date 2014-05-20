#include "stdafx.h"

#include "Hello.Net.FromRuby.h"

void Hello_DotNet_FromRuby(const char* toWhom) {
  Console::WriteLine("Hello, {0}!", gcnew String(toWhom));
}