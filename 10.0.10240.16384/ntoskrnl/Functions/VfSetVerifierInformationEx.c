// VfSetVerifierInformationEx 
 
int __fastcall VfSetVerifierInformationEx(int *a1, int a2)
{
  int v3; // r3
  unsigned int v4; // r1
  int v5; // r4
  unsigned int v6; // r0
  int v7; // r3
  int v9; // [sp+4h] [bp-24h]
  int v10[2]; // [sp+8h] [bp-20h] BYREF
  _DWORD _10[10]; // [sp+10h] [bp-18h] BYREF

  _10[9] = a2;
  _10[8] = a1;
  v3 = *a1;
  __dmb(0xBu);
  v9 = v3;
  v4 = a1[4];
  __dmb(0xBu);
  if ( !v9 || (v5 = VfSetVerifierRunningMode(v3), v5 >= 0) )
  {
    if ( !v4 || (v4 != -1 ? (v6 = v4) : (v6 = 0), v5 = VfWdSetCancelTimeout(v6), v5 >= 0) )
    {
      v7 = dword_620DE8 + 1;
      __dmb(0xBu);
      dword_620DE8 = v7;
      v5 = VfProbeAndCaptureUnicodeString(v10, a1 + 2, 512, v7);
      if ( v5 >= 0 )
      {
        VfDriverLock();
        _10[0] = dword_620DF0;
        _10[1] = dword_620DF4;
        dword_620DF0 = v10[0];
        dword_620DF4 = v10[1];
        __dmb(0xBu);
        ViDriversLoadLockOwner = 0;
        KeReleaseMutex((int)&ViDriversLoadLock);
        VfFreeCapturedUnicodeString((unsigned int)_10);
      }
    }
  }
  return v5;
}
