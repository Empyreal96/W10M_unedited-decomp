// MiObtainNonPagedPoolCharges 
 
int __fastcall MiObtainNonPagedPoolCharges(int a1)
{
  unsigned int v3; // r0
  unsigned int v4; // r0

  if ( dword_640714 )
  {
    if ( !MiChargeCommit(MiSystemPartition, a1, 1) )
      return sub_5148B8();
    if ( !MiChargeResident(MiSystemPartition, a1, 0) )
      JUMPOUT(0x5148C2);
    do
      v3 = __ldrex(&dword_634A2C[32]);
    while ( __strex(v3 + a1, &dword_634A2C[32]) );
    do
      v4 = __ldrex((unsigned int *)algn_634D8C);
    while ( __strex(v4 + a1, (unsigned int *)algn_634D8C) );
  }
  return 1;
}
