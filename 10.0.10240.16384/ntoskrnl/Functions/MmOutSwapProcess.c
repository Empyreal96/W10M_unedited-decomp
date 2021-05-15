// MmOutSwapProcess 
 
int __fastcall MmOutSwapProcess(int result)
{
  int v1; // r5
  unsigned int *v2; // r4
  unsigned int v3; // r1

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 192);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x40, v2) );
  __dmb(0xBu);
  if ( (*(_BYTE *)(result + 607) & 0xC0) == 64 )
    result = MiReleaseOutSwappedProcessCommit();
  if ( *(_DWORD *)(v1 + 552) == 3 )
    result = sub_516380(result);
  return result;
}
