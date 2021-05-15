// PopBatteryApplyCompositeState 
 
int __fastcall PopBatteryApplyCompositeState(int *a1, int a2)
{
  bool v4; // zf
  int v5; // r2
  unsigned int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int i; // r4
  int v12; // r7
  int v13; // r4
  int v14; // r0
  int v15; // r0
  char v16; // [sp+10h] [bp-58h] BYREF
  int v17; // [sp+14h] [bp-54h]
  _DWORD v18[20]; // [sp+18h] [bp-50h] BYREF

  v4 = (*a1 & 1) == 0;
  v17 = 0;
  v13 = v4;
  PopAcquirePolicyLock();
  if ( dword_61EC0C != v13 )
  {
    dword_61EC0C = v13;
    PopDiagTraceAcDcStateChange(v13);
    PopBatteryUpdateAlarms(1, 0);
    v14 = PopSetNotificationWork(4);
    PopInitSIdle(v14);
    v15 = PopInitilizeAcDcSettings();
    PpmProfileAcDcUpdate(v15);
    v17 = 1;
  }
  if ( byte_61ED70 )
  {
    PopSetPowerSettingValueAcDc((int *)&GUID_BATTERY_COUNT, 4u, (int)&dword_61ED6C);
    v17 = 1;
  }
  PopReleasePolicyLock();
  v5 = *a1;
  if ( *a1 != dword_61ED84 || (v6 = (unsigned __int8)byte_61ED70, byte_61ED70) )
  {
    PopSetNotificationWork(8);
    v6 = 0;
    byte_61ED70 = 0;
  }
  PopBatteryCheckCompositeCapacity((unsigned int)a1, v13, v5, v6);
  v7 = a1[1];
  v8 = a1[2];
  v9 = a1[3];
  dword_61ED84 = *a1;
  dword_61ED88 = v7;
  dword_61ED8C = v8;
  dword_61ED90 = v9;
  dword_61ED94 = a2;
  DbgPrintEx(
    146,
    3,
    (int)"\n"
         "Composite Status\n"
         "|-- PowerState = 0x%08x\n"
         "|-- Capacity   = %u\n"
         "|-- Voltage    = %u\n"
         "|-- Rate       = %d\n"
         "|-- Est Time   = %u\n",
    dword_61ED84);
  PopRecalculateCBTriggerLevels();
  PopBatteryTraceSystemBatteryStatus(0);
  PopAcquirePolicyLock();
  for ( i = 0; i < 4; ++i )
  {
    if ( PopBatteryCheckTrigger(&dword_61EE30[4 * i]) )
      return sub_7F3700();
    PopCB[4 * i + 53] &= 0xFFFFFFFC;
    if ( i == 1 && PopBatteryLowLastState )
    {
      if ( (unsigned int)dword_6163C8 > 5 && TlgKeywordOn((int)&dword_6163C8, 0x800000000000i64) )
      {
        v18[8] = &v16;
        v18[9] = 0;
        v18[10] = 1;
        v18[11] = 0;
        v16 = 0;
        TlgWrite(&dword_6163C8, (unsigned __int8 *)&word_41422E + 1, 0, 0, 3, v18);
      }
      PopBatteryLowLastState = 0;
    }
  }
  v12 = v17;
  if ( v17 )
    PopTracePowerReconfig();
  PopEsBatteryStatusChanged(v12);
  return PopReleasePolicyLock();
}
