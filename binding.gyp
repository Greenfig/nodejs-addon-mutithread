{

    'conditions': [
        ['OS=="win"', {
            "targets": [
                {
                    "target_name": "addon",
                    "include_dirs": [
                        "./header",
                        "./src"
                    ],
                    "sources": [
                        "./src/addon.cpp",
                    ],
                    "configurations": {
                        "Debug": {
                            'msvs_settings': {
                                'VCCLCompilerTool': {
                                    'AdditionalOptions': ['/openmp', '/VERBOSE:LIB', '/W4']
                                }
                            }
                        },
                        "Release": {
                            'msvs_settings': {
                                'VCCLCompilerTool': {
                                    'AdditionalOptions': ['/MT', '/Ox', '/openmp', '/W4']
                                }
                            }
                        }
                    }
                }]
        }]
    ]
}
