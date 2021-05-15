// RtlIpv4StringToAddressA 
 
int __fastcall RtlIpv4StringToAddressA(_BYTE *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int *v5; // r2
  int v7; // r9
  unsigned int v8; // r10
  int result; // r0
  int v10; // r7
  int v11; // r3
  int v12; // r3
  unsigned int *v13; // [sp+0h] [bp-40h]
  unsigned int v16; // [sp+10h] [bp-30h] BYREF
  unsigned int v17; // [sp+14h] [bp-2Ch]
  unsigned int v18; // [sp+18h] [bp-28h]
  unsigned int v19; // [sp+1Ch] [bp-24h] BYREF

  v5 = &v16;
  v13 = &v16;
  while ( 1 )
  {
    v7 = 0;
    v8 = 0;
    if ( *a1 == 48 )
      return sub_5556E4();
    while ( 1 )
    {
      v10 = (char)*a1;
      if ( !*a1 || !_isascii((char)*a1, a2, v5) || !isdigit(v10) || v10 - 48 >= 10 )
        break;
      if ( v10 + 10 * v8 - 48 < v8 )
        goto LABEL_9;
      ++a1;
      v7 = 1;
      v8 = v10 + 10 * v8 - 48;
    }
    if ( *a1 != 46 )
      break;
    if ( v13 < &v19 )
    {
      *v13 = v8;
      v5 = v13 + 1;
      ++a1;
      ++v13;
      if ( v7 )
        continue;
    }
    goto LABEL_9;
  }
  if ( !v7 )
    goto LABEL_9;
  *v13 = v8;
  v11 = ((char *)v13 - (char *)&v16 + 4) >> 2;
  if ( a2 )
  {
    if ( v11 != 4 )
      goto LABEL_9;
  }
  switch ( v11 )
  {
    case 1:
      v12 = v16;
      break;
    case 2:
      if ( v16 > 0xFF || v17 > 0xFFFFFF )
        goto LABEL_9;
      v12 = v17 & 0xFFFFFF | (v16 << 24);
      break;
    case 3:
      if ( v16 > 0xFF || v17 > 0xFF || v18 > 0xFFFF )
        goto LABEL_9;
      v12 = (unsigned __int16)v18 | (((unsigned __int8)v17 | (v16 << 8)) << 16);
      break;
    default:
      if ( v11 == 4 && v16 <= 0xFF && v17 <= 0xFF && v18 <= 0xFF && v19 <= 0xFF )
      {
        v12 = (unsigned __int8)v19 | (((unsigned __int8)v18 | (((unsigned __int8)v17 | (v16 << 8)) << 8)) << 8);
        break;
      }
LABEL_9:
      result = -1073741811;
      *a3 = a1;
      return result;
  }
  *a3 = a1;
  *a4 = bswap32(v12);
  return 0;
}
