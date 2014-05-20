require 'ffi'

module Library
  extend FFI::Library

  ffi_lib File.join(File.dirname(__FILE__), 'Debug/Hello.Net.FromRuby.dll')

  attach_function :hello, :Hello_DotNet_FromRuby, [:string], :void
end
