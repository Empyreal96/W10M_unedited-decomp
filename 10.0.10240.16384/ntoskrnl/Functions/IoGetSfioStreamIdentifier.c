// IoGetSfioStreamIdentifier 
 
int __fastcall IoGetSfioStreamIdentifier(int a1, int a2, int a3)
{
  if ( !a1 || !a2 )
    return 0;
  IopGetSetStreamIdentifier(a1, 0);
  return a3;
}
