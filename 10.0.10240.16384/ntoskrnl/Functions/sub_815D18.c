// sub_815D18 
 
void sub_815D18(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  int v7; // r5
  int v8; // r6
  int v9; // r7
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  if ( EtwGetProviderIdFromHandle(v8, v7, 0, (int *)va) >= 0 )
  {
    WdipStartEndScenario((int *)va, v9, v6, 11);
    EtwWrite(v8, v7, v6, v9);
  }
  JUMPOUT(0x7AC576);
}
