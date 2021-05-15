// VerifierEtwUnregister 
 
int __fastcall VerifierEtwUnregister(unsigned int a1, unsigned int a2)
{
  VfTargetEtwUnregister(a1, a2);
  return pXdvEtwUnregister(a1, a2);
}
