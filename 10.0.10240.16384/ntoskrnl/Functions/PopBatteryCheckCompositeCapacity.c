// PopBatteryCheckCompositeCapacity 
 
unsigned int __fastcall PopBatteryCheckCompositeCapacity(unsigned int result, int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r2
  unsigned int v6; // r4
  unsigned int v7; // r1
  int v8; // r0
  int v9; // r1
  int v10; // r9
  int v11; // r10
  int v12; // r4
  unsigned int v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = a4;
  if ( dword_61ED6C )
  {
    v5 = *(_DWORD *)(result + 4);
    if ( v5 != dword_61ED88 )
    {
      result = dword_61EDA8;
      v6 = 100;
      v13[0] = 100;
      if ( dword_61EDA8 > v5 )
      {
        v7 = 100 * v5 + ((unsigned int)dword_61EDA8 >> 1);
        if ( !dword_61EDA8 )
          __brkdiv0();
        result = v7 / dword_61EDA8;
        v6 = v7 / dword_61EDA8;
        v13[0] = v7 / dword_61EDA8;
      }
      if ( v6 != dword_61EE70 )
      {
        v8 = KeQueryInterruptTime();
        v10 = v9;
        v11 = v8;
        if ( dword_61EE70 == -1 )
        {
          PopSetPowerSettingValueAcDc((int *)&GUID_BATTERY_PERCENTAGE_REMAINING, 4u, (int)v13);
          v12 = v13[0];
          PopSqmBatteryUpdate(v13[0], 0, a2, 0);
          result = PopBatteryTracePercentageRemaining(v12, 0, a2, 0);
          dword_61EE70 = v12;
          unk_61EE78 = v11;
          unk_61EE7C = v10;
        }
        else
        {
          result = sub_7F36C8();
        }
      }
    }
  }
  return result;
}
