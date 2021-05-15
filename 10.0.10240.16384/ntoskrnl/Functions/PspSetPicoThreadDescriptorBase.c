// PspSetPicoThreadDescriptorBase 
 
int __fastcall PspSetPicoThreadDescriptorBase(int result, unsigned int a2)
{
  unsigned int v2; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( result )
  {
    *(_DWORD *)(v2 + 1080) = a2;
    __dmb(0xFu);
    __mcr(15, 0, a2, 13, 0, 2);
  }
  else
  {
    *(_DWORD *)(v2 + 1076) = a2;
  }
  return result;
}
