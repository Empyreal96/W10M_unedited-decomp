// CmpFileFlush 
 
int __fastcall CmpFileFlush(int a1, int a2)
{
  int result; // r0

  if ( !*(_DWORD *)(a1 + 4 * a2 + 1776) || CmpNoWrite || ZwFlushBuffersFile() >= 0 )
    result = 1;
  else
    result = sub_7F3E50();
  return result;
}
