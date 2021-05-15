// HvpBuildMapForLoaderHive 
 
int __fastcall HvpBuildMapForLoaderHive(int a1, unsigned int a2)
{
  int v4; // r4
  unsigned int v5; // r9
  _DWORD *v6; // r6
  int v7; // r4
  int v8; // r7
  _DWORD *v9; // r0
  unsigned int v10; // r2
  unsigned int v12; // [sp+8h] [bp-28h]
  int v13; // [sp+Ch] [bp-24h]

  v4 = HvpInitMap(a1);
  if ( v4 < 0 )
    return v4;
  v5 = 0;
  v6 = (_DWORD *)a2;
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40);
  if ( a2 >= v7 + a2 )
    return 0;
  while ( 1 )
  {
    if ( v6[2] > v7 - v5 || *v6 != 1852400232 || v6[1] != v5 )
      JUMPOUT(0x812ABC);
    v8 = v5 + a2;
    v12 = v5 + a2;
    v13 = 0;
    do
    {
      v9 = (_DWORD *)HvpGetCellMap(a1, v5);
      if ( !v9 )
        JUMPOUT(0x812AAC);
      v10 = v12;
      *v9 = v13;
      v9[1] = v8;
      v9[2] = 0;
      if ( v12 == v8 && (v9[1] = v8 | 1, v12 == a2) )
        v9[4] = v7;
      else
        v9[4] = 0;
      v9[3] = 1;
      v13 += 4096;
      v12 += 4096;
      v5 += 4096;
    }
    while ( v10 + 4096 < *(_DWORD *)(v8 + 8) + v8 );
    if ( (*(_BYTE *)(a1 + 72) & 2) == 0 && !HvpEnlistFreeCells((_DWORD *)a1, v8, *(_DWORD *)(v8 + 4)) )
      break;
    v6 = (_DWORD *)((char *)v6 + v6[2]);
    if ( (unsigned int)v6 >= v7 + a2 )
      return 0;
  }
  return sub_812A8C();
}
