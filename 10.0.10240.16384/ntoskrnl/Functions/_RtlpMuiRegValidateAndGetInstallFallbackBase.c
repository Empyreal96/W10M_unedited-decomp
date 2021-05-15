// _RtlpMuiRegValidateAndGetInstallFallbackBase 
 
int __fastcall RtlpMuiRegValidateAndGetInstallFallbackBase(int a1, int a2, int a3, unsigned __int16 *a4)
{
  int v4; // r4
  __int64 v6; // kr00_8
  int v8; // [sp+0h] [bp-18h] BYREF
  unsigned __int16 *v9; // [sp+4h] [bp-14h]

  v8 = a3;
  v9 = a4;
  v4 = -1073741823;
  if ( !a1 || !a4 || !a2 )
    return -1073741811;
  if ( *(_DWORD *)(a2 + 4) == 7 )
  {
    v6 = *(_QWORD *)(a2 + 8);
    if ( HIDWORD(v6) && (_DWORD)v6 + a2 && *(_WORD *)(v6 + a2) )
    {
      if ( !a3 )
        return 0;
      v9 = a4;
      if ( RtlLCIDToCultureName(a3, (unsigned int)&v8) )
      {
        if ( RtlpLangNameInMultiSzString((unsigned __int16 *)(v6 + a2), v9) )
          return 0;
      }
    }
    else if ( !a3 )
    {
      return 0;
    }
  }
  return v4;
}
