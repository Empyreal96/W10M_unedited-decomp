// ExAcquireTimeRefreshLock 
 
int __fastcall ExAcquireTimeRefreshLock(int a1)
{
  int v1; // r2
  int v2; // r3
  int result; // r0

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(__int16 *)(v1 + 0x134) - 1;
  *(_WORD *)(v1 + 308) = v2;
  if ( ExAcquireResourceExclusiveLite((int)&ExpTimeRefreshLock, a1, v1, v2) )
    result = 1;
  else
    result = sub_7C3E88();
  return result;
}
