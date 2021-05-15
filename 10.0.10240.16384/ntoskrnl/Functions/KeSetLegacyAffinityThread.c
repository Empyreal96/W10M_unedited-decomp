// KeSetLegacyAffinityThread 
 
int __fastcall KeSetLegacyAffinityThread(int a1, int a2)
{
  int v3; // r8
  int v4; // r6
  unsigned int v6; // r10
  unsigned int *v7; // r4
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r1
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r2
  int v15; // [sp+0h] [bp-38h] BYREF
  int v16; // [sp+4h] [bp-34h]
  int v17; // [sp+8h] [bp-30h] BYREF
  int v18; // [sp+Ch] [bp-2Ch]
  int v19; // [sp+10h] [bp-28h]

  v3 = *(_DWORD *)(a1 + 336);
  v4 = 0;
  if ( a2 )
  {
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v15 = 0;
    v16 = KfRaiseIrql(2);
    v6 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v7 = (unsigned int *)(v3 + 48);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_51BB1C();
    v9 = *v7 & 0x7FFFFFFF;
    do
      v10 = __ldrex(v7);
    while ( v10 == v9 && __strex(v9 + 1, v7) );
    __dmb(0xBu);
    if ( v10 != v9 )
      ExpWaitForSpinLockSharedAndAcquire(v3 + 48, v10);
    v11 = *(unsigned __int16 *)(a1 + 344);
    v12 = dword_681D78[v11];
    LOWORD(v18) = *(_WORD *)(a1 + 344);
    if ( (v12 & a2) != 0 && (*(_DWORD *)(v3 + 4 * v11 + 72) & v12 & a2) == (v12 & a2) )
    {
      v17 = v12 & a2;
      v4 = *(_DWORD *)(a1 + 340);
      KiSetAffinityThread(a1, &v15, &v17);
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v3 + 48);
    }
    else
    {
      __dmb(0xBu);
      do
        v13 = __ldrex(v7);
      while ( __strex(v13 & 0xBFFFFFFF, v7) );
      __dmb(0xBu);
      do
        v14 = __ldrex(v7);
      while ( __strex(v14 - 1, v7) );
    }
    KiProcessDeferredReadyList(v6 + 1408, &v15, v16);
  }
  return v4;
}
