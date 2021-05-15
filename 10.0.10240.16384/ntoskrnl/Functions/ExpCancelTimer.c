// ExpCancelTimer 
 
int __fastcall ExpCancelTimer(int a1)
{
  int v1; // r5
  unsigned int *v4; // r6
  unsigned int v5; // r2
  __int64 v6; // r0
  char v7; // r3

  v1 = 0;
  if ( (*(_BYTE *)(a1 + 144) & 1) == 0 )
  {
    KeCancelTimer(a1);
LABEL_3:
    *(_BYTE *)(a1 + 145) = 0;
    return v1;
  }
  v4 = (unsigned int *)(*(_DWORD *)(a1 + 60) + 864);
  if ( (dword_682604 & 0x210000) == 0 )
  {
    do
      v5 = __ldrex(v4);
    while ( __strex(1u, v4) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire(v4);
    v6 = *(_QWORD *)(a1 + 132);
    if ( *(_DWORD *)(v6 + 4) != a1 + 132 || *(_DWORD *)HIDWORD(v6) != a1 + 132 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v6) = v6;
    *(_DWORD *)(v6 + 4) = HIDWORD(v6);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    v7 = *(_BYTE *)(a1 + 144) & 0xFE;
    *(_BYTE *)(a1 + 144) = v7;
    if ( (v7 & 2) != 0 && *(_BYTE *)(a1 + 145) || KeCancelTimer(a1) || KeRemoveQueueDpcEx(a1 + 100, 0) )
      v1 = 1;
    if ( KeRemoveQueueApc(a1 + 52) )
      ++v1;
    goto LABEL_3;
  }
  return sub_53F9E0();
}
