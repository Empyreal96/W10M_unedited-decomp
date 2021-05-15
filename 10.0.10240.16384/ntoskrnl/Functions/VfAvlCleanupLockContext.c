// VfAvlCleanupLockContext 
 
int __fastcall VfAvlCleanupLockContext(int result)
{
  int v1; // r4

  v1 = result;
  if ( (*(_BYTE *)(result + 5) & 2) != 0 )
    return sub_518B28();
  if ( (*(_BYTE *)(result + 5) & 1) != 0 )
  {
    result = KfLowerIrql(*(unsigned __int8 *)(result + 4));
    *(_BYTE *)(v1 + 5) &= 0xFEu;
    *(_BYTE *)(v1 + 4) = 0;
  }
  return result;
}
