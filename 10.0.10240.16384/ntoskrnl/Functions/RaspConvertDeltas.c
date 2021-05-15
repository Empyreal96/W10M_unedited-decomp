// RaspConvertDeltas 
 
int __fastcall RaspConvertDeltas(__int16 *a1)
{
  _WORD *v1; // r7
  __int16 *v2; // lr
  int v3; // r8
  int v4; // r2
  unsigned int v5; // r1
  int v6; // r6
  __int16 v7; // r9
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r0
  int v11; // r5
  __int16 v12; // r3
  int v13; // r3

  if ( *a1 <= 0 )
    return 0;
  v1 = *(_WORD **)(a1 + 19);
  v2 = *(__int16 **)(a1 + 21);
  v3 = (__int16)*(_DWORD *)(a1 + 5);
  LOWORD(v4) = 0;
  LOWORD(v5) = 0;
  v6 = (__int16)*(_DWORD *)(a1 + 1);
  v7 = 0;
  v8 = (__int16)*(_DWORD *)(a1 + 7);
  v9 = *(_DWORD *)(a1 + 3);
  v10 = (unsigned __int16)a1[12];
  v11 = (__int16)v9;
  if ( !v10 )
    return 0;
  while ( 1 )
  {
    v7 += *v1;
    v12 = *v2;
    *v1 = v7;
    v1 += 2;
    v4 = (__int16)(v12 + v4);
    *v2 = v4;
    v2 += 2;
    v13 = (__int16)*(v1 - 2);
    if ( v13 > v3 || v13 < v6 || v4 > v8 || v4 < v11 )
      break;
    v5 = (unsigned __int16)(v5 + 1);
    if ( v5 >= v10 )
      return 0;
  }
  return -1073741823;
}
