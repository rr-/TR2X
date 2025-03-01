project('TR2X', ['c'],
  default_options: [
    'c_std=c17',
    'warning_level=2',
  ],
)

trx = subproject('libtrx')
c_compiler = meson.get_compiler('c')

build_opts = [
  '-Wno-unused',
  '-DMESON_BUILD',
  '-fno-omit-frame-pointer',
  '-ffile-prefix-map=../../src/=',
]

add_project_arguments(build_opts, language: 'c')

staticdeps = get_option('staticdeps')

null_dep = dependency('', required: false)
dep_trx = trx.get_variable('dep_trx')
dep_sdl2 = dependency('SDL2', static: staticdeps)
dep_mathlibrary = c_compiler.find_library('m', static: staticdeps, required : false)

# autogenerated files
exe_resources = []
dll_resources = []
python3 = find_program('python3', required: true)
git = find_program('git', required: true)

init = custom_target(
  'fake_init',
  output: ['init.c'],
  command: [python3, meson.source_root() + '/tools/generate_init', '-o', meson.current_build_dir() / '@OUTPUT0@'],
  build_always_stale: true,
)

version_rc = custom_target(
  'fake_version',
  output: ['version.rc'],
  command: [python3, meson.source_root() + '/tools/generate_rcfile', '-o', '@OUTPUT0@'],
  build_always_stale: true,
)

icon_rc = custom_target(
  'fake_icon',
  output: ['icon.rc'],
  command: [python3, meson.source_root() + '/tools/generate_rcfile', '-o', '@OUTPUT0@'],
)

link_args = []

if host_machine.system() == 'windows'
  windows = import('windows')

  version_resource = windows.compile_resources(version_rc)
  icon_resource = windows.compile_resources(icon_rc)
  exe_resources = [version_resource, icon_resource]
  dll_resources = [version_resource]

  link_args += ['-static']
endif

exe_sources = [
  'src/main_exe.c',
  exe_resources,
]

dll_sources = [
  init,
  'src/config.c',
  'src/config_map.c',
  'src/decomp/decomp.c',
  'src/decomp/stats.c',
  'src/game/background.c',
  'src/game/box.c',
  'src/game/camera.c',
  'src/game/clock.c',
  'src/game/collide.c',
  'src/game/console.c',
  'src/game/console_cmd.c',
  'src/game/creature.c',
  'src/game/demo.c',
  'src/game/effects.c',
  'src/game/game.c',
  'src/game/gameflow.c',
  'src/game/gun/gun.c',
  'src/game/gun/gun_misc.c',
  'src/game/gun/gun_pistols.c',
  'src/game/gun/gun_rifle.c',
  'src/game/hwr.c',
  'src/game/input.c',
  'src/game/inventory.c',
  'src/game/items.c',
  'src/game/lara/lara_cheat.c',
  'src/game/lara/lara_col.c',
  'src/game/lara/lara_control.c',
  'src/game/lara/lara_draw.c',
  'src/game/lara/lara_look.c',
  'src/game/lara/lara_misc.c',
  'src/game/lara/lara_state.c',
  'src/game/level.c',
  'src/game/los.c',
  'src/game/lot.c',
  'src/game/math.c',
  'src/game/math_misc.c',
  'src/game/matrix.c',
  'src/game/music/music_backend_cdaudio.c',
  'src/game/music/music_backend_files.c',
  'src/game/music/music_main.c',
  'src/game/objects/common.c',
  'src/game/objects/creatures/bird.c',
  'src/game/objects/creatures/diver.c',
  'src/game/objects/general/door.c',
  'src/game/objects/general/final_level_counter.c',
  'src/game/objects/vehicles/boat.c',
  'src/game/option/option.c',
  'src/game/option/option_compass.c',
  'src/game/option/option_controls.c',
  'src/game/option/option_detail.c',
  'src/game/option/option_passport.c',
  'src/game/option/option_sound.c',
  'src/game/output.c',
  'src/game/overlay.c',
  'src/game/random.c',
  'src/game/room.c',
  'src/game/room_draw.c',
  'src/game/shell.c',
  'src/game/sound.c',
  'src/game/text.c',
  'src/global/vars.c',
  'src/inject_exec.c',
  'src/inject_util.c',
  'src/lib/winmm.c',
  'src/main_dll.c',
  'src/specific/s_audio_sample.c',
  'src/specific/s_flagged_string.c',
  'src/specific/s_input.c',
  dll_resources,
]

dll_dependencies = [
  dep_trx,
  dep_sdl2,
  dep_mathlibrary,
]

executable(
  'TR2X',
  exe_sources,
  name_prefix: '',
  include_directories: ['src/'],
  link_args: link_args,
  gui_app: true,
)

library(
  'TR2X',
  dll_sources,
  name_prefix: '',
  include_directories: ['src/'],
  dependencies: dll_dependencies,
  link_args: link_args,
)
