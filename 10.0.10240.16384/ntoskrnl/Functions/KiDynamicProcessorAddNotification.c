// KiDynamicProcessorAddNotification 
 
int __fastcall KiDynamicProcessorAddNotification(int a1, int a2, __int16 a3, char a4, int a5, int a6)
{
  int v7; // [sp+0h] [bp-28h] BYREF
  _DWORD v8[3]; // [sp+8h] [bp-20h] BYREF
  __int16 v9; // [sp+14h] [bp-14h]
  char v10; // [sp+16h] [bp-12h]
  char v11; // [sp+17h] [bp-11h]
  int v12; // [sp+18h] [bp-10h]

  v10 = a4;
  v11 = 0;
  v8[0] = a1;
  v8[1] = a2;
  v12 = a5;
  v9 = a3;
  v8[2] = a6;
  v7 = 0;
  ExNotifyWithProcessing(ExCbProcessorAdd, (int)v8, (int)&v7, 0);
  return v7;
}
