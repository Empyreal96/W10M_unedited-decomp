// MiAllocatePerSessionProtos 
 
int __fastcall MiAllocatePerSessionProtos(int a1, int a2, int a3, int a4, unsigned int *a5)
{
  int v6; // r9
  unsigned int v7; // r6
  int v8; // r4
  int v9; // r0
  unsigned int v10; // r5
  int v11; // r10
  unsigned int *v12; // r0
  unsigned int *v13; // r4
  unsigned int v14; // lr
  unsigned int v15; // r1
  unsigned int v16; // r8
  unsigned int v17; // r1
  unsigned int v18; // r8
  _DWORD *v19; // r9
  unsigned int v20; // r4
  int v21; // r0
  int v22; // r0
  int v23; // r2
  int v24; // r4
  unsigned int v25; // r0
  int v26; // r0
  unsigned int v27; // r0
  unsigned int v29; // [sp+18h] [bp-50h]
  unsigned int *v33; // [sp+28h] [bp-40h]
  _DWORD v34[2]; // [sp+38h] [bp-30h] BYREF
  _DWORD _40[16]; // [sp+40h] [bp-28h] BYREF

  _40[13] = a2;
  _40[15] = a4;
  _40[14] = a3;
  v6 = a1;
  _40[12] = a1;
  *a5 = 0;
  v7 = 0;
  if ( !MiChargeCommit((int)MiSystemPartition, *(_DWORD *)(a1 + 28), 0) )
    return -1073741523;
  v9 = ExAllocatePoolWithTag(512, 24, 1934847309);
  v10 = v9;
  _40[0] = v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 20) = 1;
    v12 = (unsigned int *)ExAllocatePoolWithTag(-2147483647, 4 * *(_DWORD *)(v6 + 28), 1951624525);
    v13 = v12;
    *(_DWORD *)(v10 + 16) = v12;
    if ( v12 )
    {
      memset(v12, 0, 4 * *(_DWORD *)(v6 + 28));
      v14 = v6 & 0xFFFFFC00 | ((v6 & 0x7F8 | 0x800u) >> 1);
      v34[0] = v14;
      v33 = *(unsigned int **)(v6 + 4);
      v15 = 0;
      v29 = 0;
      if ( *(_DWORD *)(v6 + 28) )
      {
        v16 = (unsigned int)(v13 + 267649024);
        while ( 1 )
        {
          v17 = *v33++;
          if ( !v17 )
            break;
          if ( !a2 )
          {
            if ( (v17 & 2) != 0 || (v17 & 0x400) != 0 || (v17 & 0x800) != 0 || (v17 & 0x10) != 0 )
            {
              if ( v16 + 3145728 > 0x3FFFFF )
              {
                *v13 = v14;
              }
              else
              {
                __dmb(0xBu);
                *v13 = v14;
                if ( v16 <= 0xFFF )
                  MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v14, (__int16)v13);
              }
            }
            else if ( v16 + 3145728 > 0x3FFFFF )
            {
              *v13 = v17;
            }
            else
            {
              __dmb(0xBu);
              *v13 = v17;
              if ( v16 <= 0xFFF )
                MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v17, (__int16)v13);
            }
          }
          ++v13;
          v16 += 4;
          v15 = v29 + 1;
          v29 = v15;
          v14 = v34[0];
          if ( v15 >= *(_DWORD *)(v6 + 28) )
            goto LABEL_26;
        }
        v15 = v29;
      }
LABEL_26:
      v18 = *(_DWORD *)(v10 + 16);
      if ( !a2 )
      {
        v11 = a1;
        goto LABEL_39;
      }
      v19 = *(_DWORD **)v6;
      v20 = v15 << 12;
      v21 = MmSizeOfMdl(a2, v15 << 12);
      v22 = ExAllocatePoolWithTag(512, v21, 543974477);
      v7 = v22;
      v34[0] = v22;
      if ( v22 )
      {
        *(_DWORD *)v22 = 0;
        v23 = a2 & 0xFFF;
        *(_WORD *)(v22 + 4) = 4 * (((v23 + v20 + 4095) >> 12) + 7);
        *(_WORD *)(v22 + 6) = 0;
        *(_DWORD *)(v22 + 16) = a2 & 0xFFFFF000;
        *(_DWORD *)(v22 + 24) = v23;
        *(_DWORD *)(v22 + 20) = v20;
        MmProbeAndLockPages(v22);
        v11 = a1;
        v24 = (*(unsigned __int16 *)(a1 + 16) >> 1) & 0x1F;
        if ( !MiChargeResident(MiSystemPartition, v29, 0) )
        {
          v8 = -1073741670;
          goto LABEL_40;
        }
        do
          v25 = __ldrex(&dword_634A2C[85]);
        while ( __strex(v25 + v29, &dword_634A2C[85]) );
        if ( (MiFlags & 0x30000) != 0 && (MiFlags & 0x80000) != 0 && (v24 & 2) != 0 )
        {
          v34[1] = *(_DWORD *)(v19[14] + 8);
          v34[0] = a3 << 12;
          _40[1] = 0;
          _40[0] = *(_DWORD *)(*v19 + 24) + (a3 << 12) + a4;
          v26 = MiFillPerSessionProtos((int)v19, v18, v7 + 28, v29, v24, a3, a4, v34, _40);
        }
        else
        {
          v26 = MiFillPerSessionProtos((int)v19, v18, v7 + 28, v29, v24, a3, a4, 0, 0);
        }
        v8 = v26;
        if ( v26 < 0 )
          goto LABEL_40;
LABEL_39:
        *a5 = v10;
        v10 = 0;
        v8 = 0;
        goto LABEL_40;
      }
    }
  }
  v8 = -1073741670;
  v11 = a1;
LABEL_40:
  if ( v7 )
  {
    MmUnlockPages(v7);
    ExFreePoolWithTag(v7);
  }
  if ( v10 )
  {
    v27 = *(_DWORD *)(v10 + 16);
    if ( v27 )
      ExFreePoolWithTag(v27);
    ExFreePoolWithTag(v10);
  }
  if ( v8 < 0 )
    MiReturnCommit((int)MiSystemPartition, *(_DWORD *)(v11 + 28));
  return v8;
}
