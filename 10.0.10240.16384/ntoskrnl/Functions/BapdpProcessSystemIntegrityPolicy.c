// BapdpProcessSystemIntegrityPolicy 
 
int __fastcall BapdpProcessSystemIntegrityPolicy(int a1)
{
  int result; // r0
  int v2[3]; // [sp+8h] [bp-38h] BYREF
  __int16 v3; // [sp+14h] [bp-2Ch]
  __int16 v4; // [sp+16h] [bp-2Ah]
  char v5; // [sp+18h] [bp-28h]
  char v6; // [sp+19h] [bp-27h]
  char v7; // [sp+1Ah] [bp-26h]
  char v8; // [sp+1Bh] [bp-25h]
  char v9; // [sp+1Ch] [bp-24h]
  char v10; // [sp+1Dh] [bp-23h]
  char v11; // [sp+1Eh] [bp-22h]
  char v12; // [sp+1Fh] [bp-21h]
  int v13; // [sp+20h] [bp-20h] BYREF
  __int16 v14; // [sp+24h] [bp-1Ch]
  __int16 v15; // [sp+26h] [bp-1Ah]
  char v16; // [sp+28h] [bp-18h]
  char v17; // [sp+29h] [bp-17h]
  char v18; // [sp+2Ah] [bp-16h]
  char v19; // [sp+2Bh] [bp-15h]
  char v20; // [sp+2Ch] [bp-14h]
  char v21; // [sp+2Dh] [bp-13h]
  char v22; // [sp+2Eh] [bp-12h]
  char v23; // [sp+2Fh] [bp-11h]

  v13 = -1484001011;
  v14 = 2816;
  v15 = 18658;
  v16 = -126;
  v17 = 47;
  v18 = -6;
  v19 = -107;
  v20 = 59;
  v21 = 88;
  v22 = 32;
  v23 = -53;
  v2[2] = -539488817;
  v3 = 18844;
  v4 = 19732;
  v5 = -98;
  v6 = -115;
  v7 = 53;
  v8 = -49;
  v9 = 46;
  v10 = 1;
  v11 = -2;
  v12 = -62;
  v2[0] = 0;
  result = BapdpQueryData(a1, &v13, 0, 0, v2);
  if ( result != -1073741789 )
    result = sub_96D8B4();
  return result;
}
