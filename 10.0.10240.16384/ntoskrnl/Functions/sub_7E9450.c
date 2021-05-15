// sub_7E9450 
 
int __fastcall sub_7E9450(int a1)
{
  unsigned int *v1; // r0
  int v2; // r5
  int v3; // r3
  char v5; // r7
  unsigned int v6; // r1
  int v7; // r4
  bool *v8; // r6
  int v9; // r5
  unsigned int v10; // r2
  char v11; // r3
  int (__fastcall *v12)(int); // [sp-4h] [bp-4h]

  if ( a1 >= 0 || a1 == -2 || a1 == -1 )
    v9 = *(_DWORD *)(*(_DWORD *)(v7 + 116) + 336);
  else
    v9 = ObpKernelHandleTable;
  --*(_WORD *)(v7 + 308);
  v1 = ExMapHandleToPointer(v9, a1);
  if ( v1 )
  {
    v10 = v1[1];
    v11 = *(_QWORD *)v1 & 6;
    if ( (v10 & 0x4000000) != 0 )
      v11 |= 8u;
    if ( (v10 & 0x2000000) != 0 )
      v11 |= 1u;
    v5 = v11 & 7;
    __dmb(0xBu);
    do
      v6 = __ldrex(v1);
    while ( __strex(v6 + 1, v1) );
    __dmb(0xBu);
    __dmb(0xFu);
    if ( *(_DWORD *)(v9 + 32) )
      v1 = (unsigned int *)ExfUnblockPushLock(v9 + 32, 0);
    *v8 = (v5 & 4) != 0;
    v2 = 0;
  }
  else
  {
    v2 = -1073741816;
  }
  v3 = (__int16)(*(_WORD *)(v7 + 308) + 1);
  *(_WORD *)(v7 + 308) = v3;
  if ( !v3 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery((int)v1);
  return v12(v2);
}
