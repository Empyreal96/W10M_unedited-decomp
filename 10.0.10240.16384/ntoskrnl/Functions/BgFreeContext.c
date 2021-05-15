// BgFreeContext 
 
unsigned int __fastcall BgFreeContext(int a1)
{
  unsigned int result; // r0

  result = BgpFwGetCurrentIrql(a1);
  if ( result <= 2 && a1 )
  {
    BgpFwAcquireLock(result);
    if ( (dword_619018 & 1) != 0 )
      ResFwFreeContext(a1);
    result = BgpFwReleaseLock();
  }
  return result;
}
