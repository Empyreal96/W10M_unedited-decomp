// KsepIsModuleShimmed 
 
int __fastcall KsepIsModuleShimmed(int a1, int a2, _DWORD *a3)
{
  int v3; // r6
  unsigned int v7; // r4
  int v8; // r0
  unsigned int v9; // r1
  _DWORD *v11; // r2
  unsigned int v12; // r0
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  _DWORD *v16; // r0
  int v17; // r3

  v3 = 0;
  if ( !a2 || !a1 || !a3 )
    return 0;
  *a3 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire((unsigned int)dword_6416EC, 0, 0);
  do
    v9 = __ldrex((unsigned __int8 *)dword_6416EC);
  while ( __strex(v9 | 1, (unsigned __int8 *)dword_6416EC) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    return sub_7CD344(v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v11 = *(_DWORD **)(a1 + 20);
  while ( v11 != (_DWORD *)(a1 + 20) )
  {
    v16 = v11;
    v17 = v11[2];
    v11 = (_DWORD *)*v11;
    if ( v17 == a2 )
    {
      *a3 = v16;
      v3 = 1;
      break;
    }
  }
  __dmb(0xBu);
  do
    v12 = __ldrex(dword_6416EC);
  while ( __strex(v12 - 1, dword_6416EC) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock(dword_6416EC);
  v13 = KeAbPostRelease((unsigned int)dword_6416EC);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v3;
}
