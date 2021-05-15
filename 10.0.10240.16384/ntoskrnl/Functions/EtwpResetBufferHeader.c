// EtwpResetBufferHeader 
 
int __fastcall EtwpResetBufferHeader(int result, __int16 a2)
{
  *(_DWORD *)(result + 4) = 0;
  __dmb(0xBu);
  *(_DWORD *)(result + 8) = 72;
  *(_WORD *)(result + 54) = a2;
  *(_DWORD *)(result + 32) = 0;
  return result;
}
