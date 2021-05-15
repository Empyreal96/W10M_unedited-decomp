// PoSetUserPresent 
 
int __fastcall PoSetUserPresent(int a1)
{
  int v2; // r4
  int result; // r0

  v2 = 0;
  if ( (unsigned int)KeGetCurrentIrql(a1) < 2 )
  {
    PopAcquirePolicyLock();
    v2 = 1;
  }
  result = PopSetSystemState(4, a1);
  if ( v2 )
    result = PopReleasePolicyLock();
  return result;
}
