// PopArePowerSettingsEqual 
 
BOOL __fastcall PopArePowerSettingsEqual(int a1, int a2, int a3)
{
  return a1 && a2 && *(_DWORD *)(a1 + 4) == a3 && RtlCompareMemory((unsigned __int8 *)(a1 + 12), a2, a3) == a3;
}
