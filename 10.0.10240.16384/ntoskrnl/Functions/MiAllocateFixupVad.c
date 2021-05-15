// MiAllocateFixupVad 
 
_DWORD *__fastcall MiAllocateFixupVad(int a1)
{
  int v2; // r5
  int v3; // r0
  int v4; // r0
  _DWORD *v5; // r4

  v2 = **(_DWORD **)(a1 + 44);
  if ( !**(_DWORD **)(v2 + 56) )
    return 0;
  v3 = MiBytesForFixupVad(**(_DWORD **)(a1 + 44));
  v4 = ExAllocatePoolWithTag(512, v3, 1231315286);
  v5 = (_DWORD *)v4;
  if ( !v4 )
    return 0;
  memmove(v4, a1, 0x4Cu);
  v5[19] = ((*(_DWORD *)(a1 + 12) - ((*(_DWORD *)(a1 + 48) - *(_DWORD *)(v2 + 84)) >> 2)) << 12)
         - *(_DWORD *)(*(_DWORD *)v2 + 24);
  v5[8] = v5[8] & 0x80000000 | MiInitializePrivateFixupBitmap(v5 + 20, v2) & 0x7FFFFFFF;
  v5[7] |= 0x20000u;
  return v5;
}
