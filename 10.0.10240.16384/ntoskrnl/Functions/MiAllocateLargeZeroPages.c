// MiAllocateLargeZeroPages 
 
_DWORD *__fastcall MiAllocateLargeZeroPages(int a1, int a2, int a3)
{
  _DWORD *v6; // r4
  unsigned int v7; // r5
  int v8; // r6
  int v9; // r2
  unsigned int v10; // r1

  v6 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1818520909);
  if ( !v6 )
    return 0;
  v7 = dword_633818;
  if ( (dword_633818 & 0xFFFFFFF) != dword_633818
    || (v8 = ExAllocatePoolWithTag(512, 16 * dword_633818, 1818520909)) == 0 )
  {
    ExFreePoolWithTag((unsigned int)v6);
    return 0;
  }
  if ( v7 )
  {
    v9 = v8;
    v10 = v7;
    do
    {
      *(_DWORD *)(v9 + 8) = 0;
      *(_DWORD *)(v9 + 12) = 0xFFFFF;
      v9 += 16;
      --v10;
    }
    while ( v10 );
  }
  *v6 = v6;
  v6[1] = v6;
  v6[2] = v8;
  v6[3] = 0;
  if ( MiFindLargePageMemory(a1, v6, a2, a3) )
  {
    if ( v6[3] == 1 )
      MiZeroInParallel(v8, v7, 0);
  }
  else
  {
    ExFreePoolWithTag((unsigned int)v6);
    v6 = 0;
  }
  ExFreePoolWithTag(v8);
  return v6;
}
