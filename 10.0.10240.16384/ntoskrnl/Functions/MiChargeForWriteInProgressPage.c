// MiChargeForWriteInProgressPage 
 
int __fastcall MiChargeForWriteInProgressPage(__int16 *a1, char a2)
{
  char v4; // r8
  int v5; // lr
  unsigned int *v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r5
  int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r4
  unsigned int v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r0

  if ( (a2 & 2) != 0 )
  {
    v4 = 4;
    v5 = -1;
  }
  else
  {
    v4 = 8;
    v5 = 0;
  }
  if ( a1 == MiSystemPartition
    && (v6 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4992), (v7 = *v6) != 0)
    && v7 != -1 )
  {
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 - 1, v6) );
    if ( v8 != v7 )
      return sub_53A344();
    v10 = 1;
  }
  else
  {
    v10 = MiChargePartitionResidentAvailable((int)a1, 1u, v5);
    if ( !v10 )
      return 0;
  }
  if ( (a2 & 1) == 0 )
  {
    if ( a1 == MiSystemPartition )
    {
      do
        v11 = __ldrex(&dword_634A2C[122]);
      while ( __strex(v11 + 1, &dword_634A2C[122]) );
    }
    return v10;
  }
  if ( a1 == MiSystemPartition )
  {
    do
      v12 = __ldrex(&dword_634A2C[124]);
    while ( __strex(v12 + 1, &dword_634A2C[124]) );
  }
  if ( MiChargeCommit((int)a1, 1u, v4) )
    return v10;
  if ( a1 == MiSystemPartition )
  {
    MiReturnResidentAvailable(1);
    do
      v13 = __ldrex(&dword_634A2C[125]);
    while ( __strex(v13 + 1, &dword_634A2C[125]) );
  }
  else
  {
    v14 = (unsigned int *)(a1 + 1920);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 + 1, v14) );
  }
  return 0;
}
