// RtlQueryAtomsInAtomTable 
 
int __fastcall RtlQueryAtomsInAtomTable(_DWORD *a1, unsigned int a2, unsigned int *a3, int a4)
{
  int v6; // r4
  unsigned int v7; // r5
  unsigned int i; // r8
  int j; // r6
  unsigned int *v10; // r5
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  if ( !RtlpLockAtomTable(a1) )
    return -1073741811;
  v6 = 0;
  v7 = 0;
  for ( i = 0; i < a1[5]; ++i )
  {
    for ( j = a1[i + 6]; j; j = *(_DWORD *)j )
    {
      if ( RtlpLookupLowBox((int)a1, j) )
      {
        if ( v7 >= a2 )
          v6 = -1073741820;
        else
          *(_WORD *)(a4 + 2 * v7) = *(_WORD *)(j + 6);
        ++v7;
      }
    }
  }
  *a3 = v7;
  v10 = a1 + 2;
  __dmb(0xBu);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 - 1, v10) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 2);
  v12 = KeAbPostRelease((unsigned int)(a1 + 2));
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return v6;
}
