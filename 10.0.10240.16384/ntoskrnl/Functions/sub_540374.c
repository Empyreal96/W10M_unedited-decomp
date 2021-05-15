// sub_540374 
 
void __fastcall sub_540374(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r5
  int v17; // r8
  int v18; // r9
  int v19; // r10
  unsigned int *v20; // r6
  unsigned int *v21; // r4
  unsigned int v22; // r2
  int v23; // r2
  int v24; // r3
  int v25; // [sp+0h] [bp+0h]
  int v26; // [sp+4h] [bp+4h]
  int v27; // [sp+8h] [bp+8h]

  while ( 1 )
  {
    v19 = 0;
    v25 = *(_DWORD *)(*(_DWORD *)(v17 + 136) + 8 * v16 + 4);
    v27 = *(_DWORD *)(*(_DWORD *)(v17 + 136) + 8 * v16);
    v20 = *(unsigned int **)(*(_DWORD *)(v18 + 392) + 4 * v27);
    v21 = v20 + 20;
    v26 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)(v20 + 20));
    }
    else
    {
      do
        v22 = __ldrex(v21);
      while ( __strex(1u, v21) );
      __dmb(0xBu);
      if ( v22 )
        KxWaitForSpinLockAndAcquire(v20 + 20);
    }
    v23 = v20[31] + 8 * v25;
    if ( *(_BYTE *)(v23 + 4) == 1 )
    {
      *(_BYTE *)(v23 + 4) = 0;
      v24 = v20[32] - 1;
      v20[32] = v24;
      if ( !v24 )
        v19 = 1;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v20 + 20, a16);
    }
    else
    {
      __dmb(0xBu);
      *v21 = 0;
    }
    KfLowerIrql(v26);
    if ( v19 )
      PopPluginComponentActive(v18, v27, 1, 0);
    if ( (unsigned int)++v16 >= *(_DWORD *)(v17 + 132) )
      JUMPOUT(0x4AC578);
  }
}
