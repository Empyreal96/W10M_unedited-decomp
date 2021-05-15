// PspInsertProperty 
 
int __fastcall PspInsertProperty(_DWORD *a1, int a2, int a3)
{
  int v6; // r4
  _DWORD *v7; // r5
  unsigned int *v8; // r6
  unsigned int v10; // r2
  int v11; // r2
  int v12; // [sp+0h] [bp-20h]

  v6 = 0;
  v7 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1349742672);
  if ( !v7 )
    return -1073741801;
  v8 = a1 + 2;
  v12 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51F728();
  do
    v10 = __ldrex(v8);
  while ( __strex(1u, v8) );
  __dmb(0xBu);
  if ( v10 )
    KxWaitForSpinLockAndAcquire(a1 + 2);
  if ( PspFindPropertySetEntry(a1, a2) )
  {
    v6 = -1073741771;
  }
  else
  {
    v7[2] = a2;
    v7[3] = a3;
    v11 = *a1;
    *v7 = *a1;
    v7[1] = a1;
    if ( *(_DWORD **)(v11 + 4) != a1 )
      __fastfail(3u);
    *(_DWORD *)(v11 + 4) = v7;
    *a1 = v7;
    ObfReferenceObjectWithTag(a3, 1917875024);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 + 2);
  }
  else
  {
    __dmb(0xBu);
    *v8 = 0;
  }
  KfLowerIrql(v12);
  if ( v6 < 0 )
    ExFreePoolWithTag(v7, 1349742672);
  return v6;
}
