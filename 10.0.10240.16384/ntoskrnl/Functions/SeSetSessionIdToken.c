// SeSetSessionIdToken 
 
int __fastcall SeSetSessionIdToken(int a1, int a2)
{
  int v4; // r5
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  _DWORD *v13; // r1

  v4 = 0;
  if ( PsIsCurrentThreadInServerSilo() )
    return sub_7DC060();
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(__int16 *)(v6 + 0x134) - 1;
  *(_WORD *)(v6 + 308) = v7;
  ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 48), 1, v6, v7);
  __dmb(0xFu);
  if ( *(_BYTE *)(a1 + 180) )
  {
    v4 = -1073741525;
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 176) & 0x4000) != 0 )
    {
      v13 = *(_DWORD **)(a1 + 628);
      if ( v13 )
      {
        SepDereferenceLowBoxNumberEntry(*(_DWORD *)(a1 + 120), v13);
        *(_DWORD *)(a1 + 628) = 0;
      }
    }
    v9 = *(_DWORD *)(a1 + 176);
    *(_DWORD *)(a1 + 120) = a2;
    if ( (v9 & 0x4000) != 0 )
      v4 = SepSetTokenLowboxNumber(a1, *(_DWORD *)(a1 + 480), v8, v9);
  }
  __dmb(0xFu);
  v10 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v4;
}
