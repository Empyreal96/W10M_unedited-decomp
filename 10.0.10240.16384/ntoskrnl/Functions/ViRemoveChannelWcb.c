// ViRemoveChannelWcb 
 
int __fastcall ViRemoveChannelWcb(int a1, int a2, int a3)
{
  int v6; // r9
  unsigned int *v7; // r5
  unsigned int v8; // r2
  int i; // r3
  int v10; // r3
  int v11; // r4
  __int64 v12; // r0
  int v14; // [sp+0h] [bp-20h]
  int vars4; // [sp+24h] [bp+4h]

  v6 = 0;
  if ( a2 && a3 )
    return 0;
  v7 = (unsigned int *)(a1 + 76);
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 76);
  }
  else
  {
    do
      v8 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 76));
  }
  for ( i = *(_DWORD *)(a1 + 68); ; i = *(_DWORD *)(v11 + 40) )
  {
    v11 = i - 40;
    if ( a1 + 68 == i )
      break;
    if ( (!a2 || *(_DWORD *)(i + 12) != a2 && *(_DWORD *)(i + 8) != a2) && (!a3 || *(_DWORD *)(i - 20) != a3) )
    {
      v10 = *(_DWORD *)(i - 12);
      if ( v10 != 1 )
      {
        if ( v10 )
          continue;
      }
    }
    v12 = *(_QWORD *)(v11 + 40);
    if ( *(_DWORD *)(v12 + 4) != v11 + 40 || *(_DWORD *)HIDWORD(v12) != v11 + 40 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v12) = v12;
    *(_DWORD *)(v12 + 4) = HIDWORD(v12);
    v6 = 1;
    break;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)(a1 + 76), vars4);
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0;
  }
  KfLowerIrql(v14);
  if ( v6 != 1 )
    return 0;
  return v11;
}
