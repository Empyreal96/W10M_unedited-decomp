// RtlSubtreePredecessor 
 
int __fastcall RtlSubtreePredecessor(int a1)
{
  int result; // r0
  int i; // r3

  result = *(_DWORD *)(a1 + 4);
  if ( !result )
    return 0;
  for ( i = *(_DWORD *)(result + 8); i; i = *(_DWORD *)(i + 8) )
    result = i;
  return result;
}
