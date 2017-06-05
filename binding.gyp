{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cc" ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
        'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
        'cflags!': [ '-fno-exceptions' ],
        'cflags_cc!': [ '-fno-exceptions' ],
        'xcode_settings': {
            "OTHER_CPLUSPLUSFLAGS" : [ "-std=c++11", "-stdlib=libc++" ],
              "OTHER_LDFLAGS": [ "-stdlib=libc++" ],
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'CLANG_CXX_LIBRARY': 'libc++',
            'MACOSX_DEPLOYMENT_TARGET': '10.8'
        },
        'msvs_settings': {
            'VCCLCompilerTool': { 'ExceptionHandling': 1 },
        }
    }
  ]
}