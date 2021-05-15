// MmStoreChargeResidentAvailableForRead 
 
int __fastcall MmStoreChargeResidentAvailableForRead(int a1)
{
  int v1; // r4
  unsigned int v2; // r0

  v1 = a1 + 16;
  if ( !MiChargeResident(MiSystemPartition, a1 + 16, 0) )
    return 0;
  do
    v2 = __ldrex(&dword_634A2C[118]);
  while ( __strex(v2 + v1, &dword_634A2C[118]) );
  return 1;
}
