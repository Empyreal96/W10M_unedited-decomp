// PoClearPowerRequestInternalDeferred 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PoClearPowerRequestInternalDeferred(int a1, int a2, unsigned int a3)
{
  _BYTE *v5; // r0
  _BYTE *v6; // r4 OVERLAPPED
  int (*v8)(); // r3

  if ( !a3 )
    return PoClearPowerRequestInternal(a1, 4);
  v5 = (_BYTE *)ExAllocatePoolWithTag(512, 88, 1414616912);
  v6 = v5;
  if ( !v5 )
    return sub_5272A0();
  memset(v5, 0, 88);
  *((_DWORD *)v6 + 20) = a1;
  *((_DWORD *)v6 + 21) = 4;
  *v6 = 19;
  v6[1] = 1;
  v8 = PopDelayedPowerRequestClearDpc;
  *(_QWORD *)(v6 + 12) = *(_QWORD *)(&v6 - 1);
  *((_WORD *)v6 + 1) = 0;
  *((_DWORD *)v6 + 7) = 0;
  *((_DWORD *)v6 + 2) = 0;
  KeInitializeTimerEx(v6 + 32, 0);
  KiSetTimerEx(v6 + 32, -a3, -10000 * a3, (-10000i64 * (unsigned __int64)a3) >> 32, 0, 0, v6);
  return 0;
}
