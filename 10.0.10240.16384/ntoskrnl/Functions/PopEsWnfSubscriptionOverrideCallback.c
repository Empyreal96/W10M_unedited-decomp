// PopEsWnfSubscriptionOverrideCallback 
 
int PopEsWnfSubscriptionOverrideCallback(int a1, int a2, int a3, ...)
{
  int v3; // r6
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r2
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v14; // r4
  unsigned int v16; // [sp+0h] [bp-18h] BYREF
  int v17[5]; // [sp+4h] [bp-14h] BYREF
  int varg_r3; // [sp+2Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+2Ch] [bp+14h]
  va_list va1; // [sp+30h] [bp+18h] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v17[0] = a3;
  v17[1] = varg_r3;
  v16 = 4;
  if ( ExQueryWnfStateData(a1, (int *)varg_r3a, (int)v17, &v16) >= 0 )
  {
    v3 = v17[0];
    if ( v17[0] <= 2u )
    {
      v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v4 + 308);
      v5 = KeAbPreAcquire((unsigned int)&PopEsLock, 0, 0);
      v6 = v5;
      do
        v7 = __ldrex((unsigned __int8 *)&PopEsLock);
      while ( __strex(v7 | 1, (unsigned __int8 *)&PopEsLock) );
      __dmb(0xBu);
      if ( (v7 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&PopEsLock, v5, (unsigned int)&PopEsLock);
      if ( v6 )
        *(_BYTE *)(v6 + 14) |= 1u;
      __mrc(15, 0, 13, 0, 3);
      PopEsMode = v3;
      dword_61DED4 = 0;
      __pld(&PopEsLock);
      v8 = PopEsLock;
      v9 = PopEsLock - 16;
      if ( (PopEsLock & 0xFFFFFFF0) <= 0x10 )
        v9 = 0;
      if ( (PopEsLock & 2) != 0 )
        goto LABEL_16;
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&PopEsLock);
      while ( v10 == v8 && __strex(v9, (unsigned int *)&PopEsLock) );
      if ( v10 != v8 )
LABEL_16:
        ExfReleasePushLock(&PopEsLock, v8);
      v11 = KeAbPostRelease((unsigned int)&PopEsLock);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = *(_WORD *)(v12 + 0x134) + 1;
      *(_WORD *)(v12 + 308) = v13;
      if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(v11);
      __dmb(0xBu);
      do
        v14 = __ldrex(&PopEsWorkItemDue);
      while ( __strex(v14 | 0x80000002, &PopEsWorkItemDue) );
      __dmb(0xBu);
      if ( v14 >= 0 )
        ExQueueWorkItem(&PopEsWorkItem, 1);
    }
  }
  return 0;
}
