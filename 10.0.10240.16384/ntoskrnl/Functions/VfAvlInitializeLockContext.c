// VfAvlInitializeLockContext 
 
int __fastcall VfAvlInitializeLockContext(int result, int a2)
{
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 4) = 0;
  if ( !a2 )
    *(_BYTE *)(result + 5) |= 4u;
  return result;
}
