// PopHiberComplete 
 
int __fastcall PopHiberComplete(int result, int a2)
{
  if ( result == -1073741632 )
  {
    if ( (PopSimulate & 0x1000) == 0 )
    {
      while ( 1 )
        ;
    }
    *(_BYTE *)a2 = 1;
  }
  else
  {
    *(_DWORD *)(a2 + 120) = result;
    PoHiberInProgress = 0;
  }
  return result;
}
