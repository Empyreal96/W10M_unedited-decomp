// _CmIsLocalMachineContainer 
 
BOOL __fastcall CmIsLocalMachineContainer(int a1, unsigned __int16 *a2)
{
  BOOL v3; // r4
  int v5; // [sp+10h] [bp-68h] BYREF
  char v6[4]; // [sp+14h] [bp-64h] BYREF
  char v7[76]; // [sp+18h] [bp-60h] BYREF
  __int16 v8; // [sp+64h] [bp-14h]

  v5 = 78;
  v3 = 0;
  if ( CmGetDeviceRegProp(a1, (int)L"HTREE\\ROOT\\0", 0, 37, (int)v6, (int)v7, (int)&v5) >= 0 )
  {
    v8 = 0;
    v3 = wcsicmp((int)v7, a2) == 0;
  }
  return v3;
}
