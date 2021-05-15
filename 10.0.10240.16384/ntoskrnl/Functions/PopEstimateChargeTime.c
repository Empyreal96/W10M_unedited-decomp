// PopEstimateChargeTime 
 
int PopEstimateChargeTime()
{
  unsigned int v0; // r7
  int v1; // r5
  int v2; // r10
  char v3; // r6
  unsigned __int64 v4; // r8
  char v5; // r10
  int *v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r3
  int v9; // r3
  int v10; // r3
  __int64 v11; // r6
  unsigned __int64 v12; // r0
  char v14; // [sp+20h] [bp-D0h] BYREF
  int v15; // [sp+24h] [bp-CCh] BYREF
  int v16; // [sp+28h] [bp-C8h]
  unsigned __int64 v17; // [sp+30h] [bp-C0h] BYREF
  int v18[2]; // [sp+38h] [bp-B8h] BYREF
  int v19[2]; // [sp+40h] [bp-B0h] BYREF
  __int64 v20; // [sp+48h] [bp-A8h] BYREF
  _DWORD v21[40]; // [sp+50h] [bp-A0h] BYREF

  v0 = 0;
  v1 = -1;
  v2 = 0;
  v3 = 0;
  v15 = 0;
  v16 = -1;
  v19[0] = -1;
  LODWORD(v20) = -1;
  v18[0] = 0;
  LODWORD(v17) = 0;
  v4 = 0i64;
  if ( PopBatteryEstimatesSpoiled() )
  {
    v5 = 83;
  }
  else
  {
    v6 = (int *)dword_61ED7C;
    if ( (int *)dword_61ED7C != &dword_61ED7C )
    {
      do
      {
        v7 = v6[12];
        v8 = v6[18];
        if ( v7 != -1 && v8 != -1 && v8 < v7 )
        {
          v0 = (__PAIR64__(v0, v2) + v7 - v8) >> 32;
          v2 += v7 - v8;
        }
        v9 = v6[20];
        if ( v9 != 0x80000000 && v9 > 0 )
          v4 += v9;
        v10 = v6[17];
        v6 = (int *)*v6;
        v3 |= v10;
      }
      while ( v6 != &dword_61ED7C );
      LODWORD(v17) = v0;
      v18[0] = v2;
    }
    v15 = v3 & 7;
    v11 = PopMaxChargeRate;
    if ( v15 == 5 )
    {
      if ( PopMaxChargeRate < v4 )
      {
        PopMaxChargeRate = v4;
        v11 = v4;
      }
      if ( v2 | (unsigned int)v17 && v11 )
      {
        LODWORD(v12) = _rt_udiv64(v11, 4000 * __PAIR64__(v17, v2));
        LODWORD(v20) = HIDWORD(v12);
        v19[0] = v12;
        if ( v12 > 0x5460 )
        {
          v5 = 76;
        }
        else
        {
          v16 = HIDWORD(v12);
          v1 = v12;
          v5 = 79;
        }
      }
      else
      {
        v5 = 90;
      }
    }
    else
    {
      v5 = 80;
    }
  }
  DbgPrintEx(146, 3, (int)"Charge time: Rate=%lld CapToChg=%lld MaxRate=%lld Est=%lld\n", v16);
  if ( (unsigned int)dword_6163C8 > 5 && TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64) )
  {
    v18[1] = v17;
    v14 = v5;
    v17 = v4;
    v19[1] = v20;
    v20 = PopMaxChargeRate;
    v21[8] = v18;
    v21[9] = 0;
    v21[10] = 8;
    v21[11] = 0;
    v21[12] = v19;
    v21[13] = 0;
    v21[14] = 8;
    v21[15] = 0;
    v21[16] = &v20;
    v21[17] = 0;
    v21[18] = 8;
    v21[19] = 0;
    v21[20] = &v14;
    v21[21] = 0;
    v21[22] = 1;
    v21[23] = 0;
    v21[24] = &v17;
    v21[25] = 0;
    v21[26] = 8;
    v21[27] = 0;
    v21[28] = &v15;
    v21[29] = 0;
    v21[30] = 4;
    v21[31] = 0;
    TlgWrite(&dword_6163C8, (unsigned __int8 *)&word_4141DA + 1, 0, 0, 8, v21);
  }
  return v1;
}
