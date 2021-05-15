// sub_50CE80 
 
void sub_50CE80()
{
  int v0; // r6
  unsigned int *v1; // r2
  unsigned int v2; // r4

  __dmb(0xBu);
  v1 = (unsigned int *)(v0 + 804);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 - 1, v1) );
  __dmb(0xBu);
  PsBoostThreadIoEx(v0, 1, 0);
  JUMPOUT(0x482320);
}
