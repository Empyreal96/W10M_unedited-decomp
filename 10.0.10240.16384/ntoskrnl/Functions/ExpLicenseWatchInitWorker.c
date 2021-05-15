// ExpLicenseWatchInitWorker 
 
int ExpLicenseWatchInitWorker()
{
  _DWORD *v0; // r3
  int result; // r0
  int v2; // r4

  v0 = KiProcessorBlock;
  result = *((_DWORD *)KiProcessorBlock + 257);
  *((_DWORD *)KiProcessorBlock + 257) = 0;
  v0[256] = 0;
  v2 = (InitSafeBootMode != 0) | (MEMORY[0xFFFF92D4] >> 1);
  if ( __mrc(15, 0, 9, 13, 0) % 0x64u > 3 )
    v2 |= 1u;
  if ( !v2 )
    result = sub_96E174(result);
  return result;
}
