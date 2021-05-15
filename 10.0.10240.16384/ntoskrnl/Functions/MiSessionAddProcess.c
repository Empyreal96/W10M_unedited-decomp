// MiSessionAddProcess 
 
unsigned int __fastcall MiSessionAddProcess(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int result; // r0

  *(_DWORD *)(a1 + 324) = a2;
  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 192);
  do
    result = __ldrex(v2);
  while ( __strex(result | 0x10000, v2) );
  __dmb(0xBu);
  return result;
}
