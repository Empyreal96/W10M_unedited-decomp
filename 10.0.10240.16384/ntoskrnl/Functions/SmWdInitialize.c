// SmWdInitialize 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall SmWdInitialize(_BYTE *a1, unsigned int a2)
{
  __int128 v2; // r3 OVERLAPPED
  _DWORD *result; // r0
  int v4; // r2

  *(_QWORD *)((char *)&v2 + 4) = __PAIR64__((unsigned int)a1, a2);
  memset(a1, 0, 96);
  result = KeInitializeTimerEx((_DWORD *)DWORD2(v2), 0);
  *(_BYTE *)(DWORD2(v2) + 48) = 19;
  *(_BYTE *)(DWORD2(v2) + 49) = 1;
  LODWORD(v2) = SmWdDPC;
  v4 = 0;
  *(_WORD *)(DWORD2(v2) + 50) = 0;
  *(_QWORD *)(DWORD2(v2) + 60) = v2;
  LODWORD(v2) = DWORD2(v2) + 80;
  *(_DWORD *)(DWORD2(v2) + 76) = 0;
  *(_DWORD *)(DWORD2(v2) + 56) = 0;
  *(_DWORD *)(DWORD2(v2) + 88) = 0;
  *(_QWORD *)v2 = *(_QWORD *)((char *)&v2 - 4);
  WatchdogReadsQueueTimeout = dword_989680;
  unk_641604 = 0;
  WatchdogWritesQueueTimeout.LowPart = (unsigned int)dword_989680;
  dword_64160C = 0;
  return result;
}
