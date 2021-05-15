// _RtlpMuiRegAddNeutralLanguage 
 
int __fastcall RtlpMuiRegAddNeutralLanguage(int a1, int a2)
{
  if ( !a1 || !a2 )
    return -1073741811;
  *(_WORD *)(a2 + 8) &= 0x3FFFu;
  *(_WORD *)(a2 + 10) = 0;
  return 0;
}
