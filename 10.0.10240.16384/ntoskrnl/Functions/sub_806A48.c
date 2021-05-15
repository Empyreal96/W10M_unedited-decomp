// sub_806A48 
 
void __fastcall sub_806A48(int a1, unsigned int a2)
{
  unsigned int *v2; // r4

  ExpReleaseFastMutexContended(v2, a2);
  JUMPOUT(0x754B78);
}
