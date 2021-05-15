// sub_53FDFC 
 
void __fastcall sub_53FDFC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  unsigned int *v16; // r5
  int v17; // r8
  unsigned int *v18; // r6
  unsigned int v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r7
  int v22; // r1
  int v23; // r4
  int v24; // [sp+4h] [bp+4h]

  v18 = v16 + 20;
  v24 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)(v16 + 20));
  }
  else
  {
    do
      v19 = __ldrex(v18);
    while ( __strex(1u, v18) );
    __dmb(0xBu);
    if ( v19 )
      KxWaitForSpinLockAndAcquire(v16 + 20);
  }
  v20 = v16[30];
  v21 = 0;
  v16[32] = v20;
  if ( v20 )
  {
    do
    {
      v22 = v16[31] + 8 * v21;
      v23 = *(_DWORD *)(*(_DWORD *)(v17 + 392) + 4 * *(_DWORD *)v22);
      *(_BYTE *)(v22 + 4) = 1;
      PopFxActivateComponent(v17, v23, 2, a5);
      if ( *(int *)(v23 + 52) < 0 )
      {
        *(_BYTE *)(v16[31] + 8 * v21 + 4) = 0;
        --v16[32];
      }
      ++v21;
    }
    while ( v21 < v16[30] );
    v18 = v16 + 20;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v18, a16);
  }
  else
  {
    __dmb(0xBu);
    *v18 = 0;
  }
  KfLowerIrql(v24);
  JUMPOUT(0x4AB35E);
}
