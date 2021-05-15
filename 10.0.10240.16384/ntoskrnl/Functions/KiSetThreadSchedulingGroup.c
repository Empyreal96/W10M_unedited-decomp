// KiSetThreadSchedulingGroup 
 
int __fastcall KiSetThreadSchedulingGroup(int a1, int a2, int a3, int a4)
{
  int result; // r0
  unsigned int v7; // r7
  unsigned int *v8; // r6
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r4
  unsigned __int8 *v12; // r3
  unsigned int v13; // r2
  int v14; // r8
  _DWORD *v15; // r1
  int *v16; // r2
  char v17; // lr
  int v18; // [sp+0h] [bp-20h] BYREF
  int v19[7]; // [sp+4h] [bp-1Ch] BYREF

  v18 = a2;
  v19[0] = a3;
  v19[1] = a4;
  if ( !a2 )
    return KiRemoveThreadFromSchedulingGroup(a1);
  v7 = 0;
  v8 = (unsigned int *)(a1 + 44);
  do
    v9 = __ldrex(v8);
  while ( __strex(1u, v8) );
  __dmb(0xBu);
  if ( v9 )
    return sub_515774();
  v10 = KiAcquireThreadStateLock(a1, &v18, v19);
  v11 = v10;
  *(_DWORD *)(a1 + 68) = a2;
  __dmb(0xBu);
  v12 = (unsigned __int8 *)(a1 + 2);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 | 4, v12) );
  __dmb(0xBu);
  v14 = v18;
  result = KeUpdateThreadSchedulingProperties(a1, v10, v18);
  v15 = (_DWORD *)v19[0];
  if ( v11 == 1 && v19[0] && (*(_DWORD *)(a1 + 80) & 0x1000) == 0 )
  {
    v16 = *(int **)(a1 + 148);
    result = *(_DWORD *)(a1 + 144);
    v7 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v17 = *(_BYTE *)(a1 + 123);
    if ( *(_DWORD *)(result + 4) != a1 + 144 || *v16 != a1 + 144 )
      __fastfail(3u);
    *v16 = result;
    *(_DWORD *)(result + 4) = v16;
    if ( v16 == (int *)result )
      v15[1] ^= 1 << v17;
    *(_BYTE *)(a1 + 132) = 7;
  }
  if ( v14 )
  {
    __dmb(0xBu);
    *(_DWORD *)(v14 + 24) = 0;
  }
  if ( v15 )
  {
    __dmb(0xBu);
    *v15 = 0;
  }
  __dmb(0xBu);
  *v8 = 0;
  if ( v7 )
    result = KiDeferredReadyThread(v7, a1);
  return result;
}
