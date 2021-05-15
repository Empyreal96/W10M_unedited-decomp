// FsRtlTryToAcquireHeaderMutex 
 
int __fastcall FsRtlTryToAcquireHeaderMutex(int a1)
{
  unsigned int v1; // r5
  int v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  int result; // r0
  unsigned int v6; // r3

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 40);
  v2 = KeAbPreAcquire(v1, 0, 1);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)v1);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)v1) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
  {
    if ( v2 )
      *(_BYTE *)(v2 + 14) |= 1u;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v1 + 28) = v3;
    *(_DWORD *)(v1 + 4) = v6;
    result = 1;
  }
  else
  {
    KfLowerIrql(v3);
    if ( v2 )
      KeAbPostReleaseEx(v1, v2);
    __dmb(0xAu);
    __yield();
    result = 0;
  }
  return result;
}
