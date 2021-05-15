// PiProfileUpdateDeviceTreeWorker 
 
unsigned int __fastcall PiProfileUpdateDeviceTreeWorker(unsigned int a1, int a2)
{
  PpDevNodeLockTree(1, a2);
  PipForDeviceNodeSubtree(IopRootDeviceNode, (int)PiProfileUpdateDeviceTreeCallback, 0, (int)&IopRootDeviceNode);
  PpDevNodeUnlockTree(1);
  return ExFreePoolWithTag(a1);
}
