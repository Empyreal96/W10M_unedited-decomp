// MiCreateDataFileMap 
 
int __fastcall MiCreateDataFileMap(int a1, int *a2, unsigned int *a3, int a4, int a5, int a6, int a7)
{
  char v7; // r9
  int result; // r0
  unsigned int v11; // r7
  unsigned int v12; // r8
  __int64 v13; // kr08_8
  int v14; // r4
  int *v15; // r0
  int *v16; // r5
  unsigned int v17; // r10
  _DWORD *v18; // r6
  unsigned int v19; // r2
  unsigned int v20; // r9
  char v21; // r1
  int v22; // r0
  __int16 v23; // r10
  __int16 v24; // r2
  char v25; // r3
  unsigned int v26; // r4
  int v27; // r7
  int v28; // r6
  unsigned int v29; // r9
  __int16 v30; // r3
  int v31; // r2
  _BYTE *v32; // r0
  unsigned int v33; // r0
  __int16 v34; // r3
  unsigned int v35; // r0
  unsigned int v36; // r4
  int v37; // [sp+0h] [bp-38h]
  _DWORD *v38; // [sp+4h] [bp-34h]
  int v39; // [sp+8h] [bp-30h]
  __int64 v41[5]; // [sp+10h] [bp-28h] BYREF
  int varg_r0; // [sp+40h] [bp+8h]
  int *varg_r1; // [sp+44h] [bp+Ch]
  unsigned int *varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = a4;
  if ( (a7 & 1) != 0 )
  {
    v11 = a3[1];
    v12 = *a3;
    goto LABEL_7;
  }
  result = FsRtlGetFileSize(a1, v41);
  if ( result == -1073741638 )
    return sub_7D4DE0();
  if ( result >= 0 )
  {
    v11 = HIDWORD(v41[0]);
    v12 = v41[0];
    if ( !v41[0] && !*(_QWORD *)a3 )
      return -1073741538;
    v13 = *(_QWORD *)a3;
    if ( *(_QWORD *)a3 > v41[0] )
    {
      if ( (v7 & 0x44) == 0 )
        goto LABEL_39;
      v12 = *a3;
      v41[0] = *(_QWORD *)a3;
      v11 = HIDWORD(v13);
      result = FsRtlSetFileSize(a1, v41);
      if ( result < 0 )
        return result;
    }
LABEL_7:
    if ( v11 < 0x3FFFFF || v11 <= 0x3FFFFF && v12 <= 0xFFFFF000 )
    {
      v39 = (__int64)(__PAIR64__(v11, v12) + 4095) >> 12;
      LODWORD(v41[0]) = (unsigned int)((__PAIR64__(v11, v12) + 4095) >> 32) >> 12;
      v14 = ExAllocatePoolWithTag(1, 32, 1834184013);
      if ( !v14 )
        return -1073741670;
      v15 = (int *)ExAllocatePoolWithTag(512, 160, 1631808845);
      v16 = v15;
      if ( !v15 )
      {
        v33 = v14;
        goto LABEL_48;
      }
      memset(v15, 0, 160);
      v17 = (__PAIR64__(v11, v12) + 4095) >> 42;
      v18 = 0;
      v19 = 0x2000;
      v37 = 0x2000;
      v38 = 0;
      v20 = 4 * ((__int64)(__PAIR64__(v11, v12) + 4095) >> 12);
      do
      {
        if ( !v17 && v20 < 0x2000 )
        {
          v19 = v20;
          v37 = v20;
        }
        if ( v18 )
        {
          v32 = (_BYTE *)ExAllocatePoolWithTag(512, 68, 1666411853);
          v18 = v32;
          if ( !v32 )
          {
            ExFreePoolWithTag(v14);
            v35 = v16[22];
            if ( v35 )
            {
              do
              {
                v36 = *(_DWORD *)(v35 + 8);
                ExFreePoolWithTag(v35);
                v35 = v36;
              }
              while ( v36 );
            }
            v33 = (unsigned int)v16;
LABEL_48:
            ExFreePoolWithTag(v33);
            return -1073741670;
          }
          memset(v32, 0, 68);
          v19 = v37;
          v38[2] = v18;
        }
        else
        {
          v18 = v16 + 20;
        }
        v17 = (__PAIR64__(v17, v20) - v19) >> 32;
        v20 -= v19;
        v18[7] = v19 >> 2;
        v38 = v18;
      }
      while ( __PAIR64__(v17, v20) );
      *a2 = v14;
      memset((_BYTE *)v14, 0, 32);
      *(_DWORD *)(v14 + 28) = 0;
      *v16 = v14;
      v16[1] = (int)(v16 + 1);
      v16[2] = (int)(v16 + 1);
      v16[16] = 1;
      v16[17] = 0;
      v16[3] = 1;
      v16[18] = 0;
      if ( (a7 & 1) != 0 )
        v16[7] |= 0x8000u;
      else
        v16[6] = 1;
      v16[7] = v16[7] ^ (v16[7] ^ (a6 << 20)) & 0x3F00000 | 0x82;
      v21 = dword_632E1C;
      if ( (a7 & 0x10000) == 0 )
      {
        if ( (a5 & 0x10000000) != 0 )
        {
          v21 = dword_632E1C | 8;
          v34 = *(_WORD *)(v14 + 8) | 0x8000;
        }
        else
        {
          if ( (a5 & 0x40000000) == 0 )
            goto LABEL_24;
          v21 = dword_632E1C | 0x18;
          v34 = *(_WORD *)(v14 + 8) | 0x4000;
        }
        *(_WORD *)(v14 + 8) = v34;
      }
LABEL_24:
      v22 = (__int64)(__PAIR64__(v11, v12) + 4095) >> 12;
      v23 = v21 & 0x1F;
      v24 = *(_WORD *)(v14 + 8) & 0xFC00 | v41[0] & 0x3FF;
      v25 = *(_BYTE *)(v14 + 10);
      *(_DWORD *)v14 = v16;
      *(_DWORD *)(v14 + 4) = v39;
      *(_DWORD *)(v14 + 16) = v12;
      *(_DWORD *)(v14 + 20) = v11;
      *(_BYTE *)(v14 + 10) = v25 & 0xC1 | (2 * (v21 & 0x1F));
      *(_WORD *)(v14 + 8) = v24;
      v26 = 0;
      v27 = (v11 << 20) | (v12 >> 12);
      v28 = (int)(v16 + 20);
      v29 = 0;
      do
      {
        v30 = *(_WORD *)(v28 + 16);
        *(_DWORD *)v28 = v16;
        *(_DWORD *)(v28 + 20) = v26;
        *(_WORD *)(v28 + 16) = (v30 & 1 | ((_WORD)v29 << 6)) & 0xFFC1 | (2 * v23);
        if ( *(_DWORD *)(v28 + 8) )
        {
          *(_DWORD *)(v28 + 24) = *(_DWORD *)(v28 + 28);
        }
        else
        {
          *(_DWORD *)(v28 + 24) = v27 - v26;
          v31 = *(_DWORD *)(v28 + 28);
          *(_WORD *)(v28 + 18) = *(_WORD *)(v28 + 18) & 0xF | (16 * v12);
          *(_DWORD *)(v28 + 28) = v22 - v26;
          *(_DWORD *)(v28 + 36) = v31 - (v22 - v26);
        }
        v29 = (__PAIR64__(v29, v26) + *(unsigned int *)(v28 + 28)) >> 32;
        v26 += *(_DWORD *)(v28 + 28);
        *(_DWORD *)(v28 + 52) = v28 + 52;
        *(_DWORD *)(v28 + 56) = v28 + 52;
        MiInsertSubsectionNode(v16, v28, 0);
        v28 = *(_DWORD *)(v28 + 8);
        v22 = v39;
      }
      while ( v28 );
      return 0;
    }
LABEL_39:
    result = -1073741760;
  }
  return result;
}
