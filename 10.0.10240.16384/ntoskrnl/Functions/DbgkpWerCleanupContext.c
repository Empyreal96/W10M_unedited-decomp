// DbgkpWerCleanupContext 
 
int __fastcall DbgkpWerCleanupContext(_DWORD *a1)
{
  int result; // r0
  int v3; // r0
  unsigned int v4; // r0
  int v5; // r3
  int v6; // r0
  int v7; // r3
  unsigned int v8; // r5
  unsigned int v9; // r0
  unsigned int v10; // r6
  unsigned int v11; // r0
  unsigned int v12; // r0
  int v13; // r0

  result = DbgPrintEx(5, 3, (int)"DBGK: DbgkpWerCleanupContext: Context 0x%p\n", (int)a1);
  if ( a1 )
  {
    if ( a1[23] )
    {
      v3 = IoDiscardDeferredLiveDumpData();
      if ( v3 < 0 )
        DbgPrintEx(5, 0, (int)"DBGK: IoDiscardDeferredLiveDumpData failed, status 0x%X\n", v3);
      a1[23] = 0;
    }
    v4 = a1[21];
    if ( v4 )
    {
      ExFreePoolWithTag(v4);
      a1[21] = 0;
    }
    v5 = a1[22];
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 + 12);
      if ( v6 )
      {
        ObfDereferenceObject(v6);
        *(_DWORD *)(a1[22] + 12) = 0;
      }
      if ( *(_DWORD *)(a1[22] + 8) )
      {
        ZwClose();
        *(_DWORD *)(a1[22] + 8) = 0;
      }
      v7 = a1[22];
      v8 = *(_DWORD *)(v7 + 32);
      *(_DWORD *)(v7 + 32) = 0;
      if ( v8 )
      {
        do
        {
          v9 = *(_DWORD *)(v8 + 16);
          v10 = *(_DWORD *)(v8 + 28);
          if ( v9 )
            ExFreePoolWithTag(v9);
          ExFreePoolWithTag(v8);
          v8 = v10;
        }
        while ( v10 );
      }
      v11 = a1[22];
      if ( v11 )
        ExFreePoolWithTag(v11);
      a1[22] = 0;
    }
    v12 = a1[24];
    if ( v12 )
    {
      ExFreePoolWithTag(v12);
      a1[24] = 0;
    }
    result = a1[19];
    if ( result )
    {
      if ( (a1[20] & 1) == 0 )
      {
        v13 = WerLiveKernelCancelReport_0();
        if ( v13 < 0 )
          DbgPrintEx(5, 1, (int)"DBGK: DbgkpWerCleanupContext: WerLiveKernelCancelReport failed, 0x%X\n", v13);
      }
      result = WerLiveKernelCloseHandle_0();
      if ( result < 0 )
        result = DbgPrintEx(5, 1, (int)"DBGK: DbgkpWerCleanupContext: WerLiveKernelCloseHandle failed, 0x%X\n", result);
      a1[19] = 0;
    }
  }
  return result;
}
