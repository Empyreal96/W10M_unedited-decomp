// RtlpAllocateSecondLevelDirUsingFreeList 
 
int __fastcall RtlpAllocateSecondLevelDirUsingFreeList(int a1, int *a2, int a3, int a4)
{
  int v4; // r7
  unsigned int v6; // r2
  _DWORD *v7; // r5
  __int64 v8; // r2
  int v9; // r0
  int v10; // r0
  unsigned int v11; // lr
  unsigned int v12; // r2
  int **v13; // r1
  int **v14; // r7
  __int64 v15; // r0
  int v16; // r9
  unsigned int v17; // r2
  void **v18; // r2
  int *v19; // [sp+0h] [bp-28h] BYREF
  int **v20; // [sp+4h] [bp-24h]
  int v21; // [sp+8h] [bp-20h]

  v19 = a2;
  v20 = (int **)a3;
  v21 = a4;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50F230();
  do
    v6 = __ldrex((unsigned int *)&dword_6416AC);
  while ( __strex(1u, (unsigned int *)&dword_6416AC) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&dword_6416AC);
  v7 = off_6178C8;
  if ( off_6178C8 == &off_6178C8 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&dword_6416AC);
    }
    else
    {
      __dmb(0xBu);
      dword_6416AC = 0;
    }
    KfLowerIrql(v4);
    v10 = ExAllocatePoolWithTag(512, 4096);
    v7 = (_DWORD *)v10;
    if ( !v10 )
      return 0;
    v11 = v10 + 4096;
    v12 = v10 + 1024;
    v13 = &v19;
    v14 = &v19;
    *(_DWORD *)(v10 + 8) = 1;
    v19 = (int *)&v19;
    v20 = &v19;
    if ( v10 + 1024 < (unsigned int)(v10 + 4096) )
    {
      LODWORD(v15) = &v19;
      do
      {
        *(_DWORD *)(v12 + 8) = 0;
        HIDWORD(v15) = v20;
        *(_QWORD *)v12 = v15;
        if ( *(int ***)HIDWORD(v15) != &v19 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v15) = v12;
        v13 = (int **)v12;
        v20 = (int **)v12;
        v12 += 1024;
      }
      while ( v12 < v11 );
      v14 = (int **)v19;
    }
    if ( v14[1] != (int *)&v19 || *v13 != (int *)&v19 )
      __fastfail(3u);
    *v13 = (int *)v14;
    v14[1] = (int *)v13;
    v16 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(&dword_6416AC);
    }
    else
    {
      do
        v17 = __ldrex((unsigned int *)&dword_6416AC);
      while ( __strex(1u, (unsigned int *)&dword_6416AC) );
      __dmb(0xBu);
      if ( v17 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&dword_6416AC);
    }
    v18 = off_6178CC;
    if ( *((void ***)off_6178C8 + 1) != &off_6178C8 || *off_6178CC != &off_6178C8 )
      __fastfail(3u);
    if ( (int **)(*v14)[1] != v14 || (int **)*v14[1] != v14 )
      __fastfail(3u);
    *off_6178CC = v14;
    off_6178CC = (void **)v14[1];
    *v14[1] = (int)&off_6178C8;
    v14[1] = (int *)v18;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&dword_6416AC);
    }
    else
    {
      __dmb(0xBu);
      dword_6416AC = 0;
    }
    v9 = v16;
  }
  else
  {
    v8 = *(_QWORD *)off_6178C8;
    if ( *((void ***)off_6178C8 + 1) != &off_6178C8 || *(void **)(v8 + 4) != off_6178C8 )
      __fastfail(3u);
    off_6178C8 = *(void **)off_6178C8;
    *(_DWORD *)(v8 + 4) = &off_6178C8;
    v7[2] = 1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&dword_6416AC);
    }
    else
    {
      __dmb(0xBu);
      dword_6416AC = 0;
    }
    v9 = v4;
  }
  KfLowerIrql(v9);
  return (int)v7;
}
