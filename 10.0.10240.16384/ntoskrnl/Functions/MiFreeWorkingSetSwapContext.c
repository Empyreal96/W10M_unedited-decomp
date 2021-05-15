// MiFreeWorkingSetSwapContext 
 
unsigned int __fastcall MiFreeWorkingSetSwapContext(int a1, unsigned int *a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r0

  if ( *a2 )
    ExFreePoolWithTag(*a2);
  v4 = a2[1];
  if ( v4 )
    ExFreePoolWithTag(v4);
  v5 = a2[7];
  if ( v5 )
    ExFreePoolWithTag(v5);
  MiFreeReservationRun(a1, a2 + 8);
  return ExFreePoolWithTag((unsigned int)a2);
}
