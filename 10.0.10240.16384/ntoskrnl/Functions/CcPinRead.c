// CcPinRead 
 
int __fastcall CcPinRead(int a1, __int64 *a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  char v6; // r10
  int *v9; // lr
  unsigned int *v10; // r4
  unsigned int v11; // r5
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r4
  int v15; // r0
  unsigned int v16; // r5
  unsigned int v17; // r1
  int v18; // r0
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int *v21; // r0
  int v22; // r1
  unsigned int v23; // r2
  unsigned __int8 v25; // [sp+18h] [bp-48h]
  int v26; // [sp+1Ch] [bp-44h] BYREF
  unsigned int v27; // [sp+20h] [bp-40h]
  int *v28; // [sp+24h] [bp-3Ch]
  int v29; // [sp+28h] [bp-38h] BYREF
  int *v30; // [sp+2Ch] [bp-34h]
  unsigned __int64 v31; // [sp+30h] [bp-30h] BYREF
  __int64 v32; // [sp+38h] [bp-28h] BYREF
  int varg_r0; // [sp+68h] [bp+8h]
  __int64 *varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = a4;
  v27 = a3;
  v29 = 0;
  v31 = *a2;
  v26 = 0;
  v9 = &v26;
  v28 = &v26;
  if ( (a4 & 1) != 0 )
  {
    v10 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4252);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 + 1, v10) );
  }
  else
  {
    v12 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4248);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 + 1, v12) );
  }
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4) = 0;
  v14 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  v15 = v31;
  v16 = HIDWORD(v32);
  v17 = v32;
  while ( 1 )
  {
    if ( v26 )
    {
      if ( v9 == &v26 )
      {
        v26 = CcAllocateObcb(a2, v27);
        v9 = (int *)(v26 + 16);
        v30 = (int *)(v26 + 16);
        *a6 = v29;
        v15 = v31;
        v16 = HIDWORD(v32);
        v17 = v32;
      }
      v18 = v27 + v15 - v17;
      v27 = v18;
      varg_r2 = v18;
      v31 = __PAIR64__(v16, v17);
      v28 = ++v9;
      v30 = v9;
    }
    else
    {
      v18 = v27;
    }
    if ( !CcPinFileData(a1, &v31, v18, (*(_DWORD *)(v14 + 96) & 0x200) == 0, 0, v6, (int **)v9, &v29, &v32) )
    {
      v19 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4308);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 + 1, v19) );
      v25 = 0;
      goto LABEL_22;
    }
    v17 = v32;
    v15 = v31;
    v16 = HIDWORD(v32);
    if ( (__int64)(v32 - v31) >= v27 )
      break;
    v9 = v28;
  }
  *a5 = v26;
  if ( v28 == &v26 )
    *a6 = v29;
  v25 = 1;
LABEL_22:
  v21 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4312);
  v22 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4);
  do
    v23 = __ldrex(v21);
  while ( __strex(v23 + v22, v21) );
  if ( !v25 && v26 )
    CcUnpinData(v26);
  return v25;
}
