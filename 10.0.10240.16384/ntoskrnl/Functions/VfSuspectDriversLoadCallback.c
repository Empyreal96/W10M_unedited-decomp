// VfSuspectDriversLoadCallback 
 
int __fastcall VfSuspectDriversLoadCallback(int a1, int k, int a3, int a4)
{
  int v4; // r8
  int v8; // r9
  int i; // r4
  int j; // r4
  int **v11; // r2
  int *v12; // r3
  int v13; // r7
  int v14; // r0
  int *v15; // r0
  int v16; // r0
  int v17; // r3
  int result; // r0

  v4 = a4;
  v8 = 0;
  VfDriverLock();
  if ( (VfOptionFlags & 1) != 0 )
  {
    for ( i = VfExcludedDriversList; (int *)i != &VfExcludedDriversList; i = *(_DWORD *)i )
    {
      if ( RtlEqualUnicodeString((unsigned __int16 *)(i + 8), (unsigned __int16 *)(a1 + 44), 1) )
        goto LABEL_55;
    }
  }
  if ( (MmVerifyDriverLevel & 0xFF8000) != 0 )
  {
    for ( j = VfXdvExcludedDriversList; (int *)j != &VfXdvExcludedDriversList; j = *(_DWORD *)j )
    {
      if ( RtlEqualUnicodeString((unsigned __int16 *)(j + 8), (unsigned __int16 *)(a1 + 44), 1) )
        goto LABEL_55;
    }
  }
  if ( RtlEqualUnicodeString((unsigned __int16 *)&VfTcpIpName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    v11 = (int **)&VfWin32kSizeOfImage;
    VfTcpIpDllBase = *(_DWORD *)(a1 + 24);
    v12 = *(int **)(a1 + 32);
    VfTcpIpSizeOfImage = (int)v12;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfTdxName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    v11 = (int **)&VfWin32kSizeOfImage;
    VfTdxDllBase = *(_DWORD *)(a1 + 24);
    v12 = *(int **)(a1 + 32);
    VfTdxSizeOfImage = (int)v12;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfMrxsmbName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    v11 = (int **)&VfWin32kSizeOfImage;
    VfMrxsmbDllBase = *(_DWORD *)(a1 + 24);
    v12 = *(int **)(a1 + 32);
    VfMrxsmbSizeOfImage = (int)v12;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfTmName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    v11 = (int **)&VfWin32kSizeOfImage;
    VfTmDllBase = *(_DWORD *)(a1 + 24);
    v12 = *(int **)(a1 + 32);
    VfTmSizeOfImage = (int)v12;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfWin32kName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    v11 = (int **)&VfWin32kSizeOfImage;
    VfWin32kDllBase = *(_DWORD *)(a1 + 24);
    v12 = *(int **)(a1 + 32);
    VfWin32kSizeOfImage = (int)v12;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfKsName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    v11 = (int **)&VfWin32kSizeOfImage;
    VfKsDllBase = *(_DWORD *)(a1 + 24);
    v12 = *(int **)(a1 + 32);
    VfKsSizeOfImage = (int)v12;
  }
  if ( !a3 )
  {
    v8 = VfThunkApplyMandatoryThunks(a1, v4);
    if ( !v8 )
      goto LABEL_55;
    v8 = 0;
  }
  if ( k )
    goto LABEL_42;
  v13 = 0;
  for ( k = VfSuspectDriversList; (int *)k != &VfSuspectDriversList; k = *(_DWORD *)k )
  {
    v13 = RtlEqualUnicodeString((unsigned __int16 *)(k + 16), (unsigned __int16 *)(a1 + 44), 1);
    if ( v13 )
      goto LABEL_43;
  }
  if ( KernelVerifier )
  {
    if ( !a3 )
    {
      v12 = &ViForceAllDriversSuspect;
      v14 = ViForceAllDriversSuspect;
      goto LABEL_36;
    }
  }
  else if ( ViVerifyAllDrivers != 1 )
  {
    v14 = VfInitPickCurrentRandomTarget();
LABEL_36:
    if ( !v14 )
    {
      k = 0;
      goto LABEL_43;
    }
    goto LABEL_38;
  }
LABEL_38:
  v15 = (int *)VfSuspectDriversAllocateEntry((unsigned __int16 *)(a1 + 44));
  k = (int)v15;
  if ( !v15 )
    goto LABEL_43;
  v11 = (int **)dword_61D36C;
  *v15 = (int)&VfSuspectDriversList;
  v15[1] = (int)v11;
  v12 = *v11;
  if ( *v11 != &VfSuspectDriversList )
    __fastfail(3u);
  *v11 = v15;
  dword_61D36C = (int)v15;
LABEL_42:
  v13 = 1;
LABEL_43:
  if ( a4 )
  {
    if ( v13 )
      v16 = VfTargetDriversEnableVerifier(*(_DWORD *)(a1 + 24), k, (int)v11, (int)v12);
    else
      v16 = 1;
  }
  else
  {
    v16 = VfTargetDriversAdd(*(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 32), k, (int)v12);
  }
  if ( (v13 || KernelVerifier) && v16 )
  {
    v8 = VfThunkApplyThunks(a1, a4);
    if ( v8 )
    {
      if ( v13 )
      {
        VfUtilPrintCheckinString((unsigned __int16 *)(a1 + 44));
        VfCheckImageCompliance((int *)a1);
        v17 = dword_620DB0 + 1;
        __dmb(0xBu);
        dword_620DB0 = v17;
        ++*(_DWORD *)(k + 8);
        VfNotifyVerifierExtensions(1, (_DWORD *)a1);
      }
    }
    else
    {
      VfTargetDriversRemove(a1);
    }
  }
LABEL_55:
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  result = KeReleaseMutex((int)&ViDriversLoadLock);
  if ( v8 )
    *(_DWORD *)(a1 + 52) |= 0x2000000u;
  return result;
}
