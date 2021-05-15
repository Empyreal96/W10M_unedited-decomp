// PopMarkHiberPhase 
 
char *__fastcall PopMarkHiberPhase(int a1)
{
  const void *v2; // r2
  int *v3; // r4
  const void *v4; // r0
  char *result; // r0
  _DWORD *v6; // r4
  _DWORD *v7; // r5
  _DWORD *v8; // t1
  const void *v9; // r2

  PoSetHiberRange(0, 0x10000, (const void *)a1, (const void *)0x138, 0);
  PoSetHiberRange(0, 0x10000, *(const void **)algn_61EEDC, (const void *)dword_61EEE0, 0);
  v2 = *(const void **)(a1 + 180);
  if ( v2 )
    PoSetHiberRange(0, 0x10000, v2, *(const void **)(a1 + 184), 0);
  PoSetHiberRange(0, 0x10000, *(const void **)(a1 + 96), (const void *)(*(_DWORD *)(a1 + 100) << 12), 0);
  v3 = *(int **)(a1 + 76);
  v4 = (const void *)MmSizeOfMdl(0, v3[5]);
  PoSetHiberRange(0, 0x10000, v3, v4, 0);
  PoSetHiberRange(0, 0x10000, *(const void **)(a1 + 152), (const void *)(*(_DWORD *)(a1 + 156) << 12), 0);
  result = PoSetHiberRange(0, 0x10000, (const void *)dword_61EEB0, (const void *)dword_61EEB4, 0);
  v8 = *(_DWORD **)(a1 + 40);
  v7 = (_DWORD *)(a1 + 40);
  v6 = v8;
  while ( v6 != v7 )
  {
    v9 = v6;
    v6 = (_DWORD *)*v6;
    result = PoSetHiberRange(0, 0x10000, v9, (const void *)0x18, 0);
  }
  return result;
}
