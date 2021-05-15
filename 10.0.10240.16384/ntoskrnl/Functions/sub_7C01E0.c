// sub_7C01E0 
 
void sub_7C01E0()
{
  int v0; // r4
  unsigned int v1; // r5
  int v2; // r6
  unsigned int v3; // r3
  unsigned int v4; // r2
  _DWORD *v5; // r0
  int v6; // r0
  unsigned int v7; // r1
  int v8; // r3

  v3 = v1 >> 2;
  if ( v1 >> 2 <= 0xFFFF && v3 + 49152 >= v3 && v3 + 49152 <= 0xFFFF )
  {
    *(_WORD *)(v0 + 4) = v3;
    *(_WORD *)(v0 + 6) = v3 - 0x4000;
    JUMPOUT(0x6A6236);
  }
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = ExMapHandleToPointer(*(_DWORD *)(v2 + 12), v1);
  v6 = ExDestroyHandle(*(_DWORD *)(v2 + 12), v1, v5);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = (__int16)(*(_WORD *)(v7 + 0x134) + 1);
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v6);
  JUMPOUT(0x6A6234);
}
