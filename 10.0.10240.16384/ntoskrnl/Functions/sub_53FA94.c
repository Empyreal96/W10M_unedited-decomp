// sub_53FA94 
 
void __fastcall sub_53FA94(unsigned int *a1)
{
  unsigned int *v1; // r9
  unsigned int v2; // r2
  unsigned int v3; // r1

  v2 = *v1;
  do
    v3 = __ldrex(a1);
  while ( (unsigned int *)v3 == v1 && __strex(v2, a1) );
  JUMPOUT(0x4A9936);
}
