// KiUnmaskSecondaryInterruptInternal 
 
int __fastcall KiUnmaskSecondaryInterruptInternal(int a1, int a2)
{
  int v2; // r4
  unsigned int *v4; // r5
  int v5; // r8
  int v6; // r9
  unsigned int v8; // r2
  int v9; // r2
  int v10; // r3
  _DWORD *v11; // r1
  int v12; // r7
  int v13; // r4

  v2 = 7 * (a1 - 4096);
  v4 = (unsigned int *)(KiGlobalSecondaryIDT + 28 * (a1 - 4096));
  v5 = 0;
  v6 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51F92C();
  do
    v8 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForSpinLockAndAcquire(v4);
  v9 = KiGlobalSecondaryIDT + 4 * v2;
  if ( *(_BYTE *)(v9 + 20) )
  {
    v10 = *(_DWORD *)(v9 + 24);
    if ( v10 )
    {
      v11 = (_DWORD *)(v10 + 4);
      while ( 1 )
      {
        v12 = v11[14];
        if ( (v12 & 1) == 0 )
          break;
        v11 = (_DWORD *)*v11;
        if ( v11 == (_DWORD *)(*(_DWORD *)(v9 + 24) + 4) )
          goto LABEL_11;
      }
      *(_BYTE *)(v9 + 20) = 0;
LABEL_11:
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
      if ( (v12 & 1) == 0 )
        v5 = off_617A64(a2, 0);
      return v5;
    }
    v13 = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
  }
  else
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
    v13 = 296;
  }
  KfLowerIrql(v6);
  return v13;
}
