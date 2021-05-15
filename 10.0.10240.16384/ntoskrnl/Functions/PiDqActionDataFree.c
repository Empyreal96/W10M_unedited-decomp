// PiDqActionDataFree 
 
unsigned int __fastcall PiDqActionDataFree(_DWORD *a1)
{
  unsigned int v2; // r0
  int v3; // r1

  if ( *a1 )
  {
    v2 = a1[2];
    if ( v2 )
      ExFreePoolWithTag(v2);
    v3 = a1[4];
    if ( v3 )
      PnpFreeDevPropertyArray(a1[3], v3, 1483763280);
  }
  return ExFreePoolWithTag((unsigned int)a1);
}
