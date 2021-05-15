// PopUmpoSendReapplyBrightnessSettings 
 
int PopUmpoSendReapplyBrightnessSettings()
{
  _BYTE *v0; // r0
  int result; // r0
  int v2[20]; // [sp+0h] [bp-50h] BYREF

  v0 = memset(v2, 0, 68);
  v2[0] = 13;
  if ( (PoDebug & 0x10000000) != 0 )
    result = sub_555C20(v0);
  else
    result = PopUmpoSendPowerMessage((int)v2, 0x44u);
  return result;
}
