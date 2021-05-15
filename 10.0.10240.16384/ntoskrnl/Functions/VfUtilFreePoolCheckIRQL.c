// VfUtilFreePoolCheckIRQL 
 
int __fastcall VfUtilFreePoolCheckIRQL(int a1)
{
  BOOL v2; // r1

  v2 = KeGetCurrentIrql(a1) != 2;
  return VfPoolDelayFreeIfPossible(a1, v2);
}
