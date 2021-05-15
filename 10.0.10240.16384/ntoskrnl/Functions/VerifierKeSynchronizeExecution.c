// VerifierKeSynchronizeExecution 
 
int __fastcall VerifierKeSynchronizeExecution(int a1, int a2, int a3)
{
  int v6; // r3
  unsigned int vars4; // [sp+14h] [bp+4h]

  v6 = dword_620D8C + 1;
  __dmb(0xBu);
  dword_620D8C = v6;
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetIncrementCounter(vars4, 80, a3, MmVerifierData);
  ViKeRaiseIrqlSanityChecks(*(unsigned __int8 *)(a1 + 49), 0);
  return pXdvKeSynchronizeExecution(a1, a2, a3);
}
