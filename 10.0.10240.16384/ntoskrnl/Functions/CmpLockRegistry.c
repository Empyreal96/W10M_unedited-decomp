// CmpLockRegistry 
 
int CmpLockRegistry()
{
  unsigned int v0; // r2
  int result; // r0

  if ( !CmpPuntBoot )
  {
    PsBoostThreadIo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
    v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v0 + 308);
    result = ExAcquireResourceSharedLite((int)&CmpRegistryLock, 1);
  }
  return result;
}
