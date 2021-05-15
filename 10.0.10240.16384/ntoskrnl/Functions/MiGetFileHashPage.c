// MiGetFileHashPage 
 
int __fastcall MiGetFileHashPage(int a1, int a2, int a3, int a4)
{
  __int16 *v4; // r4
  unsigned int v7; // r0
  int v8; // r0
  int v9; // r5
  int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r0
  _DWORD v15[6]; // [sp+0h] [bp-18h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v4 = *(__int16 **)(a1 + 128);
  if ( !MiChargeCommit(v4, 1, 1) )
    JUMPOUT(0x510D84);
  if ( !MiChargeResident(v4, 1, 128) )
    return sub_510D7C();
  if ( v4 == &MiSystemPartition )
  {
    do
      v7 = __ldrex(&dword_634A2C[25]);
    while ( __strex(v7 + 1, &dword_634A2C[25]) );
  }
  v8 = MiGetPage(v4, a2, 128);
  v9 = v8;
  if ( v8 == -1 )
  {
    if ( v4 == &MiSystemPartition )
    {
      MiReturnResidentAvailable(1);
      do
        v12 = __ldrex(&dword_634A2C[26]);
      while ( __strex(v12 + 1, &dword_634A2C[26]) );
    }
    else
    {
      v13 = (unsigned int *)(v4 + 1920);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 + 1, v13) );
    }
    MiReturnCommit(v4, 1);
  }
  else
  {
    v10 = MiMapPageInHyperSpaceWorker(v8, v15, 0x80000000);
    RtlFillMemoryUlong(v10, 4096, 0);
    MiUnmapPageInHyperSpaceWorker(v10, LOBYTE(v15[0]), 0x80000000);
    do
      v11 = __ldrex((unsigned int *)algn_634F8C);
    while ( __strex(v11 + 1, (unsigned int *)algn_634F8C) );
  }
  return v9;
}
