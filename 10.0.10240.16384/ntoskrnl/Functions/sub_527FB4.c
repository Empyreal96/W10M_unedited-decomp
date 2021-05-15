// sub_527FB4 
 
void sub_527FB4()
{
  unsigned int v0; // r1

  do
    v0 = __ldrex((unsigned int *)algn_632F58);
  while ( __strex(v0 - 1, (unsigned int *)algn_632F58) );
  JUMPOUT(0x4DCAD4);
}
