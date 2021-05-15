// RtlStdReleaseStackTrace 
 
int __fastcall RtlStdReleaseStackTrace(int a1, int a2)
{
  int v3; // r5
  int v4; // r6
  unsigned int v5; // r1
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r0
  int v10; // r7
  unsigned int *v11; // r5
  char v12; // r9
  unsigned int v13; // r2
  __int16 v14; // r1
  int v15; // r3
  int *v16; // r2
  int *v17; // r3
  int v18; // r7
  int result; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int vars4; // [sp+24h] [bp+4h]

  v3 = *(unsigned __int16 *)(a2 + 10);
  v4 = 0;
  v5 = 0;
  if ( v3 )
  {
    v7 = a2;
    do
    {
      v8 = *(_DWORD *)(v7 + 12);
      v7 += 4;
      v5 += v8;
      --v3;
    }
    while ( v3 );
  }
  v9 = *(_DWORD *)(a1 + 376);
  if ( !v9 )
    __brkdiv0();
  v10 = a1 + 12 * (v5 % v9);
  v11 = (unsigned int *)(v10 + 384);
  v12 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v10 + 384);
  }
  else
  {
    do
      v13 = __ldrex(v11);
    while ( __strex(1u, v11) );
    __dmb(0xBu);
    if ( v13 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(v10 + 384));
  }
  *(_BYTE *)(v10 + 388) = v12;
  if ( (*(_WORD *)(a2 + 4) & 0x7FF) != 2047 )
  {
    v14 = *(_WORD *)(a2 + 4) & 0xF800 | (*(_WORD *)(a2 + 4) - 1) & 0x7FF;
    *(_WORD *)(a2 + 4) = v14;
    if ( (v14 & 0x7FF) == 0 )
    {
      v15 = *(_DWORD *)(v10 + 380);
      v16 = (int *)(v10 + 380);
      while ( 1 )
      {
        if ( !v15 )
          __debugbreak();
        v17 = (int *)*v16;
        if ( *v16 == a2 )
          break;
        v16 = (int *)*v16;
        v15 = *v17;
      }
      *v16 = *(_DWORD *)a2;
      v4 = 1;
    }
  }
  v18 = *(unsigned __int8 *)(v10 + 388);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v11, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v11 = 0;
  }
  result = KfLowerIrql(v18);
  if ( v4 )
  {
    result = RtlpInterlockedPushEntrySList(
               (unsigned __int64 *)(a1 + 8 * ((*(unsigned __int16 *)(a2 + 4) >> 11) + 15)),
               (_DWORD *)(a2 + 12));
    __dmb(0xBu);
    v20 = (unsigned int *)(a1 + 108);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 + 1, v20) );
    __dmb(0xBu);
  }
  return result;
}
