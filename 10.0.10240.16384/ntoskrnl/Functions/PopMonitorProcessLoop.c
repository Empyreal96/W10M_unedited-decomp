// PopMonitorProcessLoop 
 
int PopMonitorProcessLoop()
{
  int result; // r0
  int v1; // r1
  signed int v2; // r3
  int v3[19]; // [sp+1Ch] [bp-8Ch] BYREF
  unsigned __int16 v4; // [sp+6Ch] [bp-3Ch]
  int v5; // [sp+80h] [bp-28h]
  int v6; // [sp+84h] [bp-24h]

  result = ZwAlpcSendWaitReceivePort();
  if ( result )
    return result;
  while ( 1 )
  {
    v2 = v4 & 0xFFFF00FF;
    if ( v2 != 3 )
      break;
    v3[0] = v6;
    if ( v5 )
    {
      if ( v5 == 2 )
      {
        PopUmpoSendHotKey(v6, v1, 1, 2);
      }
      else if ( v5 == 3 )
      {
        PopSetPowerSettingValueAcDc(&GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS, 4, v3);
      }
    }
    else
    {
      PopUmpoSendBrightness(v6, v6, 1);
    }
LABEL_7:
    result = ZwAlpcSendWaitReceivePort();
    if ( result )
      return result;
  }
  if ( v2 <= 4 )
    goto LABEL_19;
  if ( v2 <= 6 )
  {
    ZwClose();
    if ( (PoDebug & 2) != 0 )
      DbgPrint("%s: monitor disconnected.\n", "PopMonitorProcessLoop");
    PopAlpcMonitorClientPort = 0;
    goto LABEL_7;
  }
  if ( v2 != 10 )
  {
LABEL_19:
    if ( (PoDebug & 1) != 0 )
      JUMPOUT(0x7F2610);
    goto LABEL_7;
  }
  if ( !PopAlpcMonitorClientPort )
    JUMPOUT(0x7F258C);
  return sub_7F2584();
}
