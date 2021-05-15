// sub_969990 
 
void sub_969990()
{
  unsigned int v0; // r1

  __dmb(0xBu);
  do
    v0 = __ldrex(ViTargetAllocationFailures);
  while ( __strex(1u, ViTargetAllocationFailures) );
  JUMPOUT(0x952E52);
}
