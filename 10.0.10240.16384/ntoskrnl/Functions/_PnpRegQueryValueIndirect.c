// _PnpRegQueryValueIndirect 
 
int __fastcall PnpRegQueryValueIndirect(int a1, unsigned int a2, int a3, unsigned int *a4, unsigned __int16 *a5, unsigned int *a6, bool *a7)
{
  unsigned __int16 *v7; // r4
  int v9; // r0
  unsigned int v11; // r2
  bool v12; // r3
  unsigned int v13; // r9
  int v14; // r2
  unsigned __int16 *v15; // r1
  int v16; // r7
  unsigned __int16 *v17; // r2
  int v18; // r3
  int i; // r5
  int v20; // r1
  unsigned __int16 *v21; // r2
  int j; // r3
  unsigned int v23; // [sp+8h] [bp-30h] BYREF
  int v24; // [sp+Ch] [bp-2Ch]
  __int16 v25[20]; // [sp+10h] [bp-28h] BYREF

  v7 = a5;
  v23 = a2;
  if ( a5 )
  {
    if ( !*a6 )
      v7 = 0;
  }
  else
  {
    *a6 = 0;
  }
  if ( a7 )
    *a7 = 0;
  *a4 = 0;
  v9 = RegRtlQueryValue(a2);
  v24 = v9;
  if ( v9 && v9 != -1073741789 || !a7 )
    return v24;
  v11 = *a4;
  if ( *a4 > 3 )
  {
    if ( v11 <= 6 )
      goto LABEL_26;
    if ( v11 != 7 )
    {
      if ( v11 - 8 > 3 )
      {
        v12 = (unsigned __int16)v11 == 25;
LABEL_16:
        *a7 = v12;
        return v24;
      }
LABEL_26:
      v12 = 0;
      goto LABEL_16;
    }
  }
  if ( !v9 )
  {
    if ( RtlStringCbLengthW((int)v7, *a6, &v23) >= 0 )
    {
      if ( !PnpParseIndirectInfString(v7) )
      {
        if ( RtlUnalignedStringCchLengthW(v7, 0x7FFF, &v23) < 0 )
          return v24;
        v13 = v23;
        if ( v23 < 5 || *v7 != 64 )
          return v24;
        v14 = 1;
        if ( v7[1] )
        {
          v15 = v7 + 1;
          do
          {
            if ( *v15 == 44 )
              break;
            v15 = &v7[++v14];
          }
          while ( *v15 );
        }
        if ( v7[v14] != 44 )
          return v24;
        v16 = v14 + 1;
        v17 = &v7[v14 + 1];
        v18 = *v17;
        if ( v18 != 45 && v18 != 35 )
          return v24;
        for ( i = v16 + 1; v7[i] && v7[i] != 59; ++i )
          ;
        if ( v7[i] != 59 )
          i = 0;
        if ( RtlInitUnicodeStringEx((int)v25, v17 + 1) < 0 )
          return v24;
        if ( i )
        {
          v25[0] = 2 * (i - v16 - 1);
          v25[1] = v25[0];
        }
        if ( RtlUnicodeStringToInteger(v25, 10, &v23) < 0 )
          return v24;
        if ( i )
        {
          v20 = i + 1;
          v21 = &v7[i + 1];
          for ( j = *v21; *v21; j = *v21 )
          {
            if ( j == 59 && v21[1] == 40 && v7[v13 - 1] == 41 )
              break;
            v21 = &v7[++v20];
          }
        }
      }
      *a7 = 1;
    }
    return v24;
  }
  return sub_7C65D0();
}
