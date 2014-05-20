require 'ffi'

module Library
  extend FFI::Library

  ffi_lib File.join(File.dirname(__FILE__), 'Debug/Hello.Net.FromRuby.dll')

  class Person < FFI::Struct

    # this layout needs to match exactly with the C++ side
    layout :is_male, :bool,
      :age, :int,
      :name, :string,
      :languages, :pointer,
      :number_of_languages, :int

    def male?
      self[:is_male]
    end

    def age
      self[:age]
    end

    def name
      self[:name]
    end

    def languages
      # read the char ** individually
      self[:number_of_languages].times.collect do |index|
        pointer = (self[:languages] + (index * FFI::Type::POINTER.size)).read_pointer
        pointer.read_string
      end
    end

  end

  attach_function :get_information, :Get_Information, [], Person.by_ref
  attach_function :hello, :Hello_DotNet_FromRuby, [:string], :void
end

