// sub_5C1588 
 
int sub_5C1588()
{
  if ( !dword_653534 )
  {
    if ( !RtlIsMultiSessionSku() )
      dword_653530 = 1;
    dword_653534 = 1;
  }
  return dword_653530;
}
