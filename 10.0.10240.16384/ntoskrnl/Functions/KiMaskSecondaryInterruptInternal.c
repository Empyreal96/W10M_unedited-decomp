// KiMaskSecondaryInterruptInternal 
 
int __fastcall KiMaskSecondaryInterruptInternal(int a1, int a2)
{
  int v2; // r8
  unsigned int *v4; // r4
  int v5; // r5
  int v6; // r7
  unsigned int v8; // r2
  int v9; // r1
  int v10; // r3
  _DWORD *v11; // r2

  v2 = 7 * (a1 - 4096);
  v4 = (unsigned int *)(KiGlobalSecondaryIDT + 28 * (a1 - 4096));
  v5 = 0;
  v6 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51F8E0();
  do
    v8 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForSpinLockAndAcquire(v4);
  v9 = KiGlobalSecondaryIDT + 4 * v2;
  if ( *(_BYTE *)(v9 + 20) || (v10 = *(_DWORD *)(v9 + 24)) == 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    KfLowerIrql(v6);
    v5 = 0;
  }
  else
  {
    v11 = (_DWORD *)(v10 + 4);
    while ( (v11[14] & 1) != 0 )
    {
      v11 = (_DWORD *)*v11;
      if ( v11 == (_DWORD *)(*(_DWORD *)(v9 + 24) + 4) )
      {
        *(_BYTE *)(v9 + 20) = 1;
        goto LABEL_12;
      }
    }
    v5 = 296;
LABEL_12:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    KfLowerIrql(v6);
    if ( !v5 )
      off_617A60(a2, 0);
  }
  return v5;
}
