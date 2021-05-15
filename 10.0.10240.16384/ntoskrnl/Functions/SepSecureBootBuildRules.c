// SepSecureBootBuildRules 
 
int SepSecureBootBuildRules()
{
  if ( *(_WORD *)(dword_641874 + 36) )
    return sub_96D9D0();
  if ( *(_WORD *)(dword_641874 + 38) )
    dword_641860 = *(_DWORD *)(dword_641874 + 44) + dword_641874 + 60;
  return 0;
}
