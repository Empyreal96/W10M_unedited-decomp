// sub_7E86BC 
 
void sub_7E86BC(int a1, int *a2, int a3, int a4, ...)
{
  int v4; // r4
  int v5; // r5
  int v6; // r6
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( HvpMarkCellDirty(v4, *a2, 0, 0) )
  {
    *(_DWORD *)(v6 + 12) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 2004) + 8 * v5 + 4) + 20);
    JUMPOUT(0x6FC3EE);
  }
  (*(void (__fastcall **)(int, int *))(v4 + 8))(v4, (int *)va);
  JUMPOUT(0x6FC408);
}
