// ExRegisterCallback 
 
int __fastcall ExRegisterCallback(int a1, int a2, int a3)
{
  int v6; // r0
  _DWORD *v7; // r4
  int v8; // r7
  unsigned int *v9; // r6
  int v10; // r9
  unsigned int v12; // r2
  _DWORD *v13; // r1

  ObfReferenceObjectWithTag(a1);
  v6 = ExAllocatePoolWithTag(512, 28);
  v7 = (_DWORD *)v6;
  if ( !v6 )
    goto LABEL_19;
  *(_DWORD *)(v6 + 20) = 0;
  *(_BYTE *)(v6 + 24) = 0;
  *(_DWORD *)(v6 + 12) = a2;
  *(_DWORD *)(v6 + 16) = a3;
  *(_DWORD *)(v6 + 8) = a1;
  v8 = 0;
  v9 = (unsigned int *)(a1 + 4);
  v10 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50F1B0();
  do
    v12 = __ldrex(v9);
  while ( __strex(1u, v9) );
  __dmb(0xBu);
  if ( v12 )
    KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 4));
  if ( *(_BYTE *)(a1 + 16) || *(_DWORD *)(a1 + 8) == a1 + 8 )
  {
    v13 = *(_DWORD **)(a1 + 12);
    *v7 = a1 + 8;
    v7[1] = v13;
    v8 = 1;
    if ( *v13 != a1 + 8 )
      __fastfail(3u);
    *v13 = v7;
    *(_DWORD *)(a1 + 12) = v7;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 + 4);
  }
  else
  {
    __dmb(0xBu);
    *v9 = 0;
  }
  KfLowerIrql(v10);
  if ( !v8 )
  {
    ExFreePoolWithTag(v7, 0);
LABEL_19:
    ObfDereferenceObjectWithTag(a1);
    v7 = 0;
  }
  return (int)v7;
}
