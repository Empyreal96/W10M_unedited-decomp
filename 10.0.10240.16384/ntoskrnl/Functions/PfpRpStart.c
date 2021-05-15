// PfpRpStart 
 
int __fastcall PfpRpStart(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(result + 80);
  do
    v2 = __ldrex(v1);
  while ( __strex(0, v1) );
  __dmb(0xBu);
  *(_DWORD *)(result + 96) |= 1u;
  return result;
}
