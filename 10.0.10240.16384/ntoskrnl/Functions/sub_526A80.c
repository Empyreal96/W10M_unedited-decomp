// sub_526A80 
 
void __fastcall sub_526A80(int a1, _QWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v12; // r5
  int v13; // r3
  unsigned int *v14; // r4
  unsigned __int64 v15; // kr08_8
  int v16; // r9
  unsigned int v17; // r2

  if ( !*a2 )
    JUMPOUT(0x461F04);
  v13 = *(_DWORD *)(a1 + 60);
  __dmb(0xBu);
  if ( v13 )
LABEL_16:
    JUMPOUT(0x461F06);
  v14 = (unsigned int *)(v12 + 16);
  v15 = *a2 - 1i64;
  v16 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v12 + 16);
  }
  else
  {
    do
      v17 = __ldrex(v14);
    while ( __strex(1u, v14) );
    __dmb(0xBu);
    if ( v17 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(v12 + 16));
  }
  if ( v15 >= *(_QWORD *)v12 )
  {
    if ( (dword_682604 & 0x10000) == 0 )
    {
LABEL_13:
      __dmb(0xBu);
      *v14 = 0;
      goto LABEL_14;
    }
  }
  else if ( (dword_682604 & 0x10000) == 0 )
  {
    goto LABEL_13;
  }
  KiReleaseSpinLockInstrumented((_DWORD *)(v12 + 16), a12);
LABEL_14:
  KfLowerIrql(v16);
  goto LABEL_16;
}
