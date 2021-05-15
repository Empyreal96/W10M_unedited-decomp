// PnprWakeProcessors 
 
int PnprWakeProcessors()
{
  int v0; // r0
  int v1; // r3
  int v2; // r0
  int v3; // r6
  int result; // r0
  unsigned int v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r1

  if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 )
  {
    (*(void (__fastcall **)(_DWORD, _DWORD))(PnprContext + 604))(*(_DWORD *)(PnprContext + 552), 0);
    v0 = PnprGetMillisecondCounter(0);
    v1 = PnprContext;
    *(_DWORD *)(PnprContext + 644) = v0;
    __dmb(0xBu);
    *(_DWORD *)(v1 + 148) = 6;
  }
  off_617A00(0, 0);
  KeResumeClockTimerSafe();
  ((void (__cdecl *)())off_6179EC)();
  v2 = PnprGetMillisecondCounter(0);
  v3 = PnprContext;
  v5 = (10000 * (unsigned __int64)(unsigned int)v2) >> 32;
  result = 10000 * v2;
  *(_QWORD *)(PnprContext + 616) = __PAIR64__(v5, result) - 10000i64 * *(_QWORD *)(PnprContext + 616);
  __dmb(0xBu);
  *(_DWORD *)(v3 + 148) = 7;
  __dmb(0xBu);
  v6 = (unsigned int *)(PnprContext + 136);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + 1, v6) );
  __dmb(0xBu);
  if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 )
    result = ((int (__cdecl *)())off_617A18)();
  return result;
}
