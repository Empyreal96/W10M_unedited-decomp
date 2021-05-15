// WmipUpdateAddGuid 
 
BOOL __fastcall WmipUpdateAddGuid(_DWORD *a1, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v9; // r0
  _DWORD *v10; // r4
  int v11; // r3
  _DWORD *v12; // r1
  int v13; // r0
  int v15; // r0

  v9 = WmipAllocEntry((int *)&WmipISChunkInfo);
  v10 = v9;
  if ( !v9 )
    return 0;
  v11 = v9[2];
  v9[7] = a2;
  v9[8] = a1;
  v9[2] = v11 | 8;
  v12 = v9 + 5;
  v13 = a1[5];
  *v12 = v13;
  v12[1] = a1 + 5;
  if ( *(_DWORD **)(v13 + 4) != a1 + 5 )
    __fastfail(3u);
  *(_DWORD *)(v13 + 4) = v12;
  a1[5] = v12;
  if ( WmipBuildInstanceSet(a2, a3, a4, v10, a1[7]) < 0 )
  {
    WmipUnreferenceEntry((int *)&WmipISChunkInfo, v10);
    return 0;
  }
  v15 = WmipLinkDataSourceToList(a1, 0, 0);
  *a5 = v10;
  return v15 >= 0;
}
