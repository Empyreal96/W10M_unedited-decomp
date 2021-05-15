// PopCheckPowerSourceAfterRtcWakeCancel 
 
int PopCheckPowerSourceAfterRtcWakeCancel()
{
  int v1; // [sp+0h] [bp-10h]
  int v2[2]; // [sp+8h] [bp-8h] BYREF

  v2[0] = 0;
  v2[1] = 0;
  if ( KeWaitForSingleObject((unsigned int)&PopCheckPowerSourceAfterRtcWakeCompleted, 0, 0, 0, v2) )
  {
    if ( KeCancelTimer2((int)&PopCheckPowerSourceAfterRtcWakeTimer) )
      KeSetEvent((int)&PopCheckPowerSourceAfterRtcWakeCompleted, 0, 0);
    else
      KeWaitForSingleObject((unsigned int)&PopCheckPowerSourceAfterRtcWakeCompleted, 0, 0, 0, 0);
  }
  return v1;
}
