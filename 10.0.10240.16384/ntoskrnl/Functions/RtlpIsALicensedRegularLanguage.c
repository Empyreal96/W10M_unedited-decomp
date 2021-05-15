// RtlpIsALicensedRegularLanguage 
 
int __fastcall RtlpIsALicensedRegularLanguage(_DWORD *a1)
{
  int result; // r0

  result = 0;
  if ( !a1 )
    return -1073741772;
  if ( !a1[20] )
    goto LABEL_5;
  if ( !RtlpLangNameInMultiSzString(a1[20]) )
    return -1073741772;
  result = 0;
LABEL_5:
  if ( a1[19] )
    return sub_80C0E4(0);
  if ( a1[23] )
    JUMPOUT(0x80C0F2);
  return result;
}
