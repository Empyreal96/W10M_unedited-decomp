// PopThermalInit 
 
int PopThermalInit()
{
  int result; // r0
  unsigned int i; // r1

  dword_61E70C = 0;
  PopThermalLock = 0;
  dword_61E61C = 0;
  PopThermalTelemetryLock = 0;
  PopSystemThermalInfo = 1;
  PopInitializeTimer(PopThermalTelemetryTimer, (int)PopThermalTelemetryCallback, 0, (int)PopThermalTelemetryWorker, 0);
  result = 0;
  for ( i = 0; i < 0x7D0; i += 100 )
    PopThermalTrackingThresholds[result++] = i / 0x14;
  return result;
}
