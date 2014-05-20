#include "stdafx.h"

#include "Hello.Net.FromRuby.h"

void Hello_DotNet_FromRuby(const char* toWhom) {
  Console::WriteLine("Hello, {0}!", gcnew String(toWhom));
}

_declspec(dllexport) PersonPtr Get_Information() {
  return new Person(true, 34, "Joe Johnston", "English", "Spanish", "Danish");
}
