// VfSetVerifierInformation 
 
int __fastcall VfSetVerifierInformation(_DWORD *a1, unsigned int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  int v5; // r4
  int v6; // r6
  __int16 v7; // r1
  int v8; // r2
  _BYTE *v9; // r6
  int v10; // r3
  int varg_r2; // [sp+30h] [bp+10h]

  varg_r2 = a3;
  LOBYTE(varg_r2) = a3;
  v4 = a1;
  if ( a2 < 4 )
    return -1073741820;
  if ( VfSafeMode )
    return -1073740961;
  v6 = *a1;
  VfDriverLock();
  if ( !MmVerifierData )
    MmVerifyDriverLevel = 0;
  VfInitSystemNoRebootNeeded(KernelVerifier, 0);
  v7 = VerifierModifyableOptions & v6;
  v8 = VerifierModifyableOptions & ~v6;
  v9 = (_BYTE *)((MmVerifierData | VerifierModifyableOptions & v6) & ~v8);
  v5 = 0;
  if ( v9 != (_BYTE *)MmVerifierData )
  {
    VfSettingsCheckForChanges(MmVerifierData, v7, v8, v9);
    v10 = dword_620DE8 + 1;
    __dmb(0xBu);
    dword_620DE8 = v10;
    MmVerifierData = (int)v9;
    *v4 = v9;
  }
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  return v5;
}
