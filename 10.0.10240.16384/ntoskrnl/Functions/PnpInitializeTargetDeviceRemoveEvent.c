// PnpInitializeTargetDeviceRemoveEvent 
 
int __fastcall PnpInitializeTargetDeviceRemoveEvent(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v16; // r8
  int v17; // r7
  _BYTE *v18; // r0
  __int64 v19; // r2
  int v20; // r5
  int result; // r0

  ObfReferenceObject(a3);
  if ( a3 )
    v16 = *(_DWORD *)(*(_DWORD *)(a3 + 176) + 20);
  else
    v16 = 0;
  v17 = *(unsigned __int16 *)(v16 + 20) >> 1;
  v18 = memset((_BYTE *)a1, 0, a2);
  LODWORD(v19) = 1;
  *(_DWORD *)(a1 + 32) = 1;
  *(_DWORD *)(a1 + 12) = a9;
  *(_DWORD *)(a1 + 8) = a8;
  *(_DWORD *)(a1 + 24) = a11;
  *(_DWORD *)(a1 + 28) = a12;
  v20 = a1 + 64;
  *(_DWORD *)(v20 + 28) = 2 * (v17 + 35);
  *(_DWORD *)(v20 + 32) = a3;
  HIDWORD(v19) = a10;
  *(_QWORD *)(v20 + 16) = v19;
  if ( a6 )
    return sub_7DF2BC(v18);
  result = -885374962;
  *(_DWORD *)v20 = -885374962;
  *(_DWORD *)(v20 + 4) = 298862320;
  *(_DWORD *)(v20 + 8) = 1610649520;
  *(_DWORD *)(v20 + 12) = 1057297303;
  if ( a5 )
    *(_DWORD *)(v20 + 24) |= 2u;
  if ( a4 )
    *(_DWORD *)(v20 + 24) |= 4u;
  if ( a7 )
    *(_DWORD *)(v20 + 24) |= 8u;
  if ( v17 )
    result = memmove(v20 + 36, *(_DWORD *)(v16 + 24), 2 * v17);
  *(_WORD *)(v20 + 2 * v17 + 36) = 0;
  return result;
}
