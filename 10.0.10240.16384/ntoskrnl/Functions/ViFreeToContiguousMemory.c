// ViFreeToContiguousMemory 
 
int __fastcall ViFreeToContiguousMemory(int a1, int a2, unsigned int a3)
{
  int v3; // r3
  unsigned int v4; // r4
  int *v6; // r2
  int v7; // t1
  unsigned int *v9; // r5
  int v10; // r7
  unsigned int v11; // r2
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = *(_DWORD *)(a1 + 188);
  v4 = a3;
  if ( !v3 )
    return 0;
  if ( a3 >= 0x20 || *(_DWORD *)(v3 + 4 * a3) != a2 )
  {
    v6 = *(int **)(a1 + 188);
    v4 = 0;
    while ( 1 )
    {
      v7 = *v6++;
      if ( v7 == a2 )
        break;
      if ( ++v4 >= 0x20 )
        return 0;
    }
  }
  if ( v4 >= 0x20 )
    return 0;
  v9 = (unsigned int *)(a1 + 200);
  v10 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 200);
  }
  else
  {
    do
      v11 = __ldrex(v9);
    while ( __strex(1u, v9) );
    __dmb(0xBu);
    if ( v11 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 200));
  }
  RtlClearBits((_BYTE *)(a1 + 208), v4, 1u);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)(a1 + 200), vars4);
  }
  else
  {
    __dmb(0xBu);
    *v9 = 0;
  }
  KfLowerIrql(v10);
  return 1;
}
