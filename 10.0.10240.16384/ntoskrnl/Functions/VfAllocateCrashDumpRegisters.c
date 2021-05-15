// VfAllocateCrashDumpRegisters 
 
int __fastcall VfAllocateCrashDumpRegisters(int a1, unsigned int *a2)
{
  int v4; // r8
  int v5; // r6
  unsigned int v6; // r2
  unsigned int *v7; // r4
  unsigned int v8; // r5

  if ( (unsigned int)KeGetCurrentIrql(a1) > 2 )
    VfDisableHalVerifier();
  v4 = ViGetAdapterInformationInternal(a1, 1);
  v5 = HalAllocateCrashDumpRegisters(a1, a2);
  if ( v4 )
  {
    VF_ASSERT_IRQL(2);
    __dmb(0xBu);
    v6 = *a2;
    v7 = (unsigned int *)(v4 + 80);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 + v6, v7) );
    __dmb(0xBu);
    ADD_MAP_REGISTERS(v4, *a2, 0);
    if ( ViVerifyDma )
    {
      if ( !v5 )
        v5 = -559026163;
    }
  }
  return v5;
}
