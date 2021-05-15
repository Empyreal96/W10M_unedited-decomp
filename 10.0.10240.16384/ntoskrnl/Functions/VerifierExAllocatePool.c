// VerifierExAllocatePool 
 
int __fastcall VerifierExAllocatePool(int a1, int a2)
{
  int vars4; // [sp+14h] [bp+4h]

  VfCheckPoolType(a1, vars4);
  ++dword_620D9C;
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetIncrementCounter(vars4);
  return pXdvExAllocatePoolWithTagPriority(a1 | 0x80, a2, 1885434455, 32);
}
