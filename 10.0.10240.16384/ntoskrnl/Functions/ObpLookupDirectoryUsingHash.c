// ObpLookupDirectoryUsingHash 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ObpLookupDirectoryUsingHash(int a1, int a2, int a3, int a4)
{
  int v5; // r9
  int v6; // lr
  _DWORD *v7; // r6 OVERLAPPED
  unsigned int v9; // r5
  unsigned int *v10; // r5
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  _DWORD *v14; // r4
  int v15; // r5
  int v16; // r5 OVERLAPPED
  unsigned int *v17; // r4
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  int v22; // r0
  __int16 v23; // r2
  int v24; // r0
  int result; // r0
  unsigned int *v26; // r4
  int v27; // r1
  unsigned int v28; // r0
  unsigned int v29; // r2
  int v30; // r0
  int v31; // r0
  unsigned int v32; // r1
  int v33; // r3

  v5 = *(unsigned __int8 *)(a3 + 18);
  v6 = a4;
  v7 = (_DWORD *)(a1 + 4 * *(unsigned __int16 *)(a3 + 16));
  if ( !*(_BYTE *)(a3 + 18) )
  {
    *(_DWORD *)(a3 + 20) = -1145368012;
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = (unsigned int *)(a1 + 148);
    v11 = KeAbPreAcquire(a1 + 148, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v10);
    while ( !v13 && __strex(0x11u, v10) );
    __dmb(0xBu);
    if ( v13 )
      ExfAcquirePushLockSharedEx(v10, v11, (unsigned int)v10);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    *(_DWORD *)(a3 + 20) = -572714444;
    ObfReferenceObject(a1);
    v6 = a4;
    *(_DWORD *)a3 = a1;
    *(_BYTE *)(a3 + 18) = 1;
    *(_BYTE *)(a3 + 19) = 0;
  }
  v14 = (_DWORD *)*v7;
  if ( *v7 )
  {
    v15 = *(_DWORD *)(a3 + 12);
    while ( v14[2] != v15
         || !RtlEqualUnicodeString(a2, v14[1] - 24 - ObpInfoMaskToOffset[*(_BYTE *)(v14[1] - 10) & 3] + 4, v6) )
    {
      v7 = v14;
      v14 = (_DWORD *)*v14;
      if ( !v14 )
        goto LABEL_30;
      v6 = a4;
    }
    v16 = v14[1];
    ObfReferenceObject(v16);
    if ( !v5 )
    {
      v17 = (unsigned int *)(a1 + 148);
      __pld((void *)(a1 + 148));
      v18 = *(_DWORD *)(a1 + 148);
      if ( (v18 & 0xFFFFFFF0) > 0x10 )
        v19 = v18 - 16;
      else
        v19 = 0;
      if ( (v18 & 2) != 0 )
        goto LABEL_35;
      __dmb(0xBu);
      do
        v20 = __ldrex(v17);
      while ( v20 == v18 && __strex(v19, v17) );
      if ( v20 != v18 )
LABEL_35:
        ExfReleasePushLock((_DWORD *)(a1 + 148), v18);
      KeAbPostRelease(a1 + 148);
      v21 = *(_DWORD *)a3;
      *(_DWORD *)(a3 + 20) = -286387660;
      ObfDereferenceObject(v21);
      *(_DWORD *)a3 = 0;
      *(_BYTE *)(a3 + 18) = 0;
      *(_BYTE *)(a3 + 19) = 0;
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v23 = *(_WORD *)(v22 + 0x134);
      *(_WORD *)(v22 + 308) = v23 + 1;
      if ( v23 == -1 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
        KiCheckForKernelApcDelivery(v22);
      v7 = 0;
    }
    v24 = *(_DWORD *)(a3 + 4);
    if ( v24 )
      ObfDereferenceObject(v24);
    *(_QWORD *)(a3 + 4) = *(_QWORD *)(&v7 - 1);
    result = v16;
  }
  else
  {
LABEL_30:
    if ( !v5 )
    {
      v26 = (unsigned int *)(a1 + 148);
      __pld((void *)(a1 + 148));
      v27 = *(_DWORD *)(a1 + 148);
      if ( (v27 & 0xFFFFFFF0) > 0x10 )
        v28 = v27 - 16;
      else
        v28 = 0;
      if ( (v27 & 2) != 0 )
        goto LABEL_48;
      __dmb(0xBu);
      do
        v29 = __ldrex(v26);
      while ( v29 == v27 && __strex(v28, v26) );
      if ( v29 != v27 )
LABEL_48:
        ExfReleasePushLock((_DWORD *)(a1 + 148), v27);
      KeAbPostRelease(a1 + 148);
      v30 = *(_DWORD *)a3;
      *(_DWORD *)(a3 + 20) = -286387660;
      v31 = ObfDereferenceObject(v30);
      *(_DWORD *)a3 = 0;
      *(_BYTE *)(a3 + 18) = 0;
      *(_BYTE *)(a3 + 19) = 0;
      v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v33 = (__int16)(*(_WORD *)(v32 + 0x134) + 1);
      *(_WORD *)(v32 + 308) = v33;
      if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
        KiCheckForKernelApcDelivery(v31);
    }
    result = 0;
  }
  return result;
}
