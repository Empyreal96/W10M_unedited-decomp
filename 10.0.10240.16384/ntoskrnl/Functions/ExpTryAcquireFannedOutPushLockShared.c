// ExpTryAcquireFannedOutPushLockShared 
 
unsigned int *__fastcall ExpTryAcquireFannedOutPushLockShared(unsigned int a1)
{
  int v1; // r2
  unsigned int v2; // r3
  unsigned int *v3; // r4
  unsigned int v4; // r2

  v1 = (a1 >> 13) & 0x3FFFF;
  v2 = __clz(v1);
  v3 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x4CBC)
                                              + 4 * (29 - v2))
                                  + 4 * (v1 ^ (1 << (31 - v2)))
                                  + 4)
                      + 4 * ((a1 >> 3) & 0x3FF));
  do
    v4 = __ldrex(v3);
  while ( !v4 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v4 && !ExfTryAcquirePushLockShared(v3) )
    v3 = 0;
  return v3;
}
