// VfMapTransfer 
 
_DWORD *VfMapTransfer(_DWORD *a1, int a2, ...)
{
  void *v3; // r5
  int v4; // r7
  int v6; // r0
  int *v7; // r8
  int v8; // r9
  int v9; // r1
  int v10; // r0
  int v11; // r6
  void *v12; // r4
  int v14; // r0
  int v15; // r6
  int v16; // r0
  int v17; // r0
  int v18[2]; // [sp+10h] [bp-28h] BYREF
  void (__fastcall *v19)(int *, int, int, void *, void *, int *, _DWORD); // [sp+18h] [bp-20h]
  int varg_r2; // [sp+48h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+48h] [bp+10h]
  void *varg_r3; // [sp+4Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+4Ch] [bp+14h]
  void *v24; // [sp+50h] [bp+18h] BYREF
  va_list va2; // [sp+50h] [bp+18h]
  int *v26; // [sp+54h] [bp+1Ch]
  int v27; // [sp+58h] [bp+20h]
  va_list va3; // [sp+5Ch] [bp+24h] BYREF

  va_start(va3, a2);
  va_start(va2, a2);
  va_start(varg_r3a, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3a, _DWORD);
  va_copy(va2, varg_r3a);
  varg_r3 = va_arg(va2, void *);
  va_copy(va3, va2);
  v24 = va_arg(va3, void *);
  v26 = va_arg(va3, int *);
  v27 = va_arg(va3, _DWORD);
  v3 = varg_r3;
  v4 = varg_r2;
  v18[0] = a2;
  v19 = (void (__fastcall *)(int *, int, int, void *, void *, int *, _DWORD))ViGetRealDmaOperation(a2, 32);
  v6 = ViGetAdapterInformationInternal(a2, 1);
  v7 = v26;
  v8 = v6;
  if ( v6 )
  {
    VF_ASSERT_MAX_IRQL(v6);
    VERIFY_BUFFER_LOCKED(varg_r2);
    ViCheckAdapterBuffers(v8);
    if ( *(_DWORD *)(v8 + 120) == 3 )
    {
      v10 = ViCheckMdlLength(varg_r2, v9, 0, 0, *v7);
      v11 = v10;
      if ( v10 )
      {
        ViHalPreprocessOptions(
          &dword_6187AC,
          "The provided MDL is not sufficient to satisfy the requested length",
          36,
          v10,
          0,
          0);
        VfReportIssueWithOptions(230, 36, v11, 0, 0, &dword_6187AC);
      }
    }
    if ( varg_r3 == (void *)-559026163 )
    {
      v3 = 0;
    }
    else
    {
      v14 = ViGetMapRegisterFile(varg_r3);
      v15 = v14;
      if ( v14 )
      {
        v12 = v24;
        v16 = ViMapDoubleBuffer(v14, varg_r2);
        if ( v16 && (*v7 = v16, v17 = ViSwap(varg_r3a, (int *)varg_r2a, va2), v12 = v24, v4 = varg_r2, v17) )
          v3 = varg_r3;
        else
          v3 = *(void **)(v15 + 28);
        goto LABEL_8;
      }
    }
  }
  v12 = v24;
LABEL_8:
  v19(v18, v18[0], v4, v3, v12, v7, (unsigned __int8)v27);
  *a1 = v18[0];
  a1[1] = v18[1];
  if ( v8 )
    INCREASE_MAPPED_TRANSFER_BYTE_COUNT(v8, *v7, 0);
  return a1;
}
