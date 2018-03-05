# echo "--------------------------------------10K map"
# ./lem-in < maps/10K_map.txt
echo "--------------------------------------empty file"
./lem-in < maps/empty_file
echo "--------------------------------------bad end"
./lem-in < maps/err_bad_end.txt
echo "--------------------------------------bad end 2"
./lem-in < maps/err_bad_end2.txt
echo "--------------------------------------bad start"
./lem-in < maps/err_bad_start.txt
echo "--------------------------------------bad start 2"
./lem-in < maps/err_bad_start2.txt
echo "--------------------------------------double pipe"
./lem-in < maps/err_double_pipe.txt
echo "--------------------------------------double room name"
./lem-in < maps/err_double_room_name.txt
echo "--------------------------------------empty map"
./lem-in < maps/err_empty_map.txt
echo "--------------------------------------letter in ants"
./lem-in < maps/err_letter_in_ants.txt
echo "--------------------------------------letter in coord"
./lem-in < maps/err_letter_in_coords.txt
echo "--------------------------------------many comments"
./lem-in < maps/err_many_comments.txt
echo "--------------------------------------negative ant nb"
./lem-in < maps/err_neg_ants.txt
echo "--------------------------------------no end"
./lem-in < maps/err_no_end.txt
echo "--------------------------------------no pipe"
./lem-in < maps/err_no_pipes.txt
echo "--------------------------------------no rooms"
./lem-in < maps/err_no_rooms.txt
echo "--------------------------------------no start"
./lem-in < maps/err_no_start.txt
echo "--------------------------------------pipe unknown room"
./lem-in < maps/err_pipe_unknown_room.txt
echo "--------------------------------------start is end"
./lem-in < maps/err_start_end.txt
echo "--------------------------------------coord too big"
./lem-in < maps/err_too_big_coord.txt
echo "--------------------------------------too few ants"
./lem-in < maps/err_too_few_ants.txt
echo "--------------------------------------too many ants"
./lem-in < maps/err_too_many_ants.txt
echo "--------------------------------------map 1"
./lem-in < maps/map_1.txt
echo "--------------------------------------map test"
./lem-in < maps/map_test
echo "--------------------------------------map test 2"
./lem-in < maps/map_test2
echo "--------------------------------------only start and end map"
./lem-in < maps/only_start_end.txt