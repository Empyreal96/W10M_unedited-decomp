// MiDereferenceVadUnsafe 
 
BOOL __fastcall MiDereferenceVadUnsafe(int a1)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  unsigned int v3; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(a1 + 20);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 - 1;
  }
  while ( __strex(v3, v1) );
  return !v3 && *(int *)(a1 + 28) < 0;
}
