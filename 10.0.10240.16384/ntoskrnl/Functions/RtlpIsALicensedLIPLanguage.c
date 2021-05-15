// RtlpIsALicensedLIPLanguage 
 
int __fastcall RtlpIsALicensedLIPLanguage(int a1, unsigned __int16 *a2)
{
  int result; // r0
  unsigned __int16 *v5; // r0

  if ( !a1 )
    return -1073741811;
  v5 = *(unsigned __int16 **)(a1 + 80);
  if ( v5 && RtlpLangNameInMultiSzString(v5, a2) )
    goto LABEL_7;
  result = 0;
  if ( !*(_DWORD *)(a1 + 92) )
    return result;
  if ( RtlpLangNameInMultiSzString(*(unsigned __int16 **)(a1 + 92), a2) )
LABEL_7:
    result = -1073741772;
  else
    result = 0;
  return result;
}
