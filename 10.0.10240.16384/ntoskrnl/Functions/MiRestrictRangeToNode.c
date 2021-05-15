// MiRestrictRangeToNode 
 
int __fastcall MiRestrictRangeToNode(unsigned int a1, unsigned int a2)
{
  int v4; // r10
  int v6; // r4
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r1
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r1
  unsigned int v16; // r2

  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50F124();
  v6 = dword_632EBC & 0x7FFFFFFF;
  v7 = (dword_632EBC & 0x7FFFFFFF) + 1;
  do
    v8 = __ldrex((unsigned int *)&dword_632EBC);
  while ( v8 == v6 && __strex(v7, (unsigned int *)&dword_632EBC) );
  __dmb(0xBu);
  if ( v8 != v6 )
    ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_632EBC);
  if ( dword_6337F0 )
  {
    v11 = 0;
    if ( a1 >= *(_DWORD *)(dword_6337F0 + 8) )
    {
      v12 = dword_6337F0;
      do
      {
        v12 += 8;
        ++v11;
      }
      while ( a1 >= *(_DWORD *)(v12 + 8) );
    }
    v13 = *(_DWORD *)(dword_6337F0 + 8 * v11 + 8);
    if ( a1 + a2 > v13 )
      a2 = v13 - a1;
  }
  if ( dword_6337F8 )
  {
    v14 = 0;
    if ( a1 >= *(_DWORD *)(dword_6337F8 + 12) )
    {
      v15 = dword_6337F8;
      do
      {
        v15 += 12;
        ++v14;
      }
      while ( a1 >= *(_DWORD *)(v15 + 12) );
    }
    v16 = *(_DWORD *)(dword_6337F8 + 12 * v14 + 12);
    if ( a1 + a2 > v16 )
      a2 = v16 - a1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_632EBC);
  }
  else
  {
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&dword_632EBC);
    while ( __strex(v9 & 0xBFFFFFFF, (unsigned int *)&dword_632EBC) );
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&dword_632EBC);
    while ( __strex(v10 - 1, (unsigned int *)&dword_632EBC) );
  }
  KfLowerIrql(v4);
  return a2;
}
