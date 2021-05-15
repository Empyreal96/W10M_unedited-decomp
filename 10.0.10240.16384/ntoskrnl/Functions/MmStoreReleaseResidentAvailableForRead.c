// MmStoreReleaseResidentAvailableForRead 
 
unsigned int __fastcall MmStoreReleaseResidentAvailableForRead(int a1)
{
  int v1; // r4
  unsigned int result; // r0

  v1 = a1 + 16;
  MiReturnResidentAvailable(a1 + 16);
  do
    result = __ldrex(&dword_634A2C[119]);
  while ( __strex(result + v1, &dword_634A2C[119]) );
  return result;
}
