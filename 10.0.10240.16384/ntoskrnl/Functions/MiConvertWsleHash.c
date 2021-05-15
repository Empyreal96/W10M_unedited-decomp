// MiConvertWsleHash 
 
int __fastcall MiConvertWsleHash(int a1)
{
  _DWORD *v1; // r9
  unsigned int v2; // r5
  int v3; // r4
  unsigned int v4; // r0
  unsigned int v5; // r6
  int v6; // r1
  int v7; // t1
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r4
  int result; // r0
  int v12; // r3
  int v13; // r4
  int v14; // [sp+0h] [bp-28h]
  unsigned int v15; // [sp+4h] [bp-24h]

  v1 = *(_DWORD **)(a1 + 92);
  v2 = v1[12];
  v3 = a1;
  v4 = ((v2 >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = v2 + 4096;
  v14 = v3;
  v15 = v4;
  v1[12] = 0;
  v1[10] = 0;
  if ( v2 < v2 + 4096 )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)v2;
      v2 += 8;
      v6 = v7;
      if ( (v7 & 1) != 0 )
      {
        v8 = v1[11];
        v9 = v1[13];
        v10 = v9 + 4 * ((unsigned int)(v6 - v8) >> 12);
        if ( !MiIsAddressValid(v10, 0, v8, v9) && !MiMapWsleHash(v14) )
          return sub_544208();
        *(_DWORD *)v10 = *(_DWORD *)(v2 - 4);
        *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(((v10 >> 10) & 0x3FFFFC) - 0x40000000) >> 12) + 8) = ((*(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(((v10 >> 10) & 0x3FFFFC) - 0x40000000) >> 12) + 8) & 0xFFFFE000) + 0x2000) ^ *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(((v10 >> 10) & 0x3FFFFC) - 0x40000000) >> 12) + 8) & 0x1FFF;
      }
      if ( v2 >= v5 )
      {
        v3 = v14;
        v4 = v15;
        break;
      }
    }
  }
  result = MiDeletePteRange(v3, v4, v4 + 4, 0);
  v12 = *(_BYTE *)(v3 + 112) & 7;
  *(_DWORD *)(v3 + 80) -= result;
  if ( v12 != 1 )
  {
    v13 = -result;
    do
      result = __ldrex(&dword_634DA0);
    while ( __strex(result + v13, &dword_634DA0) );
  }
  return result;
}
