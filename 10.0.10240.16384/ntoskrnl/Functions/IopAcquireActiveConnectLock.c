// IopAcquireActiveConnectLock 
 
int __fastcall IopAcquireActiveConnectLock(int result)
{
  if ( *(_DWORD *)(result + 12) )
    result = IopAcquireReleaseConnectLockInternal();
  return result;
}
