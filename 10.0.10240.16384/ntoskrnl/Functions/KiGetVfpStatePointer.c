// KiGetVfpStatePointer 
 
int __fastcall KiGetVfpStatePointer(int a1)
{
  int result; // r0
  unsigned int v2; // r3

  result = *(_DWORD *)(a1 + 20);
  if ( !result )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( !v2 || (result = *(_DWORD *)(v2 + 320)) == 0 )
      result = 0;
  }
  return result;
}
