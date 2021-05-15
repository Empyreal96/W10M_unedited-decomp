// MiInitializeProcessBottomUpEntropy 
 
unsigned int __fastcall MiInitializeProcessBottomUpEntropy(int a1)
{
  int v1; // r4
  unsigned __int8 v3; // r0
  unsigned int *v4; // r2
  unsigned int result; // r0

  v1 = 1;
  if ( (*(_DWORD *)(a1 + 188) & 0x20000) == 0 )
  {
    v3 = ExGenRandom(1);
    v1 = v3;
    if ( !v3 )
      v1 = 1;
  }
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 188);
  do
    result = __ldrex(v4);
  while ( __strex(result & 0xFDFFFFFF, v4) );
  __dmb(0xBu);
  MEMORY[0xC0402130] = v1 << 16;
  MEMORY[0xC0402110] = v1;
  return result;
}
