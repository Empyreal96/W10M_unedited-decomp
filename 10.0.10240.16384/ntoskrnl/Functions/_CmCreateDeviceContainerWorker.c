// _CmCreateDeviceContainerWorker 
 
int __fastcall CmCreateDeviceContainerWorker(int a1, int a2, int a3, int a4, _BYTE *a5, __int16 a6)
{
  int v6; // r4

  if ( a6 )
    return -1073741811;
  v6 = CmOpenDeviceContainerRegKey(a1, a2, 80);
  if ( v6 >= 0 )
    *a5 = 0;
  return v6;
}
