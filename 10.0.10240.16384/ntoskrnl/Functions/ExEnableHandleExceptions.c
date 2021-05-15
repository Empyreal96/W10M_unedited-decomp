// ExEnableHandleExceptions 
 
int __fastcall ExEnableHandleExceptions(int a1, int a2)
{
  int v4; // r8
  unsigned int v5; // r5
  unsigned __int8 *v6; // r6
  int v7; // r0
  unsigned int v8; // r2
  int v10; // r2
  unsigned int v11; // r1
  int v12; // r0
  __int16 v13; // r3
  int v14; // r3

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = (unsigned __int8 *)(a1 + 36);
  v7 = KeAbPreAcquire(a1 + 36, 0, 0);
  do
    v8 = __ldrex(v6);
  while ( __strex(v8 | 1, v6) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_7E96A8(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v10 = *(_DWORD *)(a1 + 60);
  if ( v10 )
  {
    v14 = *(_DWORD *)(v10 + 8);
    if ( (v14 & 8) == 0 )
    {
      if ( a2 )
        *(_DWORD *)(v10 + 8) = v14 | 8;
      goto LABEL_10;
    }
    goto LABEL_18;
  }
  if ( (*(_BYTE *)(a1 + 28) & 2) != 0 )
  {
LABEL_18:
    if ( !a2 )
      v4 = 1;
    goto LABEL_10;
  }
  *(_BYTE *)(a1 + 28) ^= (*(_BYTE *)(a1 + 28) ^ (2 * (a2 != 0))) & 2;
LABEL_10:
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v6);
  while ( __strex(v11 - 1, (unsigned int *)v6) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v6);
  v12 = KeAbPostRelease((unsigned int)v6);
  v13 = *(_WORD *)(v5 + 308) + 1;
  *(_WORD *)(v5 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return v4 == 0;
}
