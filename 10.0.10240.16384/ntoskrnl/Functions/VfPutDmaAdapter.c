// VfPutDmaAdapter 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall VfPutDmaAdapter(int a1)
{
  int result; // r0
  int (__fastcall *v3)(int, _DWORD); // r8
  int v4; // r10
  unsigned int v5; // r1
  int i; // r5
  unsigned int *v7; // r2
  unsigned int v8; // r1
  signed int v9; // r1
  int v10; // r1 OVERLAPPED
  _DWORD *v11; // r2 OVERLAPPED
  __int64 v12; // r0
  int vars4; // [sp+2Ch] [bp+4h]

  VF_ASSERT_MAX_IRQL(a1);
  result = ViGetRealDmaOperation(a1, 4);
  v3 = (int (__fastcall *)(int, _DWORD))result;
  if ( result )
  {
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&dword_908C58);
    }
    else
    {
      do
        v5 = __ldrex((unsigned int *)&dword_908C58);
      while ( __strex(1u, (unsigned int *)&dword_908C58) );
      __dmb(0xBu);
      if ( v5 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&dword_908C58);
    }
    for ( i = ViAdapterList; ; i = *(_DWORD *)i )
    {
      if ( &ViAdapterList == (int *)i )
        goto LABEL_34;
      if ( a1 == *(_DWORD *)(i + 8) )
        break;
    }
    __dmb(0xBu);
    v7 = (unsigned int *)(i + 20);
    do
    {
      v8 = __ldrex(v7);
      v9 = v8 - 1;
    }
    while ( __strex(v9, v7) );
    __dmb(0xBu);
    if ( v9 < 0 )
    {
      ViHalPreprocessOptions(
        &dword_6187C0,
        "Driver has attempted to access an adapter (%p) that has already been released.",
        (const void *)0x18);
      VfReportIssueWithOptions(230, 24, a1, i, 0, &dword_6187C0);
    }
    ViFlushZeroMapRegisterBaseWcbs(i);
    if ( *(_DWORD *)(i + 108) != *(_DWORD *)(i + 112) )
    {
      ViHalPreprocessOptions(
        &dword_6187B8,
        "Cannot put adapter %p until all adapter channels are freed (%x left).",
        (const void *)8,
        a1);
      VfReportIssueWithOptions(230, 8, a1, *(_DWORD *)(i + 108) - *(_DWORD *)(i + 112), i, &dword_6187B8);
    }
    if ( *(_DWORD *)(i + 100) != *(_DWORD *)(i + 104) )
    {
      ViHalPreprocessOptions(
        &dword_6187BC,
        "Cannot put adapter %p until all common buffers are freed (%x left).",
        (const void *)7,
        a1);
      VfReportIssueWithOptions(230, 7, a1, *(_DWORD *)(i + 100) - *(_DWORD *)(i + 104), i, &dword_6187BC);
    }
    if ( *(_DWORD *)(i + 88) )
    {
      ViHalPreprocessOptions(
        &dword_6187B4,
        "Cannot put adapter %p until all map registers are freed (%x left).",
        (const void *)9,
        a1);
      VfReportIssueWithOptions(230, 9, a1, *(_DWORD *)(i + 88), i, &dword_6187B4);
    }
    if ( *(_DWORD *)(i + 96) )
    {
      ViHalPreprocessOptions(
        &dword_6187B0,
        "Cannot put adapter %p until all scatter gather lists are freed (%x left).",
        (const void *)0xA,
        a1);
      VfReportIssueWithOptions(230, 10, a1, *(_DWORD *)(i + 96), i, &dword_6187B0);
    }
    if ( !*(_DWORD *)(i + 12) )
    {
      *(_QWORD *)&v10 = *(_QWORD *)i;
      if ( *(_DWORD *)(*(_DWORD *)i + 4) != i || *v11 != i )
        __fastfail(3u);
LABEL_27:
      *v11 = v10;
      *(_DWORD *)(v10 + 4) = v11;
      goto LABEL_34;
    }
    if ( *(_BYTE *)(i + 18) )
    {
      *(_QWORD *)&v10 = *(_QWORD *)i;
      if ( *(_DWORD *)(*(_DWORD *)i + 4) != i || *v11 != i )
        __fastfail(3u);
      goto LABEL_27;
    }
    i = 0;
LABEL_34:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&dword_908C58, vars4);
    }
    else
    {
      __dmb(0xBu);
      dword_908C58 = 0;
    }
    v12 = KfLowerIrql(v4);
    if ( i )
      ViReleaseDmaAdapter(i, HIDWORD(v12));
    result = v3(a1, HIDWORD(v12));
  }
  return result;
}
