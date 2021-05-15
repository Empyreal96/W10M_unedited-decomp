// PiDqPnPGetObjectPropertyLocales 
 
int __fastcall PiDqPnPGetObjectPropertyLocales(int a1, int a2, int a3, int a4, unsigned int *a5)
{
  int v6; // r4
  int v10; // r0
  int v11; // r0
  int v12; // r4
  int v14[8]; // [sp+18h] [bp-20h] BYREF

  v6 = 40;
  *a5 = 0;
  for ( v14[0] = 40; ; v6 = v14[0] )
  {
    if ( *a5 )
    {
      ExFreePoolWithTag(*a5);
      v6 = v14[0];
    }
    v10 = ExAllocatePoolWithTag(1, 2 * v6, 1483763280);
    *a5 = v10;
    if ( !v10 )
      break;
    if ( a2 )
      v11 = PnpGetObjectPropertyLocales(PiPnpRtlCtx, a1, a2, a3, a4, v10, v14[0], v14);
    else
      v11 = PnpGetGenericStorePropertyLocales(PiPnpRtlCtx, a3, a4, v10, v14[0], v14);
    v12 = v11;
    if ( v11 != -1073741789 )
      goto LABEL_11;
  }
  v12 = -1073741670;
LABEL_11:
  if ( v12 < 0 && *a5 )
  {
    ExFreePoolWithTag(*a5);
    *a5 = 0;
  }
  return v12;
}
