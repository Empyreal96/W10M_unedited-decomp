// VfFlushAdapterBuffers 
 
int __fastcall VfFlushAdapterBuffers(int a1, int a2, const void *a3, const void *a4, int a5, unsigned __int8 a6)
{
  int v10; // r0
  int v11; // r7
  int v12; // r0
  int v13; // r6
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v17; // r10
  unsigned int *v18; // r2
  unsigned int v19; // r1
  const void *v20; // [sp+8h] [bp-30h] BYREF
  const void *v21; // [sp+Ch] [bp-2Ch] BYREF
  int v22; // [sp+10h] [bp-28h] BYREF
  int (__fastcall *v23)(int, int, const void *, const void *, int, _DWORD); // [sp+14h] [bp-24h]

  v23 = (int (__fastcall *)(int, int, const void *, const void *, int, _DWORD))ViGetRealDmaOperation(a1, 20);
  v10 = ViGetAdapterInformationInternal(a1, 1);
  v11 = v10;
  if ( !v10 )
  {
LABEL_4:
    v12 = v23(a1, a2, a3, a4, a5, a6);
    v13 = v12;
    if ( v11 && v12 )
    {
      __dmb(0xBu);
      v14 = (unsigned int *)(v11 + 116);
      do
        v15 = __ldrex(v14);
      while ( __strex(0, v14) );
LABEL_8:
      __dmb(0xBu);
      return v13;
    }
    return v13;
  }
  VF_ASSERT_MAX_IRQL(v10);
  if ( a3 == (const void *)-559026163 )
  {
    a3 = 0;
    goto LABEL_4;
  }
  v17 = ViGetMapRegisterFile(a3);
  if ( !v17 )
    goto LABEL_4;
  v21 = a3;
  v22 = a2;
  v20 = a4;
  if ( ViSwap(&v21, &v22, &v20) )
  {
    v13 = v23(a1, v22, v21, v20, a5, a6);
    ViFlushDoubleBuffer(v17, a2, a4, a5, a6);
    if ( !v13 )
      return v13;
    __dmb(0xBu);
    v18 = (unsigned int *)(v11 + 116);
    do
      v19 = __ldrex(v18);
    while ( __strex(0, v18) );
    goto LABEL_8;
  }
  if ( a5 )
  {
    ViHalPreprocessOptions(
      &dword_6187A8,
      "Cannot flush map register that isn't mapped! (Map register base %p, flushing address %p, MDL %p)",
      (const void *)0x20,
      a3,
      a4);
    VfReportIssueWithOptions(230, 32, (int)a3, (int)a4, a2, &dword_6187A8);
  }
  return 0;
}
