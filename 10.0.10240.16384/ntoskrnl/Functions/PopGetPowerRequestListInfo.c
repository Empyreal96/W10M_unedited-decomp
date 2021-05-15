// PopGetPowerRequestListInfo 
 
int __fastcall PopGetPowerRequestListInfo(unsigned int *a1, _DWORD *a2)
{
  int *v2; // r4
  int v3; // r7
  _DWORD *v4; // r0
  _DWORD *v5; // r0
  unsigned int v6; // r5
  int v7; // r4
  unsigned int *v8; // r10
  unsigned int v9; // r6
  unsigned int v10; // r8
  int *v11; // r7
  unsigned int v12; // r2
  int v13; // r0
  _DWORD *v14; // r0
  unsigned int v15; // r3
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  _DWORD *v23; // [sp+0h] [bp-28h] BYREF
  unsigned int *v24; // [sp+4h] [bp-24h]
  unsigned int *v25; // [sp+8h] [bp-20h]

  v23 = a2;
  v24 = a1;
  v25 = a2;
  PopAcquirePowerRequestPushLock(0);
  v2 = (int *)PopPowerRequestObjectList;
  v3 = (4 * PopPowerRequestObjectCount + 7) & 0xFFFFFFFC;
  while ( v2 != &PopPowerRequestObjectList )
  {
    v4 = (_DWORD *)v2[15];
    v23 = 0;
    PoStoreDiagnosticContext(v4, 0, (unsigned int *)&v23, 0);
    v3 = ((unsigned int)v23 + v3 + 27) & 0xFFFFFFFC;
    v2 = (int *)*v2;
  }
  v5 = (_DWORD *)ExAllocatePoolWithTag(1, v3, 544040269);
  v6 = (unsigned int)v5;
  if ( v5 )
  {
    v8 = v5 + 1;
    v9 = (4 * PopPowerRequestObjectCount + 7) & 0xFFFFFFFC;
    v10 = v3 - v9;
    *v5 = PopPowerRequestObjectCount;
    v11 = (int *)PopPowerRequestObjectList;
    while ( 1 )
    {
      if ( v11 == &PopPowerRequestObjectList )
      {
        *v24 = v6;
        v6 = 0;
        v7 = 0;
        *v25 = v9;
        goto LABEL_15;
      }
      if ( v10 < 0x30 )
        break;
      *(_DWORD *)(v9 + v6) = v11[3];
      v12 = v9 + v6;
      v13 = 5;
      do
      {
        --v13;
        *(_DWORD *)(v12 + 4) = *(int *)((char *)v11 + v12 - v6 - v9 + 24);
        v12 += 4;
      }
      while ( v13 );
      v14 = (_DWORD *)v11[15];
      v23 = (_DWORD *)(v10 - 24);
      v7 = PoStoreDiagnosticContext(v14, v9 + v6 + 24, (unsigned int *)&v23, v10 - 24);
      if ( v7 < 0 )
        goto LABEL_15;
      v15 = ((unsigned int)v23 + 27) & 0xFFFFFFFC;
      if ( v10 < v15 )
        break;
      *v8++ = v9;
      v11 = (int *)*v11;
      v9 += v15;
      v10 -= v15;
    }
    v7 = -1073741789;
LABEL_15:
    if ( v6 )
      ExFreePoolWithTag(v6);
  }
  else
  {
    v7 = -1073741670;
  }
  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v16 = PopPowerRequestLock;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
    v17 = 0;
  else
    v17 = PopPowerRequestLock - 16;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_26;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v18 == v16 && __strex(v17, (unsigned int *)&PopPowerRequestLock) );
  if ( v18 != v16 )
LABEL_26:
    ExfReleasePushLock(&PopPowerRequestLock, v16);
  v19 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  return v7;
}
