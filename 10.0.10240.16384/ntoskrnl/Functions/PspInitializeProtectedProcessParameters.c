// PspInitializeProtectedProcessParameters 
 
int PspInitializeProtectedProcessParameters()
{
  _DWORD *v0; // r8
  int v1; // r0
  int v2; // r7
  int v3; // r4
  _WORD *v4; // r3

  v0 = (_DWORD *)dword_63282C;
  PsProtectedCurrentDirectory = NtSystemRoot;
  dword_920AC4 = dword_63282C;
  PsProtectedEnvironment = 2 * (NtSystemRoot + 42);
  word_920ABA = 2 * (NtSystemRoot + 42) + 2;
  v1 = ExAllocatePoolWithTag(1, (unsigned __int16)(2 * (NtSystemRoot + 42) + 2), 1817408336);
  dword_920ABC = v1;
  if ( !v1 )
    return -1073741670;
  *(_DWORD *)v1 = &unk_610050;
  *(_DWORD *)(v1 + 4) = "KfRaiseIrql";
  *(_WORD *)(v1 + 8) = unk_97CEE0;
  v2 = v1 + 10;
  memmove(v1 + 10, dword_63282C, (unsigned __int16)NtSystemRoot);
  v3 = (unsigned __int16)NtSystemRoot + v2;
  memmove(v3, (int)L"\\System32", 0x12u);
  *(_WORD *)(v3 + 18) = 0;
  memmove(v3 + 20, (int)L"SystemDrive=", 0x18u);
  *(_DWORD *)(v3 + 44) = *v0;
  *(_WORD *)(v3 + 48) = 0;
  memmove(v3 + 50, (int)L"SystemRoot=", 0x16u);
  v3 += 72;
  memmove(v3, dword_63282C, (unsigned __int16)NtSystemRoot);
  v4 = (_WORD *)((unsigned __int16)NtSystemRoot + v3);
  *v4 = 0;
  v4[1] = 0;
  return 0;
}
