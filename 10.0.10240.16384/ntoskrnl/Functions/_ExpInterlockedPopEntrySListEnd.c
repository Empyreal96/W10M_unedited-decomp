// _ExpInterlockedPopEntrySListEnd 
 
int __fastcall ExpInterlockedPopEntrySListEnd(unsigned __int64 *a1, int a2, int a3, int a4)
{
  unsigned int v4; // r12
  int result; // r0

  if ( __strexd(__PAIR64__(a4 - 1, v4), a1) == 1 )
    result = RtlpInterlockedPopEntrySList(a1);
  else
    result = a3;
  return result;
}
