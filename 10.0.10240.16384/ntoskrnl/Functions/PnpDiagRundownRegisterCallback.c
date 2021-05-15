// PnpDiagRundownRegisterCallback 
 
void __fastcall PnpDiagRundownRegisterCallback(int a1, int a2)
{
  int v2; // r4
  int v3; // r5
  int v4; // r1
  int v5; // r3
  int v6; // r1
  int v7; // r3

  if ( a2 == 2 )
  {
    v2 = dword_649E8C;
    v3 = PnpRundownEtwHandle;
    if ( EtwEventEnabled(PnpRundownEtwHandle, dword_649E8C, (int)KMPnPRundownEvt_SleepStudy_ConnectionResource) )
    {
      PpDevNodeLockTree(0, v4);
      PipForDeviceNodeSubtree(IopRootDeviceNode, (int)PnpDiagRundownForEachDevice, 0, v5);
      PpDevNodeUnlockTree(0);
      v2 = dword_649E8C;
      v3 = PnpRundownEtwHandle;
    }
    if ( EtwEventEnabled(v3, v2, (int)KMPnPRundownEvt_SleepStudy_ParentPdo) )
    {
      PpDevNodeLockTree(0, v6);
      PipForDeviceNodeSubtree(IopRootDeviceNode, (int)PnpDiagRundownParentPdoForEachDevice, 0, v7);
      PpDevNodeUnlockTree(0);
    }
  }
}
