// VerifierExAllocateCacheAwareRundownProtection 
 
int __fastcall VerifierExAllocateCacheAwareRundownProtection(int a1, int a2)
{
  int vars4; // [sp+Ch] [bp+4h]

  VfCheckPoolType(a1, vars4, a2);
  return pXdvExAllocateCacheAwareRundownProtection(a1, a2);
}
