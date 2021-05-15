// VerifierKfRaiseIrql 
 
int __fastcall VerifierKfRaiseIrql(int a1)
{
  int (__fastcall *v2)(int); // r5
  int v3; // r3
  int v4; // r4
  int v5; // r5
  unsigned int vars4; // [sp+14h] [bp+4h]

  v2 = (int (__fastcall *)(int))pXdvKfRaiseIrql;
  v3 = dword_620D84 + 1;
  __dmb(0xBu);
  dword_620D84 = v3;
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetIncrementCounter(vars4, 72, (int)&MmVerifierData, MmVerifierData);
  v4 = ViKeRaiseIrqlSanityChecks(a1, 0);
  if ( ViKernelVerifierOriginalCalls )
    v2 = (int (__fastcall *)(int))ViKernelVerifierOriginalCalls;
  v5 = v2(a1);
  if ( v4 )
    *(_WORD *)(v4 + 6) = KeGetCurrentProcessorNumberEx(0);
  return v5;
}
