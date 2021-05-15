// MiUpdatePageFileSectionList 
 
int __fastcall MiUpdatePageFileSectionList(int a1, int a2)
{
  int v4; // r10
  unsigned int v6; // r1
  int v7; // r6
  _DWORD *v8; // r6
  int v9; // r7
  int v10; // r2
  _DWORD *v11; // r3
  unsigned int v12; // r0

  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_510DCC();
  do
    v6 = __ldrex((unsigned __int8 *)&dword_632EBC + 3);
  while ( __strex(v6 | 0x80, (unsigned __int8 *)&dword_632EBC + 3) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(&dword_632EBC);
  while ( 1 )
  {
    v7 = dword_632EBC;
    if ( (dword_632EBC & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_632EBC & 0x40000000) == 0 )
    {
      do
        v12 = __ldrex((unsigned int *)&dword_632EBC);
      while ( v12 == v7 && __strex(v7 | 0x40000000, (unsigned int *)&dword_632EBC) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( !a2 )
  {
    RtlAvlRemoveNode(&dword_632EB8, a1 + 40);
    goto LABEL_17;
  }
  v8 = (_DWORD *)dword_632EB8;
  v9 = *(_DWORD *)(a1 + 4);
  v10 = 0;
  if ( !dword_632EB8 )
    goto LABEL_16;
  while ( MiPagefileSectionCompare(v9, v8) < 0 )
  {
    v11 = (_DWORD *)*v8;
    if ( !*v8 )
    {
      v10 = 0;
      goto LABEL_16;
    }
LABEL_11:
    v8 = v11;
  }
  v11 = (_DWORD *)v8[1];
  if ( v11 )
    goto LABEL_11;
  v10 = 1;
LABEL_16:
  RtlAvlInsertNodeEx(&dword_632EB8, v8, v10, a1 + 40);
LABEL_17:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632EBC);
  }
  else
  {
    __dmb(0xBu);
    dword_632EBC = 0;
  }
  return KfLowerIrql(v4);
}
