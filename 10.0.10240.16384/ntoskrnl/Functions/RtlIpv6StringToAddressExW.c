// RtlIpv6StringToAddressExW 
 
int __fastcall RtlIpv6StringToAddressExW(_WORD *a1, int a2, unsigned __int16 *a3, _WORD *a4)
{
  _WORD *v4; // r6
  unsigned int *v5; // r9
  unsigned int v6; // r8
  int v7; // r7
  unsigned int v8; // r10
  unsigned __int16 *v9; // r4
  unsigned int v10; // r5
  unsigned int v12; // r3
  int v13; // t1
  int v14; // r6
  int v15; // r3
  unsigned int v16; // r5
  unsigned int v17; // r2
  unsigned __int16 v18; // r3
  int v19; // r3
  __int16 v20; // r3
  unsigned __int16 *v22; // [sp+4h] [bp-24h] BYREF
  unsigned int *v23; // [sp+8h] [bp-20h]

  v22 = a3;
  v4 = a4;
  v5 = (unsigned int *)a3;
  v23 = (unsigned int *)a3;
  if ( !a1 || !a2 || !a3 || !a4 )
    return -1073741811;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( *a1 == 91 )
  {
    v7 = 1;
    ++a1;
  }
  if ( RtlIpv6StringToAddressW(a1, &v22, a2) < 0 )
    return -1073741811;
  v9 = v22;
  if ( *v22 == 37 )
  {
    v9 = v22 + 1;
    v10 = v22[1];
    if ( v10 >= 0x80 || !iswctype(*v9, 4) )
      return -1073741811;
    while ( v10 && v10 != 93 )
    {
      if ( v10 >= 0x80
        || !iswctype(v10, 4)
        || (__PAIR64__((10i64 * v8 + (unsigned __int64)v10) >> 32, -48) + ((10 * v8 + v10) | 0xFFFFFFFF00000000ui64)) >> 32 )
      {
        return -1073741811;
      }
      v12 = v10 + 10 * v8;
      v10 = *++v9;
      v8 = v12 - 48;
    }
  }
  if ( *v9 == 93 )
  {
    if ( !v7 )
      return -1073741811;
    ++v9;
    v7 = 0;
    if ( *v9 == 58 )
    {
      v13 = v9[1];
      ++v9;
      v14 = 10;
      if ( v13 == 48 )
      {
        v15 = *++v9;
        v14 = 8;
        if ( v15 == 120 || v15 == 88 )
        {
          v14 = 16;
          ++v9;
        }
      }
      v16 = *v9;
      if ( *v9 )
      {
        do
        {
          if ( v16 < 0x80 && iswctype(v16, 4) && (int)(v16 - 48) < v14 )
          {
            v17 = v16 + v14 * v6;
            if ( v17 - 48 > 0xFFFF )
              return -1073741811;
            v18 = v17 - 48;
          }
          else
          {
            if ( v14 != 16 || v16 >= 0x80 || !iswctype(v16, 128) )
              return -1073741811;
            v19 = iswctype(v16, 2) ? 97 : 65;
            if ( 16 * v6 - v19 + v16 + 10 > 0xFFFF )
              return -1073741811;
            if ( iswctype(v16, 2) )
              v20 = 97;
            else
              v20 = 65;
            v18 = v16 - v20 + 16 * v6 + 10;
          }
          v16 = *++v9;
          v6 = v18;
        }
        while ( *v9 );
        v5 = v23;
      }
      v4 = a4;
    }
  }
  if ( *v9 || v7 )
    return -1073741811;
  *v4 = __rev16(v6);
  *v5 = v8;
  return 0;
}
