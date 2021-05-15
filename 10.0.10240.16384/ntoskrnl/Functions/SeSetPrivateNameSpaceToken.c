// SeSetPrivateNameSpaceToken 
 
int __fastcall SeSetPrivateNameSpaceToken(int a1, int a2)
{
  int v4; // r5
  int v5; // r2
  int v6; // r3
  int v7; // r3
  unsigned int v8; // r3
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(__int16 *)(v5 + 0x134) - 1;
  *(_WORD *)(v5 + 308) = v6;
  ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 48), 1, v5, v6);
  __dmb(0xFu);
  if ( *(_BYTE *)(a1 + 180) )
  {
    v4 = -1073741525;
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 176);
    if ( a2 )
      v8 = v7 | 0x10000;
    else
      v8 = v7 & 0xFFFEFFFF;
    *(_DWORD *)(a1 + 176) = v8;
  }
  ExAllocateLocallyUniqueId((int *)(a1 + 52));
  __dmb(0xFu);
  v9 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v4;
}
