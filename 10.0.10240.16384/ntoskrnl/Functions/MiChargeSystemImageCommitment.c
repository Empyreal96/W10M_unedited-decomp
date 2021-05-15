// MiChargeSystemImageCommitment 
 
int __fastcall MiChargeSystemImageCommitment(int a1)
{
  unsigned int v1; // r4
  int v2; // r1
  unsigned int v4; // r0
  unsigned int v5; // r0

  v1 = *(_DWORD *)(*(_DWORD *)MiSectionControlArea(a1) + 4);
  if ( v2 == 1 )
  {
    if ( v1 )
    {
      if ( !MiChargeCommit((int)MiSystemPartition, v1, 0) )
        JUMPOUT(0x7CDE70);
      if ( !MiChargeResident(MiSystemPartition, v1, 0) )
        return sub_7CDE68();
      do
        v4 = __ldrex(&dword_634A2C[47]);
      while ( __strex(v4 + v1, &dword_634A2C[47]) );
    }
  }
  else
  {
    MiReturnCommit((int)MiSystemPartition, v1);
    if ( v1 )
    {
      MiReturnResidentAvailable(v1);
      do
        v5 = __ldrex(&dword_634A2C[53]);
      while ( __strex(v5 + v1, &dword_634A2C[53]) );
    }
  }
  return 0;
}
