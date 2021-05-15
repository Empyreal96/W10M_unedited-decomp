// MmIsFileObjectAPagingFile 
 
int __fastcall MmIsFileObjectAPagingFile(int a1)
{
  int v2; // r6
  int v3; // r10
  int v5; // r4
  unsigned int v6; // r0
  unsigned int v7; // r2
  _DWORD *v8; // r4
  int v9; // r0
  unsigned int v10; // r4
  unsigned int v11; // r1

  v2 = 0;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5440BC();
  v5 = dword_6348BC & 0x7FFFFFFF;
  v6 = (dword_6348BC & 0x7FFFFFFF) + 1;
  do
    v7 = __ldrex((unsigned int *)&dword_6348BC);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&dword_6348BC) );
  __dmb(0xBu);
  if ( v7 != v5 )
    ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_6348BC);
  v8 = (_DWORD *)dword_6348B8;
  if ( dword_6348B8 )
  {
    do
    {
      v9 = MiPagefileCompare(a1, v8);
      if ( v9 < 0 )
      {
        v8 = (_DWORD *)*v8;
      }
      else
      {
        if ( v9 <= 0 )
        {
          if ( v8 )
            v2 = 1;
          break;
        }
        v8 = (_DWORD *)v8[1];
      }
    }
    while ( v8 );
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6348BC);
  }
  else
  {
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&dword_6348BC);
    while ( __strex(v10 & 0xBFFFFFFF, (unsigned int *)&dword_6348BC) );
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&dword_6348BC);
    while ( __strex(v11 - 1, (unsigned int *)&dword_6348BC) );
  }
  KfLowerIrql(v3);
  return v2;
}
