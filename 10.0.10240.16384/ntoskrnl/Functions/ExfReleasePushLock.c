// ExfReleasePushLock 
 
int __fastcall ExfReleasePushLock(_DWORD *a1, int a2)
{
  int result; // r0

  __pld(a1);
  if ( (*a1 & 2) != 0 || (*a1 & 0xFFFFFFF0) != 0 )
    result = ExfReleasePushLockShared(a1, a2);
  else
    result = ExfReleasePushLockExclusive(a1);
  return result;
}
