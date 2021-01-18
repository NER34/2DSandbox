cxx = g++
cxxflags = -std=c++14 -Wall -pedantic -Wno-long-long -g
plc = src/
psx = -lSDL2
name = plotnpav

all: compile doc

run: compile doc
	./$(name)

compile: $(name)

doc: $(plc)air.h $(plc)dirt.h $(plc)grass.h $(plc)iblock.h $(plc)ifishing_row.h $(plc)ifood.h $(plc)inventory.h $(plc)itree.h $(plc)lava.h $(plc)leaves.h $(plc)menu.h $(plc)map.h $(plc)mouse.h $(plc)parent_block.h $(plc)parent_item.h $(plc)person.h $(plc)run_lava.h $(plc)run_lava1.h $(plc)run_lava2.h $(plc)run_water.h $(plc)run_water1.h $(plc)run_water2.h $(plc)stone.h $(plc)tree.h $(plc)water.h $(plc)wood.h $(plc)game.h $(plc)player.h $(plc)enemy.h
	doxygen Doxyfile
	mv doc/html/* doc/
	rm -r doc/html

$(name): air.o dirt.o grass.o iblock.o ifishing_row.o ifood.o inventory.o itree.o lava.o leaves.o main.o menu.o map.o mouse.o parent_block.o parent_item.o person.o run_lava.o run_lava1.o run_lava2.o run_water.o run_water1.o run_water2.o stone.o tree.o water.o wood.o movement.o draw.o game.o player.o enemy.o
	$(cxx) $^ -o $@ $(psx)

air.o: $(plc)air.cpp $(plc)air.h
	$(cxx) $(cxxflags) -c $< -o $@

dirt.o: $(plc)dirt.cpp $(plc)dirt.h
	$(cxx) $(cxxflags) -c $< -o $@

grass.o: $(plc)grass.cpp $(plc)grass.h
	$(cxx) $(cxxflags) -c $< -o $@

iblock.o: $(plc)iblock.cpp $(plc)iblock.h
	$(cxx) $(cxxflags) -c $< -o $@

ifishing_row.o: $(plc)ifishing_row.cpp $(plc)ifishing_row.h
	$(cxx) $(cxxflags) -c $< -o $@

ifood.o: $(plc)ifood.cpp $(plc)ifood.h
	$(cxx) $(cxxflags) -c $< -o $@

inventory.o: $(plc)inventory.cpp $(plc)inventory.h
	$(cxx) $(cxxflags) -c $< -o $@

itree.o: $(plc)itree.cpp $(plc)itree.h
	$(cxx) $(cxxflags) -c $< -o $@

lava.o: $(plc)lava.cpp $(plc)lava.h
	$(cxx) $(cxxflags) -c $< -o $@

leaves.o: $(plc)leaves.cpp $(plc)leaves.h
	$(cxx) $(cxxflags) -c $< -o $@

main.o: $(plc)main.cpp $(plc)menu.h
	$(cxx) $(cxxflags) -c $< -o $@

menu.o: $(plc)menu.cpp $(plc)menu.h
	$(cxx) $(cxxflags) -c $< -o $@

map.o: $(plc)map.cpp $(plc)map.h
	$(cxx) $(cxxflags) -c $< -o $@

mouse.o: $(plc)mouse.cpp $(plc)mouse.h
	$(cxx) $(cxxflags) -c $< -o $@

parent_block.o: $(plc)parent_block.cpp $(plc)parent_block.h
	$(cxx) $(cxxflags) -c $< -o $@

parent_item.o: $(plc)parent_item.cpp $(plc)parent_item.h
	$(cxx) $(cxxflags) -c $< -o $@

person.o: $(plc)person.cpp $(plc)person.h
	$(cxx) $(cxxflags) -c $< -o $@

run_lava.o: $(plc)run_lava.cpp $(plc)run_lava.h
	$(cxx) $(cxxflags) -c $< -o $@

run_lava1.o: $(plc)run_lava1.cpp $(plc)run_lava1.h
	$(cxx) $(cxxflags) -c $< -o $@

run_lava2.o: $(plc)run_lava2.cpp $(plc)run_lava2.h
	$(cxx) $(cxxflags) -c $< -o $@

run_water.o: $(plc)run_water.cpp $(plc)run_water.h
	$(cxx) $(cxxflags) -c $< -o $@

run_water1.o: $(plc)run_water1.cpp $(plc)run_water1.h
	$(cxx) $(cxxflags) -c $< -o $@

run_water2.o: $(plc)run_water2.cpp $(plc)run_water2.h
	$(cxx) $(cxxflags) -c $< -o $@

stone.o: $(plc)stone.cpp $(plc)stone.h
	$(cxx) $(cxxflags) -c $< -o $@

tree.o: $(plc)tree.cpp $(plc)tree.h
	$(cxx) $(cxxflags) -c $< -o $@

water.o: $(plc)water.cpp $(plc)water.h
	$(cxx) $(cxxflags) -c $< -o $@

wood.o: $(plc)wood.cpp $(plc)wood.h
	$(cxx) $(cxxflags) -c $< -o $@

movement.o: $(plc)movement.cpp $(plc)game.h $(plc)blocks.h $(plc)items.h $(plc)persons.h
	$(cxx) $(cxxflags) -c $< -o $@

draw.o: $(plc)draw.cpp $(plc)game.h $(plc)blocks.h $(plc)items.h $(plc)persons.h
	$(cxx) $(cxxflags) -c $< -o $@

game.o: $(plc)game.cpp $(plc)game.h $(plc)blocks.h $(plc)items.h $(plc)persons.h
	$(cxx) $(cxxflags) -c $< -o $@

player.o: $(plc)player.cpp $(plc)player.h
	$(cxx) $(cxxflags) -c $< -o $@
	
enemy.o: $(plc)enemy.cpp $(plc)enemy.h
	$(cxx) $(cxxflags) -c $< -o $@

clean:
	rm *.o $(name)
	rm -rf doc 2>/dev/null

