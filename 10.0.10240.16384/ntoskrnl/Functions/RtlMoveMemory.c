// RtlMoveMemory 
 
int __fastcall RtlMoveMemory(int a1, int a2, unsigned int a3)
{
  return memmove(a1, a2, a3);
}
