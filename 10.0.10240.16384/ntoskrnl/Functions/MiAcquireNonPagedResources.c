// MiAcquireNonPagedResources 
 
int __fastcall MiAcquireNonPagedResources(__int16 *a1, unsigned int a2)
{
  unsigned int v5; // r0

  if ( !MiChargeCommit((int)a1, a2, 0) )
    JUMPOUT(0x50F118);
  if ( !MiChargeResident(a1, a2, 0) )
    return sub_50F110();
  if ( a1 == MiSystemPartition )
  {
    do
      v5 = __ldrex(&dword_634A2C[69]);
    while ( __strex(v5 + a2, &dword_634A2C[69]) );
  }
  return 1;
}
