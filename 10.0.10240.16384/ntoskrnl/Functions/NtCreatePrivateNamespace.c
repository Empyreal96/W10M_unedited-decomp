// NtCreatePrivateNamespace 
 
int __fastcall NtCreatePrivateNamespace(unsigned int a1, int a2, int a3, int a4)
{
  char v6; // r5
  _DWORD *v7; // r4
  int v8; // r4
  _BYTE *v9; // r6
  unsigned int v10; // r3
  int v11; // r8
  int v12; // r2
  _DWORD *v13; // r8
  unsigned int v14; // r5
  int v15; // r3
  unsigned int v16; // r2
  int v17; // r10
  int v18; // r1
  int v19; // r1
  _DWORD *v20; // r2
  int v21; // r0
  unsigned int v22; // r5
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int v27; // [sp+0h] [bp-48h]
  _DWORD *v28; // [sp+1Ch] [bp-2Ch]
  _BYTE *v29; // [sp+24h] [bp-24h] BYREF
  _DWORD _28[14]; // [sp+28h] [bp-20h] BYREF

  _28[13] = a4;
  _28[12] = a3;
  _28[11] = a2;
  v28 = (_DWORD *)a1;
  _28[10] = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 )
  {
    v7 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    *v7 = *v7;
  }
  v8 = ObpCaptureBoundaryDescriptor(a4, &v29);
  if ( v8 >= 0 )
  {
    v9 = v29;
    v8 = ObpVerifyCreatorAccessCheck(v29 + 24);
    if ( v8 < 0 )
    {
LABEL_10:
      ExFreePoolWithTag((unsigned int)v9);
      return v8;
    }
    v10 = *((_DWORD *)v9 + 3);
    v11 = v10 + 200;
    if ( v10 + 200 < v10 )
    {
      v8 = -1073741811;
      goto LABEL_10;
    }
    v8 = ObCreateObjectEx(v6, (_DWORD *)ObpDirectoryObjectType, a3, v6, v27, v10 + 200, 0, 0, &v29, 0);
    if ( v8 < 0 )
      goto LABEL_10;
    v12 = v11;
    v13 = v29;
    memset(v29, 0, v12);
    v14 = ((unsigned int)v13 + 179) & 0xFFFFFFF8;
    *(_DWORD *)(v14 + 4) = v14;
    *(_DWORD *)v14 = v14;
    *(_DWORD *)(v14 + 12) = *((_DWORD *)v9 + 3);
    *(_DWORD *)(v14 + 8) = 0;
    *(_BYTE *)(v14 + 20) = v9[20];
    memmove(v14 + 24, (int)(v9 + 24), *(_DWORD *)(v14 + 12));
    ExFreePoolWithTag((unsigned int)v9);
    v13[37] = 0;
    v13[40] = -1;
    v13[42] = 1;
    if ( (*((_BYTE *)v13 - 10) & 2) != 0 )
      v15 = (int)v13 - ObpInfoMaskToOffset[*((_BYTE *)v13 - 10) & 3] - 24;
    else
      v15 = 0;
    if ( v15 )
    {
      v8 = -1073741773;
LABEL_17:
      ObfDereferenceObject((int)v13);
      return v8;
    }
    v8 = ObpRegisterPrivateNamespace(((unsigned int)v13 + 179) & 0xFFFFFFF8);
    if ( v8 < 0 )
      goto LABEL_17;
    ObfReferenceObject((int)v13);
    v8 = ObInsertObject((int)v13, 0, a2, 0, 0, (int)_28);
    v29 = (_BYTE *)v8;
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v16 + 308);
    v17 = KeAbPreAcquire((unsigned int)&dword_620C08, 0, 0);
    do
      v18 = __ldrex((unsigned __int8 *)&dword_620C08);
    while ( __strex(v18 | 1, (unsigned __int8 *)&dword_620C08) );
    __dmb(0xBu);
    if ( (v18 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_620C08, v17, (unsigned int)&dword_620C08);
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    if ( v8 >= 0 )
    {
      if ( (v13[42] & 2) == 0 )
      {
        *(_DWORD *)(v14 + 8) = v13;
        v13[41] = v14;
LABEL_33:
        __pld(&dword_620C08);
        v21 = dword_620C08;
        if ( (dword_620C08 & 0xFFFFFFF0) <= 0x10 )
          v22 = 0;
        else
          v22 = dword_620C08 - 16;
        if ( (dword_620C08 & 2) != 0 )
          goto LABEL_41;
        __dmb(0xBu);
        do
          v18 = __ldrex((unsigned int *)&dword_620C08);
        while ( v18 == v21 && __strex(v22, (unsigned int *)&dword_620C08) );
        if ( v18 != v21 )
LABEL_41:
          ExfReleasePushLock(&dword_620C08, v18);
        v23 = KeAbPostRelease((unsigned int)&dword_620C08);
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v25 = *(_WORD *)(v24 + 0x134) + 1;
        *(_WORD *)(v24 + 308) = v25;
        if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
          KiCheckForKernelApcDelivery(v23);
        if ( v8 >= 0 )
          *v28 = _28[0];
        return v8;
      }
      v19 = *(_DWORD *)v14;
      v20 = *(_DWORD **)(v14 + 4);
      if ( *(_DWORD *)(*(_DWORD *)v14 + 4) != v14 || *v20 != v14 )
        __fastfail(3u);
    }
    else
    {
      v19 = *(_DWORD *)v14;
      v20 = *(_DWORD **)(v14 + 4);
      if ( *(_DWORD *)(*(_DWORD *)v14 + 4) != v14 || *v20 != v14 )
        __fastfail(3u);
    }
    *v20 = v19;
    *(_DWORD *)(v19 + 4) = v20;
    --dword_620C0C;
    ObfDereferenceObject((int)v13);
    goto LABEL_33;
  }
  return v8;
}
