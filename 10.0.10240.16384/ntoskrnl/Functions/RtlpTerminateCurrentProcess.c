// RtlpTerminateCurrentProcess 
 
int RtlpTerminateCurrentProcess()
{
  return PsTerminateProcess(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), -1073741823);
}
