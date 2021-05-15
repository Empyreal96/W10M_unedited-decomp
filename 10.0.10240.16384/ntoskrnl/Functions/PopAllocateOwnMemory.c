// PopAllocateOwnMemory 
 
const void *__fastcall PopAllocateOwnMemory(int a1, unsigned int a2)
{
  int v3; // r6
  const void *v4; // r0
  const void *v5; // r4

  v3 = ((a2 & 0xFFF) != 0) + (a2 >> 12);
  v4 = (const void *)PopAllocatePages(v3);
  v5 = v4;
  if ( v4 )
    PoSetHiberRange(a1, 0x8000, v4, (const void *)(v3 << 12), 1131179886);
  else
    *(_DWORD *)(a1 + 120) = -1073741670;
  return v5;
}
