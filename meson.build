project('tetras', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])


raylib_dep = dependency('raylib')

src = [
  'src/main.cpp',
  'src/grid.cpp',
  'src/colors.cpp',
  'src/position.cpp',
  'src/blocks.cpp',
  'src/block.cpp',
]

exe = executable('tetras', src,
  dependencies : [raylib_dep],
  install : true)

test('basic', exe)
