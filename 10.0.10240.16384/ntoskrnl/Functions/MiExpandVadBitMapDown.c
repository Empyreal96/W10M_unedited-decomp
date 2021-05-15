// MiExpandVadBitMapDown 
 
int __fastcall MiExpandVadBitMapDown(unsigned int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r7
  int v6; // r3
  unsigned int v7; // r6
  unsigned int v8; // r8
  unsigned int v9; // r4
  unsigned int v10; // r0
  int v11; // r3
  unsigned int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  v4 = MEMORY[0xC040212C] + 1069547520;
  if ( a1 > 8 * (MEMORY[0xC040212C] + 1069547520) )
    return 0;
  v6 = ((a1 & 0x1F) != 0) + (a1 >> 5);
  v7 = (((4 * (_WORD)v6) & 0xFFF) != 0) + ((unsigned int)(4 * v6) >> 12);
  v8 = MEMORY[0xC040212C] - (v7 << 12);
  if ( MiMakeHyperRangeAccessible(v8, MEMORY[0xC040212C] - 1, v12) < 0 )
    return 0;
  v9 = v12[0];
  MEMORY[0xC0402118] += v12[0];
  do
    v10 = __ldrex(&dword_634DA4);
  while ( __strex(v10 + v9, &dword_634DA4) );
  MEMORY[0xC040212C] = v8;
  MEMORY[0xC0402114] += v7 << 15;
  v11 = 8 * v4 - (v7 << 15);
  if ( v8 == -1069547520 )
  {
    MEMORY[0xC0400000] |= 1u;
    v11 = 1;
  }
  MEMORY[0xC0402104] = v11;
  MEMORY[0xC0402108] = v11;
  MEMORY[0xC040210C] = 0;
  MiUpdateVadBits(MEMORY[0xC040212C] << 19, (v7 << 31) + (MEMORY[0xC040212C] << 19));
  return 1;
}
