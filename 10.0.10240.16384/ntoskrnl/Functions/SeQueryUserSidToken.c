// SeQueryUserSidToken 
 
int __fastcall SeQueryUserSidToken(int a1, int a2, unsigned int a3, unsigned int *a4)
{
  int v4; // r8
  unsigned int v9; // r5
  int v10; // r2
  unsigned int v11; // r4
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v4 = -1073741789;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 48), 1);
  v10 = **(_DWORD **)(a1 + 148);
  v11 = 4 * (*(unsigned __int8 *)(v10 + 1) + 2);
  if ( a3 >= v11 )
  {
    RtlCopySid(4 * (*(unsigned __int8 *)(v10 + 1) + 2), a2, v10);
    v4 = 0;
  }
  v12 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( a4 )
    *a4 = v11;
  return v4;
}
