// VerifierExAllocatePoolWithTagPriority 
 
int __fastcall VerifierExAllocatePoolWithTagPriority(int a1, int a2, int a3, int a4)
{
  int vars4; // [sp+24h] [bp+4h]

  VfCheckPoolType(a1, vars4);
  return pXdvExAllocatePoolWithTagPriority(a1 | 0x80, a2, a3, a4);
}
