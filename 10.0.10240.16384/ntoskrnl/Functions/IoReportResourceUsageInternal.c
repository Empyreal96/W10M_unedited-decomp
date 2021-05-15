// IoReportResourceUsageInternal 
 
int __fastcall IoReportResourceUsageInternal(int a1, int a2, int a3, int a4, int a5, int a6, int *a7, int a8, int a9, _BYTE *a10)
{
  int *v10; // r4
  int v13; // r5
  int v14; // r4
  unsigned int v15; // r6
  int v16; // r7
  int v18[8]; // [sp+8h] [bp-20h] BYREF

  v18[0] = a4;
  v10 = a7;
  if ( !a7 )
    v10 = (int *)a4;
  v13 = 0;
  if ( v10 )
  {
    if ( *v10 && v10[4] )
    {
      v13 = PnpCmResourcesToIoResources(a1, v10, 12288);
      if ( !v13 )
        return -1073741823;
    }
    else
    {
      v10 = 0;
    }
  }
  v15 = 0;
  *a10 = 1;
  v18[0] = (int)v10;
  v16 = 0;
  while ( 1 )
  {
    v14 = IopLegacyResourceAllocation(a1, a3, a6, v13, v18);
    if ( v14 >= 0 )
      break;
    if ( IopChangeInterfaceType(v13, v18) )
    {
      ++v15;
      v16 = 1;
      if ( v15 < 2 )
        continue;
    }
    goto LABEL_15;
  }
  *a10 = 0;
LABEL_15:
  if ( v13 )
    ExFreePoolWithTag(v13);
  if ( v16 )
    ExFreePoolWithTag(v18[0]);
  if ( v14 >= 0 )
    return 0;
  if ( v14 != -1073741670 )
    v14 = -1073741800;
  return v14;
}
