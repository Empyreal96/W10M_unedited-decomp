// FsRtlIsHpfsDbcsLegal 
 
int __fastcall FsRtlIsHpfsDbcsLegal(unsigned int a1, char *a2, int a3, int a4, char a5)
{
  unsigned int v5; // r5
  unsigned int v6; // r4
  int v9; // r3
  int v10; // r2
  unsigned int i; // r5
  int v14; // r3
  unsigned int v15; // [sp+8h] [bp-28h] BYREF
  char *v16; // [sp+Ch] [bp-24h]
  _DWORD v17[8]; // [sp+10h] [bp-20h] BYREF
  unsigned int varg_r0; // [sp+38h] [bp+8h]
  char *varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a1;
  varg_r0 = a1;
  varg_r1 = a2;
  a1 = (unsigned __int16)a1;
  v6 = 0;
  if ( !(_WORD)a1 )
    return 0;
  if ( a3 )
  {
    if ( (unsigned __int16)a1 == 1 )
    {
      v9 = *a2;
      if ( v9 == 46 || v9 == 34 )
        return 1;
    }
    if ( (unsigned __int16)a1 == 2 )
    {
      v10 = *a2;
      if ( v10 == 46 && a2[1] == 46 )
        return 1;
      if ( v10 == 34 && a2[1] == 34 )
        return 1;
    }
  }
  if ( *a2 == 92 )
  {
    if ( !a5 )
      return 0;
    if ( (unsigned __int16)a1 <= 1u )
      return 1;
    a1 = (unsigned __int16)(a1 - 1);
    ++a2;
    varg_r0 = __PAIR32__(HIWORD(varg_r0), a1) - 0x10000;
    v5 = varg_r0;
    varg_r1 = a2;
  }
  if ( a4 )
  {
    v15 = v5;
    v16 = a2;
    if ( a1 )
    {
      while ( *a2 != 92 )
      {
        FsRtlDissectDbcs(v5, a2, (int)v17, (int)&v15);
        if ( !FsRtlIsHpfsDbcsLegal(v17[0], v17[1], a3) )
          break;
        if ( !(_WORD)v15 )
          return 1;
        v5 = v15;
        a2 = v16;
      }
      return 0;
    }
    return 1;
  }
  if ( a1 <= 0xFF )
  {
    for ( i = 0; i < a1; ++i )
    {
      v6 = (unsigned __int8)a2[i];
      if ( v6 >= 0x80 && NlsMbOemCodePageTag && NlsOemLeadByteInfoTable[(unsigned __int8)a2[i]] )
      {
        if ( i == a1 - 1 )
          return 0;
        ++i;
      }
      else if ( (v6 & 0x80u) == 0 )
      {
        v14 = a3 ? 8 : 0;
        if ( (*((unsigned __int8 *)dword_407310 + v6) & (v14 | 2)) == 0 )
          return 0;
      }
    }
    if ( v6 != 32 && v6 != 46 && v6 != 34 )
      return 1;
  }
  return 0;
}
