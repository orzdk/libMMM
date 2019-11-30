# Work in progress...


// Tested config strings
//--------------------------

// 03, 01, Cable, Cable 00, Slot 00, Function 01, Offset 12, y, z, d, s, c
// 03, 01, Cable, Cable 00, Slot 01, Function 08, Set channel to 11 (0B), y, z, d, s, c
// 03, 01, Cable, Cable 01, Slot 00, Function 01, Offset 24, y, z, d, s, c
// Route cable 0,1,2,3 to jack 0 (Board 1 TX/RX 1)
// Route cable 0,1,2,3 to jack 1 (Board 1 TX/RX 2)

F0 77 77 78 0F 03 01 00 00 00 01 12 00 00 00 00 00 F7
F0 77 77 78 0F 03 01 00 00 01 08 0B 00 00 00 00 00 F7
F0 77 77 78 0F 03 01 00 01 00 01 24 00 00 00 00 00 F7
F0 77 77 78 0F 01 00 00 01 00 F7
F0 77 77 78 0F 01 00 01 01 00 F7
F0 77 77 78 0F 01 00 02 01 00 F7
F0 77 77 78 0F 01 00 03 01 00 F7
F0 77 77 78 0F 01 00 00 01 01 F7
F0 77 77 78 0F 01 00 01 01 01 F7
F0 77 77 78 0F 01 00 02 01 01 F7
F0 77 77 78 0F 01 00 03 01 01 F7
