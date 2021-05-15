// PsInsertSiloObjectByPointer 
 
int __fastcall PsInsertSiloObjectByPointer(int a1, int a2, int a3)
{
  int v6; // r5
  int v7; // r0
  _DWORD *v8; // r4
  int v9; // r2
  int v10; // r3
  _DWORD *v11; // r1
  _DWORD *v12; // r2
  _DWORD *v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v6 = 0;
  v7 = ExAllocatePoolWithTag(1, 16, 1869375827);
  v8 = (_DWORD *)v7;
  if ( !v7 )
    return -1073741670;
  *(_DWORD *)(v7 + 8) = a2;
  *(_DWORD *)(v7 + 12) = a3;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(__int16 *)(v9 + 0x136) - 1;
  *(_WORD *)(v9 + 310) = v10;
  ExAcquireResourceExclusiveLite(a1 + 28, 1, v9, v10);
  v11 = *(_DWORD **)(a1 + 120);
  v12 = (_DWORD *)(a1 + 120);
  while ( v11 != v12 )
  {
    if ( a2 == v11[2] )
    {
      v6 = -1073741771;
      ExFreePoolWithTag((unsigned int)v8);
      goto LABEL_11;
    }
    v11 = (_DWORD *)*v11;
  }
  v13 = *(_DWORD **)(a1 + 124);
  *v8 = v12;
  v8[1] = v13;
  if ( (_DWORD *)*v13 != v12 )
    __fastfail(3u);
  *v13 = v8;
  *(_DWORD *)(a1 + 124) = v8;
LABEL_11:
  v14 = ExReleaseResourceLite(a1 + 28);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x136) + 1;
  *(_WORD *)(v15 + 310) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 )
    KiCheckForKernelApcDelivery(v14);
  return v6;
}
