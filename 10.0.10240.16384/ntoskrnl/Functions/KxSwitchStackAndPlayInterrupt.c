// KxSwitchStackAndPlayInterrupt 
 
int __fastcall KxSwitchStackAndPlayInterrupt(__int64 a1, int a3, int a4, int a5)
{
  int v4; // r4
  _BYTE v6[8]; // [sp+0h] [bp-8h] BYREF

  v4 = a5 - 8;
  *(_DWORD *)(v4 + 4) = v6;
  *(_DWORD *)(v4 + 4) = v6;
  return KiPlayInterrupt(a1, a3, a4);
}
