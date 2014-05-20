#pragma once

#include "Stdafx.h"
#include "StringHelper.h"

using namespace System;

typedef struct _Person {
  bool IsMale;
  int Age;
  char* Name;
  char** Languages;
  int LanguagesLength;

  _Person(bool isMale, int age, String^ name, ...array<String^>^ languages) {
    IsMale = isMale;
    Age = age;
    Name = StringHelper::ToUnmanaged(name);

    if( languages->Length > 0 ) {
      Languages = new char*[languages->Length];
      LanguagesLength = languages->Length;
    }

    auto languageIndex = 0;
    for each(auto language in languages) {
      Languages[languageIndex++] = StringHelper::ToUnmanaged(language);
    }
  }

  ~_Person() {
    Console::WriteLine("Releasing person {0}", gcnew String(Name));
  }

} Person, *PersonPtr;