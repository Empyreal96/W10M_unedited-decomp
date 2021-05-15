// PoDeletePowerRequest 
 
int __fastcall PoDeletePowerRequest(int a1, int a2, int a3, int a4)
{
  PopPowerRequestCleanUp(a1, a2, a3, a4);
  return ObfDereferenceObject(a1);
}
