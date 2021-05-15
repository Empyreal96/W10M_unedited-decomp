// sub_546B1C 
 
void __fastcall sub_546B1C(int a1, unsigned int a2)
{
  unsigned int *v2; // r5

  ExpReleaseFastMutexContended(v2, a2);
  JUMPOUT(0x4C20FA);
}
