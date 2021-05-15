// PopProcessorInformation 
 
int __fastcall PopProcessorInformation(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  unsigned int *v5; // r8
  int v6; // r9
  int result; // r0
  unsigned int v8; // r6
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  unsigned int v13; // r2
  int v14; // r5
  int v15; // r3
  int v16; // r3
  int v17; // r2
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int v24; // [sp+8h] [bp-30h]
  unsigned int v26; // [sp+10h] [bp-28h]

  v5 = a4;
  v6 = KeQueryGroupAffinity(a3);
  v26 = 24
      * (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v6 >> 24))
                        + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v6 >> 16))
                        + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v6)
                        + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v6 >> 8)));
  v24 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v6 >> 24))
                        + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v6 >> 16))
                        + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v6)
                        + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v6 >> 8)));
  if ( v26 > 0x300 )
    return sub_7F2A00();
  if ( *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v6 >> 24))
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v6 >> 16))
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v6)
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v6 >> 8)) )
  {
    v8 = 0;
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
    while ( !v12 && __strex(0x11u, (unsigned int *)&PpmIdlePolicyLock) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(&PpmIdlePolicyLock, v10, (unsigned int)&PpmIdlePolicyLock);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    while ( v6 )
    {
      v13 = __clz(__rbit(v6));
      v6 &= ~(1 << v13);
      if ( v8 >= v24 )
        break;
      if ( v13 >= KeNumberProcessors_0 )
        v14 = 0;
      else
        v14 = (int)*(&KiProcessorBlock + v13);
      *a1 = *(unsigned __int8 *)(v14 + 1053);
      PpmPerfGetCurrentState((_DWORD *)v14, a1 + 2, a1 + 3, 0, 0, 0);
      v15 = *(_DWORD *)(v14 + 3200);
      if ( v15 )
        v16 = *(_DWORD *)(v15 + 80);
      else
        v16 = *(_DWORD *)(v14 + 964);
      a1[1] = v16;
      v17 = *(_DWORD *)(v14 + 2944);
      if ( v17 )
      {
        a1[4] = *(_DWORD *)(v17 + 28);
        a1[5] = *(_DWORD *)(v17 + 12) + 1;
      }
      else
      {
        a1[4] = 0;
        a1[5] = 0;
      }
      ++v8;
      a1 += 6;
    }
    dword_61E89C = 0;
    __pld(&PpmIdlePolicyLock);
    v18 = PpmIdlePolicyLock;
    if ( (PpmIdlePolicyLock & 0xFFFFFFF0) > 0x10 )
      v19 = PpmIdlePolicyLock - 16;
    else
      v19 = 0;
    v5 = a4;
    if ( (PpmIdlePolicyLock & 2) != 0 )
      goto LABEL_34;
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
    while ( v20 == v18 && __strex(v19, (unsigned int *)&PpmIdlePolicyLock) );
    if ( v20 != v18 )
LABEL_34:
      ExfReleasePushLock(&PpmIdlePolicyLock, v18);
    v21 = KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x134) + 1;
    *(_WORD *)(v22 + 308) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
      KiCheckForKernelApcDelivery(v21);
  }
  result = 0;
  *v5 = v26;
  return result;
}
