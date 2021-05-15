// MiDecrementCloneBlockReference 
 
int __fastcall MiDecrementCloneBlockReference(int a1, _DWORD *a2, int a3)
{
  unsigned int *v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r1
  int v9; // r6
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r1
  int v16; // r7
  unsigned int *v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r1
  _DWORD *v20; // r1
  int v21; // r3

  if ( *(_DWORD *)(a3 + 264) && *(_DWORD *)(a3 + 264) != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    KeBugCheckEx(26, 399685, a1, (int)a2, 0);
  __dmb(0xBu);
  v6 = a2 + 3;
  do
  {
    v7 = __ldrex(v6);
    v8 = v7 - 1;
  }
  while ( __strex(v8, v6) );
  __dmb(0xBu);
  if ( v8 )
    v9 = 4;
  else
    v9 = MiDeleteMergedPte((int)MiSystemPartition, a2, (int)v6, 0);
  if ( MEMORY[0xC0402140] > *(_QWORD *)(a1 + 40) )
  {
    __dmb(0xBu);
    v10 = a2 + 2;
    do
    {
      v11 = __ldrex(v10);
      v12 = v11 - 1;
    }
    while ( __strex(v12, v10) );
    __dmb(0xBu);
    if ( (v12 & 0x7FFFFFF) == 0 && v9 != 3 )
      MiReturnCommit((int)MiSystemPartition, 1);
    v9 = 5;
  }
  v13 = (unsigned int *)(a1 + 24);
  do
  {
    v14 = __ldrex(v13);
    v15 = v14 - 1;
  }
  while ( __strex(v15, v13) );
  if ( !v15 )
  {
    RtlAvlRemoveNode(a3 + 272, a1);
    v16 = *(_DWORD *)(a1 + 28);
    v17 = (unsigned int *)(v16 + 4);
    do
    {
      v18 = __ldrex(v17);
      v19 = v18 - 1;
    }
    while ( __strex(v19, v17) );
    if ( !v19 )
    {
      v20 = *(_DWORD **)(v16 + 8);
      v21 = *(_DWORD *)(a1 + 16) - *(_DWORD *)(a1 + 12);
      v20[3] = ((((_WORD)v21 + 16) & 0xFFF) != 0) + ((unsigned int)(v21 + 16) >> 12);
      RtlpInterlockedPushEntrySList((unsigned __int64 *)&dword_6337B8, v20);
      KeSetEvent((int)algn_6337A4, 0, 0);
      ExFreePoolWithTag(v16);
    }
    PsReturnProcessNonPagedPoolQuota(a3, *(_DWORD *)(a1 + 32));
    ExFreePoolWithTag(a1);
  }
  return v9;
}
