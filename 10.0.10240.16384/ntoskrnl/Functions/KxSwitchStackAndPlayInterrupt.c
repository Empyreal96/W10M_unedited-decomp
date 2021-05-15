// KxSwitchStackAndPlayInterrupt 
 
int __fastcall KxSwitchStackAndPlayInterrupt(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  _BYTE v7[8]; // [sp+0h] [bp-8h] BYREF

  v5 = a5 - 8;
  *(_DWORD *)(v5 + 4) = v7;
  *(_DWORD *)(v5 + 4) = v7;
  return KiPlayInterrupt();
}
