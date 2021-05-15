// PnpCancelStopDeviceSubtree 
 
int *__fastcall PnpCancelStopDeviceSubtree(int *a1)
{
  int *result; // r0
  _DWORD *i; // r4

  result = PnpCancelStopDeviceNode(a1);
  for ( i = (_DWORD *)a1[1]; i; i = (_DWORD *)*i )
    result = (int *)PnpCancelStopDeviceSubtree(i);
  return result;
}
