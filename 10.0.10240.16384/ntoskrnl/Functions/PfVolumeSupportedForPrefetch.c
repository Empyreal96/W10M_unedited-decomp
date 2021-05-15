// PfVolumeSupportedForPrefetch 
 
int __fastcall PfVolumeSupportedForPrefetch(_DWORD *a1)
{
  int v2; // r3

  if ( *a1 != 7 )
    return sub_54E208();
  v2 = a1[1];
  if ( (v2 & 0x10) != 0 )
    return 2;
  if ( (v2 & 1) != 0 )
    return 3;
  if ( (v2 & 0x20) != 0 )
    return 0;
  return 4;
}
