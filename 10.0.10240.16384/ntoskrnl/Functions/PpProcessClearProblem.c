// PpProcessClearProblem 
 
int __fastcall PpProcessClearProblem(int a1)
{
  int v1; // r3
  int v2; // r0
  int v3; // r2
  int v5[6]; // [sp+0h] [bp-18h] BYREF

  v5[0] = *(_DWORD *)(a1 + 20);
  v5[1] = 1;
  v5[2] = 5;
  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 )
    v2 = *(_DWORD *)(*(_DWORD *)(v1 + 176) + 20);
  else
    v2 = 0;
  v3 = *(_DWORD *)(v2 + 172);
  if ( v3 == 787 || v3 == 788 )
    return -1073741738;
  PipForDeviceNodeSubtree(v2, PiResetProblemDevicesWorker, v5);
  return 0;
}
