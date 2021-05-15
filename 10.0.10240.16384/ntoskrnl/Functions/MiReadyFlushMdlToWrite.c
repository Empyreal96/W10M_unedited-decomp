// MiReadyFlushMdlToWrite 
 
int __fastcall MiReadyFlushMdlToWrite(int a1, int a2, char a3)
{
  int v4; // r5
  int v6; // r4
  unsigned int v8; // r1
  int v9; // r8
  int v10; // r0
  int result; // r0

  v4 = a2;
  v6 = 3 * *(_DWORD *)(a1 + 28);
  v8 = *(_DWORD *)(MmPfnDatabase + 8 * v6 + 4) | 0x80000000;
  *(_DWORD *)(a1 + 24) = 0;
  v9 = MiStartingOffset(a2, v8, -1);
  v10 = MiEndingOffsetWithLock(v4);
  *(_WORD *)(a1 + 6) |= 2u;
  if ( (a3 & 8) != 0 )
    return sub_522548(v10);
  result = v9;
  *(_WORD *)(a1 + 4) = ((unsigned int)(4 * *(_DWORD *)(a1 + 20)) >> 12) + 28;
  return result;
}
