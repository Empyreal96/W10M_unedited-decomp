// sub_543E88 
 
void sub_543E88()
{
  unsigned int *v0; // r9
  unsigned int v1; // r1

  do
    v1 = __ldrex(v0);
  while ( __strex(v1 & 0x7FFFFFFF, v0) );
  JUMPOUT(0x4B942E);
}
