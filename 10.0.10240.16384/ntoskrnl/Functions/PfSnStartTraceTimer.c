// PfSnStartTraceTimer 
 
int __fastcall PfSnStartTraceTimer(int a1)
{
  unsigned int *v1; // r6
  int v2; // r7
  unsigned int v3; // r4
  unsigned int v4; // r1
  unsigned int *v6; // r4
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r5
  unsigned int v10; // r4
  unsigned int v11; // r1

  v1 = (unsigned int *)(a1 + 268);
  __pld((void *)(a1 + 268));
  v2 = a1;
  v3 = *(_DWORD *)(a1 + 268) & 0xFFFFFFFE;
  do
    v4 = __ldrex(v1);
  while ( v4 == v3 && __strex(v3 + 2, v1) );
  __dmb(0xBu);
  if ( v4 != v3 )
    return sub_54B704();
  v6 = (unsigned int *)(a1 + 192);
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v2 + 192);
  }
  else
  {
    do
      v8 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(v2 + 192));
  }
  if ( (*(_DWORD *)(v2 + 196) & 2) != 0 )
  {
    v9 = -1073741431;
  }
  else if ( KiSetTimerEx(v2 + 104, v2 + 160, *(_QWORD *)(v2 + 152), 0, 0, v2 + 160) )
  {
    v9 = -1073741595;
  }
  else
  {
    *(_DWORD *)(v2 + 196) |= 1u;
    v2 = 0;
    v9 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v6);
  }
  else
  {
    __dmb(0xBu);
    *v6 = 0;
  }
  KfLowerIrql(v7);
  if ( v2 )
  {
    __pld(v1);
    v10 = *v1 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v11 = __ldrex(v1);
    while ( v11 == v10 && __strex(v10 - 2, v1) );
    if ( v11 != v10 )
      ExfReleaseRundownProtection((unsigned __int8 *)v1);
  }
  return v9;
}
