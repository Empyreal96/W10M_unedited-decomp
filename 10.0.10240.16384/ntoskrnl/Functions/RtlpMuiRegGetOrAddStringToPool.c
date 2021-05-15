// RtlpMuiRegGetOrAddStringToPool 
 
int __fastcall RtlpMuiRegGetOrAddStringToPool(int a1, unsigned __int16 *a2, int a3, _DWORD *a4)
{
  int v7; // r10
  int v8; // r7
  int v9; // r0
  unsigned int v10; // r0
  int v11; // r4
  unsigned int v12; // r3
  unsigned int v13; // r5
  unsigned int v15; // r8
  unsigned int v16; // r2
  int v17; // [sp+0h] [bp-28h] BYREF
  int v18; // [sp+4h] [bp-24h]
  _DWORD *v19; // [sp+8h] [bp-20h]

  v18 = a3;
  v19 = a4;
  v17 = a3;
  v7 = -1;
  if ( a1 && a2 && (v8 = 0, *(_WORD *)(a1 + 6)) )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(a1 + 16) + 2 * *(__int16 *)(*(_DWORD *)(a1 + 12) + 2 * v8);
      if ( (unsigned __int16 *)v9 == a2 || !wcsicmp(v9, a2) )
        break;
      if ( ++v8 >= *(unsigned __int16 *)(a1 + 6) )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v8 = -1;
  }
  if ( a4 )
    *a4 = 0;
  if ( v8 >= 0 )
    return v8;
  if ( a1 && a2 )
  {
    v10 = wcslen(a2);
    v11 = *(unsigned __int16 *)(a1 + 10);
    v12 = *(unsigned __int16 *)(a1 + 8);
    v13 = v10 + 1;
    v18 = v11;
    if ( v11 + v10 + 1 > v12 )
      return sub_80C0A8();
    if ( v17 )
    {
      v15 = *(unsigned __int16 *)(a1 + 6);
      if ( v15 < *(unsigned __int16 *)(a1 + 4) && RtlULongLongToULong(2 * v13, (unsigned __int64)v13 >> 31, &v17) >= 0 )
      {
        *(_WORD *)(a1 + 6) = v15 + 1;
        v16 = v17;
        *(_WORD *)(a1 + 10) = v18 + 1;
        v8 = v15;
        memmove(*(_DWORD *)(a1 + 16) + 2 * (__int16)v11, (int)a2, v16);
        *(_WORD *)(a1 + 10) += v13;
        *(_WORD *)(*(_DWORD *)(a1 + 12) + 2 * v15) = v11;
        return v8;
      }
    }
  }
  return v7;
}
