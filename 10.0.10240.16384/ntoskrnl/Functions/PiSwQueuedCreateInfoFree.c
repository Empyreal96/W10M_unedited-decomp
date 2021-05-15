// PiSwQueuedCreateInfoFree 
 
unsigned int __fastcall PiSwQueuedCreateInfoFree(unsigned int *a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r0
  unsigned int v4; // r1

  v2 = *a1;
  if ( v2 )
  {
    ExFreePoolWithTag(v2);
    *a1 = 0;
  }
  PiSwPnPInfoFree(a1 + 1);
  v3 = a1[7];
  if ( v3 )
  {
    ExFreePoolWithTag(v3);
    a1[7] = 0;
  }
  v4 = a1[8];
  if ( v4 )
    PnpFreeDevPropertyArray(a1[9], v4);
  return ExFreePoolWithTag((unsigned int)a1);
}
