// ExpAcquireFannedOutPushLockShared 
 
unsigned int *__fastcall ExpAcquireFannedOutPushLockShared(unsigned int a1, int a2, unsigned int a3)
{
  int v3; // r4
  unsigned int v4; // r3
  unsigned int *v5; // r5
  unsigned int v6; // r4

  v3 = (a1 >> 13) & 0x3FFFF;
  v4 = __clz(v3);
  v5 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x4CBC)
                                              + 4 * (29 - v4))
                                  + 4 * (v3 ^ (1 << (31 - v4)))
                                  + 4)
                      + 4 * ((a1 >> 3) & 0x3FF));
  do
    v6 = __ldrex(v5);
  while ( !v6 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v6 )
    ExfAcquirePushLockSharedEx(v5, a2, a3);
  return v5;
}
