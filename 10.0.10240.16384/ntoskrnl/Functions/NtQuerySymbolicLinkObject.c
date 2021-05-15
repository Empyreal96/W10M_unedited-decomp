// NtQuerySymbolicLinkObject 
 
int __fastcall NtQuerySymbolicLinkObject(int a1, unsigned int a2, _DWORD *a3, int a4)
{
  _WORD *v5; // r6
  int v6; // r9
  _WORD *v7; // r2
  _WORD *v8; // r2
  unsigned int v9; // r10
  _DWORD *v10; // r2
  int v11; // r8
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r9
  unsigned __int8 *v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r2
  int v18; // r3
  unsigned int *v19; // r5
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int v27; // [sp+Ch] [bp-44h]
  int v28; // [sp+10h] [bp-40h] BYREF
  int v29; // [sp+18h] [bp-38h]
  int v30; // [sp+1Ch] [bp-34h]
  unsigned __int8 *v31; // [sp+20h] [bp-30h]
  int v32; // [sp+28h] [bp-28h]
  int v33; // [sp+2Ch] [bp-24h]
  int varg_r0; // [sp+58h] [bp+8h]
  unsigned int varg_r1; // [sp+5Ch] [bp+Ch]
  _DWORD *varg_r2; // [sp+60h] [bp+10h]
  int varg_r3; // [sp+64h] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  v5 = (_WORD *)a2;
  varg_r1 = a2;
  v29 = a1;
  varg_r0 = a1;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v30 = v6;
  if ( v6 )
  {
    if ( (a2 & 1) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v7 = (_WORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v7 = (_WORD *)MmUserProbeAddress;
    *v7 = *v7;
    v8 = (_WORD *)(a2 + 2);
    if ( a2 + 2 >= MmUserProbeAddress )
      v8 = (_WORD *)MmUserProbeAddress;
    *v8 = *v8;
    v32 = *(_DWORD *)a2;
    v27 = *(_DWORD *)(a2 + 4);
    v33 = v27;
    v9 = HIWORD(v32);
    ProbeForWrite(v27, HIWORD(v32), 1);
    if ( a3 )
    {
      v10 = a3;
      if ( (unsigned int)a3 >= MmUserProbeAddress )
        v10 = (_DWORD *)MmUserProbeAddress;
      *v10 = *v10;
    }
    v6 = v30;
    a1 = v29;
  }
  else
  {
    v32 = *(_DWORD *)a2;
    v27 = *(_DWORD *)(a2 + 4);
    v9 = HIWORD(v32);
  }
  v11 = ObReferenceObjectByHandle(a1, 1, ObpSymbolicLinkObjectType, v6, &v28);
  v32 = v11;
  if ( v11 >= 0 )
  {
    v12 = v28;
    v29 = v28 - 24;
    v30 = v28 - 24;
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v13 + 308);
    v31 = (unsigned __int8 *)(v12 - 16);
    v14 = KeAbPreAcquire(v12 - 16, 0, 0);
    v15 = v31;
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 | 1, v15) );
    __dmb(0xBu);
    if ( (v16 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v15, v14, (unsigned int)v15);
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
    if ( a3 )
    {
      if ( *(unsigned __int16 *)(v12 + 10) > v9 )
      {
        *a3 = *(unsigned __int16 *)(v12 + 10);
        v18 = v29;
LABEL_34:
        v11 = -1073741789;
LABEL_35:
        v19 = (unsigned int *)(v18 + 8);
        __pld((void *)(v18 + 8));
        v20 = *(_DWORD *)(v18 + 8);
        if ( (v20 & 0xFFFFFFF0) <= 0x10 )
          v21 = 0;
        else
          v21 = v20 - 16;
        if ( (v20 & 2) != 0 )
          goto LABEL_43;
        __dmb(0xBu);
        do
          v22 = __ldrex(v19);
        while ( v22 == v20 && __strex(v21, v19) );
        if ( v22 != v20 )
LABEL_43:
          ExfReleasePushLock(v19, v20);
        v23 = KeAbPostRelease((unsigned int)v19);
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v25 = *(_WORD *)(v24 + 0x134) + 1;
        *(_WORD *)(v24 + 308) = v25;
        if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
          KiCheckForKernelApcDelivery(v23);
        ObfDereferenceObject(v12);
        return v11;
      }
    }
    else if ( *(unsigned __int16 *)(v12 + 8) > v9 )
    {
      v18 = v29;
      goto LABEL_34;
    }
    if ( a3 )
      v17 = *(unsigned __int16 *)(v12 + 10);
    else
      v17 = *(unsigned __int16 *)(v12 + 8);
    memmove(v27, *(_DWORD *)(v12 + 12), v17);
    *v5 = *(_WORD *)(v12 + 8);
    if ( a3 )
      *a3 = *(unsigned __int16 *)(v12 + 10);
    v18 = v29;
    goto LABEL_35;
  }
  return v11;
}
