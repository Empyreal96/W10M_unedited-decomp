// MiHandleSynchronousFlushError 
 
int __fastcall MiHandleSynchronousFlushError(int a1, int *a2, int a3, int *a4, _DWORD *a5)
{
  int v7; // r0
  int *v9; // r2
  int v10; // r3

  v7 = *a2;
  if ( *a2 == -1073741740 && a3 == 1 )
  {
    v9 = Mi10Milliseconds;
LABEL_15:
    KeDelayExecutionThread(0, 0, (unsigned int *)v9);
    goto LABEL_16;
  }
  if ( v7 != -1073741670
    && v7 != -1073741663
    && v7 != -1073741801
    && (*(_DWORD *)(a1 + 20) <= 0x1000u || FsRtlIsTotalDeviceFailure(v7)) )
  {
    return 0;
  }
  v10 = *a4 - 1;
  *a4 = v10;
  if ( (v10 & 0x1F) != 0 )
  {
    v9 = Mi30Milliseconds;
    goto LABEL_15;
  }
  if ( *a5 == 1 || *(_DWORD *)(a1 + 20) <= 0x1000u )
    return 0;
  *a5 = 1;
LABEL_16:
  *a2 = 0;
  return 1;
}
