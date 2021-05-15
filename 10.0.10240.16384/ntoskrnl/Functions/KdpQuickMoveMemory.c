// KdpQuickMoveMemory 
 
int __fastcall KdpQuickMoveMemory(int result, _BYTE *a2, int a3)
{
  if ( a3 )
  {
    result -= (int)a2;
    do
    {
      a2[result] = *a2;
      ++a2;
      --a3;
    }
    while ( a3 );
  }
  return result;
}
