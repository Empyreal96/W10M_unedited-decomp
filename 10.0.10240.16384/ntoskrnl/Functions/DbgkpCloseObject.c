// DbgkpCloseObject 
 
void __fastcall DbgkpCloseObject(int a1, _DWORD *a2, int a3, unsigned int a4)
{
  unsigned int v5; // r4
  int v6; // r5
  int v7; // r7
  unsigned int v8; // r2
  _DWORD *v9; // r7
  _DWORD *v10; // r9
  int v11; // r5
  unsigned int v12; // r1
  char v13; // r10
  int *v14; // r4
  int v15; // r8
  int v16; // r0
  unsigned int v17; // r2
  unsigned __int8 v18; // r8
  unsigned int v19; // r1
  _DWORD *v20; // r0
  char v21; // [sp+0h] [bp-30h]
  int v22; // [sp+4h] [bp-2Ch]

  if ( a4 <= 1 )
  {
    v5 = (unsigned int)(a2 + 4);
    v6 = KeAbPreAcquire((unsigned int)(a2 + 4), 0, 0);
    v7 = KfRaiseIrql(1);
    do
      v8 = __ldrex((unsigned __int8 *)v5);
    while ( __strex(v8 & 0xFE, (unsigned __int8 *)v5) );
    __dmb(0xBu);
    if ( (v8 & 1) == 0 )
      ExpAcquireFastMutexContended(v5, v6);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    *(_DWORD *)(v5 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v5 + 28) = v7;
    v9 = (_DWORD *)a2[12];
    v10 = a2 + 12;
    a2[14] |= 1u;
    a2[12] = a2 + 12;
    a2[13] = a2 + 12;
    v11 = *(_DWORD *)(v5 + 28);
    *(_DWORD *)(v5 + 4) = 0;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v5);
    while ( !v12 && __strex(1u, (unsigned int *)v5) );
    if ( v12 )
      ExpReleaseFastMutexContended((unsigned int *)v5, v12);
    KfLowerIrql((unsigned __int8)v11);
    KeAbPostRelease(v5);
    KeSetEvent((int)a2, 0, 0);
    v13 = (v21 ^ (2 * ((a2[14] & 2) != 0))) & 2 ^ v21;
    v14 = PsGetNextProcess(0);
    if ( v14 )
    {
      do
      {
        if ( (_DWORD *)v14[85] == a2 )
        {
          v13 &= 0xFEu;
          v15 = KeAbPreAcquire((unsigned int)&DbgkpProcessDebugPortMutex, 0, 0);
          v16 = KfRaiseIrql(1);
          v22 = v16;
          do
            v17 = __ldrex((unsigned __int8 *)&DbgkpProcessDebugPortMutex);
          while ( __strex(v17 & 0xFE, (unsigned __int8 *)&DbgkpProcessDebugPortMutex) );
          __dmb(0xBu);
          if ( (v17 & 1) == 0 )
          {
            ExpAcquireFastMutexContended((int)&DbgkpProcessDebugPortMutex, v15);
            v16 = v22;
          }
          if ( v15 )
            *(_BYTE *)(v15 + 14) |= 1u;
          dword_631F64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          dword_631F7C = v16;
          if ( (_DWORD *)v14[85] == a2 )
          {
            v14[85] = 0;
            v18 = dword_631F7C;
            v13 |= 1u;
          }
          else
          {
            v18 = v22;
          }
          dword_631F64 = 0;
          __dmb(0xBu);
          do
            v19 = __ldrex((unsigned int *)&DbgkpProcessDebugPortMutex);
          while ( !v19 && __strex(1u, (unsigned int *)&DbgkpProcessDebugPortMutex) );
          if ( v19 )
            ExpReleaseFastMutexContended((unsigned int *)&DbgkpProcessDebugPortMutex, v19);
          KfLowerIrql(v18);
          KeAbPostRelease((unsigned int)&DbgkpProcessDebugPortMutex);
          if ( (v13 & 1) != 0 )
          {
            DbgkpMarkProcessPeb(v14);
            if ( (v13 & 2) != 0 )
              PsTerminateProcess((int)v14, -1073740972);
            ObfDereferenceObject((int)a2);
          }
        }
        v14 = PsGetNextProcess((int)v14);
      }
      while ( v14 );
      v10 = a2 + 12;
    }
    while ( v9 != v10 )
    {
      v20 = v9;
      v9 = (_DWORD *)*v9;
      v20[10] = -1073740972;
      DbgkpWakeTarget();
    }
  }
}
