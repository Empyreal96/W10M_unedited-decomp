// IoAllocateSfioStreamIdentifier 
 
int __fastcall IoAllocateSfioStreamIdentifier(int a1, unsigned int a2, int a3)
{
  if ( !a1 )
    return -1073741585;
  if ( !a2 || a2 > 0xFFFFFFEF )
    return -1073741584;
  if ( a3 )
    return IopGetSetStreamIdentifier();
  return -1073741583;
}
