// EtwpCompleteBuffer 
 
unsigned int __fastcall EtwpCompleteBuffer(int a1, int a2)
{
  unsigned int result; // r0

  *(_WORD *)(a2 + 52) = 0;
  if ( *(_WORD *)(a2 + 54) == 5 )
    result = sub_809BC4();
  else
    result = EtwpEnqueueFreeBuffer(a1, a2);
  return result;
}
