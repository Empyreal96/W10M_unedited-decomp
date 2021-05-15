// FsRtlIssueDeviceIoControl 
 
int __fastcall FsRtlIssueDeviceIoControl(int a1, int a2, char a3, int a4, int a5, int a6, int a7, _DWORD *a8)
{
  int v12; // r0
  int result; // r0
  int v14; // [sp+1Ch] [bp-2Ch]
  char v15[40]; // [sp+20h] [bp-28h] BYREF

  KeInitializeEvent((int)v15, 0, 0);
  v12 = IoBuildDeviceIoControlRequest(a2, a1, a4, a5, a6, a7);
  if ( !v12 )
    return -1073741670;
  *(_BYTE *)(*(_DWORD *)(v12 + 96) - 38) |= a3;
  result = IofCallDriver(a1, v12);
  if ( result == 259 )
    return sub_7D59B4();
  if ( result >= 0 )
  {
    if ( a8 )
      *a8 = v14;
  }
  return result;
}
