// PopReleasePolicyLock 
 
int PopReleasePolicyLock()
{
  unsigned int v0; // r1
  __int16 v1; // r3
  int result; // r0

  PopPolicyLockThread = 0;
  ExReleaseResourceLite((int)&PopPolicyLock);
  PopCheckForWork();
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = *(_WORD *)(v0 + 0x134) + 1;
  *(_WORD *)(v0 + 308) = v1;
  if ( v1 || *(_DWORD *)(v0 + 100) == v0 + 100 )
    result = PsBoostThreadIo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1);
  else
    result = sub_6947E4();
  return result;
}
