// PiSwValidateCreateData 
 
int __fastcall PiSwValidateCreateData(_DWORD *a1)
{
  int v2; // r7
  unsigned __int16 *v3; // r0
  int v4; // r1
  unsigned __int16 *v5; // r6
  unsigned __int16 *v6; // r2
  unsigned int v7; // r4
  unsigned int v8; // r1
  int v9; // r0
  unsigned __int16 *i; // r4
  unsigned int v11; // r1
  int v12; // r0
  unsigned __int16 *v13; // r0
  int v15; // r1
  unsigned int v16; // r0
  _DWORD *v17; // r0
  unsigned int v18; // r1
  unsigned __int16 *j; // r4

  v2 = -1073741811;
  if ( !a1 )
    return v2;
  v3 = (unsigned __int16 *)a1[1];
  if ( !v3 )
    return v2;
  if ( !*v3 )
    return v2;
  if ( wcslen(v3) > 0xC7 )
    return v2;
  if ( !*a1 )
    return v2;
  if ( !*(_WORD *)*a1 )
    return v2;
  if ( !PiSwIsValidPnpId(*a1, 0) )
    return v2;
  v5 = (unsigned __int16 *)a1[2];
  if ( !v5 )
    return v2;
  if ( !*v5 )
    return v2;
  if ( !PiSwIsValidPnpId(a1[2], v4) )
    return v2;
  v7 = wcslen(v6);
  if ( wcslen(v5) + v7 + 5 > 0xC7 )
    return v2;
  if ( (a1[8] & 0xFFFFFFF0) != 0 )
    return v2;
  v8 = a1[3];
  if ( v8 > 0x3FF || !v8 && a1[4] )
    return v2;
  v9 = a1[4];
  if ( v9 )
  {
    if ( PnpValidateMultiSz(v9, v8) < 0 )
      return v2;
    for ( i = (unsigned __int16 *)a1[4]; *i; i += wcslen(i) + 1 )
    {
      if ( !PiSwIsValidPnpId(i, 1) )
        return v2;
    }
  }
  else if ( v8 )
  {
    return v2;
  }
  v11 = a1[5];
  if ( v11 > 0x3FF || !v11 && a1[6] )
    return v2;
  v12 = a1[6];
  if ( v12 )
  {
    if ( PnpValidateMultiSz(v12, v11) < 0 )
      return v2;
    for ( j = (unsigned __int16 *)a1[6]; *j; j += wcslen(j) + 1 )
    {
      if ( !PiSwIsValidPnpId(j, 1) )
        return v2;
    }
  }
  else if ( v11 )
  {
    return v2;
  }
  v13 = (unsigned __int16 *)a1[9];
  if ( !v13 || wcslen(v13) <= 0x7FFE )
  {
    if ( a1[10] )
      return sub_7E0BC8();
    v15 = a1[12];
    if ( v15 || !a1[11] )
    {
      v16 = a1[11];
      if ( (!v15 || v16) && (!v15 || SeValidSecurityDescriptor(v16, v15)) && ((a1[8] & 8) == 0 || a1[4] || a1[6]) )
      {
        v17 = (_DWORD *)a1[14];
        if ( v17 || !a1[13] )
        {
          v18 = a1[13];
          if ( !v17 || v18 )
            v2 = PiSwValidatePropertyArray(v17, v18);
        }
      }
    }
  }
  return v2;
}
