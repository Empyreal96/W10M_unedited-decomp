// PnpGetObjectProperty 
 
int __fastcall PnpGetObjectProperty(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned int *a9, _DWORD *a10, int a11)
{
  unsigned int v12; // r7
  unsigned int v13; // r5
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r5
  int v21; // r3
  unsigned int v23; // r0
  unsigned int v24; // [sp+Ch] [bp-34h]
  int v25[8]; // [sp+20h] [bp-20h] BYREF

  v12 = 0;
  v13 = a2;
  *a9 = 0;
  for ( v25[0] = a2; ; v13 = v25[0] )
  {
    v16 = a7;
    v17 = a8;
    v18 = a11;
    if ( v13 <= v12 )
      goto LABEL_7;
    v12 = v13;
    if ( *a9 )
      ExFreePoolWithTag(*a9);
    v19 = ExAllocatePoolWithTag(1, v13, a1);
    *a9 = v19;
    if ( !v19 )
      break;
    v18 = a11;
    v17 = a8;
    v16 = a7;
LABEL_7:
    v24 = *a9;
    v25[0] = 0;
    v20 = PnpGetObjectProperty(PiPnpRtlCtx, a3, a4, a5, 0, v16, v17, v24, v12, v25, v18);
    if ( v20 != -1073741789 )
      goto LABEL_8;
  }
  v20 = -1073741670;
LABEL_8:
  if ( v20 < 0 )
  {
    v23 = *a9;
    if ( !*a9 )
      return v20;
LABEL_14:
    ExFreePoolWithTag(v23);
    *a9 = 0;
    return v20;
  }
  v21 = v25[0];
  if ( a10 )
    *a10 = v25[0];
  if ( !v21 )
  {
    v23 = *a9;
    goto LABEL_14;
  }
  return v20;
}
