// PiSwInterfaceFree 
 
unsigned int __fastcall PiSwInterfaceFree(_DWORD *a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r1

  v2 = a1[2];
  if ( v2 )
    ExFreePoolWithTag(v2);
  v3 = a1[3];
  if ( v3 )
    PnpFreeDevPropertyArray(a1[4], v3);
  return ExFreePoolWithTag((unsigned int)a1);
}
