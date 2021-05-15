// MiLimitLoaderBlockTotalMemory 
 
unsigned int __fastcall MiLimitLoaderBlockTotalMemory(int a1, unsigned int a2)
{
  _DWORD *v2; // r4
  int v3; // r7
  _DWORD *v4; // r8
  unsigned int v5; // r3
  _DWORD *v6; // r5
  unsigned int i; // lr
  int v9; // r2
  int v10; // r1
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r1
  int v15; // r3
  unsigned int v16; // r3
  __int64 v17; // r0
  int v18; // r3

  v2 = *(_DWORD **)(a1 + 28);
  v3 = 0;
  v4 = (_DWORD *)(a1 + 24);
  v5 = 0;
  v6 = v2;
  for ( i = 0; v6 != v4; v6 = (_DWORD *)v6[1] )
  {
    v9 = v6[2];
    if ( v9 != 6 && v9 != 32 && v9 != 31 && v9 != 30 && v9 != 23 && v9 != 3 && v9 != 22 )
    {
      v10 = v6[4];
      v5 += v10;
      if ( v9 == 2 || v9 == 5 || v9 == 4 || v9 == 24 || v9 == 8 )
        v3 += v10;
    }
  }
  if ( v5 - v3 > a2 )
    sub_96D6B8();
  if ( a2 < v5 )
    v11 = v5 - a2;
  else
    v11 = 0;
  for ( ; v2 != v4; v2 = (_DWORD *)v2[1] )
  {
    if ( v11 )
    {
      v15 = v2[2];
      if ( v15 == 2 || v15 == 24 || v15 == 4 || v15 == 5 || v15 == 8 )
      {
        v16 = v2[4];
        if ( v16 > v11 )
        {
          v2[4] = v16 - v11;
          v11 = 0;
        }
        else
        {
          v17 = *(_QWORD *)v2;
          if ( *(_DWORD **)(*v2 + 4) != v2 || *(_DWORD **)HIDWORD(v17) != v2 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v17) = v17;
          *(_DWORD *)(v17 + 4) = HIDWORD(v17);
          v18 = v2[4];
          v2[4] = 0;
          v11 -= v18;
        }
      }
    }
    v12 = v2[2];
    if ( v12 != 6 && v12 != 32 && v12 != 31 && v12 != 30 && v12 != 23 && v12 != 3 && v12 != 22 )
    {
      v13 = v2[4];
      if ( v13 )
      {
        if ( v2[3] + v13 > i )
          i = v2[3] + v13;
      }
    }
  }
  return i;
}
