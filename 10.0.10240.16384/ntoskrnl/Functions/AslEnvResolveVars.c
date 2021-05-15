// AslEnvResolveVars 
 
int __fastcall AslEnvResolveVars(int a1, unsigned int a2, _WORD *a3, unsigned int a4, int a5, unsigned int *a6)
{
  int v7; // r4
  unsigned int v8; // r5
  __int16 **v9; // r7
  unsigned int v11; // r10
  unsigned __int16 *v12; // r9
  int v13; // r2
  _WORD *v14; // r9
  int v15; // r4
  int v16; // r2
  unsigned int i; // [sp+10h] [bp-28h]
  unsigned __int16 *v21; // [sp+14h] [bp-24h]
  unsigned int v22; // [sp+18h] [bp-20h]

  v7 = 0;
  v8 = 0;
  v9 = off_6189A8;
  for ( i = 0; i < 4; ++i )
  {
    if ( v7 )
      goto LABEL_24;
    v21 = (unsigned __int16 *)*v9;
    v11 = wcslen((unsigned __int16 *)*v9);
    if ( a5 )
      v12 = (unsigned __int16 *)v9[2];
    else
      v12 = (unsigned __int16 *)v9[1];
    v22 = wcslen(v12);
    if ( a2 <= v11 || wcsnicmp(a1, v21, v11) )
    {
      v14 = a3;
    }
    else
    {
      v8 = v22 - v11 + a2;
      if ( v8 > a4 )
      {
        v15 = -1073741789;
        goto LABEL_25;
      }
      v13 = (int)v12;
      v14 = a3;
      v15 = RtlStringCchCopyW(a3, a4, v13);
      if ( v15 < 0 )
      {
        v16 = 847;
LABEL_19:
        AslLogCallPrintf(1, (int)"AslEnvResolveVars", v16, "RtlStringCchCopyW failed [%x]", v15);
        return v15;
      }
      v15 = RtlStringCchCatW(a3, a4, a1 + 2 * v11, a1);
      if ( v15 < 0 )
      {
        AslLogCallPrintf(1, (int)"AslEnvResolveVars", 853, "RtlStringCchCatW failed [%x]", v15);
        return v15;
      }
      v7 = 1;
    }
    v9 += 3;
  }
  if ( !v7 )
  {
    v8 = a2;
    if ( a2 > a4 )
    {
      v15 = -1073741789;
      *a6 = a2;
      return v15;
    }
    v15 = RtlStringCchCopyW(v14, a4, a1);
    if ( v15 < 0 )
    {
      v16 = 884;
      goto LABEL_19;
    }
  }
LABEL_24:
  v15 = 0;
LABEL_25:
  *a6 = v8;
  return v15;
}
