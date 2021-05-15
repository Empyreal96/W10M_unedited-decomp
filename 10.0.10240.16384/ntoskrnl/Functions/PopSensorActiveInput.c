// PopSensorActiveInput 
 
int __fastcall PopSensorActiveInput(_DWORD *a1, int a2)
{
  int v2; // r7
  _DWORD v5[12]; // [sp-4h] [bp-30h] BYREF

  v2 = a1[1];
  PopNotifyConsoleUserPresent(0, a2, a1[5]);
  v5[0] = 1868437176;
  v5[1] = 1075086709;
  v5[2] = 1596000690;
  v5[3] = -841524783;
  v5[4] = a1[3];
  PopSendSessionInfo(v2, 1868437176, 1075086709, (int)v5);
  return PopSetWin32kInputTimeout(v2, a1[2]);
}
