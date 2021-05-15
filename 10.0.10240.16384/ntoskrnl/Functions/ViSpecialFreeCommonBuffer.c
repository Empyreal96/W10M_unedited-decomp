// ViSpecialFreeCommonBuffer 
 
int __fastcall ViSpecialFreeCommonBuffer(void (__fastcall *a1)(_DWORD, _DWORD, _DWORD, _DWORD), int a2, _BYTE *a3)
{
  int *v6; // r0
  unsigned int v7; // r5
  unsigned int *v9; // r4
  unsigned int v10; // r2
  __int64 v11; // r0
  int v12; // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  v6 = (int *)VF_FIND_BUFFER((_DWORD **)(a2 + 44), (int)a3);
  v7 = (unsigned int)v6;
  if ( !v6 )
    return 0;
  ViCheckPadding(v6[3], v6[1], v6[4], v6[2]);
  v9 = (unsigned int *)(a2 + 52);
  v12 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a2 + 52);
  }
  else
  {
    do
      v10 = __ldrex(v9);
    while ( __strex(1u, v9) );
    __dmb(0xBu);
    if ( v10 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(a2 + 52));
  }
  v11 = *(_QWORD *)(v7 + 36);
  if ( *(_DWORD *)(v11 + 4) != v7 + 36 || *(_DWORD *)HIDWORD(v11) != v7 + 36 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v11) = v11;
  *(_DWORD *)(v11 + 4) = HIDWORD(v11);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)(a2 + 52), vars4);
  }
  else
  {
    __dmb(0xBu);
    *v9 = 0;
  }
  KfLowerIrql(v12);
  memset(a3, 0, *(_DWORD *)(v7 + 8));
  a1(*(_DWORD *)(a2 + 8), *(_DWORD *)(v7 + 4), *(_DWORD *)(v7 + 24), *(_DWORD *)(v7 + 28));
  DECREMENT_COMMON_BUFFERS(a2);
  ExFreePoolWithTag(v7);
  return 1;
}
