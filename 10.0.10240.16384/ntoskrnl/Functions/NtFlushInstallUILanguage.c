// NtFlushInstallUILanguage 
 
int __fastcall NtFlushInstallUILanguage(int a1, int a2)
{
  unsigned int v4; // r3
  int v5; // r4
  int v6; // r2
  int v7; // r3
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !*(_BYTE *)(v4 + 346) )
    return -1073741823;
  if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, *(char *)(v4 + 346), (int)&SeTcbPrivilege) )
    return -1073741790;
  if ( PsUILanguageComitted )
  {
    if ( a1 == (unsigned __int16)PsInstallUILanguageId )
      return 0;
    return -1073741823;
  }
  if ( MUIRefreshCachedUILock
    || (v5 = MUIInitializeResourceLock((unsigned int *)&MUIRefreshCachedUILock), (v5 & 0xC0000000) != -1073741824) )
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = *(__int16 *)(v6 + 0x134) - 1;
    *(_WORD *)(v6 + 308) = v7;
    ExAcquireResourceExclusiveLite(MUIRefreshCachedUILock, 1, v6, v7);
    if ( a2 )
      PsUILanguageComitted = 1;
    if ( (unsigned __int16)a1 == (unsigned __int16)PsInstallUILanguageId )
    {
      v5 = 0;
    }
    else
    {
      PsInstallUILanguageId = a1;
      PsMachineUILanguageId = a1;
      v5 = MigrateOOBELanguageToInstallationLanguage();
    }
    v8 = ExReleaseResourceLite(MUIRefreshCachedUILock);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v8);
  }
  return v5;
}
