// MmInSwapProcess 
 
int __fastcall MmInSwapProcess(int a1)
{
  int result; // r0
  unsigned int *v3; // r2

  if ( (*(_DWORD *)(a1 + 192) & 0x80) != 0 )
    return sub_51610C();
  __dmb(0xBu);
  v3 = (unsigned int *)(a1 + 192);
  do
    result = __ldrex(v3);
  while ( __strex(result & 0xFFFFFFBF, v3) );
  __dmb(0xBu);
  if ( (*(_BYTE *)(a1 + 607) & 0xC0) == 128 )
    result = MiReAcquireOutSwappedProcessCommit(a1);
  return result;
}
