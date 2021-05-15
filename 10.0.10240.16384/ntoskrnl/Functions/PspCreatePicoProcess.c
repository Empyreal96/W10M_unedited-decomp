// PspCreatePicoProcess 
 
int __fastcall PspCreatePicoProcess(int *a1, int *a2)
{
  int v3; // r3
  int v4; // r5
  unsigned int v5; // r8
  int v6; // r10
  int v7; // r4
  int v8; // r0
  _DWORD *v9; // r7
  int v10; // r3
  int v11; // r5
  unsigned __int8 *v12; // r6
  int v13; // r0
  int v14; // r7
  unsigned int v15; // r2
  int v16; // r7
  unsigned int v17; // r1
  int v18; // r0
  __int16 v19; // r3
  int v21; // [sp+10h] [bp-30h] BYREF
  _DWORD *v22; // [sp+14h] [bp-2Ch] BYREF
  int v23; // [sp+18h] [bp-28h] BYREF
  int v24; // [sp+1Ch] [bp-24h] BYREF
  int *v25; // [sp+20h] [bp-20h]

  v25 = a2;
  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = a1[3];
  v5 = v3 & 0xFFFFFFC0;
  v6 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  v24 = 0;
  if ( (v4 & 0xFFFFFFE0) != 0 || (v4 & 6) != 0 && (v4 & 1) == 0 || !a1[2] )
    return -1073741811;
  v7 = ObReferenceObjectByHandleWithTag(*a1, 128, PsProcessType, 0, 1917023056, (int *)&v22, 0);
  if ( v7 < 0 )
    return v7;
  v8 = a1[1];
  v9 = v22;
  if ( !v8 )
    goto LABEL_10;
  v7 = ObReferenceObjectByHandleWithTag(v8, 9, SeTokenObjectType, 0, 1917023056, &v24, 0);
  if ( v7 >= 0 )
  {
    v6 = v24;
LABEL_10:
    v10 = 0;
    if ( (v4 & 1) != 0 )
    {
      v10 = 0x2000;
      if ( (v4 & 2) != 0 )
        v10 = 8196;
      if ( (v4 & 4) != 0 )
        v10 |= 0x4000u;
    }
    if ( (v4 & 8) != 0 )
      v10 |= 1u;
    if ( (v4 & 0x10) != 0 )
      v10 |= 0x10000u;
    v7 = PspCreateMinimalProcess(v9, 0, v6, v10, &v23);
    v11 = v23;
    if ( v7 >= 0 )
    {
      v7 = ObReferenceObjectByHandleWithTag(v23, 128, PsProcessType, 0, 1917023056, &v21, 0);
      if ( v7 >= 0 )
      {
        --*(_WORD *)(v5 + 308);
        v12 = (unsigned __int8 *)(v21 + 168);
        v13 = KeAbPreAcquire(v21 + 168, 0, 0);
        v14 = v13;
        do
          v15 = __ldrex(v12);
        while ( __strex(v15 | 1, v12) );
        __dmb(0xBu);
        if ( (v15 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v12, v13, (unsigned int)v12);
        if ( v14 )
          *(_BYTE *)(v14 + 14) |= 1u;
        v16 = v21;
        if ( (*(_DWORD *)(v21 + 192) & 8) != 0 )
        {
          v7 = -1073741558;
        }
        else
        {
          *(_DWORD *)(v21 + 780) = a1[2];
          *v25 = v11;
          v11 = 0;
        }
        __dmb(0xBu);
        do
          v17 = __ldrex((unsigned int *)v12);
        while ( __strex(v17 - 1, (unsigned int *)v12) );
        if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v12);
        v18 = KeAbPostRelease((unsigned int)v12);
        v19 = *(_WORD *)(v5 + 308) + 1;
        *(_WORD *)(v5 + 308) = v19;
        if ( !v19 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
          KiCheckForKernelApcDelivery(v18);
        if ( v7 >= 0 )
          v7 = 0;
        ObfDereferenceObjectWithTag(v16);
        v9 = v22;
      }
    }
    if ( v11 )
      ZwClose();
    if ( v6 )
      ObfDereferenceObjectWithTag(v6);
  }
  if ( v9 )
    ObfDereferenceObjectWithTag((int)v9);
  return v7;
}
