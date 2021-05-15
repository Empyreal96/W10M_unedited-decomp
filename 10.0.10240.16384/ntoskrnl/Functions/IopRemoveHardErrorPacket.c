// IopRemoveHardErrorPacket 
 
// local variable allocation has failed, the output may be wrong!
int IopRemoveHardErrorPacket()
{
  int v0; // r7
  unsigned int v1; // r1
  int v2; // r5
  int v3; // r1 OVERLAPPED
  int vars4; // [sp+14h] [bp+4h]

  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_631A38);
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&dword_631A38);
    while ( __strex(1u, (unsigned int *)&dword_631A38) );
    __dmb(0xBu);
    if ( v1 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_631A38);
  }
  v2 = dword_631A30;
  *(_QWORD *)&v3 = *(_QWORD *)dword_631A30;
  if ( *(int **)(dword_631A30 + 4) != &dword_631A30 || *(_DWORD *)(v3 + 4) != dword_631A30 )
    __fastfail(3u);
  dword_631A30 = v3;
  *(_DWORD *)(v3 + 4) = &dword_631A30;
  IopCurrentHardError = v2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_631A38, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_631A38 = 0;
  }
  KfLowerIrql(v0);
  return v2;
}
