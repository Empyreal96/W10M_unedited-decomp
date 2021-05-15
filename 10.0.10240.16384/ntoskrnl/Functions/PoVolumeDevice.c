// PoVolumeDevice 
 
int __fastcall PoVolumeDevice(int a1)
{
  int result; // r0
  int v2; // r6
  int v3; // r5
  int v4; // r0
  unsigned __int8 v5; // r7
  unsigned int v6; // r2
  unsigned int v7; // r1
  int **v8; // r0

  result = PopGetDope(a1);
  v2 = result;
  if ( result )
  {
    v3 = KeAbPreAcquire((unsigned int)&PopVolumeLock, 0, 0);
    v4 = KfRaiseIrql(1);
    v5 = v4;
    do
      v6 = __ldrex((unsigned __int8 *)&PopVolumeLock);
    while ( __strex(v6 & 0xFE, (unsigned __int8 *)&PopVolumeLock) );
    __dmb(0xBu);
    if ( (v6 & 1) != 0 )
    {
      if ( v3 )
        *(_BYTE *)(v3 + 14) |= 1u;
      dword_61EAE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_61EAFC = v4;
      if ( !*(_DWORD *)(v2 + 52) )
      {
        v8 = (int **)dword_61E95C;
        *(_DWORD *)(v2 + 52) = &PopVolumeDevices;
        *(_DWORD *)(v2 + 56) = v8;
        if ( *v8 != &PopVolumeDevices )
          __fastfail(3u);
        *v8 = (int *)(v2 + 52);
        dword_61E95C = v2 + 52;
        v5 = dword_61EAFC;
      }
      dword_61EAE4 = 0;
      __dmb(0xBu);
      do
        v7 = __ldrex(&PopVolumeLock);
      while ( !v7 && __strex(1u, &PopVolumeLock) );
      if ( v7 )
        ExpReleaseFastMutexContended(&PopVolumeLock, v7);
      KfLowerIrql(v5);
      result = KeAbPostRelease((unsigned int)&PopVolumeLock);
    }
    else
    {
      result = sub_7F1CA8();
    }
  }
  return result;
}
