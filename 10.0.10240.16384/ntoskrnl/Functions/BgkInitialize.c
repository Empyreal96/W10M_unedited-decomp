// BgkInitialize 
 
int __fastcall BgkInitialize(int a1, int a2, int a3, int a4)
{
  int result; // r0
  void **v7; // r5
  int v8; // [sp+0h] [bp-10h] BYREF
  int v9; // [sp+4h] [bp-Ch]

  v8 = a3;
  v9 = a4;
  if ( !a1 )
    return -1073741823;
  if ( a2 == 1 )
  {
    if ( byte_637609 )
      return 0;
    return -1073741823;
  }
  if ( !a2 )
  {
    BgkDestroy(a1);
    dword_647478 = 0;
    BgkpLockBgfxCodeSection();
  }
  result = BgLibraryInitialize(*(_DWORD *)(*(_DWORD *)(a1 + 132) + 112), a2);
  if ( result >= 0 )
  {
    if ( !a2 )
    {
      v7 = BgConsoleGetInterface(result);
      dword_637614 = (int)v7;
      if ( v7 )
        ((void (__fastcall *)(int, int, int, _DWORD, int, int))*v7)(InitConsoleFlags, -3750202, dword_64B0AC, 0, v8, v9);
      if ( off_617B54(9, 4, &dword_6416A8, &v8) < 0 )
        dword_6416A8 = 2;
    }
    byte_637609 = 1;
    byte_63761D = 1;
    BgkpTryEnableConsole();
    return 0;
  }
  return result;
}
