// PsRegisterPicoProvider 
 
int __fastcall PsRegisterPicoProvider(_DWORD *a1, _DWORD *a2)
{
  int result; // r0
  int (__fastcall *v4)(_DWORD); // r1
  int (__fastcall *v5)(_DWORD); // r2
  int (__fastcall *v6)(_DWORD); // r3
  int (__fastcall *v7)(_DWORD, _DWORD); // r1
  int (__fastcall *v8)(_DWORD, _DWORD, _DWORD); // r2
  int v9; // r3

  if ( *a1 != 32 || *a2 != 44 )
    return -1073741820;
  if ( PspPicoRegistrationDisabled )
    return -1073741431;
  v4 = (int (__fastcall *)(_DWORD))a1[1];
  v5 = (int (__fastcall *)(_DWORD))a1[2];
  v6 = (int (__fastcall *)(_DWORD))a1[3];
  PspPicoProviderRoutines = *a1;
  dword_61D9C4 = v4;
  dword_61D9C8 = v5;
  dword_61D9CC = v6;
  v7 = (int (__fastcall *)(_DWORD, _DWORD))a1[5];
  v8 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))a1[6];
  v9 = a1[7];
  dword_61D9D0 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))a1[4];
  dword_61D9D4 = v7;
  dword_61D9D8 = v8;
  dword_61D9DC = v9;
  PspPicoProviderRanges = v9;
  *a2 = 44;
  result = 0;
  a2[1] = PspCreatePicoProcess;
  a2[2] = PspCreatePicoThread;
  a2[3] = PspGetPicoProcessContext;
  a2[4] = PspGetPicoThreadContext;
  a2[5] = PspGetContextThreadInternal;
  a2[6] = PspSetContextThreadInternal;
  a2[7] = PspTerminateThreadByPointer;
  a2[8] = PsResumeThread;
  a2[9] = PspSetPicoThreadDescriptorBase;
  a2[10] = PsSuspendThread;
  return result;
}
