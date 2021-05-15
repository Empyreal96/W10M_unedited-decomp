// VfSuspectDriversUnloadCallback 
 
int __fastcall VfSuspectDriversUnloadCallback(int a1)
{
  int i; // r4
  int v3; // r3

  VfDriverLock();
  if ( RtlEqualUnicodeString((unsigned __int16 *)&VfTcpIpName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    VfTcpIpDllBase = 0;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfTdxName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    VfTdxDllBase = 0;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfMrxsmbName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    VfMrxsmbDllBase = 0;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfTmName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    VfTmDllBase = 0;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfWin32kName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    VfWin32kDllBase = 0;
  }
  else if ( RtlEqualUnicodeString((unsigned __int16 *)&VfKsName, (unsigned __int16 *)(a1 + 44), 1) == 1 )
  {
    VfKsDllBase = 0;
  }
  for ( i = VfSuspectDriversList; (int *)i != &VfSuspectDriversList; i = *(_DWORD *)i )
  {
    if ( RtlEqualUnicodeString((unsigned __int16 *)(i + 16), (unsigned __int16 *)(a1 + 44), 1) )
    {
      v3 = dword_620DB4 + 1;
      __dmb(0xBu);
      dword_620DB4 = v3;
      ++*(_DWORD *)(i + 12);
      VfNotifyVerifierExtensions(2, (_DWORD *)a1);
      break;
    }
  }
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  return KeReleaseMutex((int)&ViDriversLoadLock);
}
