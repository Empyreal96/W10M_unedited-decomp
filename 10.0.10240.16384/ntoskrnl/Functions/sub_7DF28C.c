// sub_7DF28C 
 
void sub_7DF28C()
{
  unsigned int v0; // r6

  __dmb(0xBu);
  do
    v0 = __ldrex((unsigned int *)&PnpDeviceActionThread);
  while ( !v0 && __strex(0, (unsigned int *)&PnpDeviceActionThread) );
  __dmb(0xBu);
  if ( !v0 )
    JUMPOUT(0x775672);
  JUMPOUT(0x775600);
}
