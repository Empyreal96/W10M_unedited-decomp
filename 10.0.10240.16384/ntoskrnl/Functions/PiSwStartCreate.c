// PiSwStartCreate 
 
int __fastcall PiSwStartCreate(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v14; // r3
  int result; // r0
  unsigned int v16[2]; // [sp+0h] [bp-50h] BYREF
  int v17[3]; // [sp+8h] [bp-48h] BYREF
  unsigned int v18; // [sp+14h] [bp-3Ch]
  int v19; // [sp+18h] [bp-38h]
  unsigned int v20; // [sp+1Ch] [bp-34h]
  int v21; // [sp+20h] [bp-30h]
  int v22; // [sp+24h] [bp-2Ch]
  int v23; // [sp+28h] [bp-28h]
  int v24; // [sp+2Ch] [bp-24h]
  int v25; // [sp+30h] [bp-20h]
  int v26; // [sp+34h] [bp-1Ch]
  int v27; // [sp+38h] [bp-18h]
  int v28; // [sp+3Ch] [bp-14h]
  int v29; // [sp+40h] [bp-10h]

  v17[1] = a2;
  v17[2] = a3;
  v22 = a6;
  v18 = 0;
  v19 = a4;
  v20 = 0;
  v23 = a7;
  v27 = a10;
  v24 = a8;
  v25 = a9;
  v28 = a13;
  v14 = a12;
  v26 = a11;
  v17[0] = (int)L"DRIVERENUM";
  v21 = a5;
  v29 = a12;
  if ( v19 )
  {
    result = PnpGetMultiSzLength(a4, 1024, v16, a12);
    if ( result < 0 )
      return result;
    v14 = v16[0];
    v18 = v16[0];
  }
  if ( a5 )
  {
    result = PnpGetMultiSzLength(a5, 1024, v16, v14);
    if ( result < 0 )
      return result;
    v20 = v16[0];
  }
  return PiSwIrpStartCreateWorker(v17, 0);
}
