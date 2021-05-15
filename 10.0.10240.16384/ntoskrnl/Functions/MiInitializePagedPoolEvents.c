// MiInitializePagedPoolEvents 
 
int MiInitializePagedPoolEvents()
{
  unsigned int v0; // r7
  int v1; // r0
  unsigned int v2; // r1
  int result; // r0
  unsigned int v4; // r8
  unsigned int v5; // r0
  int v6; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 310);
  v1 = KeAbPreAcquire((unsigned int)dword_634D34, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)dword_634D34);
  while ( __strex(v2 | 1, (unsigned __int8 *)dword_634D34) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_96A078(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v4 = MiFreePoolPagesLeft(6);
  if ( v4 >= dword_632AEC )
    KeSetEvent(dword_63F7C8, 0, 0);
  else
    KeResetEvent(dword_63F7C8);
  if ( v4 <= dword_632AE8 )
    KeSetEvent(dword_63F7C4, 0, 0);
  else
    KeResetEvent(dword_63F7C4);
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)dword_634D34);
  while ( __strex(v5 - 1, (unsigned int *)dword_634D34) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)dword_634D34);
  result = KeAbPostRelease((unsigned int)dword_634D34);
  v6 = (__int16)(*(_WORD *)(v0 + 310) + 1);
  *(_WORD *)(v0 + 310) = v6;
  if ( !v6 && *(_DWORD *)(v0 + 100) != v0 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
