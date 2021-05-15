// PnpFreeDevProperty 
 
int __fastcall PnpFreeDevProperty(int a1)
{
  unsigned int v2; // r0
  int result; // r0

  v2 = *(_DWORD *)(a1 + 24);
  if ( v2 )
    ExFreePoolWithTag(v2);
  result = *(_DWORD *)(a1 + 36);
  if ( result )
    result = sub_7EE570();
  return result;
}
