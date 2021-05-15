// IoFreeMiniCompletionPacket 
 
int __fastcall IoFreeMiniCompletionPacket(int a1, int a2)
{
  *(_DWORD *)(a1 + 28) = 0;
  return IopFreeMiniCompletionPacket(a1, a2);
}
