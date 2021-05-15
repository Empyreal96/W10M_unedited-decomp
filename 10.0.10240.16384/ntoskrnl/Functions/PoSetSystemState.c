// PoSetSystemState 
 
int __fastcall PoSetSystemState(int a1)
{
  int v2; // r4
  unsigned int v3; // r0
  int v4; // r1
  int result; // r0

  v2 = 0;
  v3 = KeGetCurrentIrql(a1);
  if ( v3 < 2 )
  {
    PopAcquirePolicyLock(v3, v4);
    v2 = 1;
  }
  result = PopSetSystemState(a1, 7);
  if ( v2 )
    result = PopReleasePolicyLock(result);
  return result;
}
