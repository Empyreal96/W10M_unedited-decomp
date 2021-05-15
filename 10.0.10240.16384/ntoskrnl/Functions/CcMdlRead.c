// CcMdlRead 
 
int __fastcall CcMdlRead(int a1, unsigned int *a2, unsigned int a3, int *a4, _DWORD *a5)
{
  unsigned int v5; // r5
  int v8; // r4
  _DWORD *v9; // r8
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r10
  int v13; // r6
  int v14; // r0
  int *v15; // r8
  int v16; // r4
  int v17; // r6
  int v18; // r0
  int v19; // r6
  int *v20; // r3
  unsigned int *v21; // r1
  int v22; // r2
  unsigned int v23; // r0
  unsigned int v24; // r4
  unsigned __int64 *v25; // r5
  int v26; // r6
  int result; // r0
  int v28; // [sp+8h] [bp-70h]
  int *v29; // [sp+10h] [bp-68h] BYREF
  unsigned int v30; // [sp+14h] [bp-64h]
  int v31; // [sp+18h] [bp-60h]
  int v32; // [sp+1Ch] [bp-5Ch] BYREF
  int v33; // [sp+20h] [bp-58h]
  int v34; // [sp+24h] [bp-54h]
  unsigned int v35; // [sp+28h] [bp-50h] BYREF
  int v36; // [sp+2Ch] [bp-4Ch]
  _DWORD *v37; // [sp+30h] [bp-48h]
  int v38; // [sp+34h] [bp-44h]
  int *v39; // [sp+38h] [bp-40h]
  int v40; // [sp+3Ch] [bp-3Ch]
  _DWORD *v41; // [sp+40h] [bp-38h]
  unsigned int v42; // [sp+48h] [bp-30h] BYREF
  int v43; // [sp+4Ch] [bp-2Ch]
  unsigned __int64 v44; // [sp+50h] [bp-28h]
  int varg_r0; // [sp+80h] [bp+8h]
  unsigned __int64 *varg_r1; // [sp+84h] [bp+Ch]
  unsigned int varg_r2; // [sp+88h] [bp+10h]
  int *varg_r3; // [sp+8Ch] [bp+14h]

  varg_r2 = a3;
  v39 = a4;
  varg_r3 = a4;
  v5 = a3;
  varg_r1 = (unsigned __int64 *)a2;
  varg_r0 = a1;
  v31 = 0;
  v30 = a3;
  v36 = 0;
  v34 = 0;
  v29 = 0;
  v32 = 0;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  v40 = v8;
  v33 = v8;
  v9 = *(_DWORD **)(a1 + 24);
  v41 = v9;
  v37 = v9;
  if ( (*v9 & 0x20000) != 0 )
    CcScheduleReadAheadEx(a1, (int)a2, a3);
  v10 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4260);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 + 1, v10) );
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4) = 0;
  v12 = *a2;
  v42 = *a2;
  v13 = a2[1];
  v43 = v13;
  while ( v5 )
  {
    v14 = CcGetVirtualAddress(v8, 0, v12, v13, &v29, &v35, 0, 0);
    v38 = v14;
    if ( (*(_DWORD *)(v8 + 96) & 8) != 0 )
    {
      v15 = v29;
    }
    else
    {
      v28 = (*v9 >> 18) & 7;
      v15 = v29;
      CcFetchDataForRead(a1, (int *)&v42, v5, 1, &v32, v29, v28);
      v14 = v38;
    }
    v16 = v35;
    if ( v35 > v5 )
    {
      v16 = v5;
      v35 = v5;
    }
    v17 = (__PAIR64__(v13, v12) + (unsigned int)v16) >> 32;
    v12 += v16;
    v38 = v17;
    v44 = __PAIR64__(v17, v12);
    v18 = IoAllocateMdl(v14, v16, 0, 0, 0);
    v19 = v18;
    v31 = v18;
    if ( !v18 )
      RtlRaiseStatus(-1073741670);
    MmProbeAndLockPages(v18);
    CcFreeVirtualAddress((int)v15);
    v29 = 0;
    v20 = (int *)*v39;
    if ( *v39 )
    {
      while ( *v20 )
        v20 = (int *)*v20;
      *v20 = v19;
    }
    else
    {
      *v39 = v19;
    }
    v31 = 0;
    v42 = v12;
    v13 = v38;
    v43 = v38;
    v36 += v16;
    v34 = v36;
    v5 -= v16;
    varg_r2 = v5;
    v8 = v40;
    v9 = v41;
  }
  v21 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4320);
  v22 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4);
  do
    v23 = __ldrex(v21);
  while ( __strex(v23 + v22, v21) );
  if ( (*v37 & 0x20000) != 0 || !v32 )
  {
    v25 = varg_r1;
    v26 = varg_r0;
    v24 = v30;
  }
  else
  {
    v24 = v30;
    v25 = varg_r1;
    v26 = varg_r0;
    CcScheduleReadAheadEx(varg_r0, (int)varg_r1, v30);
  }
  CcUpdateReadHistory(v26, v25, v24);
  result = v33;
  if ( (*(_DWORD *)(v33 + 96) & 8) != 0 )
    result = CcUpdateSharedCacheMapFlag(v33, 8, 0);
  *a5 = 0;
  a5[1] = v34;
  return result;
}
