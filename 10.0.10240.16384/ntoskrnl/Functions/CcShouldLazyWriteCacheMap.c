// CcShouldLazyWriteCacheMap 
 
int __fastcall CcShouldLazyWriteCacheMap(int a1, int a2, __int64 a3)
{
  int v4; // r0
  int v7; // r1
  unsigned int v9; // r2
  int v10; // r3
  int v11; // r4
  bool v12; // zf
  __int64 v13[3]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a3;
  v4 = *(_DWORD *)(a1 + 96);
  if ( (v4 & 0x400820) != 0 )
    return 0;
  if ( (v4 & 0x10000) != 0 )
    return 1;
  if ( *(_DWORD *)(a1 + 364) )
    return 0;
  v7 = *(_DWORD *)(a1 + 4);
  if ( !v7 && (!*(_DWORD *)(a1 + 76) || !*(_QWORD *)(a1 + 8)) )
    return 1;
  v9 = *(_DWORD *)(a1 + 76);
  if ( !a2 || !v9 )
    return 0;
  v10 = *(_DWORD *)(a1 + 172) + 1;
  *(_DWORD *)(a1 + 172) = v10;
  if ( (v4 & 0x1000000) != 0 )
  {
    KeQueryTickCount((int *)v13);
    v11 = *(_DWORD *)(a1 + 152);
    if ( !*(_DWORD *)(v11 + 64) )
    {
      if ( !KeMaximumIncrement )
        __brkdiv0();
      if ( v13[0] <= (unsigned int)_rt_sdiv64((unsigned int)KeMaximumIncrement, 160000000i64) + *(_QWORD *)(v11 + 88)
        && *(_DWORD *)(a1 + 76) < 0x40u )
      {
        return 0;
      }
    }
    return 1;
  }
  if ( (v4 & 0x200) != 0 )
  {
    if ( (v10 & 0xF) == 0 || v9 >= 0x40 )
      return 1;
    v12 = HIDWORD(a3) == 16;
  }
  else
  {
    if ( (*(_DWORD *)(a3 + 44) & 0x8000) == 0 || !v7 )
      return 1;
    v12 = CcCanIWriteStream(a3, 0x1000000u, 0, 1) == 0;
  }
  return v12;
}
