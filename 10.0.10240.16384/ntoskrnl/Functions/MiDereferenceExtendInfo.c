// MiDereferenceExtendInfo 
 
int __fastcall MiDereferenceExtendInfo(int a1, int a2)
{
  int v3; // r9
  unsigned int v4; // r8
  int v5; // r7
  unsigned int v6; // r4
  unsigned int v7; // r0
  int result; // r0
  __int16 v9; // r3

  v3 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 310);
  v5 = KeAbPreAcquire((unsigned int)&dword_632E10, 0, 0);
  do
    v6 = __ldrex((unsigned __int8 *)&dword_632E10);
  while ( __strex(v6 | 1, (unsigned __int8 *)&dword_632E10) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_632E10, v5, (unsigned int)&dword_632E10);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  if ( !--*(_DWORD *)(*(_DWORD *)(a1 + 68) + 8) )
  {
    v3 = *(_DWORD *)(a1 + 68);
    *(_DWORD *)(*(_DWORD *)a2 + 24) = 0;
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&dword_632E10);
  while ( __strex(v7 - 1, (unsigned int *)&dword_632E10) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_632E10);
  result = KeAbPostRelease((unsigned int)&dword_632E10);
  v9 = *(_WORD *)(v4 + 310) + 1;
  *(_WORD *)(v4 + 310) = v9;
  if ( !v9 && *(_DWORD *)(v4 + 100) != v4 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  if ( v3 )
    result = ExFreePoolWithTag(v3);
  return result;
}
