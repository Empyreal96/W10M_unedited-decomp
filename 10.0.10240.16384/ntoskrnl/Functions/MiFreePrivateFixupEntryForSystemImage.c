// MiFreePrivateFixupEntryForSystemImage 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiFreePrivateFixupEntryForSystemImage(int a1, int a2)
{
  int *v3; // r8
  unsigned int v5; // r1
  int v6; // r4
  int *v7; // r4
  int v8; // r1
  unsigned int v9; // r0
  int *v10; // r1 OVERLAPPED
  int **v11; // r2 OVERLAPPED
  int v12; // [sp+8h] [bp-28h]

  v3 = 0;
  v12 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_552980();
  do
    v5 = __ldrex((unsigned __int8 *)&dword_632F00 + 3);
  while ( __strex(v5 | 0x80, (unsigned __int8 *)&dword_632F00 + 3) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632F00);
  while ( 1 )
  {
    v6 = dword_632F00;
    if ( (dword_632F00 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_632F00 & 0x40000000) == 0 )
    {
      v8 = dword_632F00 | 0x40000000;
      do
        v9 = __ldrex((unsigned int *)&dword_632F00);
      while ( v9 == v6 && __strex(v8, (unsigned int *)&dword_632F00) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v7 = (int *)dword_632F04;
  if ( (int *)dword_632F04 == &dword_632F04 )
    goto LABEL_10;
  while ( 1 )
  {
    v3 = v7;
    if ( a1 == v7[2] )
      break;
    v7 = (int *)*v7;
    if ( v7 == &dword_632F04 )
      goto LABEL_10;
  }
  if ( a2 )
  {
    *(_QWORD *)&v10 = *(_QWORD *)v7;
    if ( *(int **)(*v7 + 4) != v7 || *v11 != v7 )
      __fastfail(3u);
    *v11 = v10;
    v10[1] = (int)v11;
LABEL_10:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632F00);
    }
    else
    {
      __dmb(0xBu);
      dword_632F00 = 0;
    }
    KfLowerIrql(v12);
    if ( a2 )
    {
      if ( v7 == &dword_632F04 )
        KeBugCheckEx(26, 4113, a1);
      ExFreePoolWithTag(v3[5], 0);
      ExFreePoolWithTag(v3, 0);
    }
    return 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632F00);
  }
  else
  {
    __dmb(0xBu);
    dword_632F00 = 0;
  }
  KfLowerIrql(v12);
  return (int)v7;
}
