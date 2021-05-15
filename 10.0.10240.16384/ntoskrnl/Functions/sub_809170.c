// sub_809170 
 
void sub_809170(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  int v7; // r5
  int v8; // [sp+8h] [bp+8h] BYREF
  va_list va; // [sp+8h] [bp+8h]
  int v10; // [sp+Ch] [bp+Ch]
  va_list va1; // [sp+10h] [bp+10h] BYREF

  va_start(va1, a6);
  va_start(va, a6);
  v8 = va_arg(va1, _DWORD);
  v10 = va_arg(va1, _DWORD);
  PfSnBuildScenarioEventDescriptors(v7 + 16, v7 + 80, (int *)va, va1);
  EtwWrite(*(_DWORD *)(v6 + 152), *(_DWORD *)(v6 + 156), (int)PfSnEvt_GetReadLists_Stop, 0);
  JUMPOUT(0x75D242);
}
