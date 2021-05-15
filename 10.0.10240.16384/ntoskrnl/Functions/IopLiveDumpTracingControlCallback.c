// IopLiveDumpTracingControlCallback 
 
int __fastcall IopLiveDumpTracingControlCallback(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r1
  unsigned int v4; // r1

  __dmb(0xBu);
  if ( a2 )
  {
    result = 1;
    do
      v3 = __ldrex((unsigned int *)&IopLiveDumpEtwEnabled);
    while ( __strex(1u, (unsigned int *)&IopLiveDumpEtwEnabled) );
  }
  else
  {
    result = 0;
    do
      v4 = __ldrex((unsigned int *)&IopLiveDumpEtwEnabled);
    while ( __strex(0, (unsigned int *)&IopLiveDumpEtwEnabled) );
  }
  __dmb(0xBu);
  return result;
}
