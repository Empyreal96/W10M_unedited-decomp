// ViIsContextIdValid 
 
int __fastcall ViIsContextIdValid(int a1, int a2)
{
  if ( !a1 || a1 == 1 || a1 == 2 )
    return a2 < 1;
  if ( a1 != 3 )
    return 0;
  return a2 < 2;
}
