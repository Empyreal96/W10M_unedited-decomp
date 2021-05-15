// SepComputeSidSignature 
 
int __fastcall SepComputeSidSignature(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(a1 + 1) + 4);
  if ( !result )
    result = 1;
  return result;
}
