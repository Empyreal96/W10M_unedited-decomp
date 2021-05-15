// ViFaultsIsAppTarget 
 
int __fastcall ViFaultsIsAppTarget(unsigned __int16 *a1)
{
  int v2; // r5
  int i; // r4

  v2 = 0;
  for ( i = ViFaultApplicationsList; (int *)i != &ViFaultApplicationsList; i = *(_DWORD *)i )
  {
    if ( VfUtilEqualUnicodeString((unsigned __int8 **)(i + 8), a1) )
      return 1;
  }
  return v2;
}
