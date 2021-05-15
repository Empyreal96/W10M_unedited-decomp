// DbgkpQueueMessage 
 
int __fastcall DbgkpQueueMessage(int a1, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
  int v7; // r9
  int v9; // r10
  char *v10; // r4
  int v11; // r5
  int v12; // r5
  int v13; // r9
  unsigned int v14; // r2
  int v15; // r2
  unsigned int v16; // r6
  int v17; // r9
  int v18; // r10
  unsigned int v19; // r2
  char **v20; // r1
  int v21; // r9
  unsigned int v22; // r1
  unsigned __int8 v23; // r6
  unsigned int v24; // r1
  int v26; // [sp+8h] [bp-110h]
  int v27; // [sp+Ch] [bp-10Ch]
  char v29; // [sp+18h] [bp-100h] BYREF
  char v30[36]; // [sp+20h] [bp-F8h] BYREF
  int v31; // [sp+44h] [bp-D4h]

  v26 = a4 & 2;
  v27 = a3;
  v7 = a3;
  v9 = a1;
  if ( (a4 & 2) != 0 )
  {
    v10 = (char *)ExAllocatePoolWithQuotaTag(0x208u, 0xE0u, 1164403268);
    if ( !v10 )
      return -1073741670;
    *((_DWORD *)v10 + 11) = a4 | 4;
    ObfReferenceObjectWithTag(v9);
    ObfReferenceObjectWithTag((int)a2);
    *((_DWORD *)v10 + 12) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  }
  else
  {
    v10 = &v29;
    v31 = a4;
    v12 = KeAbPreAcquire((unsigned int)&DbgkpProcessDebugPortMutex, 0, 0);
    v13 = KfRaiseIrql(1);
    do
      v14 = __ldrex((unsigned __int8 *)&DbgkpProcessDebugPortMutex);
    while ( __strex(v14 & 0xFE, (unsigned __int8 *)&DbgkpProcessDebugPortMutex) );
    __dmb(0xBu);
    if ( (v14 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&DbgkpProcessDebugPortMutex, v12);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    dword_631F64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_631F7C = v13;
    v7 = v27;
    a5 = *(_DWORD **)(v9 + 340);
    v15 = *(_DWORD *)(v27 + 24);
    if ( (v15 == 1 || v15 == 2) && (a2[240] & 0x40) != 0 )
      a5 = 0;
    if ( v15 == 5 && (a2[240] & 0x40) != 0 && (a4 & 0x40) != 0 )
      a5 = 0;
    if ( (v15 == 3 || v15 == 4) && (a2[240] & 0x80) != 0 )
      a5 = 0;
    KeInitializeEvent((int)v30, 1, 0);
  }
  *((_DWORD *)v10 + 8) = v9;
  *((_DWORD *)v10 + 9) = a2;
  memmove((int)(v10 + 56), v7, 0xA8u);
  *((_DWORD *)v10 + 6) = a2[219];
  *((_DWORD *)v10 + 7) = a2[220];
  if ( a5 )
  {
    v16 = (unsigned int)(a5 + 4);
    v17 = KeAbPreAcquire((unsigned int)(a5 + 4), 0, 0);
    v18 = KfRaiseIrql(1);
    do
      v19 = __ldrex((unsigned __int8 *)v16);
    while ( __strex(v19 & 0xFE, (unsigned __int8 *)v16) );
    __dmb(0xBu);
    if ( (v19 & 1) == 0 )
      ExpAcquireFastMutexContended((int)(a5 + 4), v17);
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    a5[5] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    a5[11] = v18;
    if ( (a5[14] & 1) != 0 )
    {
      v11 = -1073740972;
    }
    else
    {
      v20 = (char **)a5[13];
      *(_DWORD *)v10 = a5 + 12;
      *((_DWORD *)v10 + 1) = v20;
      if ( *v20 != (char *)(a5 + 12) )
        __fastfail(3u);
      *v20 = v10;
      a5[13] = v10;
      if ( !v26 )
        KeSetEvent((int)a5, 0, 0);
      v11 = 0;
    }
    v21 = *(_DWORD *)(v16 + 28);
    *(_DWORD *)(v16 + 4) = 0;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v16);
    while ( !v22 && __strex(1u, (unsigned int *)v16) );
    if ( v22 )
      ExpReleaseFastMutexContended((unsigned int *)v16, v22);
    KfLowerIrql((unsigned __int8)v21);
    KeAbPostRelease(v16);
    v7 = v27;
    v9 = a1;
  }
  else
  {
    v11 = -1073740973;
  }
  if ( v26 )
  {
    if ( v11 < 0 )
    {
      ObfDereferenceObjectWithTag(v9);
      ObfDereferenceObjectWithTag((int)a2);
      ExFreePoolWithTag((unsigned int)v10);
    }
  }
  else
  {
    dword_631F64 = 0;
    v23 = dword_631F7C;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)&DbgkpProcessDebugPortMutex);
    while ( !v24 && __strex(1u, (unsigned int *)&DbgkpProcessDebugPortMutex) );
    if ( v24 )
      ExpReleaseFastMutexContended((unsigned int *)&DbgkpProcessDebugPortMutex, v24);
    KfLowerIrql(v23);
    KeAbPostRelease((unsigned int)&DbgkpProcessDebugPortMutex);
    if ( v11 >= 0 )
    {
      KeWaitForSingleObject((unsigned int)(v10 + 8), 0, 0, 0, 0);
      v11 = *((_DWORD *)v10 + 10);
      memmove(v7, (int)(v10 + 56), 0xA8u);
    }
  }
  return v11;
}
