// MiGetKernelStackSwapSupport 
 
int __fastcall MiGetKernelStackSwapSupport(_DWORD *a1, int a2)
{
  int v3; // r5
  unsigned int v4; // r7
  unsigned int v5; // r4
  int v6; // r2
  __int16 v7; // r3
  unsigned int v8; // r4
  int v10; // r0

  v3 = -1;
  v4 = dword_64050C;
  __dmb(0xBu);
  v5 = 0;
  if ( !v4 )
    return -1073741497;
  do
  {
    v6 = *(_DWORD *)&MiSystemPartition[2 * v5 + 1800];
    v7 = *(_WORD *)(v6 + 96);
    if ( (v7 & 0x10) == 0
      && (v7 & 0x40) == 0
      && (v3 == -1 || *(_DWORD *)(v6 + 28) > *(_DWORD *)(*(_DWORD *)&MiSystemPartition[2 * v3 + 1800] + 28)) )
    {
      v3 = v5;
    }
    ++v5;
  }
  while ( v5 < v4 );
  if ( v3 == -1 )
    return -1073741497;
  v8 = *(_DWORD *)(a2 + 404);
  if ( !v8 )
    return -1073741558;
  if ( v8 > 0x55555555 )
    v8 = 1431655765;
  v10 = MiAllocateWorkingSetSwapSupport(2 * v8);
  a1[7] = v10;
  if ( !v10 )
    return -1073741670;
  a1[8] ^= ((unsigned __int8)a1[8] ^ (unsigned __int8)(4 * v3)) & 4;
  a1[9] = MiFindFreePageFileSpace((int)MiSystemPartition, a1 + 8, 3 * v8, 0, 17);
  return 0;
}
