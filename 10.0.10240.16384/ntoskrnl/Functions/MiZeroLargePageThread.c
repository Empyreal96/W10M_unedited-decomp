// MiZeroLargePageThread 
 
int __fastcall MiZeroLargePageThread(int a1)
{
  int v2; // r3
  unsigned int v3; // r7
  int v4; // r4
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int *v8; // r2
  unsigned int v9; // r4
  int v10; // [sp+0h] [bp-20h]

  v2 = __mrc(15, 0, 13, 0, 3);
  v3 = *(_DWORD *)(a1 + 4);
  KeSetActualBasePriorityThread(v2 & 0xFFFFFFC0, 1);
  v4 = MiUnlinkNodeLargePage(MiSystemPartition, v3 >> byte_6337F5, 1, 1);
  if ( !v4 )
    return MiDeleteZeroThreadContext(MiSystemPartition, a1);
  while ( 1 )
  {
    MiZeroLargePage(v4, a1);
    v10 = KfRaiseIrql(2);
    v5 = (unsigned __int8 *)(v4 + 15);
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x80, v5) );
    __dmb(0xBu);
    if ( v6 >> 7 )
      break;
    MiInsertLargePageInNodeList((v4 - MmPfnDatabase) / 24, 1024, 0);
    __dmb(0xBu);
    v8 = (unsigned int *)(v4 + 12);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 & 0x7FFFFFFF, v8) );
    KfLowerIrql(v10);
    v4 = MiUnlinkNodeLargePage(MiSystemPartition, v3 >> byte_6337F5, 1, 1);
    if ( !v4 )
      return MiDeleteZeroThreadContext(MiSystemPartition, a1);
  }
  return sub_54E508();
}
