// MiReturnImageBase 
 
int __fastcall MiReturnImageBase(int result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r8
  int v3; // r6
  unsigned int v4; // r1
  unsigned int v5; // r0
  int v6; // r3

  v1 = (unsigned int *)result;
  if ( *(_DWORD *)result != -1 )
  {
    if ( *(_BYTE *)(result + 12) == 1 )
    {
      if ( *(_BYTE *)(result + 13) == 1 )
        result = MiReturnSystemImageAddress(dword_63389C + (*(_DWORD *)result << 16), *(_DWORD *)(result + 4) << 16);
    }
    else
    {
      MiZeroCfgSystemWideBitmap();
      v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v2 + 310);
      v3 = KeAbPreAcquire((unsigned int)algn_632EC4, 0, 0);
      do
        v4 = __ldrex((unsigned __int8 *)algn_632EC4);
      while ( __strex(v4 | 1, (unsigned __int8 *)algn_632EC4) );
      __dmb(0xBu);
      if ( (v4 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(algn_632EC4, v3, (unsigned int)algn_632EC4);
      if ( v3 )
        *(_BYTE *)(v3 + 14) |= 1u;
      RtlClearBits(&dword_632EC8, *v1, v1[1]);
      __dmb(0xBu);
      do
        v5 = __ldrex((unsigned int *)algn_632EC4);
      while ( __strex(v5 - 1, (unsigned int *)algn_632EC4) );
      if ( (v5 & 2) != 0 )
      {
        result = sub_80216C();
      }
      else
      {
        result = KeAbPostRelease((unsigned int)algn_632EC4);
        v6 = (__int16)(*(_WORD *)(v2 + 310) + 1);
        *(_WORD *)(v2 + 310) = v6;
        if ( !v6 && *(_DWORD *)(v2 + 100) != v2 + 100 )
          result = KiCheckForKernelApcDelivery(result);
      }
    }
  }
  return result;
}
