// PiDqPnPGetObjectPropertyKeys 
 
int __fastcall PiDqPnPGetObjectPropertyKeys(int a1, int a2, int a3, int a4, unsigned int *a5, unsigned int *a6)
{
  int i; // r4
  int v10; // r0
  int v11; // r0
  int v12; // r4

  *a5 = 0;
  for ( i = 6000; ; i = 20 * *a6 )
  {
    if ( *a5 )
      ExFreePoolWithTag(*a5);
    v10 = ExAllocatePoolWithTag(1, i, 1483763280);
    *a5 = v10;
    if ( !v10 )
      break;
    *a6 = 0;
    if ( a2 )
      v11 = PnpGetObjectPropertyKeys(PiPnpRtlCtx, a1, a2, a3);
    else
      v11 = PnpGetGenericStorePropertyKeys((int *)PiPnpRtlCtx, a3, 0, 1, v10, i, a6);
    v12 = v11;
    if ( v11 != -1073741789 )
      goto LABEL_11;
  }
  v12 = -1073741670;
LABEL_11:
  if ( v12 < 0 )
    *a6 = 0;
  if ( !*a6 && *a5 )
  {
    ExFreePoolWithTag(*a5);
    *a5 = 0;
  }
  return v12;
}
