// CmpGetCallbackObjectContext 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpGetCallbackObjectContext(_DWORD *a1, _QWORD *a2)
{
  int v3; // r7
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  int *v9; // r3
  int *v10; // r1
  unsigned int v11; // r5 OVERLAPPED
  unsigned int v12; // r6 OVERLAPPED
  __int64 v13; // kr00_8
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3

  v3 = 0;
  if ( !a1 || *a1 != 1803104306 )
    return 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&CmpContextListLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned int *)&CmpContextListLock);
  while ( !v8 && __strex(0x11u, (unsigned int *)&CmpContextListLock) );
  __dmb(0xBu);
  if ( v8 )
    ExfAcquirePushLockSharedEx(&CmpContextListLock, v6, (unsigned int)&CmpContextListLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = (int *)a1[9];
  v10 = a1 + 9;
  if ( v9 != a1 + 9 )
  {
    *(_QWORD *)&v11 = *a2;
    while ( 1 )
    {
      v13 = *((_QWORD *)v9 + 2);
      if ( v13 == __PAIR64__(v12, v11) )
        break;
      if ( v13 >= __SPAIR64__(v12, v11) )
      {
        v9 = (int *)*v9;
        if ( v9 != v10 )
          continue;
      }
      goto LABEL_16;
    }
    v3 = v9[8];
  }
LABEL_16:
  __pld(&CmpContextListLock);
  v14 = CmpContextListLock;
  v15 = CmpContextListLock - 16;
  if ( (CmpContextListLock & 0xFFFFFFF0) <= 0x10 )
    v15 = 0;
  if ( (CmpContextListLock & 2) != 0 )
    goto LABEL_23;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&CmpContextListLock);
  while ( v16 == v14 && __strex(v15, (unsigned int *)&CmpContextListLock) );
  if ( v16 != v14 )
LABEL_23:
    ExfReleasePushLock(&CmpContextListLock, v14);
  v17 = KeAbPostRelease((unsigned int)&CmpContextListLock);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v3;
}
