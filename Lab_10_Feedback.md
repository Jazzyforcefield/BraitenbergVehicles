### Feedback for Lab 10

Run on March 01, 19:48:13 PM.


#### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

7736ff121c713089298361195f9d491227ed2b06	refs/heads/devel

ac0e383e5b5007aca00575417ee7ee75b4164926	refs/heads/fix/01-compilation-errors

0b5b67b7b9a86386f13ee3e5e27b77cfe2376c45	refs/heads/master

726e6a78bc90651955db2c59a9588b2ce741df0b	refs/heads/support-code



+ Pass: Run git ls-remote to check for # of branches in repo
Sufficient branches (found=4,required=3)


#### Necessary Files and Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


#### Essential Files Exist

+ Pass: Check that directory "project" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".

+ Pass: Check that file "Makefile" exists.


### Test that code compiles and creates the exectuable

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>cd src; make -j
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Lab_10_Feedback/repo-ungxx028/project/src'
==== Auto-Generating Dependencies for controller.cc. ====
==== Auto-Generating Dependencies for braitenberg_vehicle.cc. ====
==== Auto-Generating Dependencies for arena.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/arena.d -MP -MT ../build/obj/src/arena.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 arena.cc
==== Auto-Generating Dependencies for motion_behavior_differential.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/motion_behavior_differential.d -MP -MT ../build/obj/src/motion_behavior_differential.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 motion_behavior_differential.cc
==== Auto-Generating Dependencies for food.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/food.d -MP -MT ../build/obj/src/food.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 food.cc
==== Auto-Generating Dependencies for main.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/main.d -MP -MT ../build/obj/src/main.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 main.cc
==== Auto-Generating Dependencies for rgb_color.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/rgb_color.d -MP -MT ../build/obj/src/rgb_color.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 rgb_color.cc
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/braitenberg_vehicle.d -MP -MT ../build/obj/src/braitenberg_vehicle.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 braitenberg_vehicle.cc
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/controller.d -MP -MT ../build/obj/src/controller.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 controller.cc
==== Auto-Generating Dependencies for motion_behavior.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/motion_behavior.d -MP -MT ../build/obj/src/motion_behavior.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 motion_behavior.cc
==== Auto-Generating Dependencies for graphics_arena_viewer.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/graphics_arena_viewer.d -MP -MT ../build/obj/src/graphics_arena_viewer.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 graphics_arena_viewer.cc
==== Auto-Generating Dependencies for light.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/light.d -MP -MT ../build/obj/src/light.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 light.cc
==== Compiling arena.cc into ../build/obj/src/arena.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/arena.o arena.cc
==== Compiling rgb_color.cc into ../build/obj/src/rgb_color.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/rgb_color.o rgb_color.cc
==== Compiling motion_behavior.cc into ../build/obj/src/motion_behavior.o. ====
==== Compiling food.cc into ../build/obj/src/food.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/food.o food.cc
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/motion_behavior.o motion_behavior.cc
==== Compiling light.cc into ../build/obj/src/light.o. ====
==== Compiling motion_behavior_differential.cc into ../build/obj/src/motion_behavior_differential.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/motion_behavior_differential.o motion_behavior_differential.cc
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/light.o light.cc
==== Compiling braitenberg_vehicle.cc into ../build/obj/src/braitenberg_vehicle.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/braitenberg_vehicle.o braitenberg_vehicle.cc
==== Compiling graphics_arena_viewer.cc into ../build/obj/src/graphics_arena_viewer.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/graphics_arena_viewer.o graphics_arena_viewer.cc
==== Compiling main.cc into ../build/obj/src/main.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/main.o main.cc
==== Compiling controller.cc into ../build/obj/src/controller.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/controller.o controller.cc
In file included from ../src/motion_behavior.h:15:0,
                 from ../src/motion_behavior_differential.h:16,
                 from motion_behavior_differential.cc:10:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/motion_behavior.h:15:0,
                 from motion_behavior.cc:12:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/motion_behavior_differential.h:13:0,
                 from motion_behavior_differential.cc:10:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/braitenberg_vehicle.h:18:0,
                 from braitenberg_vehicle.cc:11:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/light.h:16:0,
                 from light.cc:11:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/motion_behavior.h:13:0,
                 from motion_behavior.cc:12:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/braitenberg_vehicle.h:17:0,
                 from braitenberg_vehicle.cc:11:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/arena_entity.h:18:0,
                 from ../src/arena_mobile_entity.h:16,
                 from ../src/light.h:16,
                 from light.cc:11:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/arena.h:20:0,
                 from arena.cc:14:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/arena.h:18:0,
                 from arena.cc:14:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
cc1plus: all warnings being treated as errors
cc1plus: all warnings being treated as errors
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/motion_behavior_differential.o' failed
make[1]: *** [../build/obj/src/motion_behavior_differential.o] Error 1
make[1]: *** Waiting for unfinished jobs....
Makefile:109: recipe for target '../build/obj/src/motion_behavior.o' failed
make[1]: *** [../build/obj/src/motion_behavior.o] Error 1
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/braitenberg_vehicle.o' failed
make[1]: *** [../build/obj/src/braitenberg_vehicle.o] Error 1
Makefile:109: recipe for target '../build/obj/src/light.o' failed
make[1]: *** [../build/obj/src/light.o] Error 1
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/arena.o' failed
make[1]: *** [../build/obj/src/arena.o] Error 1
In file included from ../src/arena.h:20:0,
                 from ../src/controller.h:17,
                 from main.cc:12:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/arena.h:18:0,
                 from ../src/controller.h:17,
                 from main.cc:12:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/arena.h:20:0,
                 from ../src/controller.h:17,
                 from controller.cc:16:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from controller.cc:15:0:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/arena.h:20:0,
                 from ../src/graphics_arena_viewer.h:15,
                 from graphics_arena_viewer.cc:14:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/arena.h:18:0,
                 from ../src/graphics_arena_viewer.h:15,
                 from graphics_arena_viewer.cc:14:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
cc1plus: all warnings being treated as errors
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/main.o' failed
make[1]: *** [../build/obj/src/main.o] Error 1
Makefile:109: recipe for target '../build/obj/src/graphics_arena_viewer.o' failed
make[1]: *** [../build/obj/src/graphics_arena_viewer.o] Error 1
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/controller.o' failed
make[1]: *** [../build/obj/src/controller.o] Error 1
make[1]: Leaving directory '/class/grades/Spring-2019/csci3081/student-repos/Lab_10_Feedback/repo-ungxx028/project/src'
Makefile:4: recipe for target 'all' failed
make: *** [all] Error 2
</pre>



