// sub_5482FC 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_5482FC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  int v14; // r4
  int v15; // r6
  int v16; // r9
  int v17; // r10
  int v18; // r8
  unsigned int *v19; // r2
  unsigned int v20; // r1
  int v21; // r1 OVERLAPPED
  _DWORD *v22; // r2 OVERLAPPED

  v18 = KfRaiseIrql(2);
  if ( (*(_DWORD *)(v16 + 4) & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v15 + 160);
  }
  else
  {
    v19 = (unsigned int *)(v15 + 160);
    do
      v20 = __ldrex(v19);
    while ( __strex(1u, v19) );
    __dmb(0xBu);
    if ( v20 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(v15 + 160));
  }
  if ( *(_DWORD *)(v14 + 816) != 1 && *(_DWORD *)(v14 + 820) )
  {
    *(_QWORD *)&v21 = *(_QWORD *)(v14 + 816);
    if ( *(_DWORD *)(v21 + 4) != v14 + 816 || *v22 != v14 + 816 )
      __fastfail(3u);
    *v22 = v21;
    *(_DWORD *)(v21 + 4) = v22;
  }
  if ( (*(_DWORD *)(v16 + 4) & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)(v15 + 160), a14);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(v15 + 160) = v17;
  }
  KfLowerIrql(v18);
  JUMPOUT(0x4C7A38);
}
