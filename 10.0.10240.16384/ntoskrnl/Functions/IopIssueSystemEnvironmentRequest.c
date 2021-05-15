// IopIssueSystemEnvironmentRequest 
 
int __fastcall IopIssueSystemEnvironmentRequest(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  int v12; // r0
  int result; // r0
  int v14; // [sp+18h] [bp-40h]
  int v15; // [sp+1Ch] [bp-3Ch]
  _DWORD v16[2]; // [sp+20h] [bp-38h] BYREF
  int v17; // [sp+28h] [bp-30h]
  char v18[40]; // [sp+30h] [bp-28h] BYREF

  KeInitializeEvent((int)v18, 0, 0);
  v12 = IoBuildDeviceIoControlRequest(a1, a4, a5, a6, a7, a8);
  if ( !v12 )
    return -1073741670;
  if ( a3 )
    return sub_7D5958();
  v16[0] = a4;
  v16[1] = v12;
  result = KeExpandKernelStackAndCalloutEx((int)IopIssueSystemEnvironmentCallout, (int)v16, 59392, 1, 0);
  if ( result < 0 )
  {
    if ( result == -1073741789 )
    {
      result = -1073741801;
      if ( a9 )
        *a9 = 0;
    }
  }
  else
  {
    result = v17;
    if ( v17 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v18, 0, 0, 0, 0);
      result = v14;
    }
    if ( a9 )
      *a9 = v15;
  }
  return result;
}
