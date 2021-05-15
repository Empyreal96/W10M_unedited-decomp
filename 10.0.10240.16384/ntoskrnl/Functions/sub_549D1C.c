// sub_549D1C 
 
void sub_549D1C()
{
  int v0; // r6
  unsigned int v1; // r0

  MiReturnResidentAvailable(v0);
  do
    v1 = __ldrex(&dword_634A2C[79]);
  while ( __strex(v1 + v0, &dword_634A2C[79]) );
  JUMPOUT(0x4CAA82);
}
