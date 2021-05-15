// PopCheckPowerSourceAfterRtcWakeInitialize 
 
int PopCheckPowerSourceAfterRtcWakeInitialize()
{
  PopInitializeTimer(
    &PopCheckPowerSourceAfterRtcWakeTimer,
    PopCheckPowerSourceAfterRtcWakeTimerCallback,
    0,
    PopCheckPowerSourceAfterRtcWakeTimerWorker);
  PopCheckPowerSourceAfterRtcWakeCompleted = 0;
  byte_61E251 = 0;
  byte_61E252 = 4;
  dword_61E254 = 1;
  dword_61E25C = (int)&dword_61E258;
  dword_61E258 = (int)&dword_61E258;
  return 0;
}
