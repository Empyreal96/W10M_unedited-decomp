// RaspLoadBearings 
 
int __fastcall RaspLoadBearings(int a1, unsigned int a2, int a3, int *a4)
{
  unsigned int v4; // r7
  int result; // r0
  int v10; // r4
  int v11; // r6
  int v12; // r0
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r2
  _DWORD *v16; // r1
  int v17; // r9
  unsigned int v18; // [sp+0h] [bp-28h] BYREF
  _DWORD v19[9]; // [sp+4h] [bp-24h] BYREF

  v18 = a2;
  v19[0] = a3;
  v19[1] = a4;
  v4 = *(unsigned __int16 *)(a1 + 68);
  LOWORD(v18) = 0;
  if ( a2 >= v4 )
  {
    v17 = *(_DWORD *)(a1 + 48) + 4 * (v4 - 1);
    result = FioFwReadBytesAtOffset(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 8), v17, 4, v19);
    if ( result < 0 )
      return result;
    v10 = __rev16(LOWORD(v19[0]));
    result = FioFwReadUshortAtOffset(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 8), v17 + 2 * (a2 - v4 + 2), &v18);
    if ( result < 0 )
      return result;
    v11 = (__int16)v18;
  }
  else
  {
    result = FioFwReadBytesAtOffset(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 8), *(_DWORD *)(a1 + 48) + 4 * a2, 4, v19);
    if ( result < 0 )
      return result;
    v10 = __rev16(LOWORD(v19[0]));
    v11 = (__int16)__rev16(HIWORD(v19[0]));
    if ( !v10 )
      return sub_54DA34();
  }
  if ( v11 < 0 )
    LOWORD(v11) = 0;
  v12 = *(_DWORD *)(a3 + 18);
  if ( v10 < *(_DWORD *)(a3 + 10) + (__int16)v11 - v12 )
    v10 = *(_DWORD *)(a3 + 10) + (__int16)v11 - v12;
  v13 = *(unsigned __int16 *)(a3 + 24);
  v14 = *(_DWORD *)(a3 + 38);
  *a4 = v10;
  v15 = (_DWORD *)(v14 + 4 * v13);
  *v15 = v12 - (__int16)v11;
  v15[1] = *(_DWORD *)(a3 + 18) - (__int16)v11 + v10;
  v16 = (_DWORD *)(*(_DWORD *)(a3 + 42) + 4 * *(unsigned __int16 *)(a3 + 24));
  *v16 = *(__int16 *)(a1 + 62) + *(__int16 *)(a1 + 64);
  v16[1] = *(__int16 *)(a1 + 62) + *(__int16 *)(a1 + 64);
  *(_WORD *)(a3 + 24) += 2;
  return 0;
}
