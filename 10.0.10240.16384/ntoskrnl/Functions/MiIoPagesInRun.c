// MiIoPagesInRun 
 
int __fastcall MiIoPagesInRun(int a1, int a2)
{
  int v4; // r4

  v4 = 0;
  do
  {
    if ( MI_IS_PFN(a1) )
      break;
    ++v4;
    if ( !--a2 )
      break;
    ++a1;
  }
  while ( (a1 & 0x1FF) != 0 );
  return v4;
}
