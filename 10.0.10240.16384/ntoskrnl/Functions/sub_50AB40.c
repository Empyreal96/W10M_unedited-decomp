// sub_50AB40 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_50AB40(int a1)
{
  return ExpTryAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
}
