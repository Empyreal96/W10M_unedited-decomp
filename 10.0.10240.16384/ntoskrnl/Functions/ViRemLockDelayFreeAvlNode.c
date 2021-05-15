// ViRemLockDelayFreeAvlNode 
 
int __fastcall ViRemLockDelayFreeAvlNode(int result, int a2)
{
  *(_DWORD *)(result + 60) = a2;
  return result;
}
