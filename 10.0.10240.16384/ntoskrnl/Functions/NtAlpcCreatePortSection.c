// NtAlpcCreatePortSection 
 
int __fastcall NtAlpcCreatePortSection(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6)
{
  unsigned int v7; // r5
  int v8; // r4
  int v9; // r10
  int v10; // r5
  int v11; // r4
  _DWORD *v12; // r6
  _DWORD *v13; // r2
  _DWORD *v14; // r8
  _DWORD *v15; // r2
  int v16; // r3
  int v17; // r3
  int v18; // r9
  int v19; // r4
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r1
  unsigned int v23; // r1
  __int16 v24; // r3
  __int16 v26; // [sp+8h] [bp-30h]
  int v27; // [sp+Ch] [bp-2Ch] BYREF
  int v28; // [sp+10h] [bp-28h]
  _DWORD _14[15]; // [sp+14h] [bp-24h] BYREF

  _14[12] = a2;
  v28 = a4;
  _14[14] = a4;
  _14[13] = a3;
  _14[11] = a1;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = __mrc(15, 0, 13, 0, 3);
  v9 = *(char *)((v8 & 0xFFFFFFC0) + 0x15A);
  HIBYTE(v26) = *(_BYTE *)((v8 & 0xFFFFFFC0) + 0x15A);
  if ( (a2 & 0xFFFBFFFF) != 0 )
    goto LABEL_2;
  if ( (a2 & 0x40000) != 0 )
  {
    if ( a3 )
    {
LABEL_2:
      v10 = -1073741811;
      goto LABEL_23;
    }
    v11 = 1;
  }
  else
  {
    v11 = 0;
  }
  LOBYTE(v26) = v11;
  if ( v9 )
  {
    v12 = (_DWORD *)a5;
    v13 = (_DWORD *)a5;
    if ( a5 >= MmUserProbeAddress )
      v13 = (_DWORD *)MmUserProbeAddress;
    *v13 = *v13;
    v14 = (_DWORD *)a6;
    v15 = (_DWORD *)a6;
    if ( a6 >= MmUserProbeAddress )
      v15 = (_DWORD *)MmUserProbeAddress;
    *v15 = *v15;
  }
  else
  {
    v14 = (_DWORD *)a6;
    v12 = (_DWORD *)a5;
  }
  v16 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  a1 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v16, _14);
  v10 = a1;
  if ( a1 >= 0 )
  {
    v17 = a3;
    v18 = _14[0];
    v10 = AlpcpCreateSection(_14[0], v11, 1, v17, v28, &v27, v26);
    if ( v10 >= 0 )
    {
      v19 = v27;
      *v12 = *(_DWORD *)(v27 + 12);
      *v14 = *(_DWORD *)(v19 + 4);
      __dmb(0xBu);
      v20 = (unsigned int *)(v19 - 12);
      do
      {
        v21 = __ldrex(v20);
        v22 = v21 - 1;
      }
      while ( __strex(v22, v20) );
      __dmb(0xBu);
      if ( v22 <= 0 )
      {
        if ( v22 )
          KeBugCheckEx(24, 0, v19, 33, v22);
        AlpcpDestroyBlob(v19);
      }
    }
    a1 = ObfDereferenceObject(v18);
  }
LABEL_23:
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v10;
}
