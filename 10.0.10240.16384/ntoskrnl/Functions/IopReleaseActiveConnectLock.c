// IopReleaseActiveConnectLock 
 
int __fastcall IopReleaseActiveConnectLock(int result)
{
  if ( *(_DWORD *)(result + 12) )
    result = IopAcquireReleaseConnectLockInternal();
  return result;
}
