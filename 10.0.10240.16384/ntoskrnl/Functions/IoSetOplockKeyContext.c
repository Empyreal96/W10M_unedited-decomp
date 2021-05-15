// IoSetOplockKeyContext 
 
int __fastcall IoSetOplockKeyContext(int a1, int a2, int a3, int *a4)
{
  int v6; // r4
  _BYTE *v7; // r0
  unsigned int v8; // r6
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r4
  int *v19[6]; // [sp+0h] [bp-18h] BYREF

  v19[1] = a4;
  v19[0] = 0;
  if ( a3 != 1 && a3 != 2 )
    return -1073741811;
  if ( *(_DWORD *)(a1 + 124) )
  {
    IopGetFileObjectExtension(a1, 6, v19);
  }
  else
  {
    v6 = IopAllocateFileObjectExtension(a1, v19);
    if ( v6 < 0 )
      return v6;
  }
  v7 = (_BYTE *)ExAllocateFromNPagedLookasideList((int)&IopOplockFoExtLookasideList);
  v8 = (unsigned int)v7;
  if ( !v7 )
    return -1073741670;
  memset(v7, 0, 44);
  *(_WORD *)v8 = a3;
  if ( a3 == 1 )
  {
    v15 = *(_DWORD *)(a2 + 4);
    v16 = *(_DWORD *)(a2 + 8);
    v17 = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v8 + 20) = *(_DWORD *)a2;
    *(_DWORD *)(v8 + 24) = v15;
    *(_DWORD *)(v8 + 28) = v16;
    *(_DWORD *)(v8 + 32) = v17;
  }
  else
  {
    if ( a3 != 2 )
      goto LABEL_18;
    if ( *(_BYTE *)(a2 + 32) )
    {
      v9 = *(_DWORD *)(a2 + 4);
      v10 = *(_DWORD *)(a2 + 8);
      v11 = *(_DWORD *)(a2 + 12);
      *(_DWORD *)(v8 + 4) = *(_DWORD *)a2;
      *(_DWORD *)(v8 + 8) = v9;
      *(_DWORD *)(v8 + 12) = v10;
      *(_DWORD *)(v8 + 16) = v11;
      *(_WORD *)(v8 + 2) |= 1u;
    }
    if ( !*(_BYTE *)(a2 + 33) )
      goto LABEL_18;
    v12 = *(_DWORD *)(a2 + 20);
    v13 = *(_DWORD *)(a2 + 24);
    v14 = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(v8 + 20) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(v8 + 24) = v12;
    *(_DWORD *)(v8 + 28) = v13;
    *(_DWORD *)(v8 + 32) = v14;
  }
  *(_WORD *)(v8 + 2) |= 2u;
LABEL_18:
  v6 = IopSetTypeSpecificFoExtension((int)v19[0], 6u, v8);
  if ( v6 == -1073741823 )
    ExFreeToNPagedLookasideList((int)&IopOplockFoExtLookasideList, (_DWORD *)v8);
  return v6;
}
