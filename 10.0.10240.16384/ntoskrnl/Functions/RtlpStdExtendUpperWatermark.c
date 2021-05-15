// RtlpStdExtendUpperWatermark 
 
int __fastcall RtlpStdExtendUpperWatermark(int a1)
{
  int v2; // r6
  char v3; // r5
  unsigned int v4; // r2
  unsigned int v5; // r1
  int v6; // r5
  int v7; // r3
  int v8; // r5
  unsigned int v10; // [sp+8h] [bp-18h]
  int vars4; // [sp+24h] [bp+4h]

  v2 = 0;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1);
  }
  else
  {
    do
      v4 = __ldrex((unsigned int *)a1);
    while ( __strex(1u, (unsigned int *)a1) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire((unsigned int *)a1);
  }
  *(_BYTE *)(a1 + 4) = v3;
  v5 = *(_DWORD *)(a1 + 80);
  v6 = *(_DWORD *)(a1 + 88);
  if ( !*(_BYTE *)(a1 + 68) )
    goto LABEL_9;
  if ( (unsigned int)(v6 - 4) < *(_DWORD *)(a1 + 84) )
    goto LABEL_14;
  if ( !*(_BYTE *)(a1 + 68) )
  {
LABEL_9:
    if ( v6 - 4 < v5 )
    {
      if ( v5 - 4096 <= *(_DWORD *)(a1 + 76) )
        goto LABEL_14;
      v10 = v5 - 4096;
      if ( ZwAllocateVirtualMemory() < 0 )
        goto LABEL_14;
      *(_DWORD *)(a1 + 80) = v10;
    }
  }
  v7 = *(_DWORD *)(a1 + 96);
  v2 = v6 - 4;
  *(_DWORD *)(a1 + 88) = v6 - 4;
  *(_DWORD *)(a1 + 96) = v7 + 1;
LABEL_14:
  v8 = *(unsigned __int8 *)(a1 + 4);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)a1, vars4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  KfLowerIrql(v8);
  return v2;
}
