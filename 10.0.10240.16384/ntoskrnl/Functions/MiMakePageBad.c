// MiMakePageBad 
 
int __fastcall MiMakePageBad(int result, int a2, unsigned int *a3)
{
  int v3; // r6
  unsigned int v5; // r5
  unsigned int v6; // r1

  v3 = result;
  if ( (*(_BYTE *)(result + 19) & 0x40) == 0 )
  {
    MiChargeCommit((int)MiSystemPartition, 1u, 4);
    result = MiChargeResident(MiSystemPartition, 1u, -1);
    a3 = &dword_634A2C[57];
    do
      v5 = __ldrex(&dword_634A2C[57]);
    while ( __strex(v5 + 1, &dword_634A2C[57]) );
    *(_BYTE *)(v3 + 19) |= 0x40u;
  }
  if ( a2 == 1 )
    result = MiInsertPageInList(v3, 32, (int)a3);
  do
    v6 = __ldrex((unsigned int *)&dword_634424);
  while ( __strex(v6 + 1, (unsigned int *)&dword_634424) );
  return result;
}
