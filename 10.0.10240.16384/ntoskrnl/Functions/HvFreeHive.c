// HvFreeHive 
 
int __fastcall HvFreeHive(int a1, int a2)
{
  int v2; // r5
  unsigned int v4; // r7
  unsigned int v5; // r8
  unsigned int v6; // r10
  int v7; // r6
  unsigned int v8; // r4
  int v9; // r0
  _DWORD *v10; // r9
  int v11; // r0
  int v12; // r8
  __int64 v13; // kr00_8
  unsigned int v14; // r4
  unsigned int v15; // r0
  unsigned int v16; // r0
  int v17; // r1
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned int v20; // [sp+Ch] [bp-2Ch]
  char v21; // [sp+10h] [bp-28h]

  v2 = a1;
  if ( !a2 )
    return sub_805C04();
  v4 = 0;
  v5 = *(_DWORD *)(a1 + 92) & 0xFFFFFFFE;
  v21 = *(_BYTE *)(a1 + 92) & 0xFE;
  *(_DWORD *)(a1 + 92) = v5;
  v6 = 0;
  v7 = a1;
  do
  {
    v8 = v4;
    v20 = *(_DWORD *)(v7 + 952) + v4;
    if ( *(_DWORD *)(v7 + 956) && *(_DWORD *)(v7 + 952) + v4 > v4 )
    {
      do
      {
        if ( (v5 & 0x10) != 0 )
          break;
        v9 = HvpGetCellMap(v2, v8);
        v10 = (_DWORD *)v9;
        if ( !v9 )
          KeBugCheckEx(81, 1, v2, v8, 160);
        v11 = HvpMapEntryGetFreeBin(v9);
        v12 = v11;
        if ( v11 )
        {
          v17 = *(_DWORD *)(v11 + 8);
          v8 += v17;
          if ( (*(_DWORD *)(v11 + 16) & 1) != 0 )
            HvpFreeBin(v2, v17, v6, v10[1] & 0xFFFFFFF0, v10[2] & 0xFFFFFFF0);
          else
            CmpReleaseGlobalQuota(*(_DWORD *)(v11 + 8));
          (*(void (__fastcall **)(int, int))(v2 + 16))(v12, 20);
        }
        else
        {
          HvpFreeBin(v2, v10[4], v6, v10[1] & 0xFFFFFFF0, v10[2] & 0xFFFFFFF0);
          v8 += v10[4];
        }
        LOBYTE(v5) = v21;
      }
      while ( v8 < v20 );
      v13 = *(_QWORD *)(v7 + 952);
      v14 = (((unsigned int)v13 >> 12) - 1) >> 9;
      HvpFreeMap(v2, SHIDWORD(v13), 0, v14);
      if ( v14 )
      {
        CmpFree(*(_DWORD *)(v7 + 956), 4096);
        *(_DWORD *)(v7 + 956) = 0;
      }
    }
    ++v6;
    *(_DWORD *)(v7 + 952) = 0;
    v4 += 0x80000000;
    v7 += 412;
  }
  while ( v6 <= 1 );
  *(_BYTE *)(v2 + 72) &= 0xFBu;
  HvViewMapCleanup(v2 + 152, v2, 1);
  if ( (v5 & 0x10) != 0 )
  {
    __dmb(0xBu);
    do
    {
      v18 = __ldrex((unsigned int *)&CmpPreloadedHivesCount);
      v19 = v18 - 1;
    }
    while ( __strex(v19, (unsigned int *)&CmpPreloadedHivesCount) );
    __dmb(0xBu);
    if ( !v19 )
      CmpFreeBootRegistry();
  }
  (*(void (__fastcall **)(_DWORD, _DWORD))(v2 + 16))(*(_DWORD *)(v2 + 32), *(_DWORD *)(v2 + 64));
  v15 = *(_DWORD *)(v2 + 40);
  *(_DWORD *)(v2 + 32) = 0;
  if ( v15 )
  {
    CmpFree(v15, *(_DWORD *)(v2 + 48));
    *(_DWORD *)(v2 + 40) = 0;
  }
  v16 = *(_DWORD *)(v2 + 56);
  if ( v16 )
  {
    CmpFree(v16, *(_DWORD *)(v2 + 48));
    *(_DWORD *)(v2 + 56) = 0;
  }
  return HvpFreeHiveFreeDisplay((_DWORD *)v2, a2);
}
