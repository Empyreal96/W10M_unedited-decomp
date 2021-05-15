// PpHotSwapGetDevnodeRemovalPolicy 
 
int __fastcall PpHotSwapGetDevnodeRemovalPolicy(int a1, int a2, int *a3)
{
  int v6; // r0
  int v7; // r4
  int result; // r0

  v6 = PpDevNodeLockTree(0, a2);
  if ( a2 )
    v7 = *(unsigned __int8 *)(a1 + 318);
  else
    v7 = *(unsigned __int8 *)(a1 + 319);
  if ( !v7 )
    return sub_81B8EC(v6);
  if ( v7 > 3 )
  {
    if ( v7 != 4 )
      JUMPOUT(0x81B906);
    v7 = 2;
  }
  result = PpDevNodeUnlockTree(0);
  *a3 = v7;
  return result;
}
