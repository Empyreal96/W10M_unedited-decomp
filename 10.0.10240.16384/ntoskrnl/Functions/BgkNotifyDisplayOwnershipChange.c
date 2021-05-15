// BgkNotifyDisplayOwnershipChange 
 
int __fastcall BgkNotifyDisplayOwnershipChange(int a1, int (__fastcall *a2)(_DWORD, _DWORD, _DWORD))
{
  unsigned int v3; // r1
  unsigned int v4; // r2
  int v5; // r5
  int v6; // r0
  int (__fastcall **v7)(_DWORD, int, int, _DWORD); // r0
  int (__fastcall *v8[2])(_DWORD); // [sp+0h] [bp-30h] BYREF
  char v9[40]; // [sp+8h] [bp-28h] BYREF

  if ( byte_64A430 )
    return sub_54D580();
  if ( a1 == (unsigned __int8)byte_63761D )
    JUMPOUT(0x54D594);
  if ( a1 )
  {
    if ( !dword_637610 )
      return -1073741823;
    v8[0] = 0;
    v5 = dword_637610(0, v9, v8);
    if ( v5 >= 0 )
    {
      dword_64A42C = v8[0];
      BgkpLockBgfxCodeSection();
      v5 = BgLibraryEnable(v9, 0);
      if ( v5 >= 0 )
        byte_63761D = 1;
      v7 = (int (__fastcall **)(_DWORD, int, int, _DWORD))BgConsoleGetInterface();
      dword_637614 = (int)v7;
      if ( v7 )
        v7 = (int (__fastcall **)(_DWORD, int, int, _DWORD))(*v7)(0, -3750202, dword_64B0AC, 0);
      BgkpTryEnableConsole(v7);
    }
    return v5;
  }
  if ( a2 )
  {
    dword_637610 = a2;
    goto LABEL_7;
  }
  if ( dword_637610 )
  {
LABEL_7:
    BgDisplayFade();
    byte_63760A = 0;
    byte_63761C = 0;
    do
      v3 = __ldrex((unsigned int *)&dword_61646C);
    while ( !v3 && __strex(1u, (unsigned int *)&dword_61646C) );
    __dmb(0xBu);
    if ( v3 && v3 != 1 )
      ExfWaitForRundownProtectionRelease((unsigned int *)&dword_61646C, v3);
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&dword_61646C);
    while ( __strex(1u, (unsigned int *)&dword_61646C) );
    __dmb(0xBu);
    v5 = BgLibraryDisable();
    if ( v5 < 0 )
    {
      BgkDestroy();
      InbvSetFunction();
      v5 = 0;
    }
    else
    {
      byte_63761D = 0;
      if ( dword_637614 )
      {
        BgConsoleDestroyInterface(dword_637614);
        dword_637614 = 0;
      }
    }
    v6 = BgkpUnlockBgfxCodeSection();
    if ( dword_64A42C )
    {
      dword_64A42C(v6);
      dword_64A42C = 0;
    }
    return v5;
  }
  return -1073741584;
}
