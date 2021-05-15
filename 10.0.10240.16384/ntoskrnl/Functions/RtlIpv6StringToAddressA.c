// RtlIpv6StringToAddressA 
 
int __fastcall RtlIpv6StringToAddressA(char *a1, _DWORD *a2, int a3)
{
  _BYTE *v3; // r8
  int v4; // r4
  int v5; // lr
  _BYTE *v6; // r0
  int v7; // r2
  int v8; // r7
  unsigned int v9; // r5
  unsigned int v10; // r9
  unsigned int v11; // r10
  int v12; // r1
  int v13; // r2
  int v14; // r1
  int v15; // r2
  int v17; // r0
  int v18; // [sp+0h] [bp-30h]
  _BYTE *v20; // [sp+8h] [bp-28h]

  v3 = a1;
  v4 = *a1;
  v5 = a3;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v20 = 0;
  v10 = 0;
  v11 = 0;
  v18 = 0;
  if ( v4 )
  {
    do
    {
      if ( v8 == 1 )
      {
        if ( _isascii(v4, 0, v7) && isdigit(v4) )
        {
          v6 = v20;
          ++v10;
LABEL_6:
          v7 = v18;
          v5 = a3;
          goto LABEL_7;
        }
        if ( _isascii(v4, v12, v13) && isxdigit(v4) )
        {
          v7 = v18;
          v5 = a3;
          v6 = v20;
          ++v10;
          goto LABEL_7;
        }
        if ( v4 != 58 )
          return sub_55282C();
        if ( v9 > 6 )
          goto LABEL_46;
        v6 = v20;
        if ( v3[1] == 58 )
        {
          if ( v11 )
            JUMPOUT(0x552894);
          v11 = v9 + 1;
          v9 += 2;
          ++v3;
          v8 = 2;
        }
        else
        {
          ++v9;
          v8 = 0;
        }
        if ( !v20 )
          goto LABEL_6;
        if ( v10 > 4 )
          return -1073741811;
        v5 = a3;
        *(_WORD *)(a3 + 2 * v18) = __rev16((unsigned __int16)((int (*)(void))strtol)());
        v7 = ++v18;
        v6 = v20;
      }
      else
      {
        if ( !v8 && v4 == 58 )
          JUMPOUT(0x552844);
        if ( v9 > 7 )
          break;
        if ( _isascii(v4, 0, v7) && isdigit(v4) )
        {
          v8 = 1;
          v6 = v3;
          v10 = 1;
          v20 = v3;
          goto LABEL_6;
        }
        if ( !_isascii(v4, v14, v15) )
LABEL_46:
          JUMPOUT(0x55289C);
        v17 = isxdigit(v4);
        v7 = v18;
        v5 = a3;
        if ( !v17 )
        {
          v6 = v20;
          break;
        }
        v8 = 1;
        v6 = v3;
        v10 = 1;
        v20 = v3;
      }
LABEL_7:
      v4 = (char)*++v3;
    }
    while ( *v3 );
  }
  *a2 = v3;
  if ( !v11 && v9 != 7 )
    return -1073741811;
  if ( v8 == 1 )
  {
    if ( v10 <= 4 )
    {
      v5 = a3;
      *(_WORD *)(a3 + 2 * v18) = __rev16((unsigned __int16)strtol(v6, 0, 16));
      goto LABEL_33;
    }
    return -1073741811;
  }
  if ( v8 != 2 )
    return -1073741811;
  *(_WORD *)(v5 + 2 * v7) = 0;
LABEL_33:
  if ( v11 )
  {
    memmove(v5 + 2 * (v11 - v9 + 8), v5 + 2 * v11, 2 * (v9 - v11));
    memset((_BYTE *)(a3 + 2 * v11), 0, 2 * (8 - v9));
  }
  return 0;
}
