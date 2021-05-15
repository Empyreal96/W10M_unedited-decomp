// IoSetPartitionInformation 
 
int __fastcall IoSetPartitionInformation(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v4; // r6
  unsigned int v5; // r8
  int v6; // r4
  int v7; // r7
  int v8; // r1
  int v9; // r5
  int v10; // r9
  int v11; // r4
  _DWORD *v12; // r0
  int v13; // r2
  unsigned int v14; // r6
  int v15; // r3
  int v16; // r4
  _DWORD *v17; // r0
  unsigned __int8 *v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  unsigned int v22; // [sp+10h] [bp-68h]
  __int64 v23; // [sp+14h] [bp-64h]
  unsigned int v24; // [sp+1Ch] [bp-5Ch] BYREF
  unsigned int v25; // [sp+20h] [bp-58h]
  int v26; // [sp+24h] [bp-54h]
  int v27; // [sp+28h] [bp-50h]
  int v28; // [sp+2Ch] [bp-4Ch]
  unsigned int v29; // [sp+30h] [bp-48h]
  unsigned __int64 v30; // [sp+38h] [bp-40h] BYREF
  int v31[2]; // [sp+40h] [bp-38h] BYREF
  char v32[48]; // [sp+48h] [bp-30h] BYREF

  v28 = a4;
  v4 = 0;
  v5 = a2;
  if ( a2 < 0x200 )
    v5 = 512;
  v6 = a1;
  v25 = a3;
  v26 = a1;
  v29 = a2;
  v27 = 0;
  HalExamineMBR(a1, v5, 85, &v24);
  if ( v24 )
  {
    v4 = 1;
    v27 = 1;
    ExFreePoolWithTag(v24);
    v7 = 512;
    LODWORD(v30) = 512;
  }
  else
  {
    v7 = 0;
    LODWORD(v30) = 0;
  }
  v23 = 0i64;
  v24 = 1;
  v8 = 4096;
  v9 = 0;
  if ( v5 >= 0x1000 )
    v8 = v5;
  HIDWORD(v30) = 0;
  v22 = 0;
  v10 = ExAllocatePoolWithTag(516, v8, 1651798854);
  if ( !v10 )
    return -1073741670;
  KeInitializeEvent((int)v32, 0, 0);
  while ( 1 )
  {
    KeResetEvent((int)v32);
    v12 = IoBuildSynchronousFsdRequest(3, v6, v10, v5, &v30, (int)v32, (int)v31);
    if ( !v12 )
      break;
    *(_BYTE *)(v12[24] - 38) |= 2u;
    v11 = IofCallDriver(v6, (int)v12);
    if ( v11 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v32, 0, 0, 0, 0);
      v11 = v31[0];
    }
    if ( v11 < 0 )
      goto LABEL_44;
    if ( v4 && v7 == 512 && !v9 )
    {
      v7 = 0;
      v9 = 0;
      v30 = 0i64;
    }
    if ( *(unsigned __int16 *)(v10 + 510) != 43605 )
      goto LABEL_42;
    v13 = v10 + 446;
    v14 = 1;
    while ( 1 )
    {
      v15 = *(unsigned __int8 *)(v13 + 4);
      if ( *(_BYTE *)(v13 + 4) )
      {
        if ( v15 != 5 && v15 != 15 && ++v22 == v25 )
          break;
      }
      ++v14;
      v13 += 16;
      if ( v14 > 4 )
        goto LABEL_31;
    }
    *(_BYTE *)(v13 + 4) = v28;
    KeResetEvent((int)v32);
    v16 = v26;
    v17 = IoBuildSynchronousFsdRequest(4, v26, v10, v5, &v30, (int)v32, (int)v31);
    if ( v17 )
    {
      *(_BYTE *)(v17[24] - 38) |= 0x12u;
      v11 = IofCallDriver(v16, (int)v17);
      if ( v11 == 259 )
      {
        KeWaitForSingleObject((unsigned int)v32, 0, 0, 0, 0);
        v11 = v31[0];
      }
    }
    else
    {
      v11 = -1073741670;
    }
LABEL_31:
    if ( v14 <= 4 )
      goto LABEL_44;
    v18 = (unsigned __int8 *)(v10 + 446);
    v19 = 1;
    while ( 1 )
    {
      v20 = v18[4];
      if ( v20 == 5 || v20 == 15 )
        break;
      ++v19;
      v18 += 16;
      if ( v19 > 4 )
        goto LABEL_39;
    }
    v30 = (v18[8] + ((v18[9] + ((v18[10] + (v18[11] << 8)) << 8)) << 8)) * (unsigned __int64)v29 + v23;
    v9 = HIDWORD(v30);
    v7 = v30;
    if ( v24 )
      v23 = v30;
LABEL_39:
    if ( v19 > 4 )
    {
LABEL_42:
      v11 = -1073741655;
      goto LABEL_44;
    }
    v24 = 0;
    if ( v22 >= v25 )
      goto LABEL_44;
    v6 = v26;
    v4 = v27;
  }
  v11 = -1073741670;
LABEL_44:
  ExFreePoolWithTag(v10);
  return v11;
}
