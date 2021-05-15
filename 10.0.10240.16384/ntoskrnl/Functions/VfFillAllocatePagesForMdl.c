// VfFillAllocatePagesForMdl 
 
_DWORD *__fastcall VfFillAllocatePagesForMdl(_DWORD *result, int a2, char a3)
{
  int v3; // r4
  unsigned int v4; // r5
  unsigned int v5; // r6
  int v6; // r8
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r7
  int v10; // r2

  v3 = (int)result;
  if ( (a3 & 1) != 0 && a2 == 1 )
  {
    v4 = result[5];
    v5 = 4096;
    v6 = result[3];
    result[5] = 4096;
    result = (_DWORD *)MmMapLockedPagesSpecifyCache((int)result, 0, 1, 0, 0, 16);
    v9 = (unsigned int)result;
    if ( result )
    {
      if ( v4 < 0x1000 )
        v5 = v4;
      VfFillAllocatedMemory(result, v5, v7, v8);
      result = MmUnmapLockedPages(v9, v3, v10);
      *(_DWORD *)(v3 + 12) = v6;
    }
    *(_DWORD *)(v3 + 20) = v4;
  }
  return result;
}
