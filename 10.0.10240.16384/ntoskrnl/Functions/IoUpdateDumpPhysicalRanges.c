// IoUpdateDumpPhysicalRanges 
 
int __fastcall IoUpdateDumpPhysicalRanges(int result, int a2, int a3)
{
  unsigned int v3; // r4
  __int16 v4; // r3
  int v5; // r1

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  if ( CrashdmpImageEntry )
  {
    if ( CrashdmpInitialized == 1 )
    {
      result = ExAcquireResourceExclusiveLite((int)&IopCrashDumpLock, 1, a3, 1);
      if ( result )
      {
        if ( IopGetPhysicalMemoryBlock(result, v5) )
          dword_637668();
        result = ExpReleaseResourceForThreadLite((int)&IopCrashDumpLock, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      }
    }
  }
  if ( OfflineDumpEnabled )
    result = IopConstructInMemoryDumpHeader(result);
  v4 = *(_WORD *)(v3 + 308) + 1;
  *(_WORD *)(v3 + 308) = v4;
  if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
