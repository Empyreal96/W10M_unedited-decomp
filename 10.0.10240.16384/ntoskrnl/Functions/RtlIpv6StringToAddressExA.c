// RtlIpv6StringToAddressExA 
 
int __fastcall RtlIpv6StringToAddressExA(char *a1, int a2, int a3, _WORD *a4)
{
  _WORD *v4; // r7
  int *v5; // r10
  int v6; // r6
  unsigned int v7; // r9
  int v8; // r8
  _BYTE *v9; // r4
  signed int v10; // r5
  int result; // r0
  int v12; // t1
  int v13; // r7
  int v14; // r3
  unsigned int v15; // r6
  unsigned int v16; // r5
  unsigned int v17; // r2
  unsigned __int16 v18; // r3
  int v19; // r3
  __int16 v20; // r3
  int v22; // [sp+4h] [bp-2Ch]
  _BYTE *v23; // [sp+8h] [bp-28h] BYREF
  int *v24; // [sp+Ch] [bp-24h]

  v4 = a4;
  v5 = (int *)a3;
  v24 = (int *)a3;
  if ( !a1 || !a2 || !a3 || !a4 )
    return -1073741811;
  v6 = 0;
  v7 = 0;
  v22 = 0;
  v8 = 0;
  if ( *a1 == 91 )
  {
    v8 = 1;
    ++a1;
  }
  if ( RtlIpv6StringToAddressA(a1, &v23, a2) < 0 )
    return -1073741811;
  v9 = v23;
  if ( *v23 == 37 )
  {
    v9 = v23 + 1;
    v10 = (char)v23[1];
    if ( !_isascii(v10) || !isdigit(v10) )
      return -1073741811;
    while ( v10 && v10 != 93 )
    {
      if ( !_isascii(v10)
        || !isdigit(v10)
        || (__PAIR64__((10 * (unsigned __int64)(unsigned int)v6 + v10) >> 32, -48)
          + ((unsigned int)(10 * v6 + v10) | 0xFFFFFFFF00000000ui64)) >> 32 )
      {
        return -1073741811;
      }
      v6 = v10 + 10 * v6 - 48;
      v10 = (char)*++v9;
      v22 = v6;
    }
  }
  if ( *v9 == 93 )
  {
    if ( !v8 )
      return -1073741811;
    ++v9;
    v8 = 0;
    if ( *v9 == 58 )
    {
      v12 = (char)*++v9;
      v13 = 10;
      if ( v12 == 48 )
      {
        v14 = (char)*++v9;
        v13 = 8;
        if ( v14 == 120 || v14 == 88 )
        {
          v13 = 16;
          ++v9;
        }
      }
      v15 = (char)*v9;
      v16 = v15;
      if ( *v9 )
      {
        do
        {
          if ( _isascii(v16) && isdigit(v16) && (int)(v16 - 48) < v13 )
          {
            v17 = v15 + v13 * v7;
            if ( v17 - 48 > 0xFFFF )
              return -1073741811;
            v18 = v17 - 48;
          }
          else
          {
            if ( v13 != 16 || !_isascii(v16) || !isxdigit(v16) )
              return -1073741811;
            v19 = _isascii(v16) && islower(v16) ? 97 : 65;
            if ( 16 * v7 - v19 + v15 + 10 > 0xFFFF )
              return -1073741811;
            if ( _isascii(v16) && islower(v16) )
              v20 = 97;
            else
              v20 = 65;
            v18 = v15 - v20 + 16 * v7 + 10;
          }
          v15 = (char)*++v9;
          v7 = v18;
          v16 = v15;
        }
        while ( *v9 );
        v5 = v24;
      }
      v4 = a4;
    }
  }
  if ( *v9 || v8 )
    return -1073741811;
  *v4 = __rev16(v7);
  result = 0;
  *v5 = v22;
  return result;
}
