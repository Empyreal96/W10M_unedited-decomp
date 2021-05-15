// RtlpMuiRegResizeStringPool 
 
_BYTE *__fastcall RtlpMuiRegResizeStringPool(unsigned int a1, __int16 a2, unsigned int a3, unsigned int a4)
{
  int v4; // r6
  _BYTE *v5; // r7
  int v6; // r5
  int v9; // r1
  int v10; // r2
  int v11; // r3
  _BYTE *v12; // r0
  unsigned int v14; // [sp+0h] [bp-20h] BYREF
  unsigned int v15[7]; // [sp+4h] [bp-1Ch] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v4 = a2;
  v5 = 0;
  v6 = (__int16)a3;
  if ( a2 < 1 )
    v4 = 4;
  if ( (__int16)a3 < 1 )
    v6 = 40;
  if ( a1 )
  {
    if ( v4 >= 1
      && v6 >= 1
      && v4 >= *(unsigned __int16 *)(a1 + 6)
      && v6 >= *(unsigned __int16 *)(a1 + 10)
      && RtlULongLongToULong(2 * *(unsigned __int16 *)(a1 + 4), 0, &v14) >= 0
      && RtlULongLongToULong(2 * *(unsigned __int16 *)(a1 + 8), v9, v15) >= 0 )
    {
      v12 = RtlpMuiRegCreateStringPool(v4, v6, v10, v11);
      v5 = v12;
      if ( v12 )
      {
        memmove(*((_DWORD *)v12 + 3), *(_DWORD *)(a1 + 12), v14);
        memmove(*((_DWORD *)v5 + 4), *(_DWORD *)(a1 + 16), v15[0]);
        *((_WORD *)v5 + 3) = *(_WORD *)(a1 + 6);
        *((_WORD *)v5 + 5) = *(_WORD *)(a1 + 10);
        if ( !a4 )
          ExFreePoolWithTag(a1);
      }
    }
  }
  return v5;
}
