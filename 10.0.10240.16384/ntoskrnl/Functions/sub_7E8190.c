// sub_7E8190 
 
void sub_7E8190()
{
  char v0; // r3
  int v1; // r5
  int v2; // r6
  unsigned int v3; // r2
  unsigned int v4; // r1

  __dmb(0xFu);
  v0 = KiDynamicProcessorLock;
  __dmb(0xBu);
  if ( (v0 & 1) == 0 )
  {
    v1 = KeAbPreAcquire((unsigned int)&KiDynamicProcessorLock, 0, 0);
    v2 = KfRaiseIrql(1);
    do
      v3 = __ldrex((unsigned __int8 *)&KiDynamicProcessorLock);
    while ( __strex(v3 & 0xFE, (unsigned __int8 *)&KiDynamicProcessorLock) );
    __dmb(0xBu);
    if ( (v3 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&KiDynamicProcessorLock, v1);
    if ( v1 )
      *(_BYTE *)(v1 + 14) |= 1u;
    __mrc(15, 0, 13, 0, 3);
    dword_624E5C = v2;
    dword_624E44 = 0;
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&KiDynamicProcessorLock);
    while ( !v4 && __strex(1u, (unsigned int *)&KiDynamicProcessorLock) );
    if ( v4 )
      ExpReleaseFastMutexContended((unsigned int *)&KiDynamicProcessorLock, v4);
    KfLowerIrql((unsigned __int8)v2);
    KeAbPostRelease((unsigned int)&KiDynamicProcessorLock);
  }
  JUMPOUT(0x6FA1EE);
}
