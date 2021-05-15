// sub_54ACCC 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_54ACCC(int a1, int a2, int a3)
{
  return KiAcquireQueuedSpinLockInstrumented(a1, a3);
}
