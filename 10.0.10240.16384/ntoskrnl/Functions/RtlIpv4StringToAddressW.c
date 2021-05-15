// RtlIpv4StringToAddressW 
 
int __fastcall RtlIpv4StringToAddressW(_WORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r2
  unsigned int *v7; // r10
  int v8; // r8
  int v9; // r7
  unsigned int v10; // r9
  unsigned int v11; // r0
  int v12; // r0
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r3
  int v16; // r3
  int result; // r0
  int v18; // r3
  int v19; // r3
  unsigned int v22; // [sp+8h] [bp-30h] BYREF
  unsigned int v23; // [sp+Ch] [bp-2Ch]
  unsigned int v24; // [sp+10h] [bp-28h]
  unsigned int v25; // [sp+14h] [bp-24h] BYREF

  v5 = a2;
  v7 = &v22;
  while ( 1 )
  {
    v8 = 0;
    v9 = 10;
    v10 = 0;
    if ( *a1 == 48 )
    {
      v11 = (unsigned __int16)*++a1;
      if ( v11 < 0x80 && (v12 = iswctype(v11, 4), v5 = a2, v12) )
      {
        v9 = 8;
      }
      else
      {
        v13 = (unsigned __int16)*a1;
        if ( v13 == 120 || v13 == 88 )
        {
          v9 = 16;
          ++a1;
        }
        else
        {
          v8 = 1;
        }
      }
    }
    if ( v5 && v9 != 10 )
      goto LABEL_30;
    v14 = (unsigned __int16)*a1;
    if ( *a1 )
    {
      do
      {
        if ( v14 < 0x80 && iswctype(v14, 4) && (int)(v14 - 48) < v9 )
        {
          v15 = v14 + v9 * v10 - 48;
        }
        else
        {
          if ( v9 != 16 || v14 >= 0x80 || !iswctype(v14, 128) )
            break;
          if ( iswctype(v14, 2) )
            v16 = 97;
          else
            v16 = 65;
          v15 = 16 * v10 - v16 + v14 + 10;
        }
        if ( v15 < v10 )
          goto LABEL_30;
        v14 = (unsigned __int16)*++a1;
        v8 = 1;
        v10 = v15;
      }
      while ( *a1 );
      v5 = a2;
    }
    if ( *a1 != 46 )
      break;
    if ( v7 < &v25 )
    {
      ++a1;
      *v7++ = v10;
      if ( v8 )
        continue;
    }
    goto LABEL_30;
  }
  if ( !v8 )
    goto LABEL_30;
  v18 = ((char *)v7 - (char *)&v22 + 4) >> 2;
  *v7 = v10;
  if ( v5 )
  {
    if ( v18 != 4 )
      goto LABEL_30;
  }
  switch ( v18 )
  {
    case 1:
      v19 = v22;
      goto LABEL_51;
    case 2:
      if ( v22 <= 0xFF && v23 <= 0xFFFFFF )
      {
        v19 = v23 & 0xFFFFFF | (v22 << 24);
        goto LABEL_51;
      }
      goto LABEL_30;
    case 3:
      if ( v22 <= 0xFF && v23 <= 0xFF && v24 <= 0xFFFF )
      {
        v19 = (unsigned __int16)v24 | (((unsigned __int8)v23 | (v22 << 8)) << 16);
        goto LABEL_51;
      }
LABEL_30:
      result = -1073741811;
      *a3 = a1;
      return result;
  }
  if ( v18 != 4 || v22 > 0xFF || v23 > 0xFF || v24 > 0xFF || v25 > 0xFF )
    goto LABEL_30;
  v19 = (unsigned __int8)v25 | (((unsigned __int8)v24 | (((unsigned __int8)v23 | (v22 << 8)) << 8)) << 8);
LABEL_51:
  *a3 = a1;
  *a4 = bswap32(v19);
  return 0;
}
