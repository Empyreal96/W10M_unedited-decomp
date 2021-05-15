// PiPnpRtlGatherContainerRemoveInfo 
 
int __fastcall PiPnpRtlGatherContainerRemoveInfo(int a1, int a2, int **a3)
{
  int *v6; // r0
  int v7; // r4
  int v8; // r0

  v6 = (int *)ExAllocatePoolWithTag(1, 8, 1198550608);
  *a3 = v6;
  if ( !v6 )
  {
    v7 = -1073741670;
LABEL_8:
    PiPnpRtlFreeContainerRemoveInfo(*a3);
    *a3 = 0;
    return v7;
  }
  *v6 = 0;
  v6[1] = 0;
  v8 = PiDmGetObject(1, a1, v6);
  v7 = v8;
  if ( v8 != -1073741772 && v8 < 0 )
    goto LABEL_8;
  v7 = PiDmGetObject(5, a2, *a3 + 1);
  if ( v7 == -1073741772 )
    v7 = 0;
  if ( v7 < 0 )
    goto LABEL_8;
  return v7;
}
