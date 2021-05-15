// PipAllocateDeviceNode 
 
int __fastcall PipAllocateDeviceNode(int a1, int *a2)
{
  int v4; // r0
  unsigned int v6; // r0
  int v7; // r3
  _DWORD *v8; // r3
  _DWORD *v9; // r3
  _DWORD *v10; // r3
  _DWORD *v11; // r3
  _DWORD *v12; // r3
  _DWORD *v13; // r3
  _DWORD *v14; // r3
  _DWORD *v15; // r3

  v4 = ExAllocatePoolWithTag(512, 460, 1685024324);
  *a2 = v4;
  if ( !v4 )
    return sub_7CBF88();
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&IopNumberDeviceNodes);
  while ( __strex(v6 + 1, (unsigned int *)&IopNumberDeviceNodes) );
  __dmb(0xBu);
  memset((_BYTE *)*a2, 0, 460);
  *(_DWORD *)(*a2 + 300) = -1;
  *(_DWORD *)(*a2 + 304) = -1;
  *(_DWORD *)(*a2 + 308) = -1;
  *(_DWORD *)(*a2 + 312) = -1;
  *(_WORD *)(*a2 + 316) = -1;
  *(_DWORD *)(*a2 + 172) = 769;
  *(_DWORD *)(*a2 + 388) = 0;
  *(_DWORD *)(*a2 + 408) = 0;
  *(_DWORD *)(*a2 + 412) = 0;
  *(_DWORD *)(*a2 + 416) = 0;
  *(_DWORD *)(*a2 + 420) = -1;
  v7 = *a2;
  *(_BYTE *)(v7 + 318) = 0;
  *(_BYTE *)(v7 + 319) = 0;
  v8 = (_DWORD *)(*a2 + 328);
  *v8 = v8;
  v8[1] = v8;
  v9 = (_DWORD *)(*a2 + 336);
  *v9 = v9;
  v9[1] = v9;
  if ( a1 )
  {
    *(_DWORD *)(*a2 + 16) = a1;
    *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) = *a2;
    *(_DWORD *)(a1 + 28) &= 0xFFFFFF7F;
  }
  v10 = (_DWORD *)(*a2 + 320);
  *v10 = v10;
  v10[1] = v10;
  v11 = (_DWORD *)(*a2 + 376);
  *v11 = v11;
  v11[1] = v11;
  v12 = (_DWORD *)(*a2 + 392);
  *v12 = v12;
  v12[1] = v12;
  v13 = (_DWORD *)(*a2 + 400);
  *v13 = v13;
  v13[1] = v13;
  v14 = (_DWORD *)(*a2 + 92);
  *v14 = v14;
  v14[1] = v14;
  v15 = (_DWORD *)(*a2 + 100);
  *v15 = v15;
  v15[1] = v15;
  return 0;
}
