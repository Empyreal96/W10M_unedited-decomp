// MmDeleteProcessAddressSpace 
 
int __fastcall MmDeleteProcessAddressSpace(_DWORD *a1)
{
  _DWORD *v1; // r4
  int v3; // r9
  int v4; // r1
  __int16 *v5; // r0
  __int16 *v6; // r6
  unsigned int v7; // r4
  _DWORD *v8; // r0
  unsigned int v9; // r0
  unsigned int v10; // r0
  int result; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r3
  unsigned int v16; // r0

  v1 = (_DWORD *)a1[106];
  if ( a1[70] )
    sub_7C0900((int)a1);
  if ( v1 )
  {
    while ( 1 )
    {
      v15 = (_DWORD *)*v1;
      if ( !*v1 )
        break;
      do
      {
        v16 = (unsigned int)v15;
        v15 = (_DWORD *)*v15;
      }
      while ( v15 );
      if ( !v16 )
        break;
      ExFreePoolWithTag(v16);
    }
    ExFreePoolWithTag((unsigned int)v1);
  }
  v3 = MiDeleteFinalPageTables((int)a1);
  PsReturnProcessQuota((int)a1, v4, 4);
  v5 = MiGetThreadPartition();
  v6 = v5;
  if ( v5 == MiSystemPartition )
  {
    MiReturnResidentAvailable(4);
    do
      v7 = __ldrex(&dword_634A04[6]);
    while ( __strex(v7 + 4, &dword_634A04[6]) );
  }
  else
  {
    MiReturnPartitionResidentAvailable((int)v5, 4);
  }
  if ( a1[82] )
    MiDeletePhysicalProcessPages(a1);
  v8 = (_DWORD *)a1[125];
  if ( v8 )
  {
    MiEmptyPageAccessLog(v8);
    a1[125] = 0;
  }
  v9 = a1[154];
  if ( v9 )
  {
    ExFreePoolWithTag(v9);
    a1[154] = 0;
  }
  MiReturnCommit((int)v6, 3 - v3);
  do
    v10 = __ldrex(&dword_634DA8);
  while ( __strex(v10 - 3, &dword_634DA8) );
  MiDeleteProcessPageDirectories(a1);
  if ( a1[81] )
    MiReleaseProcessReferenceToSessionDataPage();
  result = MiContractPagingFiles((int)v6);
  if ( v6 != MiSystemPartition )
    result = MiDereferencePartition((int)v6, v12, v13, v14);
  return result;
}
