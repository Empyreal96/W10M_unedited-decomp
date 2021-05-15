// RtlIpv4StringToAddressExW 
 
int __fastcall RtlIpv4StringToAddressExW(int a1, int a2, int a3, _WORD *a4)
{
  _WORD *v5; // r4
  unsigned int v6; // r6
  unsigned int v7; // r7
  int v8; // r8
  int v9; // r3
  unsigned int v10; // r5
  unsigned int v11; // r2
  unsigned __int16 v12; // r3
  int v13; // r3
  __int16 v14; // r3
  _WORD *v16; // [sp+0h] [bp-20h]

  v16 = a4;
  if ( !a1 || !a3 || !a4 || RtlIpv4StringToAddressW() < 0 )
    return -1073741811;
  if ( *v16 != 58 )
  {
    if ( !*v16 )
    {
      v6 = 0;
      goto LABEL_33;
    }
    return -1073741811;
  }
  v5 = v16 + 1;
  v6 = 0;
  v7 = 10;
  v8 = 1;
  if ( v16[1] == 48 )
  {
    v5 = v16 + 2;
    v9 = (unsigned __int16)v16[2];
    v7 = 8;
    if ( v9 == 120 || v9 == 88 )
    {
      v7 = 16;
      v5 = v16 + 3;
    }
  }
  v10 = (unsigned __int16)*v5;
  if ( *v5 )
  {
    v8 = 0;
    do
    {
      ++v5;
      if ( v10 < 0x80 && iswctype(v10, 4) && (unsigned __int16)(v10 - 48) < v7 )
      {
        v11 = v10 + v6 * v7;
        if ( v11 - 48 > 0xFFFF )
          return -1073741811;
        v12 = v11 - 48;
      }
      else
      {
        if ( v7 != 16 || v10 >= 0x80 || !iswctype(v10, 128) )
          return -1073741811;
        v13 = iswctype(v10, 2) ? 97 : 65;
        if ( 16 * v6 - v13 + v10 + 10 > 0xFFFF )
          return -1073741811;
        if ( iswctype(v10, 2) )
          v14 = 97;
        else
          v14 = 65;
        v12 = v10 - v14 + 16 * v6 + 10;
      }
      v10 = (unsigned __int16)*v5;
      v6 = v12;
    }
    while ( *v5 );
  }
  if ( v8 )
    return -1073741811;
LABEL_33:
  *a4 = __rev16(v6);
  return 0;
}
