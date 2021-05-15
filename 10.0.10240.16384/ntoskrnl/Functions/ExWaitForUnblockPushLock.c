// ExWaitForUnblockPushLock 
 
int __fastcall ExWaitForUnblockPushLock(int a1, int a2)
{
  return ExTimedWaitForUnblockPushLock(a1, a2);
}
