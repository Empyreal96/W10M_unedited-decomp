// PoUnblockConsoleSwitch 
 
int __fastcall PoUnblockConsoleSwitch(int a1, int a2)
{
  int v3; // [sp+Ch] [bp-4h] BYREF

  v3 = a2;
  *(_DWORD *)(a1 + 16) = 7;
  return PopDispatchStateCallout(a1, (int)&v3);
}
