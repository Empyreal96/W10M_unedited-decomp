// SmpKeyedStoreSetVaRanges 
 
int SmpKeyedStoreSetVaRanges(unsigned __int8 *a1, ...)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r5
  unsigned int v7; // r1
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  va_list varg_r1; // [sp+14h] [bp+Ch] BYREF

  va_start(varg_r1, a1);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)a1, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex(a1);
  while ( __strex(v5 | 1, a1) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1, v3, (unsigned int)a1);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( SmpKeyedStoreEntryGet((int)a1, (int)varg_r1, 0, 1) )
    v6 = -1073741637;
  else
    v6 = -1073741275;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)a1);
  while ( __strex(v7 - 1, (unsigned int *)a1) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a1);
  v8 = KeAbPostRelease((unsigned int)a1);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v6;
}
