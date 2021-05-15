// ViAvlAcquireTableLockAtDpcLevelSafe 
 
int __fastcall ViAvlAcquireTableLockAtDpcLevelSafe(int result, int a2)
{
  int v2; // r5

  v2 = result;
  if ( (*(_BYTE *)(a2 + 5) & 2) != 0 )
  {
    result = *(_DWORD *)a2;
    if ( *(_DWORD *)a2 != v2 )
      return sub_518B7C();
  }
  if ( (*(_BYTE *)(a2 + 5) & 2) == 0 )
    result = ViAvlAcquireTableLockAtDpcLevel(v2, a2);
  return result;
}
