// ExEnableRaiseUMExceptionOnInvalidHandleClose 
 
int __fastcall ExEnableRaiseUMExceptionOnInvalidHandleClose(int a1, int a2)
{
  unsigned int v4; // r4
  unsigned __int8 *v5; // r5
  int v6; // r0
  unsigned int v7; // r2
  int result; // r0
  char v9; // r3
  unsigned int v10; // r1
  __int16 v11; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = (unsigned __int8 *)(a1 + 36);
  v6 = KeAbPreAcquire(a1 + 36, 0, 0);
  do
    v7 = __ldrex(v5);
  while ( __strex(v7 | 1, v5) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    return sub_7E9068(v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( !a2 )
  {
    v9 = *(_BYTE *)(a1 + 28) & 0xEF;
LABEL_9:
    *(_BYTE *)(a1 + 28) = v9;
    goto LABEL_10;
  }
  if ( a2 == 1 )
  {
    v9 = *(_BYTE *)(a1 + 28) | 0x10;
    goto LABEL_9;
  }
LABEL_10:
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v5);
  while ( __strex(v10 - 1, (unsigned int *)v5) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v5);
  result = KeAbPostRelease((unsigned int)v5);
  v11 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
