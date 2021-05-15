// sub_5454FC 
 
void sub_5454FC()
{
  int v0; // r5
  unsigned int *v1; // r2
  unsigned int v2; // r0

  __dmb(0xBu);
  v1 = (unsigned int *)(v0 + 12);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 & 0x7FFFFFFF, v1) );
  JUMPOUT(0x4BE05E);
}
