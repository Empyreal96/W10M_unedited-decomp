// MiInitializeProcessTopDownEntropy 
 
int __fastcall MiInitializeProcessTopDownEntropy(int result, int a2)
{
  int v2; // r4

  if ( (*(_DWORD *)(result + 736) & 1) == 0 && (!a2 || (*(_DWORD *)(result + 188) & 0x20000) == 0) )
  {
    v2 = MEMORY[0xC0402134];
    result = ExGenRandom(1);
    MEMORY[0xC0402134] = v2 - ((unsigned __int8)result << 16);
    MEMORY[0xC0402138] = v2 - ((unsigned __int8)result << 16);
  }
  return result;
}
