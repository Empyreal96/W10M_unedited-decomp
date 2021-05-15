// IoWritePartitionTable 
 
int __fastcall IoWritePartitionTable(int a1, unsigned int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v5; // r5
  int v6; // r4
  unsigned int v8; // r8
  int v9; // r10
  int v10; // r9
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r1
  unsigned int v14; // r3
  int v15; // r6
  int v16; // r3
  unsigned int v17; // r2
  int v18; // r4
  _DWORD *v19; // r0
  int v20; // r2
  unsigned int v21; // r1
  int v22; // r2
  int v23; // r7
  int v24; // r6
  int v25; // r8
  char v26; // r3
  int v27; // r1
  int v28; // lr
  __int64 v29; // r0
  char v30; // r3
  __int64 v31; // r0
  unsigned int v32; // r3
  char v33; // r2
  int v34; // r4
  _DWORD *v35; // r0
  unsigned int v36; // r3
  int v38; // [sp+10h] [bp-A0h]
  int v39; // [sp+18h] [bp-98h] BYREF
  int v40; // [sp+1Ch] [bp-94h]
  int v41; // [sp+20h] [bp-90h]
  int v42; // [sp+24h] [bp-8Ch] BYREF
  BOOL v43; // [sp+28h] [bp-88h]
  unsigned int v44; // [sp+2Ch] [bp-84h]
  unsigned int v45; // [sp+30h] [bp-80h]
  int v46; // [sp+38h] [bp-78h]
  int v47; // [sp+3Ch] [bp-74h]
  int v48; // [sp+40h] [bp-70h]
  unsigned int v49; // [sp+44h] [bp-6Ch]
  unsigned int v50; // [sp+48h] [bp-68h]
  int v51; // [sp+4Ch] [bp-64h]
  int v52; // [sp+50h] [bp-60h]
  unsigned int v53; // [sp+54h] [bp-5Ch]
  int v54; // [sp+58h] [bp-58h]
  int v55; // [sp+5Ch] [bp-54h]
  int v56; // [sp+60h] [bp-50h]
  unsigned int v57; // [sp+64h] [bp-4Ch]
  unsigned int v58; // [sp+68h] [bp-48h]
  int v59[2]; // [sp+70h] [bp-40h] BYREF
  unsigned int v60; // [sp+78h] [bp-38h] BYREF
  char v61[16]; // [sp+80h] [bp-30h] BYREF
  unsigned int v62; // [sp+90h] [bp-20h]

  v57 = a4;
  v58 = a3;
  v5 = a2;
  v6 = 0;
  v8 = a2;
  if ( a2 < 0x200 )
    v8 = 512;
  v55 = a1;
  v50 = v8;
  v46 = 0;
  v47 = 0;
  v38 = 0;
  v41 = 0;
  v52 = 0;
  xHalGetPartialGeometry(a1, &v60);
  HalExamineMBR(a1, v8, 85, &v42);
  if ( v42 )
  {
    v41 = 1;
    ExFreePoolWithTag(v42);
    v9 = 512;
    v39 = 512;
  }
  else
  {
    v9 = 0;
    v39 = 0;
  }
  v54 = 0;
  v48 = 0;
  v10 = 0;
  v11 = *(_DWORD *)a5;
  v40 = 0;
  v45 = 31 - __clz(v5);
  v56 = v11;
  v62 = v45;
  if ( v11 == 1 && !*(_QWORD *)(a5 + 8) && !*(_DWORD *)(a5 + 24) )
  {
    v52 = 1;
    if ( *(_DWORD *)(a5 + 28) || *(_BYTE *)(a5 + 32) != 4 || *(_BYTE *)(a5 + 33) == 1 )
      return -1073741811;
    if ( *(_BYTE *)(a5 + 35) == 1 )
      v38 = 1;
    v41 = 0;
  }
  v12 = v11 + 3;
  v13 = 4096;
  v14 = v12 >> 2;
  if ( v8 >= 0x1000 )
    v13 = v8;
  *(_DWORD *)a5 = v14;
  v15 = ExAllocatePoolWithTag(516, v13, 1651798854);
  v42 = v15;
  if ( !v15 )
    return -1073741670;
  v16 = *(_DWORD *)a5;
  v17 = 0;
  v44 = 0;
  if ( v16 )
  {
    v51 = v47;
    while ( 1 )
    {
      v43 = v17 == 0;
      KeInitializeEvent((int)v61, 0, 0);
      v18 = v55;
      v19 = IoBuildSynchronousFsdRequest(3, v55, v15, v8, &v39, (int)v61, (int)v59);
      if ( !v19 )
        break;
      *(_BYTE *)(v19[24] - 38) |= 2u;
      v6 = IofCallDriver(v18, (int)v19);
      if ( v6 == 259 )
      {
        KeWaitForSingleObject((unsigned int)v61, 0, 0, 0, 0);
        v6 = v59[0];
      }
      if ( v6 < 0 )
        goto LABEL_72;
      if ( v41 && v9 == 512 && !v10 )
      {
        v9 = 0;
        v39 = 0;
        v40 = 0;
        v10 = 0;
      }
      if ( !v52 )
      {
        *(_WORD *)(v15 + 510) = -21931;
        v38 = 0;
        if ( !(v9 | v10) )
        {
          v20 = *(_DWORD *)(a5 + 4);
          if ( *(_DWORD *)(v15 + 440) != v20 )
          {
            v38 = 1;
            *(_DWORD *)(v15 + 440) = v20;
          }
        }
        v21 = 0;
        v49 = 0;
        v22 = 4 * v44;
        v53 = 4 * v44;
        v23 = a5 + (v44 << 7) + 8;
        v24 = v15 + 446;
        while ( v22 != v56 )
        {
          v25 = *(unsigned __int8 *)(v23 + 24);
          if ( *(_BYTE *)(v23 + 27) )
          {
            v38 = 1;
            *(_BYTE *)(v24 + 4) = v25;
            if ( *(_BYTE *)(v23 + 25) )
              v26 = 0x80;
            else
              v26 = 0;
            *(_BYTE *)v24 = v26;
            if ( v25 )
            {
              if ( !v43 && (v25 == 5 || v25 == 15) )
              {
                v27 = v46;
                v28 = v51;
              }
              else
              {
                v27 = v9;
                v28 = v10;
              }
              v29 = (__int64)(*(_QWORD *)v23 - __PAIR64__(v28, v27)) >> v45;
              if ( HIDWORD(v29) )
              {
                v6 = -1073741811;
                goto LABEL_72;
              }
              v30 = v45;
              *(_DWORD *)(v24 + 8) = v29;
              v31 = *(__int64 *)(v23 + 8) >> v30;
              if ( HIDWORD(v31) )
              {
                v6 = -1073741811;
                break;
              }
              v32 = v60;
              v33 = v45;
              *(_DWORD *)(v24 + 12) = v31;
              HalpCalculateChsValues((__int64 *)v23, (__int64 *)(v23 + 8), v33, v58, v57, v32, (_BYTE *)v24);
              v22 = v53;
              v21 = v49;
            }
            else
            {
              *(_DWORD *)(v24 + 8) = 0;
              *(_DWORD *)(v24 + 12) = 0;
              *(_BYTE *)(v24 + 1) = 0;
              *(_BYTE *)(v24 + 5) = 0;
              *(_WORD *)(v24 + 2) = 0;
              *(_WORD *)(v24 + 6) = 0;
            }
          }
          if ( v25 == 5 || v25 == 15 )
          {
            v54 = *(_DWORD *)v23;
            v48 = *(_DWORD *)(v23 + 4);
          }
          ++v21;
          ++v22;
          v24 += 16;
          v23 += 32;
          v49 = v21;
          v53 = v22;
          if ( v21 >= 4 )
            break;
        }
        if ( v6 < 0 )
          goto LABEL_72;
        v15 = v42;
        v8 = v50;
      }
      if ( v38 == 1 )
      {
        v38 = 0;
        KeInitializeEvent((int)v61, 0, 0);
        if ( v41 && !(v9 | v10) )
        {
          v39 = 512;
          v40 = 0;
        }
        v34 = v55;
        v35 = IoBuildSynchronousFsdRequest(4, v55, v15, v8, &v39, (int)v61, (int)v59);
        if ( !v35 )
          break;
        *(_BYTE *)(v35[24] - 38) |= 0x12u;
        v6 = IofCallDriver(v34, (int)v35);
        if ( v6 == 259 )
        {
          KeWaitForSingleObject((unsigned int)v61, 0, 0, 0, 0);
          v6 = v59[0];
        }
        if ( v6 < 0 )
          goto LABEL_72;
      }
      v9 = v54;
      v39 = v54;
      v40 = v48;
      v10 = v48;
      if ( v43 )
      {
        v46 = v54;
        v51 = v48;
      }
      v36 = *(_DWORD *)a5;
      v17 = v44 + 1;
      v44 = v17;
      if ( v17 >= v36 )
        goto LABEL_72;
    }
    v6 = -1073741670;
  }
LABEL_72:
  ExFreePoolWithTag(v42);
  return v6;
}
