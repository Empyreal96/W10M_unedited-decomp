// FsRtlpRegisterUncProvider 
 
int __fastcall FsRtlpRegisterUncProvider(int a1, int a2, int a3, _DWORD *a4)
{
  int v9; // r4
  int v10[8]; // [sp+8h] [bp-20h] BYREF

  v10[0] = -1;
  if ( a1 && *(_DWORD *)(a1 + 4) && *(_WORD *)a1 && *(_WORD *)(a1 + 2) )
  {
    if ( !a2 )
      return sub_819CD4();
    KeWaitForSingleObject((unsigned int)&FsRtlpUncSemaphore, 0, 0, 0, 0);
    v9 = FsRtlpOpenDev(v10);
    if ( v9 < 0 || (v9 = FsRtlpRegisterProviderWithMUP(v10[0], a1, a2, a3), v9 < 0) )
    {
      if ( v10[0] != -1 )
      {
        if ( v10[0] )
          ZwClose();
      }
      *a4 = -1;
    }
    else
    {
      ++FsRtlpRedirs;
      *a4 = v10[0];
    }
    KeReleaseSemaphore((int)&FsRtlpUncSemaphore, 0, 1);
  }
  else
  {
    v9 = -1073741811;
    *a4 = -1;
  }
  return v9;
}
