// PsSetCurrentThreadPrefetching 
 
unsigned int __fastcall PsSetCurrentThreadPrefetching(char a1)
{
  unsigned int v1; // r1
  char v2; // r2
  unsigned int v3; // r4
  __int16 v4; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 310);
  v2 = *(_BYTE *)(v1 + 0x3C8);
  *(_BYTE *)(v1 + 968) = (v2 ^ (a1 << 6)) & 0x40 ^ v2;
  v3 = v2 & 0x40;
  v4 = *(_WORD *)(v1 + 0x136) + 1;
  *(_WORD *)(v1 + 310) = v4;
  if ( !v4 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    KiCheckForKernelApcDelivery(a1);
  return v3 >> 6;
}
