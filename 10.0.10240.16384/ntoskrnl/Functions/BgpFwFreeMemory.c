// BgpFwFreeMemory 
 
int __fastcall BgpFwFreeMemory(int a1)
{
  _DWORD *v2; // r0
  int v3; // r1
  __int64 v4; // kr00_8
  int v5; // r2
  int v6; // r0
  int v8; // r4

  v2 = (_DWORD *)(a1 - 12);
  v3 = *v2;
  if ( *v2 == 1262700354 )
    return BgpFwReserveFree();
  if ( v3 == 1262634818 )
  {
    v4 = *((_QWORD *)v2 - 1);
    if ( *(_DWORD **)(v4 + 4) != v2 - 2 || *(_DWORD **)HIDWORD(v4) != v2 - 2 )
      sub_51B9B4(v2, 1262634818);
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
    v5 = 32;
  }
  else
  {
    v5 = 16;
  }
  if ( v2[1] >= 0x1000u )
  {
    v8 = v2[2];
    MmUnmapLockedPages(a1 - v5, v8, v5);
    MiFreePagesFromMdl(MiSystemPartition, v8, 0);
    v3 = 0;
    v6 = v8;
  }
  else
  {
    v6 = a1 - v5;
  }
  return ExFreePoolWithTag(v6, v3);
}
