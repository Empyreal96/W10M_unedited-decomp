// VfDriverEnableVerifier 
 
int __fastcall VfDriverEnableVerifier(int a1, int a2, _DWORD *a3)
{
  int v3; // r5
  unsigned int v6; // r10
  int v7; // r7
  int v8; // r5
  int v9; // r0
  int **v10; // r1
  int v11; // r3

  v3 = 0;
  *a3 = 0;
  v6 = 0;
  v7 = 0;
  VfDriverLock();
  if ( ViSuspectDriversLookupEntry(a1 + 16) )
    goto LABEL_23;
  if ( !a2 )
  {
    ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
    v8 = PsLoadedModuleList;
    if ( (int *)PsLoadedModuleList == &PsLoadedModuleList )
      goto LABEL_7;
    do
    {
      a2 = v8;
      if ( RtlEqualUnicodeString((unsigned __int16 *)(a1 + 16), (unsigned __int16 *)(v8 + 44), 1) )
        break;
      v8 = *(_DWORD *)v8;
      ++v6;
    }
    while ( (int *)v8 != &PsLoadedModuleList );
    if ( (int *)v8 == &PsLoadedModuleList )
LABEL_7:
      a2 = 0;
    v3 = 1;
    if ( !a2 )
    {
      v9 = 0;
      goto LABEL_16;
    }
  }
  if ( (MmVerifierData & ~VerifierModifyableOptions) == 0
    && (!v3 || v6 > 1 && !VfUtilIsProtectedDriver((unsigned __int16 *)(a2 + 44))) )
  {
    v9 = 1;
LABEL_16:
    v10 = (int **)dword_61D36C;
    *(_DWORD *)a1 = &VfSuspectDriversList;
    *(_DWORD *)(a1 + 4) = v10;
    if ( *v10 != &VfSuspectDriversList )
      __fastfail(3u);
    *v10 = (int *)a1;
    dword_61D36C = a1;
    *a3 = 1;
    if ( v9 )
      VfDriverLoadImage(a2, a1, 0, 1);
    v11 = dword_620DE8 + 1;
    __dmb(0xBu);
    dword_620DE8 = v11;
    goto LABEL_21;
  }
  v7 = -1073741554;
LABEL_21:
  if ( v3 )
    ExReleaseResourceLite((int)&PsLoadedModuleResource);
LABEL_23:
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  return v7;
}
