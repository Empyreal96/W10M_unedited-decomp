// RtlSubtreeSuccessor 
 
int __fastcall RtlSubtreeSuccessor(int a1)
{
  int result; // r0
  int i; // r3

  result = *(_DWORD *)(a1 + 8);
  if ( !result )
    return 0;
  for ( i = *(_DWORD *)(result + 4); i; i = *(_DWORD *)(i + 4) )
    result = i;
  return result;
}
