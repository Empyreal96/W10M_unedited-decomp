// sub_7E0CF4 
 
void sub_7E0CF4()
{
  int v0; // r7
  unsigned int v1; // r2

  v0 = KeAbPreAcquire((unsigned int)&PiResourceListLock, 0, 0);
  KfRaiseIrql(1);
  do
    v1 = __ldrex((unsigned __int8 *)&PiResourceListLock);
  while ( __strex(v1 & 0xFE, (unsigned __int8 *)&PiResourceListLock) );
  __dmb(0xBu);
  if ( (v1 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PiResourceListLock, v0);
  if ( v0 )
    *(_BYTE *)(v0 + 14) |= 1u;
  JUMPOUT(0x777E00);
}
