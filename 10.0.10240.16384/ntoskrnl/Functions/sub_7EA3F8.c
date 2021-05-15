// sub_7EA3F8 
 
void sub_7EA3F8(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  int v7; // r5
  int v8; // r6
  int v9; // [sp+8h] [bp+8h] BYREF
  va_list va; // [sp+8h] [bp+8h]
  int v11; // [sp+Ch] [bp+Ch]
  va_list va1; // [sp+10h] [bp+10h] BYREF

  va_start(va1, a6);
  va_start(va, a6);
  v9 = va_arg(va1, _DWORD);
  v11 = va_arg(va1, _DWORD);
  PfSnBuildScenarioEventDescriptors(v8 + 16, v8 + 80, (int *)va, va1);
  EtwWrite(*(_DWORD *)(v7 + 152), *(_DWORD *)(v7 + 156), v6, 0);
  JUMPOUT(0x704E92);
}
