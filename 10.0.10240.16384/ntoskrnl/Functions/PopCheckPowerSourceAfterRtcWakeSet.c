// PopCheckPowerSourceAfterRtcWakeSet 
 
int PopCheckPowerSourceAfterRtcWakeSet()
{
  _DWORD v1[6]; // [sp+10h] [bp-18h] BYREF

  KeResetEvent((int)&PopCheckPowerSourceAfterRtcWakeCompleted);
  v1[0] = 0;
  v1[1] = 0;
  v1[2] = -1;
  v1[3] = -1;
  return KeSetTimer2(
           PopCheckPowerSourceAfterRtcWakeTimer,
           -10000000i64 * (unsigned int)PopCheckPowerSourceAfterRtcWakeTime,
           0i64,
           (int)v1);
}
