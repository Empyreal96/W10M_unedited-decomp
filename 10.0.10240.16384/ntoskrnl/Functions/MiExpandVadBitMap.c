// MiExpandVadBitMap 
 
int __fastcall MiExpandVadBitMap(unsigned int a1, int a2, int a3, int a4)
{
  int v5; // r8
  int v7; // r9
  int v8; // r7
  int v9; // r4
  unsigned int v10; // r0
  int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r0
  int v14; // r1
  int v15[8]; // [sp+0h] [bp-20h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v5 = MEMORY[0xC0402114] + 8 * (MEMORY[0xC040212C] + 1069547520);
  if ( a1 > MEMORY[0xC040211C] - v5 + 1 )
    return sub_7F5528();
  v7 = MEMORY[0xC040212C] + (MEMORY[0xC0402114] >> 3);
  v8 = MEMORY[0xC0402114] + 8 * MEMORY[0xC040212C];
  if ( MiMakeHyperRangeAccessible(v7, MEMORY[0xC040212C] + ((MEMORY[0xC0402114] + a1 - 1) >> 3), v15) < 0 )
    return 0;
  v9 = v15[0];
  MEMORY[0xC0402118] += v15[0];
  do
    v10 = __ldrex(&dword_634DA4);
  while ( __strex(v10 + v9, &dword_634DA4) );
  if ( v7 == -1069547520 )
  {
    MEMORY[0xC0400000] |= 1u;
    if ( MEMORY[0xC0402114] )
      MEMORY[0xC0402104] = 1;
    MEMORY[0xC0402108] = 1;
    MEMORY[0xC040210C] = 0;
  }
  v11 = ((a1 & 0x1F) != 0) + (a1 >> 5);
  v12 = (((4 * (_WORD)v11) & 0xFFF) != 0) + ((unsigned int)(4 * v11) >> 12);
  v13 = v5 + (v12 << 15);
  v14 = MEMORY[0xC0402114] + (v12 << 15);
  MEMORY[0xC0402114] = v14;
  if ( v13 > MEMORY[0xC040211C] + 1 )
    MEMORY[0xC0402114] = v14 - v13 + MEMORY[0xC040211C] + 1;
  MiUpdateVadBits(v8 << 16, (v12 << 31) + (v8 << 16));
  return 1;
}
