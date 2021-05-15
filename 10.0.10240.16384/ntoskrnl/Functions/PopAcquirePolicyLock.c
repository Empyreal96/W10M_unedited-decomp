// PopAcquirePolicyLock 
 
int PopAcquirePolicyLock()
{
  int v0; // r2
  int v1; // r3
  int result; // r0

  PsBoostThreadIo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = *(__int16 *)(v0 + 0x134) - 1;
  *(_WORD *)(v0 + 308) = v1;
  result = ExAcquireResourceExclusiveLite((int)&PopPolicyLock, 1, v0, v1);
  PopPolicyLockThread = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return result;
}
