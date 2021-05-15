// PoSetHiberRange 
 
char *__fastcall PoSetHiberRange(int a1, int a2, const void *a3, const void *a4, int a5)
{
  int v5; // r8
  unsigned int v6; // r5
  int v7; // r7
  char *result; // r0
  unsigned int v9; // r4
  int v10; // r3
  int v11; // r2
  unsigned int v12; // r6
  int v13; // r3
  unsigned int v14; // r5
  unsigned int v15; // r7
  int v16; // r9
  int v17; // r2
  int v18; // r10
  int v19; // r3
  unsigned int v20; // r8
  int v21; // [sp+8h] [bp-40h]
  int v22; // [sp+Ch] [bp-3Ch] BYREF
  int v23; // [sp+10h] [bp-38h]
  __int64 v24; // [sp+18h] [bp-30h] BYREF
  __int64 v25[5]; // [sp+20h] [bp-28h] BYREF
  int varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  const void *varg_r2[2]; // [sp+58h] [bp+10h] BYREF

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2[1] = a4;
  v5 = a1;
  v21 = a1;
  v6 = (unsigned int)a3;
  v7 = (int)a4;
  result = (char *)KiBugCheckActive;
  varg_r2[0] = a3;
  v9 = a2;
  if ( (KiBugCheckActive & 3) != 0 )
    return result;
  if ( !v5 )
  {
    result = &PopAction;
    v5 = dword_61EC98;
    v21 = dword_61EC98;
    if ( !dword_61EC98 )
      KeBugCheckEx(160, 267, 10, 0, 0);
    v10 = *(_DWORD *)(dword_61EC98 + 116);
    if ( v10 != 8 )
    {
      if ( v10 != 9 )
        KeBugCheckEx(160, 267, 10, v10, 0);
      return result;
    }
    v11 = 0x10000;
    if ( (a2 & 0xFFFFBFFF) != 0x10000 )
      KeBugCheckEx(160, 268, 10, a2, 0);
    if ( v7 )
      goto LABEL_23;
    if ( (a2 & 0x4000) != 0 )
      KeBugCheck2(160, 268, 0xAu, a2, 0, 0);
    goto LABEL_16;
  }
  v11 = 0x10000;
  if ( (a2 & 0x10000) != 0 )
    KeBugCheckEx(160, 268, 10, a2, 0);
  if ( !a4 )
  {
LABEL_16:
    if ( (a2 & 0x10000) != 0 )
      return (char *)MmMarkImageForHiberPhase(v6);
    result = (char *)MmGetSectionRange(v6, varg_r2, &v22);
    if ( (int)result < 0 )
    {
      if ( (PoDebug & 0x80) != 0 )
        DbgPrint("PoSetHiberRange: Section for %p not found - skipped\n", varg_r2[0]);
      KeBugCheckEx(160, 2, 659842, 0, 0);
    }
    v7 = v22;
    v6 = (unsigned int)varg_r2[0];
  }
LABEL_23:
  if ( (v9 & 4) != 0 )
    v9 = v9 & 0xFFFFFFF9 | 2;
  if ( (v9 & 0x4000) != 0 )
    return (char *)PopSetRange(v5, v9 & 0xFFFFBFFF, v6, v7, a5);
  v12 = v6 >> 12;
  v13 = v6 + v7;
  v14 = v6 + v7 + 4095;
  while ( v12 < v14 >> 12 )
  {
    MmGetPhysicalAddress((int)&v24, v12 << 12, v11, v13);
    v15 = v12 + 1;
    v16 = 1;
    v17 = v24 >> 12;
    v23 = v17;
    if ( v12 + 1 < v14 >> 12 )
    {
      v18 = (v12 + 1) << 12;
      v19 = v17 - v12;
      v22 = v17 - v12;
      v20 = v17 - v12;
      do
      {
        MmGetPhysicalAddress((int)v25, v18, v17, v19);
        v19 = v25[0] >> 12;
        if ( v20 + v15 != v19 )
          break;
        ++v15;
        ++v16;
        v18 += 4096;
      }
      while ( v15 < v14 >> 12 );
      v5 = v21;
      v17 = v23;
    }
    result = (char *)PopSetRange(v5, v9, v17, v16, a5);
    v12 += v16;
  }
  return result;
}
