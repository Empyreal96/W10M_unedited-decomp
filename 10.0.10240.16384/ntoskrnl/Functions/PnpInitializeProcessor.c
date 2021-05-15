// PnpInitializeProcessor 
 
int PnpInitializeProcessor()
{
  PnpRequestDeviceAction(*(int **)(IopRootDeviceNode + 16), 6, 0, 1, 0, 0);
  return 0;
}
