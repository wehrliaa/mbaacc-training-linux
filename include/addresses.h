// addresses.h: Memory addresses of every single thing in the universe

// Game state-related values

// Save state-related values
// キャラクター構造体のサイズを定義
const DWORD PLR_STRUCT_SIZE = 0xAFC; // 3084 bytes
// 1Pデータの開始位置を定義
const DWORD DAT_P1_AD = 0x155140; // 971 bytes
const DWORD aCam1X = 0x164B14; // 4 bytes
const DWORD aCam2X = 0x15DEC4; // 4 bytes
const DWORD aCam1Y = 0x164B18; // 4 bytes
const DWORD aCam2Y = 0x15DEC8; // 4 bytes
const DWORD aObjects = 0x27BD70; // 74576 bytes
const DWORD aStoppageStatus = 0x158600; // 1632 bytes
const DWORD aDamage = 0x157DD8; // 52 bytes
const DWORD aDamage2 = 0x157E10; // 1004 bytes
const DWORD aShiftControlFlag1 = 0x157DB8; // 4 bytes
const DWORD aShiftControlFlag2 = 0x157DBC; // 4 bytes
//const DWORD dwDmp_data = self.DAT_P1_AD; // 971 bytes
//const DWORD dwDmp_data = self.DAT_P1_AD + (self.PLR_STRUCT_SIZE * 1); // 971 bytes
//const DWORD dwDmp_data = self.DAT_P1_AD + (self.PLR_STRUCT_SIZE * 2); // 971 bytes
//const DWORD dwDmp_data = self.DAT_P1_AD + (self.PLR_STRUCT_SIZE * 3); // 971 bytes
