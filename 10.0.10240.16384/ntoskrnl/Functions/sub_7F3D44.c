// sub_7F3D44 
 
void sub_7F3D44(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  _DWORD *v6; // r5
  int v7; // r7
  _DWORD *v8; // r8
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  if ( (*(int (__fastcall **)(int, _DWORD, int *, _DWORD *))(v7 + 24))(v7, 0, (int *)va, v6)
    && *v6 == 1852400232
    && !v6[1] )
  {
    *v8 = v6[5];
    v8[1] = v6[6];
    JUMPOUT(0x70F04E);
  }
  (*(void (__fastcall **)(_DWORD *, _DWORD))(v7 + 16))(v6, *(_DWORD *)(v7 + 64));
  JUMPOUT(0x70F040);
}
