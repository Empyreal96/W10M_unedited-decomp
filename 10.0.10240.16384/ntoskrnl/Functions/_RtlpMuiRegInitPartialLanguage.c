// _RtlpMuiRegInitPartialLanguage 
 
int __fastcall RtlpMuiRegInitPartialLanguage(int a1, int a2, _WORD *a3)
{
  if ( !a1 || !a2 || !a3 || (*a3 & 2) == 0 )
    return -1073741811;
  if ( RtlpMuiRegPopulateBaseLanguages() < 0 )
    *a3 |= 0x1000u;
  *a3 |= 0x1000u;
  return 0;
}
