// FstubWritePartitionTableEFI 
 
int __fastcall FstubWritePartitionTableEFI(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7, int a8, int a9, int a10, int a11, unsigned int a12, int a13)
{
  int v13; // r6
  unsigned int v14; // r3
  int v16; // r7
  int v17; // r8
  unsigned int v18; // r0
  unsigned int v19; // r2
  int v20; // r3
  unsigned int v21; // r4
  unsigned int v22; // r9
  _DWORD *v23; // r6
  unsigned int v24; // r8
  unsigned int v25; // r7
  int result; // r0
  int v27; // [sp+4h] [bp-D4h]
  int v28; // [sp+Ch] [bp-CCh]
  int v29; // [sp+28h] [bp-B0h] BYREF
  _DWORD *v30; // [sp+2Ch] [bp-ACh]
  unsigned int v31; // [sp+30h] [bp-A8h]
  unsigned int v32; // [sp+34h] [bp-A4h]
  _DWORD varA0[43]; // [sp+38h] [bp-A0h] BYREF
  int varg_r1; // [sp+E4h] [bp+Ch]
  int varg_r2; // [sp+E8h] [bp+10h]
  int varg_r3; // [sp+ECh] [bp+14h]

  varA0[42] = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v13 = a4;
  v14 = a1[1];
  v16 = a3;
  v17 = a2;
  varg_r1 = a2;
  varg_r2 = a3;
  v30 = a1;
  varg_r3 = v13;
  v32 = v14;
  if ( !v14 )
    __brkdiv0();
  v18 = (v14 + (a6 << 7) - 1) / v14;
  v19 = a12;
  v20 = 0;
  v21 = 0;
  v31 = v18;
  v29 = 0;
  v22 = 0;
  if ( a12 )
  {
    v23 = v30;
    v24 = v32;
    v25 = v18;
    do
    {
      if ( *(_DWORD *)(a13 + 32)
        || *(_WORD *)(a13 + 36)
        || *(_WORD *)(a13 + 38)
        || *(_BYTE *)(a13 + 40)
        || *(_BYTE *)(a13 + 41)
        || *(_BYTE *)(a13 + 42)
        || *(_BYTE *)(a13 + 43)
        || *(_BYTE *)(a13 + 44)
        || *(_BYTE *)(a13 + 45)
        || *(_BYTE *)(a13 + 46)
        || *(_BYTE *)(a13 + 47) )
      {
        FstubCopyEntryEFI(varA0, a13, v24);
        result = FstubWriteEntryEFI((int)v23, v25, v21, (int)varA0, a11, v27, &v29);
        if ( result < 0 )
          return result;
        v19 = a12;
        ++v21;
      }
      ++v22;
      a13 += 144;
    }
    while ( v22 < v19 );
    v16 = varg_r2;
    v13 = varg_r3;
    v17 = varg_r1;
    v20 = v29;
  }
  if ( v21 >= a6 )
    return FstubWriteHeaderEFI(v30, v31, v17, v16, v13, a5, a6, v28, a7, a8, a9, a10, v20, a11);
  while ( 1 )
  {
    memset(varA0, 0, 128);
    result = FstubWriteEntryEFI((int)v30, v31, v21, (int)varA0, a11, v27, &v29);
    if ( result < 0 )
      break;
    if ( ++v21 >= a6 )
    {
      v16 = varg_r2;
      v13 = varg_r3;
      v17 = varg_r1;
      v20 = v29;
      return FstubWriteHeaderEFI(v30, v31, v17, v16, v13, a5, a6, v28, a7, a8, a9, a10, v20, a11);
    }
  }
  return result;
}
