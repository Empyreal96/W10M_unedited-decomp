// IopDequeueIrpFromFileObject 
 
int __fastcall IopDequeueIrpFromFileObject(_DWORD *a1, int a2)
{
  unsigned int *v3; // r4
  int v4; // r6
  unsigned int v6; // r2
  _DWORD *v7; // r2
  __int64 v8; // r0

  v3 = (unsigned int *)(a2 + 112);
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_521520();
  do
    v6 = __ldrex(v3);
  while ( __strex(1u, v3) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire(v3);
  v7 = a1 + 4;
  v8 = *((_QWORD *)a1 + 2);
  if ( *(_DWORD **)(v8 + 4) != a1 + 4 || *(_DWORD **)HIDWORD(v8) != v7 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v8) = v8;
  *(_DWORD *)(v8 + 4) = HIDWORD(v8);
  *v7 = v7;
  a1[5] = a1 + 4;
  ObfDereferenceObjectWithTag(a1[12] & 0xFFFFFFFC);
  a1[2] = a1[2] & 0xFFFFDFFF | 0x8000;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(v4);
}
