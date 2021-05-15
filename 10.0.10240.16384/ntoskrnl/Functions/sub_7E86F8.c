// sub_7E86F8 
 
void __fastcall sub_7E86F8(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  int v8; // r0
  __int16 v9; // r3

  __dmb(0xBu);
  v8 = ExReleaseResourceLite(a6 + 32);
  if ( v6 )
  {
    v9 = *(_WORD *)(v6 + 310) + 1;
    *(_WORD *)(v6 + 310) = v9;
    if ( !v9 && *(_DWORD *)(v6 + 100) != v6 + 100 )
      KiCheckForKernelApcDelivery(v8);
  }
  __dmb(0xBu);
  __dmb(0xBu);
  __dmb(0xBu);
  __dmb(0xBu);
  if ( v6 )
    --*(_WORD *)(v6 + 310);
  JUMPOUT(0x6FC594);
}
