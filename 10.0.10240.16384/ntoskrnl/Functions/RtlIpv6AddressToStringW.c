// RtlIpv6AddressToStringW 
 
int __fastcall RtlIpv6AddressToStringW(unsigned __int16 *a1, int a2)
{
  int v3; // r5
  int v4; // r8
  int v5; // r10
  char *v6; // r3
  int v7; // r0
  unsigned __int16 v8; // r2
  int v9; // r7
  int v10; // r0
  int v11; // r9
  int v12; // r1
  unsigned __int16 *v13; // r6
  int i; // r6
  int v16; // r0

  v3 = a2;
  v4 = 8;
  v5 = a2 + 92;
  if ( !*a1 && !a1[1] && !a1[2] && !a1[3] && a1[6] )
  {
    if ( !a1[4] )
    {
      if ( !a1[5] )
        goto LABEL_10;
      if ( a1[5] == 0xFFFF )
      {
        if ( a1[5] )
        {
          v6 = "ffff:";
          goto LABEL_12;
        }
LABEL_10:
        v6 = &byte_5CB13F;
LABEL_12:
        v7 = swprintf_s(
               a2,
               46,
               (int)L"::%hs%u.%u.%u.%u",
               v6,
               *((unsigned __int8 *)a1 + 12),
               *((unsigned __int8 *)a1 + 13),
               *((unsigned __int8 *)a1 + 14),
               *((unsigned __int8 *)a1 + 15));
LABEL_39:
        v3 += 2 * v7;
        return v3;
      }
    }
    if ( a1[4] == 0xFFFF && !a1[5] )
    {
      v7 = swprintf_s(
             a2,
             46,
             (int)L"::ffff:0:%u.%u.%u.%u",
             *((unsigned __int8 *)a1 + 12),
             *((unsigned __int8 *)a1 + 13),
             *((unsigned __int8 *)a1 + 14),
             *((unsigned __int8 *)a1 + 15));
      goto LABEL_39;
    }
  }
  v8 = a1[4];
  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( (v8 & 0xFFFD) == 0 && a1[5] == 65118 )
    v4 = 6;
  v12 = 0;
  v13 = a1;
  do
  {
    if ( *v13++ )
    {
      v10 = v12 + 1;
    }
    else if ( v12 - v10 + 1 > v9 - v11 )
    {
      v11 = v10;
      v9 = v12 + 1;
    }
    ++v12;
  }
  while ( v12 < v4 );
  if ( v9 - v11 <= 1 )
  {
    v9 = 0;
    v11 = 0;
  }
  for ( i = 0; i < v4; ++i )
  {
    if ( v11 > i || i >= v9 )
    {
      if ( i && i != v9 )
        v3 += 2 * swprintf_s(v3, (v5 - v3) >> 1, (int)L":");
      v16 = swprintf_s(v3, (v5 - v3) >> 1, (int)L"%x", __rev16(a1[i]));
    }
    else
    {
      v16 = swprintf_s(v3, (v5 - v3) >> 1, (int)L"::");
      i = v9 - 1;
    }
    v3 += 2 * v16;
  }
  if ( v4 < 8 )
  {
    v7 = swprintf_s(
           v3,
           (v5 - v3) >> 1,
           (int)L":%u.%u.%u.%u",
           *((unsigned __int8 *)a1 + 12),
           *((unsigned __int8 *)a1 + 13),
           *((unsigned __int8 *)a1 + 14),
           *((unsigned __int8 *)a1 + 15));
    goto LABEL_39;
  }
  return v3;
}
