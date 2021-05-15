// RtlpStdLogCapturedStackTrace 
 
int __fastcall RtlpStdLogCapturedStackTrace(int a1, int a2, unsigned int a3)
{
  unsigned int v4; // r0
  int v5; // r9
  int v7; // r8
  unsigned int *v8; // r4
  unsigned int v9; // r5
  int v10; // r5
  char v11; // r4
  unsigned int v12; // r2
  int v13; // r4
  int v14; // r8
  int v15; // r0
  unsigned int v16; // r0
  int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r1
  int v20; // r6
  int vars4; // [sp+24h] [bp+4h]

  v4 = *(_DWORD *)(a1 + 376);
  v5 = *(unsigned __int16 *)(a2 + 10);
  if ( !v4 )
    __brkdiv0();
  v7 = a1 + 12 * (a3 % v4);
  __dmb(0xBu);
  v8 = (unsigned int *)(a1 + 92);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 + 1, v8) );
  __dmb(0xBu);
  v10 = v7 + 384;
  v11 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v7 + 384);
  }
  else
  {
    do
      v12 = __ldrex((unsigned int *)v10);
    while ( __strex(1u, (unsigned int *)v10) );
    __dmb(0xBu);
    if ( v12 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(v7 + 384));
  }
  *(_BYTE *)(v7 + 388) = v11;
  v13 = *(_DWORD *)(v7 + 380);
  if ( v13 )
  {
    v14 = *(unsigned __int16 *)(a2 + 10);
    while ( *(unsigned __int16 *)(v13 + 10) != v14
         || RtlCompareMemory((unsigned __int8 *)(v13 + 12), a2 + 12, 4 * v5) != 4 * v5 )
    {
      v13 = *(_DWORD *)v13;
      if ( !v13 )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    v15 = RtlpStdGetSpaceForTrace(a1, *(unsigned __int16 *)(a2 + 10));
    v13 = v15;
    if ( !v15 )
    {
      __dmb(0xBu);
      v18 = (unsigned int *)(a1 + 112);
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 + 1, v18) );
      __dmb(0xBu);
      goto LABEL_24;
    }
    memmove(v15 + 12, a2 + 12, 4 * v5);
    *(_WORD *)(v13 + 10) = *(_WORD *)(a2 + 10);
    *(_WORD *)(v13 + 4) &= 0xF800u;
    v16 = *(_DWORD *)(a1 + 376);
    if ( !v16 )
      __brkdiv0();
    v17 = a1 + 12 * (a3 % v16);
    *(_DWORD *)v13 = *(_DWORD *)(v17 + 380);
    *(_DWORD *)(v17 + 380) = v13;
  }
  if ( (*(_WORD *)(v13 + 4) & 0x7FF) != 2047 )
    *(_WORD *)(v13 + 4) = *(_WORD *)(v13 + 4) & 0xF800 | (*(_WORD *)(v13 + 4) + 1) & 0x7FF;
LABEL_24:
  v20 = *(unsigned __int8 *)(v10 + 4);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)v10, vars4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v10 = 0;
  }
  KfLowerIrql(v20);
  return v13;
}
