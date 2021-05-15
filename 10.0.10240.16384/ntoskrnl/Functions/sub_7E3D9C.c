// sub_7E3D9C 
 
void __fastcall sub_7E3D9C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, const __int16 *a8, int a9, int a10, int *a11, int a12, int a13, int a14)
{
  int v14; // r4
  int *v15; // r5
  int v16; // r6
  int v17; // r9
  int v18; // r10
  int v19; // r0
  int v20; // r0
  int v21; // r4
  int v22; // r3

  if ( v14 < 0 )
    goto LABEL_13;
  a7 = 1048590;
  a8 = L"Devices";
  a9 = 24;
  a10 = *v15;
  a11 = &a7;
  a13 = 0;
  a14 = 0;
  v15[1] = v18;
  v19 = ZwOpenKey();
  if ( v19 == v17 )
  {
    v15[1] = v18;
  }
  else if ( v19 < 0 )
  {
    goto LABEL_13;
  }
  a7 = 1048590;
  a8 = L"Classes";
  a9 = 24;
  a10 = *v15;
  a11 = &a7;
  a13 = 0;
  a14 = 0;
  v15[2] = v18;
  v20 = ZwOpenKey();
  v21 = v20;
  if ( v20 == v17 )
  {
    v15[2] = v18;
    goto LABEL_14;
  }
  if ( v20 >= 0 )
  {
    v22 = v15[2];
    if ( v22 && v16 )
    {
      a9 = 24;
      a10 = v22;
      v15[3] = v18;
      a11 = (int *)v16;
      a13 = 0;
      a14 = 0;
      v21 = ZwOpenKey();
      if ( v21 == v17 )
      {
        v21 = 0;
        v15[3] = v18;
      }
    }
    if ( v21 >= 0 )
LABEL_14:
      JUMPOUT(0x77C608);
  }
LABEL_13:
  PiDevCfgFreeMigrationContext(v15);
  goto LABEL_14;
}
