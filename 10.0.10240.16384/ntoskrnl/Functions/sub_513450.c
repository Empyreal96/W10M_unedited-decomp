// sub_513450 
 
void sub_513450()
{
  int v0; // r5
  unsigned int *v1; // r2
  unsigned int v2; // r0

  v1 = (unsigned int *)(v0 + 12);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 & 0x7FFFFFFF, v1) );
  JUMPOUT(0x42E4CC);
}
