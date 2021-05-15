// sub_7E9B5C 
 
void sub_7E9B5C()
{
  int v0; // r4
  int v1; // r6

  MmStoreFlushOutstandingEvictions();
  if ( v0 )
  {
    if ( MmQueryProcessWorkingSetSwapPages(v1) >= 0 )
      SmSwapStore(0);
  }
  JUMPOUT(0x703994);
}
