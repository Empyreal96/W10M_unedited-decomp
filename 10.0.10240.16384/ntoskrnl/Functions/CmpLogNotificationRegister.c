// CmpLogNotificationRegister 
 
int *__fastcall CmpLogNotificationRegister(int a1, int a2, char a3, char a4, char a5)
{
  _DWORD v6[2]; // [sp+8h] [bp-30h] BYREF
  char v7; // [sp+10h] [bp-28h]
  char v8; // [sp+11h] [bp-27h]
  char v9; // [sp+12h] [bp-26h]
  int v10[8]; // [sp+18h] [bp-20h] BYREF

  v8 = a4;
  v6[0] = a1;
  v6[1] = a2;
  v7 = a3;
  v9 = a5;
  v10[0] = (int)v6;
  v10[1] = 0;
  v10[2] = 11;
  v10[3] = 0;
  return EtwTraceKernelEvent(v10, 1, 0x42000000u, 2352, 5249282);
}
