// VfKeCheckForChanges 
 
_BYTE *__fastcall VfKeCheckForChanges(_BYTE *result)
{
  __int16 v1; // r7
  unsigned int v2; // r3
  int v3; // r3
  unsigned int v4; // r8
  int v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r3
  int v8; // r3
  unsigned int v9; // r5
  int v10; // r3
  unsigned int v11; // r2

  v1 = (__int16)result;
  if ( (MmVerifierData & 0xFBF) != 0 )
  {
    if ( !ViTrackIrqlQueue && (((unsigned __int8)result & 2) != 0 || VfVerifyMode >= 3) )
    {
      v2 = ViTrackIrqlQueueLength;
      __dmb(0xBu);
      if ( v2 > 0x10000 )
      {
        __dmb(0xBu);
        ViTrackIrqlQueueLength = 0x10000;
      }
      v3 = ViTrackIrqlQueueLength;
      __dmb(0xBu);
      result = (_BYTE *)ExAllocatePoolWithTagPriority(512, 32 * v3, 1819374153, 32);
      v4 = (unsigned int)result;
      if ( result )
      {
        v5 = ViTrackIrqlQueueLength;
        __dmb(0xBu);
        result = memset(result, 0, 32 * v5);
        __dmb(0xBu);
        do
          v6 = __ldrex((unsigned int *)&ViTrackIrqlQueue);
        while ( !v6 && __strex(v4, (unsigned int *)&ViTrackIrqlQueue) );
        __dmb(0xBu);
        if ( v6 )
          result = (_BYTE *)ExFreePoolWithTag(v4);
      }
    }
    if ( !VfKeCriticalRegionTraces && (v1 & 0x800) != 0 )
    {
      v7 = VfKeCriticalRegionTracesLength;
      __dmb(0xBu);
      if ( v7 > 0x10000 )
      {
        __dmb(0xBu);
        VfKeCriticalRegionTracesLength = 0x10000;
      }
      v8 = VfKeCriticalRegionTracesLength;
      __dmb(0xBu);
      result = (_BYTE *)ExAllocatePoolWithTagPriority(512, 32 * v8, 1380148822, 32);
      v9 = (unsigned int)result;
      if ( result )
      {
        v10 = VfKeCriticalRegionTracesLength;
        __dmb(0xBu);
        result = memset(result, 0, 32 * v10);
        __dmb(0xBu);
        do
          v11 = __ldrex((unsigned int *)&VfKeCriticalRegionTraces);
        while ( !v11 && __strex(v9, (unsigned int *)&VfKeCriticalRegionTraces) );
        __dmb(0xBu);
        if ( v11 )
          result = (_BYTE *)ExFreePoolWithTag(v9);
      }
    }
  }
  return result;
}
