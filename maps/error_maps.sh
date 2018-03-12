echo "--------------------------------------empty file"
./lem-in < maps/errors/empty_file
echo "--------------------------------------bad end"
./lem-in < maps/errors/err_bad_end.txt
echo "--------------------------------------bad end 2"
./lem-in < maps/errors/err_bad_end2.txt
echo "--------------------------------------bad start"
./lem-in < maps/errors/err_bad_start.txt
echo "--------------------------------------bad start 2"
./lem-in < maps/errors/err_bad_start2.txt
echo "--------------------------------------start is end"
./lem-in < maps/errors/err_start_is_end.txt
echo "--------------------------------------room defined after link"
./lem-in < maps/errors/err_part2_before_part1.txt
echo "--------------------------------------duplicate start"
./lem-in < maps/errors/err_double_start.txt
echo "--------------------------------------duplicate end"
./lem-in < maps/errors/err_double_end.txt
echo "--------------------------------------double link"
./lem-in < maps/errors/err_double_link.txt
echo "--------------------------------------double room name"
./lem-in < maps/errors/err_double_room_name.txt
echo "--------------------------------------empty map"
./lem-in < maps/errors/err_empty_map.txt
echo "--------------------------------------letter in ants"
./lem-in < maps/errors/err_letter_in_ants.txt
echo "--------------------------------------letter in coord"
./lem-in < maps/errors/err_letter_in_coords.txt
echo "--------------------------------------negative ant nb"
./lem-in < maps/errors/err_neg_ants.txt
echo "--------------------------------------no end"
./lem-in < maps/errors/err_no_end.txt
echo "--------------------------------------no link"
./lem-in < maps/errors/err_no_link.txt
echo "--------------------------------------no rooms"
./lem-in < maps/errors/err_no_rooms.txt
echo "--------------------------------------no start"
./lem-in < maps/errors/err_no_start.txt
echo "--------------------------------------link unknown room"
./lem-in < maps/errors/err_link_unknown_room.txt
echo "--------------------------------------start is end"
./lem-in < maps/errors/err_start_end.txt
echo "--------------------------------------too few ants"
./lem-in < maps/errors/err_too_few_ants.txt
echo "--------------------------------------too many ants"
./lem-in < maps/errors/err_too_many_ants.txt
echo "--------------------------------------duplicate room"
./lem-in < maps/errors/err_duplicate.txt
echo "--------------------------------------no path"
./lem-in < maps/errors/err_no_path.txt
echo "---------------------------------------------"