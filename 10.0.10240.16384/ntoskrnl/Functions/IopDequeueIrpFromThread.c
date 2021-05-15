// IopDequeueIrpFromThread 
 
int __fastcall IopDequeueIrpFromThread(_DWORD *a1)
{
  int v2; // r4
  int v3; // r6
  unsigned int *v4; // r8
  __int64 v5; // r0
  unsigned int v6; // r2
  _DWORD *v7; // r2

  v2 = a1[20];
  v3 = 0;
  if ( v2 )
  {
    v4 = (unsigned int *)(v2 + 1024);
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      LODWORD(v5) = sub_52C92C();
      return v5;
    }
    do
      v6 = __ldrex(v4);
    while ( __strex(1u, v4) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire(v2 + 1024);
  }
  v7 = a1 + 4;
  v5 = *((_QWORD *)a1 + 2);
  if ( *(_DWORD **)(v5 + 4) != a1 + 4 || *(_DWORD **)HIDWORD(v5) != v7 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v5) = v5;
  *(_DWORD *)(v5 + 4) = HIDWORD(v5);
  *v7 = v7;
  a1[5] = a1 + 4;
  if ( v2 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v2 + 1024);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(v2 + 1024) = 0;
    }
    LODWORD(v5) = KfLowerIrql(v3);
  }
  return v5;
}
