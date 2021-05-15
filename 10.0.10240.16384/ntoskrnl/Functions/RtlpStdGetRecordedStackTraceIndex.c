// RtlpStdGetRecordedStackTraceIndex 
 
int __fastcall RtlpStdGetRecordedStackTraceIndex(int a1, unsigned __int16 *a2)
{
  int v3; // r5
  unsigned int v4; // r1
  unsigned __int16 *v6; // r2
  int v7; // r3
  unsigned int v8; // r0
  int v9; // r5
  char v10; // r7
  unsigned int v11; // r2
  unsigned __int16 **v12; // r0
  int v13; // r3
  int v14; // r6
  int v15; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = a2[5];
  v4 = 0;
  if ( v3 )
  {
    v6 = a2;
    do
    {
      v7 = *((_DWORD *)v6 + 3);
      v6 += 2;
      v4 += v7;
      --v3;
    }
    while ( v3 );
  }
  v8 = *(_DWORD *)(a1 + 376);
  if ( !v8 )
    __brkdiv0();
  v9 = a1 + 12 * (v4 % v8) + 384;
  v10 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v9);
  }
  else
  {
    do
      v11 = __ldrex((unsigned int *)v9);
    while ( __strex(1u, (unsigned int *)v9) );
    __dmb(0xBu);
    if ( v11 )
      KxWaitForSpinLockAndAcquire((unsigned int *)v9);
  }
  *(_BYTE *)(v9 + 4) = v10;
  if ( a2[4] || a2[3] )
  {
    v14 = a2[4] + (a2[3] << 16);
  }
  else
  {
    v12 = (unsigned __int16 **)RtlpStdExtendUpperWatermark(a1);
    if ( v12 )
    {
      *v12 = a2;
      v13 = *(_DWORD *)(a1 + 100);
      v14 = (v13 - (int)v12) >> 2;
      a2[3] = (v13 - (int)v12) >> 18;
      a2[4] = v14;
    }
    else
    {
      v14 = 0;
    }
  }
  v15 = *(unsigned __int8 *)(v9 + 4);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)v9, vars4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v9 = 0;
  }
  KfLowerIrql(v15);
  return v14;
}
