// IoSetSystemPartition 
 
int IoSetSystemPartition()
{
  int v0; // r4
  int v1; // r5
  int v3; // [sp+8h] [bp-60h] BYREF
  int v4; // [sp+Ch] [bp-5Ch]
  __int16 v5; // [sp+10h] [bp-58h] BYREF
  __int16 v6; // [sp+12h] [bp-56h]
  __int16 *v7; // [sp+14h] [bp-54h]
  int v8; // [sp+18h] [bp-50h]
  int v9; // [sp+1Ch] [bp-4Ch]
  char *v10; // [sp+20h] [bp-48h]
  int v11; // [sp+24h] [bp-44h]
  int v12; // [sp+28h] [bp-40h]
  int v13; // [sp+2Ch] [bp-3Ch]
  char v14[8]; // [sp+30h] [bp-38h] BYREF
  __int16 v15; // [sp+38h] [bp-30h] BYREF
  __int16 v16; // [sp+3Ah] [bp-2Eh]
  __int16 v17; // [sp+3Ch] [bp-2Ch]
  __int16 v18; // [sp+3Eh] [bp-2Ah]
  __int16 v19; // [sp+40h] [bp-28h]
  __int16 v20; // [sp+42h] [bp-26h]
  __int16 v21; // [sp+44h] [bp-24h]
  __int16 v22; // [sp+46h] [bp-22h]
  __int16 v23; // [sp+48h] [bp-20h]
  __int16 v24; // [sp+4Ah] [bp-1Eh]
  __int16 v25; // [sp+4Ch] [bp-1Ch]
  __int16 v26; // [sp+4Eh] [bp-1Ah]
  __int16 v27; // [sp+50h] [bp-18h]
  __int16 v28; // [sp+52h] [bp-16h]
  __int16 v29; // [sp+54h] [bp-14h]
  __int16 v30; // [sp+56h] [bp-12h]

  v0 = 0;
  v3 = 0;
  RtlInitUnicodeString((unsigned int)v14, L"\\REGISTRY\\MACHINE\\SYSTEM");
  v4 = 0;
  v8 = 24;
  v9 = 0;
  v11 = 576;
  v10 = v14;
  v12 = 0;
  v13 = 0;
  v1 = ZwOpenKey();
  if ( v1 >= 0 )
  {
    v15 = 83;
    v16 = 101;
    v17 = 116;
    v18 = 117;
    v19 = 112;
    v20 = 0;
    v6 = 12;
    v5 = 10;
    v7 = &v15;
    v1 = IopCreateRegistryKeyEx(&v3, v4, (int)&v5, 983103, 0, 0);
    if ( v1 < 0 )
    {
      v0 = v3;
    }
    else
    {
      v15 = 83;
      v16 = 121;
      v17 = 115;
      v18 = 116;
      v19 = 101;
      v20 = 109;
      v21 = 80;
      v22 = 97;
      v23 = 114;
      v24 = 116;
      v25 = 105;
      v26 = 116;
      v27 = 105;
      v28 = 111;
      v29 = 110;
      v30 = 0;
      v6 = 32;
      v5 = 30;
      v0 = v3;
      v1 = ZwSetValueKey();
    }
  }
  if ( v4 )
    ZwClose();
  if ( v0 )
    ZwClose();
  return v1;
}
