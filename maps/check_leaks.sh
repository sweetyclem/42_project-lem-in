echo "-------------------------------------- 1"
valgrind ./lem-in < maps/1.map
echo "-------------------------------------- 2"
valgrind ./lem-in < maps/2.map
echo "-------------------------------------- 3"
valgrind ./lem-in < maps/3.map
echo "-------------------------------------- 4"
valgrind ./lem-in < maps/4.map
echo "-------------------------------------- 5"
valgrind ./lem-in < maps/5.map
echo "-------------------------------------- 6"
valgrind ./lem-in < maps/6.map
echo "-------------------------------------- 7"
valgrind ./lem-in < maps/7.map
echo "-------------------------------------- 9- 1 ant"
valgrind ./lem-in < maps/9_path_depth_1_ant.map
echo "-------------------------------------- 9- 9 ant"
valgrind ./lem-in < maps/9_path_depth_9_ants.map
echo "-------------------------------------- 10"
valgrind ./lem-in < maps/10.map
echo "-------------------------------------- 10 lots of comments"
valgrind ./lem-in < maps/10_lots_of_comments.map
echo "-------------------------------------- bad line after map"
valgrind ./lem-in < maps/bad_line_after.map
echo "-------------------------------------- sujet 1"
valgrind ./lem-in < maps/sujet1.map
echo "-------------------------------------- sujet 2"
valgrind ./lem-in < maps/sujet2.map
echo "-------------------------------------- sujet 3"
valgrind ./lem-in < maps/sujet3.map
echo "--------------------------------------empty file"
valgrind ./lem-in < maps/errors/empty_file
echo "--------------------------------------bad end"
valgrind ./lem-in < maps/errors/err_bad_end.txt
echo "--------------------------------------bad end 2"
valgrind ./lem-in < maps/errors/err_bad_end2.txt
echo "--------------------------------------bad start"
valgrind ./lem-in < maps/errors/err_bad_start.txt
echo "--------------------------------------bad start 2"
valgrind ./lem-in < maps/errors/err_bad_start2.txt
echo "--------------------------------------start is end"
valgrind ./lem-in < maps/errors/err_start_is_end.txt
echo "--------------------------------------room defined after link"
valgrind ./lem-in < maps/errors/err_part2_before_part1.txt
echo "--------------------------------------duplicate start"
valgrind ./lem-in < maps/errors/err_double_start.txt
echo "--------------------------------------duplicate end"
valgrind ./lem-in < maps/errors/err_double_end.txt
echo "--------------------------------------double link"
valgrind ./lem-in < maps/errors/err_double_link.txt
echo "--------------------------------------double room name"
valgrind ./lem-in < maps/errors/err_double_room_name.txt
echo "--------------------------------------empty map"
valgrind ./lem-in < maps/errors/err_empty_map.txt
echo "--------------------------------------letter in ants"
valgrind ./lem-in < maps/errors/err_letter_in_ants.txt
echo "--------------------------------------letter in coord"
valgrind ./lem-in < maps/errors/err_letter_in_coords.txt
echo "--------------------------------------negative ant nb"
valgrind ./lem-in < maps/errors/err_neg_ants.txt
echo "--------------------------------------no end"
valgrind ./lem-in < maps/errors/err_no_end.txt
echo "--------------------------------------no link"
valgrind ./lem-in < maps/errors/err_no_link.txt
echo "--------------------------------------no rooms"
valgrind ./lem-in < maps/errors/err_no_rooms.txt
echo "--------------------------------------no start"
valgrind ./lem-in < maps/errors/err_no_start.txt
echo "--------------------------------------link unknown room"
valgrind ./lem-in < maps/errors/err_link_unknown_room.txt
echo "--------------------------------------start is end"
valgrind ./lem-in < maps/errors/err_start_end.txt
echo "--------------------------------------too few ants"
valgrind ./lem-in < maps/errors/err_too_few_ants.txt
echo "--------------------------------------too many ants"
valgrind ./lem-in < maps/errors/err_too_many_ants.txt
echo "--------------------------------------duplicate room"
valgrind ./lem-in < maps/errors/err_duplicate.txt
echo "--------------------------------------no path"
valgrind ./lem-in < maps/errors/err_no_path.txt
echo "---------------------------------------------"

# sh maps/check_leaks.sh 2> leaks.txt
# grep -r "indirectly" leaks.txt
# grep -r "definitely" leaks.txt