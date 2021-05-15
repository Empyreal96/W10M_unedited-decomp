// KiReleaseInterruptConnectLock 
 
int __fastcall KiReleaseInterruptConnectLock(int a1, int a2)
{
  KfLowerIrql(a1);
  return KeRevertToUserGroupAffinityThread(a2);
}
