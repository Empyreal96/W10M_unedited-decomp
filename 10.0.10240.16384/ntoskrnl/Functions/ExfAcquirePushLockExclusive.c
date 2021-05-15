// ExfAcquirePushLockExclusive 
 
int __fastcall ExfAcquirePushLockExclusive(int a1)
{
  return ExfAcquirePushLockExclusiveEx(a1, 0, a1);
}
