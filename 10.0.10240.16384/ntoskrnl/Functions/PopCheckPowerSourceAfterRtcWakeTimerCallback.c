// PopCheckPowerSourceAfterRtcWakeTimerCallback 
 
int PopCheckPowerSourceAfterRtcWakeTimerCallback()
{
  return PopQueueWorkItem(&PopCheckPowerSourceAfterRtcWakeTimer[22]);
}
