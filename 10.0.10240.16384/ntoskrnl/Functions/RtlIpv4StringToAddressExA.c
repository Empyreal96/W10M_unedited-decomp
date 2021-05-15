// RtlIpv4StringToAddressExA 
 
int __fastcall RtlIpv4StringToAddressExA(_BYTE *a1, int a2, _DWORD *a3, _WORD *a4)
{
  _BYTE *v5; // r4
  unsigned int v6; // r6
  unsigned int v7; // r7
  int v8; // r8
  int v9; // r3
  unsigned int v10; // r5
  unsigned int v11; // r2
  unsigned __int16 v12; // r3
  int v13; // r3
  __int16 v14; // r3
  int v16[8]; // [sp+0h] [bp-20h] BYREF

  v16[0] = (int)a4;
  if ( !a1 || !a3 || !a4 || RtlIpv4StringToAddressA(a1, a2, v16, a3) < 0 )
    return -1073741811;
  if ( *(_BYTE *)v16[0] != 58 )
  {
    if ( !*(_BYTE *)v16[0] )
    {
      v6 = 0;
      goto LABEL_35;
    }
    return -1073741811;
  }
  v5 = (_BYTE *)(v16[0] + 1);
  v6 = 0;
  v7 = 10;
  v8 = 1;
  if ( *(_BYTE *)(v16[0] + 1) == 48 )
  {
    v5 = (_BYTE *)(v16[0] + 2);
    v9 = *(char *)(v16[0] + 2);
    v7 = 8;
    if ( v9 == 120 || v9 == 88 )
    {
      v7 = 16;
      v5 = (_BYTE *)(v16[0] + 3);
    }
  }
  v10 = (char)*v5;
  if ( *v5 )
  {
    v8 = 0;
    do
    {
      ++v5;
      if ( _isascii(v10) && isdigit(v10) && (unsigned __int16)(v10 - 48) < v7 )
      {
        v11 = v10 + v6 * v7;
        if ( v11 - 48 > 0xFFFF )
          return -1073741811;
        v12 = v11 - 48;
      }
      else
      {
        if ( v7 != 16 || !_isascii(v10) || !isxdigit(v10) )
          return -1073741811;
        v13 = _isascii(v10) && islower(v10) ? 97 : 65;
        if ( 16 * v6 - v13 + v10 + 10 > 0xFFFF )
          return -1073741811;
        if ( _isascii(v10) && islower(v10) )
          v14 = 97;
        else
          v14 = 65;
        v12 = v10 - v14 + 16 * v6 + 10;
      }
      v10 = (char)*v5;
      v6 = v12;
    }
    while ( *v5 );
  }
  if ( v8 )
    return -1073741811;
LABEL_35:
  *a4 = __rev16(v6);
  return 0;
}
