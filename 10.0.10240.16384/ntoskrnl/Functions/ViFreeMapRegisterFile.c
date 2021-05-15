// ViFreeMapRegisterFile 
 
int __fastcall ViFreeMapRegisterFile(int a1, int a2)
{
  unsigned int *v4; // r5
  int v5; // r7
  unsigned int v6; // r2
  __int64 v7; // r0
  int v8; // r2
  int v9; // r5
  unsigned int v10; // r6
  _DWORD *i; // r5
  int v12; // r0
  int v13; // r3
  int v14; // r2
  int v15; // r1
  int v16; // r0
  int v17; // r5
  BOOL v18; // r1
  BOOL v19; // r1
  int vars4; // [sp+1Ch] [bp+4h]

  if ( !a2 || *(_DWORD *)a2 != -1393569779 )
    return 0;
  v4 = (unsigned int *)(a1 + 64);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v4);
  }
  else
  {
    do
      v6 = __ldrex(v4);
    while ( __strex(1u, v4) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire(v4);
  }
  v7 = *(_QWORD *)(a2 + 4);
  if ( *(_DWORD *)(v7 + 4) != a2 + 4 || *(_DWORD *)HIDWORD(v7) != a2 + 4 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v7) = v7;
  *(_DWORD *)(v7 + 4) = HIDWORD(v7);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v5);
  v9 = *(_DWORD *)(a2 + 24);
  *(_DWORD *)a2 = 0;
  if ( v9 )
  {
    if ( (*(_WORD *)(v9 + 6) & 1) != 0 )
      MmUnmapLockedPages(*(_DWORD *)(v9 + 12), v9, v8);
    IoFreeMdl(v9);
  }
  MmUnmapLockedPages(*(_DWORD *)(a2 + 36), *(_DWORD *)(a2 + 32), v8);
  v10 = 0;
  for ( i = (_DWORD *)(a2 + 48); v10 < *(_DWORD *)(a2 + 16); i += 5 )
  {
    v12 = i[3];
    if ( *i )
    {
      v13 = i[1];
      v14 = (*i & 0xFFF) + v12 + 4096;
    }
    else
    {
      v13 = 0;
      v14 = 0;
    }
    ViCheckPadding(v12, 12288, v14, v13);
    v15 = i[3];
    i[2] = 0;
    if ( !ViFreeToContiguousMemory(a1, v15, v10) )
      ExFreePoolWithTag(i[3]);
    ++v10;
  }
  v16 = IoFreeMdl(*(_DWORD *)(a2 + 32));
  v17 = *(_DWORD *)(a2 + 40);
  if ( v17 )
  {
    v18 = KeGetCurrentIrql(v16) != 2;
    v16 = VfPoolDelayFreeIfPossible(v17, v18);
  }
  *(_DWORD *)a2 = 0;
  v19 = KeGetCurrentIrql(v16) != 2;
  VfPoolDelayFreeIfPossible(a2, v19);
  return 1;
}
