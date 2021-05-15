// VfUtilFreePoolDispatchLevel 
 
int __fastcall VfUtilFreePoolDispatchLevel(int a1)
{
  return VfPoolDelayFreeIfPossible(a1, 0);
}
