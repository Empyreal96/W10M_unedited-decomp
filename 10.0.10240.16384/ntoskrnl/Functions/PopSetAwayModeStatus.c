// PopSetAwayModeStatus 
 
int __fastcall PopSetAwayModeStatus(int a1)
{
  char v1; // r8
  int result; // r0
  BOOL v3[2]; // [sp+0h] [bp-38h] BYREF
  _DWORD v4[12]; // [sp+8h] [bp-30h] BYREF

  v1 = a1;
  v3[0] = a1 != 0;
  v4[0] = -1733823104;
  v4[1] = 1219101175;
  v4[2] = 893652892;
  v4[3] = -1058723540;
  v4[4] = v3[0];
  PopBroadcastSessionInfo(a1, -1733823104, (int)v4);
  result = PopSetPowerSettingValueAcDc((int *)&GUID_SYSTEM_AWAYMODE, 4u, (int)v3);
  byte_61EC11 = v1;
  return result;
}
