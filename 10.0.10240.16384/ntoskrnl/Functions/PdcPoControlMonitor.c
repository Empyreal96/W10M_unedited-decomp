// PdcPoControlMonitor 
 
int __fastcall PdcPoControlMonitor(int a1, int a2)
{
  int var20[11]; // [sp+0h] [bp-20h] BYREF
  int varsC; // [sp+2Ch] [bp+Ch] BYREF

  var20[10] = a1;
  varsC = a2;
  memset(var20, 0, 24);
  var20[0] = 3;
  LOBYTE(var20[1]) = 0;
  var20[2] = 8;
  var20[3] = a1;
  var20[4] = 0;
  var20[5] = 0;
  return PsInvokeWin32Callout(5, var20, 1, &varsC);
}
