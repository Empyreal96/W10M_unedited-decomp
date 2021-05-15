// WmipLinkDataSourceToList 
 
int __fastcall WmipLinkDataSourceToList(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // r8
  _DWORD *i; // r9
  int *v8; // r7
  int *v9; // r0
  int v10; // r3
  int **v11; // r1
  int result; // r0
  int v13; // r2
  _DWORD *v14; // r1

  v3 = (_DWORD *)a1[5];
  for ( i = a1 + 5; v3 != i; v3 = (_DWORD *)*v3 )
  {
    v8 = v3 - 5;
    if ( (*(v3 - 3) & 8) != 0 )
    {
      v9 = WmipFindGEByGuid(v3[2], 0);
      if ( !v9 )
      {
        if ( WmipAllocGuidEntry() )
          result = sub_7CBC64();
        else
          result = -1073741670;
        return result;
      }
      v10 = *(v3 - 3);
      v3[2] = v9;
      *(v3 - 3) = v10 & 0xFFFFFFF7;
      v11 = (int **)v9[9];
      *v8 = (int)(v9 + 8);
      *(v3 - 4) = v11;
      if ( *v11 != v9 + 8 )
        __fastfail(3u);
      *v11 = v8;
      v9[9] = (int)v8;
      ++v9[5];
      if ( (*(v3 - 3) & 0x80000) != 0 )
        WmipRegisterEtwProvider(v3 - 5, a3);
    }
  }
  if ( a2 )
  {
    a1[2] |= 0x40000000u;
    v13 = WmipDSHeadPtr;
    v14 = *(_DWORD **)(WmipDSHeadPtr + 4);
    *a1 = WmipDSHeadPtr;
    a1[1] = v14;
    if ( *v14 != v13 )
      __fastfail(3u);
    *v14 = a1;
    *(_DWORD *)(v13 + 4) = a1;
  }
  return 0;
}
