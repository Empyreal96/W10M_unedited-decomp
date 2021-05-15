// IoAllocateMiniCompletionPacket 
 
int __fastcall IoAllocateMiniCompletionPacket(int a1, int a2)
{
  int result; // r0

  result = IopAllocateMiniCompletionPacket(4, 0);
  if ( result )
  {
    *(_BYTE *)(result + 36) = 1;
    *(_DWORD *)(result + 28) = a1;
    *(_DWORD *)(result + 32) = a2;
  }
  return result;
}
