// WmipProcessLegacyEtwRegister 
 
int __fastcall WmipProcessLegacyEtwRegister(int a1, int a2, __int64 a3)
{
  int v5; // r8
  __int64 v6; // kr00_8
  int v7; // r0
  int v9; // r4
  int v10; // [sp+0h] [bp-28h]
  __int64 v11[4]; // [sp+8h] [bp-20h] BYREF

  v11[0] = a3;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v5 = *(_DWORD *)(a1 + 80);
  if ( v5 == a2 )
    *(_DWORD *)(a1 + 80) = -1;
  v11[0] = *(_QWORD *)(a1 + 72);
  v6 = v11[0];
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 76) = 0;
  v7 = KeReleaseMutex((int)&WmipSMMutex);
  if ( v6 )
    return sub_818E98(v7);
  if ( v5 == a2 )
  {
    v9 = EtwRegisterClassicProvider(
           a1 + 40,
           0,
           (void (__fastcall *)(int, int, int *, int))WmipLegacyEtwCallback,
           a1,
           v11);
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    if ( v9 < 0 )
      *(_DWORD *)(a1 + 80) = 0;
    else
      *(_QWORD *)(a1 + 72) = v11[0];
    KeReleaseMutex((int)&WmipSMMutex);
  }
  return v10;
}
