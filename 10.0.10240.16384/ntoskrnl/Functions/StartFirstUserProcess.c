// StartFirstUserProcess 
 
unsigned int StartFirstUserProcess()
{
  int v0; // r7
  int v1; // r4
  _BYTE *v2; // r0
  unsigned int v3; // r5
  int v4; // r3
  int v5; // r4
  int v6; // r0
  int v7; // r0
  unsigned int v9; // [sp+20h] [bp-60h] BYREF
  int v10; // [sp+24h] [bp-5Ch]

  BuildKnownDlls();
  v0 = (unsigned __int16)word_920ABA;
  v1 = HIWORD(PsProtectedCurrentDirectory) + 736;
  v2 = (_BYTE *)ExAllocatePoolWithTag(512, (unsigned __int16)word_920ABA + v1, 1649636176);
  v3 = (unsigned int)v2;
  if ( !v2 )
    sub_96C5C8();
  memset(v2, 0, v0 + v1);
  *(_DWORD *)(v3 + 4) = v1;
  *(_DWORD *)(v3 + 8) = 4194305;
  *(_DWORD *)v3 = v1;
  *(_DWORD *)(v3 + 72) = v3 + v1;
  *(_DWORD *)(v3 + 656) = v0;
  *(_WORD *)(v3 + 50) = 0;
  *(_WORD *)(v3 + 48) = 0;
  *(_DWORD *)(v3 + 52) = 0;
  *(_DWORD *)(v3 + 40) = v3 + 676;
  *(_WORD *)(v3 + 38) = HIWORD(PsProtectedCurrentDirectory);
  RtlCopyUnicodeString((unsigned __int16 *)(v3 + 36), (unsigned __int16 *)&PsProtectedCurrentDirectory);
  *(_DWORD *)(v3 + 60) = *(unsigned __int16 *)(v3 + 38) + v3 + 676;
  *(_WORD *)(v3 + 58) = 60;
  RtlCopyUnicodeString((unsigned __int16 *)(v3 + 56), (unsigned __int16 *)&NtInitialUserProcess);
  *(_DWORD *)(v3 + 64) = *(_DWORD *)(v3 + 56);
  v4 = *(_DWORD *)(v3 + 60);
  HIWORD(v9) = v0;
  *(_DWORD *)(v3 + 68) = v4;
  v10 = *(_DWORD *)(v3 + 72);
  LOWORD(v9) = 0;
  RtlCopyUnicodeString((unsigned __int16 *)&v9, (unsigned __int16 *)&PsProtectedEnvironment);
  v5 = RtlCreateUserProcess(v3 + 56);
  if ( InbvIsBootDriverInstalled() )
    FinalizeBootLogo();
  if ( v5 < 0 )
    KeBugCheckEx(109, v5, 0, 1, 0);
  v6 = ZwSetInformationProcess();
  if ( v6 < 0 )
    KeBugCheckEx(109, v6, 0, 2, 0);
  v7 = ZwResumeThread();
  if ( v7 < 0 )
    KeBugCheckEx(109, v7, 0, 3, 0);
  byte_637608 = 1;
  v9 = -50000000;
  v10 = -1;
  KeDelayExecutionThread(0, 0, &v9);
  ZwClose();
  ZwClose();
  return ExFreePoolWithTag(v3);
}
