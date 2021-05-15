// sub_804CD8 
 
void sub_804CD8()
{
  if ( !TmIsTransactionActive() )
    JUMPOUT(0x74DFEC);
  JUMPOUT(0x74DFC4);
}
