// sub_7CFC2C 
 
void sub_7CFC2C()
{
  int v0; // r5
  _BYTE *v1; // r6
  int v2; // r7
  unsigned int v3; // r4
  int v4; // r6
  int v5; // r8
  unsigned int v6; // r2
  int v7; // r5
  unsigned int v8; // r1

  if ( !ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(v0 + 156), 1) )
  {
    if ( *v1 == 27 )
    {
      v3 = v0 + 160;
      v4 = KeAbPreAcquire(v0 + 160, 0, 0);
      v5 = KfRaiseIrql(1);
      do
        v6 = __ldrex((unsigned __int8 *)v3);
      while ( __strex(v6 & 0xFE, (unsigned __int8 *)v3) );
      __dmb(0xBu);
      if ( (v6 & 1) == 0 )
        ExpAcquireFastMutexContended(v0 + 160, v4);
      if ( v4 )
        *(_BYTE *)(v4 + 14) |= 1u;
      *(_DWORD *)(v0 + 164) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v0 + 188) = v5;
      --*(_DWORD *)(v0 + 80);
      if ( *(_DWORD *)(v0 + 76) || !RawInitiateDeleteVolume(v0, 0, 0) )
      {
        v7 = *(_DWORD *)(v0 + 188);
        *(_DWORD *)(v3 + 4) = 0;
        __dmb(0xBu);
        do
          v8 = __ldrex((unsigned int *)v3);
        while ( !v8 && __strex(1u, (unsigned int *)v3) );
        if ( v8 )
          ExpReleaseFastMutexContended((unsigned int *)v3, v8);
        KfLowerIrql((unsigned __int8)v7);
        KeAbPostRelease(v3);
      }
    }
    *(_DWORD *)(v2 + 24) = -1073741202;
    IofCompleteRequest(v2, 1);
    JUMPOUT(0x789684);
  }
  JUMPOUT(0x789644);
}
