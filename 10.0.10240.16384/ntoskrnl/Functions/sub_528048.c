// sub_528048 
 
void sub_528048()
{
  if ( MiGetPagePrivilege() != 1 )
    JUMPOUT(0x4DCCB0);
  JUMPOUT(0x4DCCB2);
}
