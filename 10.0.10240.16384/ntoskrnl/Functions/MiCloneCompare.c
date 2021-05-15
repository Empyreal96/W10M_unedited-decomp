// MiCloneCompare 
 
int __fastcall MiCloneCompare(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r2

  if ( *(_DWORD *)(a1 + 12) > *(_DWORD *)(a2 + 16) )
    return 1;
  v3 = *(_DWORD *)(a1 + 16);
  result = -1;
  if ( v3 >= *(_DWORD *)(a2 + 12) )
    result = 0;
  return result;
}
