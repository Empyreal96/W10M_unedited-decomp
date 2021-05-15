// RtlpLookupUserFunctionTable 
 
unsigned int __fastcall RtlpLookupUserFunctionTable(int a1, unsigned int *a2)
{
  unsigned int v3; // r4
  unsigned int v4; // r6
  int v5; // r10
  unsigned int *v6; // r8
  int v7; // r0
  int v8; // r9
  unsigned int v9; // r2
  int *v10; // r10
  int v11; // r3
  int v12; // r9
  int v13; // r0
  int v14; // lr
  int *v15; // r1
  unsigned int v16; // r2
  int v17; // r9
  unsigned int v18; // r2
  int v19; // r0
  __int16 v20; // r3
  int v21; // r3
  unsigned int v22; // r2
  int v23; // r0
  __int16 v24; // r3
  int v25; // r6
  unsigned int v26; // r3
  int v27; // r0
  unsigned int v28; // r3
  unsigned int v30; // [sp+0h] [bp-38h] BYREF
  unsigned int v31; // [sp+4h] [bp-34h]
  unsigned int v32; // [sp+8h] [bp-30h] BYREF
  int _C[15]; // [sp+Ch] [bp-2Ch] BYREF

  _C[13] = a1;
  _C[14] = (int)a2;
  v31 = a1;
  v3 = RtlpLookupUserFunctionTableInverted();
  v30 = v3;
  if ( v3 )
    return v3;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_DWORD *)(v4 + 0x150);
  if ( *(_DWORD *)(v5 + 704) )
  {
    --*(_WORD *)(v4 + 310);
    v6 = (unsigned int *)(v5 + 708);
    v7 = KeAbPreAcquire(v5 + 708, 0, 0);
    v8 = v7;
    do
      v9 = __ldrex(v6);
    while ( !v9 && __strex(0x11u, v6) );
    __dmb(0xBu);
    if ( v9 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v5 + 708), v7, v5 + 708);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    v10 = *(int **)(v5 + 704);
    if ( v10 )
    {
      v11 = *v10;
      if ( *v10 != 1 )
      {
        v12 = 1;
        v13 = v11 - 1;
        while ( v13 >= v12 )
        {
          v14 = (v13 + v12) >> 1;
          v15 = &v10[4 * v14 + 4];
          v16 = v15[1];
          v32 = v15[2] + v16;
          if ( v31 >= v16 )
          {
            if ( v31 < v32 )
              goto LABEL_20;
            v12 = v14 + 1;
          }
          else
          {
            if ( !v14 )
              break;
            v13 = v14 - 1;
          }
        }
      }
      v15 = 0;
LABEL_20:
      if ( v15 )
      {
        v17 = *v15;
        a2[1] = v15[1];
        a2[2] = v15[2];
        __dmb(0xBu);
        do
          v18 = __ldrex(v6);
        while ( v18 == 17 && __strex(0, v6) );
        if ( v18 != 17 )
          ExfReleasePushLockShared(v6);
        v19 = KeAbPostRelease((unsigned int)v6);
        v20 = *(_WORD *)(v4 + 310) + 1;
        *(_WORD *)(v4 + 310) = v20;
        if ( !v20 && *(_DWORD *)(v4 + 100) != v4 + 100 )
          v19 = KiCheckForKernelApcDelivery(v19);
        v3 = *(_DWORD *)(v17 + 8);
        v30 = v3;
        *a2 = v3;
        v21 = 8 * *(_DWORD *)(v17 + 52);
        a2[3] = v21;
        if ( v21 )
        {
          if ( (v3 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v19);
          if ( v21 + v3 > MmUserProbeAddress || v21 + v3 < v3 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
        return v3;
      }
    }
    __dmb(0xBu);
    do
      v22 = __ldrex(v6);
    while ( v22 == 17 && __strex(0, v6) );
    if ( v22 != 17 )
      ExfReleasePushLockShared(v6);
    v23 = KeAbPostRelease((unsigned int)v6);
    v24 = *(_WORD *)(v4 + 310) + 1;
    *(_WORD *)(v4 + 310) = v24;
    if ( !v24 && *(_DWORD *)(v4 + 100) != v4 + 100 )
      KiCheckForKernelApcDelivery(v23);
  }
  if ( MmGetImageBase(v31, _C, &v32) >= 0 )
  {
    v25 = _C[0];
    v27 = RtlCaptureImageExceptionValues(_C[0], (int *)&v30, (int)(a2 + 3));
    v3 = v30;
    if ( v30 )
    {
      v28 = a2[3];
      if ( !v28 || (v28 & 7) != 0 )
      {
        v3 = 0;
        v30 = 0;
      }
      else
      {
        if ( (v30 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v27);
        if ( v28 + v30 > MmUserProbeAddress || v28 + v30 < v30 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
    }
    v26 = v32;
  }
  else
  {
    v25 = 0;
    v26 = 0;
  }
  a2[1] = v25;
  a2[2] = v26;
  *a2 = v3;
  if ( !v3 )
    a2[3] = 0;
  return v3;
}
