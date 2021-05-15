// ExpAllocatePoolForNode 
 
_DWORD *__fastcall ExpAllocatePoolForNode(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r2
  _DWORD *v8; // r4
  int v9; // r5
  _BYTE *v10; // r0
  _DWORD *v11; // r4
  int v12; // r2
  int v14[6]; // [sp+0h] [bp-18h] BYREF

  v14[0] = a4;
  v4 = a2 + 96;
  v7 = (unsigned __int8)*(_DWORD *)(a1 + 4 * (a2 + 96)) >> 1;
  v8 = *(&KeNodeBlock + v7);
  if ( v8 == (_DWORD *)((char *)&KiNodeInit + 384 * v7) )
    v8 = 0;
  v9 = v8[v4];
  if ( (v9 & 1) != 0 )
    v9 = 0;
  v10 = (_BYTE *)ExAllocatePoolWithTag(512, 440, 1817671749);
  v11 = v10;
  if ( !v10 )
    return 0;
  memset(v10, 0, 440);
  v12 = v11[107];
  v11[103] = a1;
  v11[107] = v12 & 0x80000000 | *(_DWORD *)(v9 + 428) & 0x7FFFFFFF;
  v11[108] = *(_DWORD *)(v9 + 432);
  v11[109] = a2;
  KeQueryNodeActiveAffinity(*(unsigned __int16 *)(a1 + 266), 0, v14);
  KeInitializePriQueue((int)v11, LOWORD(v14[0]));
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4 * v4) = v11;
  return v11;
}
