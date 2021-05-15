// sub_50C48C 
 
void sub_50C48C()
{
  int v0; // r7
  int v1; // r8
  int v2; // r9
  _BYTE *v3; // r0
  _BYTE *v4; // r10
  unsigned int *v5; // r4
  unsigned int v6; // r2

  v3 = (_BYTE *)ExAllocatePoolWithTag(512, 56);
  v4 = v3;
  if ( v3 )
  {
    memset(v3, 0, 56);
    RtlCaptureStackBackTrace(1u, 0xAu, (int)(v4 + 8), 0);
    *((_DWORD *)v4 + 12) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *((_DWORD *)v4 + 13) = v2;
  }
  v5 = (unsigned int *)(v1 + 1020);
  KfRaiseIrql(2);
  if ( (*(_DWORD *)(v0 + 1960) & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v1 + 1020);
  }
  else
  {
    do
      v6 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(v1 + 1020));
  }
  JUMPOUT(0x47C04E);
}
