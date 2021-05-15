// RtlIpv6StringToAddressW 
 
int __fastcall RtlIpv6StringToAddressW(unsigned __int16 *a1, unsigned __int16 **a2, int a3)
{
  unsigned __int16 *v3; // r8
  unsigned int v4; // r4
  unsigned __int16 *v5; // r0
  unsigned int v6; // r6
  int v7; // r1
  int v8; // r7
  unsigned int v9; // r5
  unsigned int v10; // r9
  int v11; // r10
  unsigned __int16 v12; // r0
  unsigned int v13; // r0
  __int16 v14; // r3
  unsigned int v15; // r0
  int v16; // r4
  int v18; // [sp+0h] [bp-30h]
  unsigned __int16 *v19; // [sp+4h] [bp-2Ch]
  int v20; // [sp+8h] [bp-28h]
  int v21; // [sp+Ch] [bp-24h]

  v3 = a1;
  v4 = *a1;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v19 = 0;
  v20 = a3;
  v21 = 0;
  v10 = 0;
  v11 = 0;
  v18 = 0;
  if ( v4 )
  {
    do
    {
      if ( v8 )
      {
        if ( v8 == 1 )
        {
          if ( v4 < 0x80 )
          {
            if ( iswctype(v4, 4) )
            {
              ++v10;
LABEL_14:
              v5 = v19;
              goto LABEL_8;
            }
            if ( iswctype(v4, 128) )
            {
              ++v10;
              if ( v6 )
                break;
              v21 = 1;
              goto LABEL_14;
            }
          }
          if ( v4 == 58 )
          {
            if ( v6 || v9 > 6 )
              break;
            if ( v3[1] == 58 )
            {
              if ( v11 )
                break;
              v11 = v9 + 1;
              v9 += 2;
              v8 = 2;
              ++v3;
              goto LABEL_24;
            }
            ++v9;
          }
          else
          {
            if ( v4 != 46 || v21 || v6 > 2 || v9 > 6 )
              break;
            ++v6;
          }
          v8 = 0;
LABEL_24:
          v5 = v19;
LABEL_40:
          if ( !v5 )
            goto LABEL_8;
          if ( v6 )
          {
            if ( v10 > 3 )
              return -1073741811;
            v13 = wcstol(v5, 0, 10);
            if ( v13 > 0xFF )
              return -1073741811;
            v7 = v18;
            a3 = v20;
            *(_BYTE *)(v6 + 2 * v18 + v20 - 1) = v13;
          }
          else
          {
            if ( v10 > 4 )
              return -1073741811;
            v12 = wcstol(v5, 0, 16);
            a3 = v20;
            *(_WORD *)(v20 + 2 * v18) = __rev16(v12);
            v7 = ++v18;
          }
          v5 = v19;
          goto LABEL_9;
        }
      }
      else if ( v4 == 58 )
      {
        if ( v6 || v9 || v3[1] != 58 )
          break;
        *(_WORD *)(a3 + 2 * v7) = 0;
        v9 = 2;
        v18 = v7 + 1;
        v11 = 1;
        ++v3;
        v8 = 2;
        goto LABEL_40;
      }
      if ( v9 > 7 || v4 >= 0x80 )
        break;
      if ( iswctype(v4, 4) )
      {
        v8 = 1;
        v5 = v3;
        v10 = 1;
        v21 = 0;
        v19 = v3;
LABEL_8:
        v7 = v18;
        a3 = v20;
        goto LABEL_9;
      }
      if ( !iswctype(v4, 128) || v6 )
        break;
      v8 = 1;
      v5 = v3;
      a3 = v20;
      v7 = v18;
      v10 = 1;
      v21 = 1;
      v19 = v3;
LABEL_9:
      v4 = *++v3;
    }
    while ( *v3 );
  }
  *a2 = v3;
  if ( v6 )
  {
    if ( v6 != 3 )
      return -1073741811;
    ++v9;
  }
  if ( !v11 && v9 != 7 )
    return -1073741811;
  if ( v8 != 1 )
  {
    if ( v8 == 2 )
    {
      v14 = 0;
      goto LABEL_62;
    }
    return -1073741811;
  }
  if ( !v6 )
  {
    if ( v10 <= 4 )
    {
      v14 = __rev16((unsigned __int16)wcstol(v19, 0, 16));
LABEL_62:
      v16 = v20;
      *(_WORD *)(v20 + 2 * v18) = v14;
      goto LABEL_63;
    }
    return -1073741811;
  }
  if ( v10 > 3 )
    return -1073741811;
  v15 = wcstol(v19, 0, 10);
  if ( v15 > 0xFF )
    return -1073741811;
  v16 = v20;
  *(_BYTE *)(v6 + 2 * v18 + v20) = v15;
LABEL_63:
  if ( v11 )
  {
    memmove(v16 + 2 * (v11 - v9 + 8), v16 + 2 * v11, 2 * (v9 - v11));
    memset((_BYTE *)(v16 + 2 * v11), 0, 2 * (8 - v9));
  }
  return 0;
}
