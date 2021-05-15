// MiReserveWorkingSetSwapSpaceRuns 
 
unsigned int __fastcall MiReserveWorkingSetSwapSpaceRuns(int a1, unsigned int a2, int a3, int a4, unsigned int a5)
{
  unsigned int v5; // r4
  char v7; // r8
  _DWORD *v9; // r5
  int v10; // r7
  int v11; // r0

  v5 = a2;
  v7 = a3;
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 4 * a3 + 3600) + 24) >= a2 )
  {
    v9 = (_DWORD *)a5;
    if ( a5 < a5 + 40 )
    {
      v10 = 40;
      do
      {
        if ( !v5 )
          break;
        *v9 = *v9 & 0x1FFB | (4 * (v7 & 1 | (a4 << 11)));
        v11 = MiFindFreePageFileSpace(a1, v9, v5, 0, 21);
        v9[1] = v11;
        if ( (v10 >> 3) * v11 < v5 )
          break;
        v9 += 2;
        v5 -= v11;
        v10 -= 8;
      }
      while ( (unsigned int)v9 < a5 + 40 );
    }
  }
  return v5;
}
