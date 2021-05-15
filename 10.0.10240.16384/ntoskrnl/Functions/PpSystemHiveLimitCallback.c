// PpSystemHiveLimitCallback 
 
int __fastcall PpSystemHiveLimitCallback(int result, unsigned int a2)
{
  if ( a2 >= *(_DWORD *)(result + 4) )
  {
    PnpSystemHiveTooLarge = 1;
  }
  else
  {
    PnpSystemHiveTooLarge = 0;
    PpResetProblemDevices(IopRootDeviceNode);
    result = PnpRequestDeviceAction(*(int **)(IopRootDeviceNode + 16), 14, 0, 0, 0, 0);
  }
  return result;
}
