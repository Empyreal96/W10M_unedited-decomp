// ObUnRegisterCallbacks 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall ObUnRegisterCallbacks(unsigned int a1)
{
  unsigned int v2; // r7
  unsigned int *v3; // r4
  unsigned int *v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r2
  unsigned __int8 *v7; // r8
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  unsigned int *v11; // r1 OVERLAPPED
  unsigned int **v12; // r2 OVERLAPPED
  int *v13; // r5
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3

  v2 = 0;
  if ( *(_WORD *)(a1 + 2) )
  {
    v3 = (unsigned int *)(a1 + 16);
    do
    {
      v4 = v3 + 8;
      do
        v5 = __ldrex(v4);
      while ( !v5 && __strex(1u, v4) );
      __dmb(0xBu);
      if ( v5 && v5 != 1 )
        ExfWaitForRundownProtectionRelease(v4, v5);
      v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v6 + 310);
      v7 = (unsigned __int8 *)(v3[5] + 128);
      v8 = KeAbPreAcquire((unsigned int)v7, 0, 0);
      v9 = v8;
      do
        v10 = __ldrex(v7);
      while ( __strex(v10 | 1, v7) );
      __dmb(0xBu);
      if ( (v10 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v7, v8, (unsigned int)v7);
      if ( v9 )
        *(_BYTE *)(v9 + 14) |= 1u;
      *(_QWORD *)&v11 = *(_QWORD *)v3;
      if ( *(unsigned int **)(*v3 + 4) != v3 || *v12 != v3 )
        __fastfail(3u);
      *v12 = v11;
      v11[1] = (unsigned int)v12;
      v13 = (int *)(v3[5] + 128);
      __pld(v13);
      v14 = *v13;
      v15 = *v13 - 16;
      if ( (*v13 & 0xFFFFFFF0) <= 0x10 )
        v15 = 0;
      if ( (v14 & 2) != 0 )
        goto LABEL_24;
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)v13);
      while ( v16 == v14 && __strex(v15, (unsigned int *)v13) );
      if ( v16 != v14 )
LABEL_24:
        ExfReleasePushLock(v13, v14);
      v17 = KeAbPostRelease((unsigned int)v13);
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = *(_WORD *)(v18 + 0x136) + 1;
      *(_WORD *)(v18 + 310) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 )
        KiCheckForKernelApcDelivery(v17);
      ++v2;
      v3 += 9;
    }
    while ( v2 < *(unsigned __int16 *)(a1 + 2) );
  }
  return ExFreePoolWithTag(a1);
}
