// WmipSDRegistryQueryRoutine 
 
int __fastcall WmipSDRegistryQueryRoutine(int a1, int a2, int a3, unsigned int a4, int a5, int *a6)
{
  int v7; // r4
  int v10; // r0

  v7 = 0;
  if ( a3 && a2 == 3 && SeValidSecurityDescriptor(a4, a3) )
  {
    v10 = ExAllocatePoolWithTag(1, a4, 1885957463);
    *a6 = v10;
    if ( v10 )
      memmove(v10, a3, a4);
    else
      v7 = -1073741670;
  }
  return v7;
}
