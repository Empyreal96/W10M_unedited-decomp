// TxtpAddCacheEntry 
 
int __fastcall TxtpAddCacheEntry(int a1, __int16 a2, _DWORD *a3, int a4)
{
  __int64 v6; // r4
  int v7; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2
  int v14; // r3
  __int64 v15; // kr00_8

  HIDWORD(v6) = a1;
  LOWORD(v6) = a2;
  v7 = BgpFwAllocateMemory(0x24u);
  if ( !v7 )
    return -1073741801;
  *(_WORD *)(v7 + 8) = v6;
  v9 = a3[1];
  v10 = a3[2];
  v11 = a3[3];
  *(_DWORD *)(v7 + 12) = *a3;
  *(_DWORD *)(v7 + 16) = v9;
  *(_DWORD *)(v7 + 20) = v10;
  *(_DWORD *)(v7 + 24) = v11;
  v12 = a3[4];
  *(_DWORD *)(v7 + 32) = a4;
  *(_DWORD *)(v7 + 28) = v12;
  v13 = *(_DWORD *)HIDWORD(v6);
  *(_DWORD *)v7 = *(_DWORD *)HIDWORD(v6);
  *(_DWORD *)(v7 + 4) = HIDWORD(v6);
  if ( *(_DWORD *)(v13 + 4) != HIDWORD(v6) )
    __fastfail(3u);
  *(_DWORD *)(v13 + 4) = v7;
  *(_DWORD *)HIDWORD(v6) = v7;
  v14 = *(_DWORD *)(HIDWORD(v6) + 8);
  if ( v14 == 125 )
  {
    LODWORD(v6) = *(_DWORD *)(HIDWORD(v6) + 4);
    v15 = *(_QWORD *)v6;
    if ( __PAIR64__(*(_DWORD *)v6, **(_DWORD **)(v6 + 4)) != v6 )
      __fastfail(3u);
    *(_DWORD *)(HIDWORD(v6) + 4) = HIDWORD(v15);
    *(_DWORD *)HIDWORD(v15) = HIDWORD(v6);
    BgpGxRectangleDestroy(*(_DWORD *)(v6 + 32));
    BgpFwFreeMemory(v6);
  }
  else
  {
    *(_DWORD *)(HIDWORD(v6) + 8) = v14 + 1;
  }
  return 0;
}
