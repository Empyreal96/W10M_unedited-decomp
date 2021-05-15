// MmCopyMemory 
 
int __fastcall MmCopyMemory(int a1, int a2, signed __int64 a3, unsigned int a4, int a5, _DWORD *a6)
{
  _DWORD *v6; // r10
  char v7; // r5
  int v8; // r6
  unsigned int v9; // r7
  int v10; // r3
  unsigned int v11; // r0
  int v12; // r4
  unsigned int v13; // r9
  unsigned int v14; // r8
  int v15; // r10
  int v16; // r0
  unsigned int v17; // r4
  int v18; // r0
  int v19; // r3
  int v20; // r5
  unsigned int v21; // r1
  int v22; // r0
  unsigned int *v23; // r9
  int v24; // r3
  unsigned int *v25; // r2
  unsigned int v26; // r5
  char v28[4]; // [sp+8h] [bp-60h] BYREF
  unsigned int v29; // [sp+Ch] [bp-5Ch] BYREF
  int v30; // [sp+10h] [bp-58h]
  int v31; // [sp+14h] [bp-54h] BYREF
  int v32; // [sp+18h] [bp-50h]
  int v33; // [sp+1Ch] [bp-4Ch]
  int v34; // [sp+20h] [bp-48h]
  int v35; // [sp+24h] [bp-44h]
  int v36; // [sp+28h] [bp-40h] BYREF
  int v37; // [sp+2Ch] [bp-3Ch] BYREF
  unsigned int v38; // [sp+30h] [bp-38h]
  int v39; // [sp+34h] [bp-34h]
  int v40; // [sp+38h] [bp-30h]
  int v41; // [sp+3Ch] [bp-2Ch]
  int v42; // [sp+40h] [bp-28h] BYREF
  unsigned int v43; // [sp+44h] [bp-24h]
  int varg_r0; // [sp+70h] [bp+8h]
  int varg_r1; // [sp+74h] [bp+Ch]
  signed __int64 varg_r2; // [sp+78h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v6 = a6;
  v7 = a5;
  *a6 = 0;
  v32 = a1;
  v35 = 0;
  if ( !a5 || (a5 & 0xFFFFFFFC) != 0 || ((a5 - 1) & a5) != 0 || (unsigned int)KeGetCurrentIrql(a1) > 1 )
    return -1073741582;
  v9 = a4;
  v39 = a5 & 1;
  if ( (a5 & 1) != 0 )
  {
    if ( !MiCheckPhysicalAddressRange(varg_r2, a4) )
      return -1073741800;
    v10 = (varg_r2 & 0xFFF) + a4;
  }
  else
  {
    if ( (unsigned int)varg_r2 + a4 <= (unsigned int)varg_r2 )
      return -1073741800;
    if ( (unsigned int)varg_r2 <= MmHighestUserAddress )
    {
      if ( (unsigned int)varg_r2 + a4 <= MmHighestUserAddress )
        return ZwReadVirtualMemory();
      return -1073741800;
    }
    v10 = (varg_r2 & 0xFFF) + a4;
  }
  v38 = (unsigned int)(v10 + 4095) >> 12;
  v40 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v41 = MiReservePtes(&dword_634D58, v38);
  v34 = v41;
  v11 = varg_r2;
  v8 = 0;
  v12 = varg_r2 & 0xFFF;
  v13 = 4096 - v12;
  v30 = 4096 - v12;
  v33 = v12;
  if ( 4096 - v12 > a4 )
  {
    v13 = a4;
    v30 = a4;
  }
  if ( (a5 & 1) != 0 )
    v14 = varg_r2 >> 12;
  else
    v14 = -1;
  v29 = v14;
  if ( a4 )
  {
    while ( 1 )
    {
      v36 = 0;
      v15 = 0;
      v37 = 0;
      if ( v39 )
        break;
      v16 = MiTranslatePageForCopy(v11, (unsigned int **)&v31, (int *)&v29, &v37, v28, &v36);
      v8 = v16;
      if ( v16 >= 0 )
      {
        if ( v16 == 273 )
        {
          v8 = 0;
          v21 = v13;
          if ( v13 )
          {
            v22 = v32 - v12;
            do
            {
              *(_BYTE *)(v22 + v12) = *((_BYTE *)&v36 + (v12 & 3));
              ++v12;
              --v21;
            }
            while ( v21 );
          }
          v14 = v29;
LABEL_51:
          ++v14;
          v9 -= v13;
          v35 += v13;
          v29 = v14;
          v30 = v9;
          v32 += v13;
          v11 = v13 + varg_r2;
          LODWORD(varg_r2) = v13 + varg_r2;
          if ( v9 > 0x1000 )
            v30 = 4096;
          v12 = 0;
          v33 = 0;
          if ( v34 )
            v34 += 4;
          goto LABEL_55;
        }
        v15 = v37;
        v14 = v29;
        v23 = (unsigned int *)v31;
        v37 = (unsigned __int8)v28[0];
LABEL_43:
        v8 = MiCopySinglePage(v32, v14, v12, v30, v34, v7);
        if ( v23 )
        {
          v24 = MmPfnDatabase + 24 * v14;
          __dmb(0xBu);
          v25 = (unsigned int *)(v24 + 12);
          do
            v26 = __ldrex(v25);
          while ( __strex(v26 & 0x7FFFFFFF, v25) );
          if ( v15 )
            MiUnlockProtoPoolPage(v15, 2);
          MiUnlockWorkingSetExclusive((int)v23, v37);
          v7 = a5;
        }
        if ( v8 < 0 )
        {
LABEL_60:
          v6 = a6;
          goto LABEL_61;
        }
        v13 = v30;
        goto LABEL_51;
      }
      if ( v16 != -1073741608 )
        goto LABEL_60;
      v17 = varg_r2;
      v42 = varg_r2;
      v43 = v9;
      if ( v9 > 0x400000 - ((unsigned int)varg_r2 & 0x3FFFFF) )
        v43 = 0x400000 - (varg_r2 & 0x3FFFFF);
      v18 = 1;
      v31 = 1;
      if ( (unsigned int)varg_r2 >= dword_63389C )
      {
        v19 = *((unsigned __int8 *)&MiState[2423]
              + ((int)((((unsigned int)varg_r2 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
        if ( v19 == 1 || v19 == 11 )
        {
          v20 = *(_DWORD *)(v40 + 324);
          if ( !v20 || PsIsSystemProcess(v40) )
          {
            v8 = -1073741819;
LABEL_58:
            v6 = a6;
            goto LABEL_61;
          }
          v18 = v20 + 3248;
          v7 = a5;
          v31 = v18;
        }
      }
      if ( v17 >= 0xC0400000 && v17 <= dword_633894 )
      {
        v8 = -1073741585;
        goto LABEL_58;
      }
      v8 = MiPrefetchVirtualMemory(1, (int)&v42, v18, 173);
      if ( v8 < 0 )
        goto LABEL_58;
      v11 = varg_r2;
      v14 = v29;
      v12 = v33;
LABEL_55:
      if ( !v9 )
        goto LABEL_60;
      v13 = v30;
    }
    v23 = 0;
    v37 = 17;
    v28[0] = 17;
    v12 = v33;
    v31 = 0;
    goto LABEL_43;
  }
LABEL_61:
  if ( v41 )
    MiReleasePtes(&dword_634D58, v41, v38);
  *v6 += v35;
  return v8;
}
