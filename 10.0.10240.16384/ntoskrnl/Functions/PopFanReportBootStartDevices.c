// PopFanReportBootStartDevices 
 
int PopFanReportBootStartDevices()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  do
    v2 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v2 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( !v2 )
    JUMPOUT(0x9669F6);
  return sub_9669EC(v1, 17);
}
