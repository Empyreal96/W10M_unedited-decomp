// PfSnCancelTraceTimer 
 
int __fastcall PfSnCancelTraceTimer(unsigned int *a1)
{
  unsigned int *v2; // r4
  int v3; // r5
  int v4; // r8
  unsigned int v6; // r2
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1

  v2 = a1 + 48;
  v3 = 0;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54B81C();
  do
    v6 = __ldrex(v2);
  while ( __strex(1u, v2) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire(v2);
  a1[49] |= 2u;
  if ( KeCancelTimer((int)(a1 + 26)) )
    v3 = 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v2);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  KfLowerIrql(v4);
  if ( v3 )
  {
    v7 = a1 + 67;
    __pld(a1 + 67);
    v8 = a1[67] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 - 2, v7) );
    if ( v9 != v8 )
      ExfReleaseRundownProtection((unsigned __int8 *)v7);
  }
  return 0;
}
