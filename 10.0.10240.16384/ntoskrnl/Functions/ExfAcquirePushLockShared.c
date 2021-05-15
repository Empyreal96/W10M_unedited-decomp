// ExfAcquirePushLockShared 
 
int __fastcall ExfAcquirePushLockShared(int a1)
{
  return ExfAcquirePushLockSharedEx(a1, 0, a1);
}
