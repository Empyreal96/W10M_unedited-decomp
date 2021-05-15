// RtlpStdExtendLowerWatermark 
 
int __fastcall RtlpStdExtendLowerWatermark(int a1, int a2)
{
  int v4; // r7
  char v5; // r5
  unsigned int v6; // r2
  unsigned int v7; // r1
  int v8; // r5
  int v9; // r5
  unsigned int v11; // [sp+8h] [bp-20h]
  unsigned int v12; // [sp+Ch] [bp-1Ch]
  int vars4; // [sp+2Ch] [bp+4h]

  v4 = 0;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1);
  }
  else
  {
    do
      v6 = __ldrex((unsigned int *)a1);
    while ( __strex(1u, (unsigned int *)a1) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire((unsigned int *)a1);
  }
  *(_BYTE *)(a1 + 4) = v5;
  v7 = *(_DWORD *)(a1 + 76);
  v8 = *(_DWORD *)(a1 + 84);
  v11 = v7;
  if ( !*(_BYTE *)(a1 + 68) )
    goto LABEL_9;
  if ( (unsigned int)(v8 + a2) > *(_DWORD *)(a1 + 88) )
    goto LABEL_14;
  if ( !*(_BYTE *)(a1 + 68) )
  {
LABEL_9:
    if ( v8 + a2 > v7 )
    {
      v12 = (a2 + 4095) & 0xFFFFF000;
      if ( v12 + v7 >= *(_DWORD *)(a1 + 80) || ZwAllocateVirtualMemory() < 0 )
        goto LABEL_14;
      *(_DWORD *)(a1 + 76) = v12 + v11;
    }
  }
  *(_DWORD *)(a1 + 84) = v8 + a2;
  v4 = v8;
  ++*(_DWORD *)(a1 + 104);
LABEL_14:
  v9 = *(unsigned __int8 *)(a1 + 4);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)a1, vars4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  KfLowerIrql(v9);
  return v4;
}
