// MiSharedCommitCompare 
 
int __fastcall MiSharedCommitCompare(int a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r2

  v2 = *(_DWORD *)(a1 + 12);
  v3 = *(_DWORD *)(a2 + 12);
  if ( v2 > v3 )
    return 1;
  if ( v2 >= v3 )
    return 0;
  return -1;
}
