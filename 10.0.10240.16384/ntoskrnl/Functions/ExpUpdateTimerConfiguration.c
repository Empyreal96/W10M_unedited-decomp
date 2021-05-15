// ExpUpdateTimerConfiguration 
 
int __fastcall ExpUpdateTimerConfiguration(int a1, int a2, int a3)
{
  char v4[4]; // [sp+0h] [bp-28h] BYREF
  int v5; // [sp+4h] [bp-24h]
  int v6; // [sp+8h] [bp-20h]
  int v7; // [sp+Ch] [bp-1Ch]
  __int16 v8[2]; // [sp+10h] [bp-18h] BYREF
  int v9; // [sp+14h] [bp-14h]
  int v10; // [sp+18h] [bp-10h]

  v8[0] = 1;
  v8[1] = 1;
  v9 = 0;
  v5 = a2;
  v6 = a3;
  v10 = 1 << KiClockTimerOwner;
  KeGenericProcessorCallback(v8, (int)ExpUpdateTimerConfigurationWorker, (int)v4, 1, a1);
  return v7;
}
