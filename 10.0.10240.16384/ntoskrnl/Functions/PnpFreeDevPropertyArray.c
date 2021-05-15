// PnpFreeDevPropertyArray 
 
int __fastcall PnpFreeDevPropertyArray(int a1, unsigned int a2)
{
  int v2; // r5
  unsigned int v3; // r7
  unsigned int i; // r4
  unsigned int v6; // r0

  v2 = a1;
  v3 = a2;
  if ( !a1 )
    return ExFreePoolWithTag(v3);
  for ( i = a2; !*(_DWORD *)(i + 24); i += 40 )
  {
    v6 = *(_DWORD *)(i + 36);
    if ( v6 )
      ExFreePoolWithTag(v6);
    if ( !--v2 )
      return ExFreePoolWithTag(v3);
  }
  return sub_7C717C();
}
