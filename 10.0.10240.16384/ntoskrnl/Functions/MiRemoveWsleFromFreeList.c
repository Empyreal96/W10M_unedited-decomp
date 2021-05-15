// MiRemoveWsleFromFreeList 
 
unsigned int __fastcall MiRemoveWsleFromFreeList(int a1, int a2)
{
  _DWORD *v2; // r4
  unsigned __int16 v3; // r2
  int v4; // r6
  int v5; // r7
  unsigned int result; // r0
  unsigned int v7; // r3
  int v8; // r5
  int v9; // r7
  unsigned int v10; // r1
  _DWORD *v11; // r5

  v2 = *(_DWORD **)(a1 + 92);
  v3 = a2;
  v4 = v2[63];
  if ( *v2 == a2 )
    return MiPopFreeWsle(a1);
  v5 = v2[9];
  if ( a2 && (*(_DWORD *)((a2 - 1) * v5 + v4) & 1) == 0 )
    return sub_522F6C();
  if ( a2 == v2[4]
    || (result = a2 + 1, v7 = *(_DWORD *)((a2 + 1) * v5 + v4), (v7 & 1) != 0)
    || v7 >> 12 != a2
    || a2 == 1048574 )
  {
    result = (*(_DWORD *)(v5 * a2 + v4) >> 1) & 0x7FF;
    v11 = (_DWORD *)(v4 + v5 * result);
    do
    {
      if ( (*v11 & 1) == 0 && *v11 >> 12 == a2 )
        break;
      result += 2048;
      v11 += 512 * v2[9];
    }
    while ( result <= v2[4] );
  }
  if ( *(_DWORD *)(v5 * result + v4) >> 12 != a2 )
    KeBugCheckEx(26, 20497, v2);
  v8 = *(_DWORD *)(v5 * a2 + v4) >> 12;
  if ( v8 != 0xFFFFF )
  {
    v9 = v5 * v8;
    v10 = *(_DWORD *)(v9 + v4);
    if ( (v10 & 1) != 0 || ((v3 ^ (unsigned __int16)(v10 >> 1)) & 0x7FF) != 0 )
      KeBugCheckEx(26, 20498, v2);
    *(_DWORD *)(v9 + v4) = (v10 ^ (2 * result)) & 0xFFE ^ v10;
  }
  *(_DWORD *)(v2[63] + v2[9] * result) = *(_DWORD *)(v2[9] * result + v4) & 0xFFF | (v8 << 12);
  return result;
}
