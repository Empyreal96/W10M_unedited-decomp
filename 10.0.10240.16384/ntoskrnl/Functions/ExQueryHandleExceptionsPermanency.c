// ExQueryHandleExceptionsPermanency 
 
int __fastcall ExQueryHandleExceptionsPermanency(int a1, _BYTE *a2, _BYTE *a3)
{
  unsigned int v6; // r5
  unsigned __int8 *v7; // r6
  int v8; // r0
  int v9; // r8
  unsigned int v10; // r4
  int v11; // r3
  unsigned int v12; // r1
  int result; // r0
  __int16 v14; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = (unsigned __int8 *)(a1 + 36);
  v8 = KeAbPreAcquire(a1 + 36, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( __strex(v10 | 1, v7) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7, v8, (unsigned int)v7);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = *(_DWORD *)(a1 + 60);
  if ( v11 )
  {
    *a2 = 1;
    if ( (*(_DWORD *)(v11 + 8) & 8) == 0 )
      goto LABEL_14;
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 28) & 2) == 0 )
    {
      *a2 = 0;
LABEL_14:
      *a3 = 0;
      goto LABEL_15;
    }
    *a2 = 1;
  }
  *a3 = 1;
LABEL_15:
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v7);
  while ( __strex(v12 - 1, (unsigned int *)v7) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v7);
  result = KeAbPostRelease((unsigned int)v7);
  v14 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
