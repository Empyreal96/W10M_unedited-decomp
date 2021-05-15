// MiInitializeLoadedModuleList 
 
int __fastcall MiInitializeLoadedModuleList(int a1)
{
  int v2; // r7
  _BYTE *v3; // r0
  int result; // r0
  _BYTE *v5; // [sp+Ch] [bp-3Ch] BYREF
  int v6; // [sp+14h] [bp-34h]

  dword_632F08 = (int)&dword_632F04;
  dword_632F04 = (int)&dword_632F04;
  ExInitializeResourceLite((int)&PsLoadedModuleResource);
  PsLoadedModuleList = (int)&PsLoadedModuleList;
  dword_62127C = (int)&PsLoadedModuleList;
  ExpCovPushLock = 0;
  ExpCovUnloadedModuleList = (int)&ExpCovUnloadedModuleList;
  dword_6198EC = (int)&ExpCovUnloadedModuleList;
  NtSetDebugFilterState(0x7Eu, 0, 1);
  v2 = *(_DWORD *)(a1 + 16);
  v6 = a1 + 16;
  v3 = (_BYTE *)MiLocateKernelSections(v2);
  if ( v2 == a1 + 16 )
  {
LABEL_6:
    MiBuildImportsForBootDrivers(v3);
    result = 1;
  }
  else
  {
    while ( MiConstructLoaderEntry(v2, (unsigned __int16 *)(v2 + 44), (unsigned __int16 *)(v2 + 36), 0, 1, (int *)&v5) >= 0 )
    {
      if ( *((_DWORD *)v5 + 6) == PsNtosImageBase )
        return sub_969D98();
      v3 = MiLockdownSections(v5);
      v2 = *(_DWORD *)v2;
      if ( v2 == v6 )
        goto LABEL_6;
    }
    result = 0;
  }
  return result;
}
