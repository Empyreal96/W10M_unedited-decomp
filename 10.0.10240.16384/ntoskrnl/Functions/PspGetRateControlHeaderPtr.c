// PspGetRateControlHeaderPtr 
 
int __fastcall PspGetRateControlHeaderPtr(int a1, int a2)
{
  if ( !a2 )
    return a1 + 736;
  if ( a2 == 1 )
    return a1 + 740;
  return a1 + 532;
}
