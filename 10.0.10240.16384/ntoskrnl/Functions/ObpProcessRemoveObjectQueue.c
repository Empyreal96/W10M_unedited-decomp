// ObpProcessRemoveObjectQueue 
 
// local variable allocation has failed, the output may be wrong!
int *ObpProcessRemoveObjectQueue()
{
  unsigned int v0; // r1 OVERLAPPED
  unsigned int v1; // r2 OVERLAPPED
  __int64 v2; // r0
  int *result; // r0
  __int64 v4; // r0
  __int64 v5; // kr10_8
  unsigned int v6; // r8
  unsigned __int64 v7; // r0
  __int64 v8; // r2
  int v9; // r6
  int v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r0
  unsigned int v13; // r7
  unsigned int v14; // r9
  int v15; // r7
  int v16; // r0
  int v17; // r6
  int v18; // r2
  int v19; // r3
  int v20; // r0
  unsigned int v21; // r1
  int *v22; // lr
  int v23; // t1
  int v24; // r3
  int v25; // r2
  __int64 v26; // kr20_8
  unsigned int v27; // r8
  unsigned int v28; // r9
  unsigned __int64 v29; // r0
  __int64 v30; // r2
  int v31; // r0
  unsigned int v32; // [sp+0h] [bp-40h]
  char v33[56]; // [sp+8h] [bp-38h] BYREF

  if ( !qword_618EA8 )
    qword_618EA8 = (unsigned int)KiTableInformation;
  if ( !qword_618E90 )
  {
    LODWORD(v2) = ReadTimeStampCounter();
    qword_618E90 = 41929663 * (unsigned int)(v2 >> 4);
    if ( !(_DWORD)qword_618E90 )
      return (int *)sub_801268();
    LODWORD(v4) = ReadTimeStampCounter();
    dword_618E98 = (41929663 * (v4 >> 4)) ^ 0xB71;
    dword_618E9C = 0;
    do
    {
      v5 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v6 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v32 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v6 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v5 != MEMORY[0xFFFF93B0] );
    LODWORD(v7) = ReadTimeStampCounter();
    _rt_udiv64(80000000000i64, 41929663 * (v7 >> 4));
    qword_618EA0 = v8 - v5 + __PAIR64__(v6, v32) + 288000000000i64;
  }
  do
  {
    *(_QWORD *)&v0 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v12 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v13 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v12 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v0 != MEMORY[0xFFFF93B0] || v1 != MEMORY[0xFFFF93B4] );
  if ( __PAIR64__(v12, v13) - __PAIR64__(v1, v0) >= qword_618EA0 )
  {
    v14 = dword_682018;
    v15 = dword_682010;
    if ( dword_682018 )
    {
      if ( KdDebuggerNotPresent )
      {
        v16 = MmGetNextSession();
        v17 = v16;
        if ( v16 )
        {
          v18 = qword_618EA8;
          v19 = HIDWORD(qword_618EA8) | qword_618EA8;
          if ( !qword_618EA8 )
          {
            v19 = 0;
            qword_618EA8 = (unsigned int)KiTableInformation;
          }
          if ( MmAttachSession(v16, (int)v33, v18, v19) >= 0 )
          {
            v20 = (int)&dword_682010 + v15;
            v21 = 0;
            if ( v14 )
            {
              v22 = (int *)v15;
              do
              {
                v23 = *v22++;
                ++v21;
                v20 = ((*(_DWORD *)((v23 >> 4) + v15) + v23) ^ v20) * v21;
              }
              while ( v21 < v14 );
            }
            v24 = qword_618EA8;
            v25 = 2 * v20;
            if ( qword_618EA8 != 2 * v20 )
            {
              v25 = qword_618E60;
              v24 = HIDWORD(qword_618E60) | qword_618E60;
              if ( !qword_618E60 )
              {
                LODWORD(qword_618E60) = __ROR4__(555745280, 21);
                qword_618E60 = (unsigned int)qword_618E60;
                unk_618E68 = 0;
                unk_618E6C = 0;
                unk_618E70 = 0;
                dword_618E74 = 0;
                dword_618E78 = 266;
                v24 = 0;
                *(_DWORD *)algn_618E7C = 0;
                unk_618E80 = v15;
                dword_618E84 = 0;
              }
            }
            MmDetachSession(v17, (int)v33, v25, v24);
          }
          MmQuitNextSession(v17);
        }
      }
    }
    if ( qword_618E60 )
    {
      if ( (int (__fastcall *)(int, int))dword_618E4C != sub_5C46B4 )
        KeInitializeDpc(
          (int)&`ObpTraceDeferredDeletionWorker'::`2'::ObjectEventList,
          (int)sub_5C46B4,
          (int)&`ObpTraceDeferredDeletionWorker'::`2'::ObjectEventList);
      dword_618E88 = 3544090;
      dword_618E8C = 0;
      KeInsertQueueDpc((int)&`ObpTraceDeferredDeletionWorker'::`2'::ObjectEventList);
    }
    do
    {
      v26 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v27 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v28 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v27 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v26 != MEMORY[0xFFFF93B0] );
    LODWORD(v29) = ReadTimeStampCounter();
    _rt_udiv64(80000000000i64, 41929663 * (v29 >> 4));
    qword_618EA0 = v30 - v26 + __PAIR64__(v27, v28) + 288000000000i64;
  }
  while ( 1 )
  {
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&ObpRemoveObjectList);
    while ( __strex(1u, (unsigned int *)&ObpRemoveObjectList) );
    __dmb(0xBu);
    do
    {
      if ( (*(_BYTE *)(v10 + 14) & 0x40) != 0 )
        v31 = v10 - ObpInfoMaskToOffset[*(_BYTE *)(v10 + 14) & 0x7F];
      else
        v31 = 0;
      if ( v31 )
        ObpHandleRevocationBlockRemoveObject(v31);
      if ( ObpTraceFlags )
        ObpDeregisterObject(v10);
      v9 = *(_DWORD *)(v10 + 4);
      ObpRemoveObjectRoutine(v10, 1);
      v10 = v9;
    }
    while ( v9 && v9 != 1 );
    if ( ObpRemoveObjectList == 1 )
    {
      __dmb(0xBu);
      do
        v11 = __ldrex((unsigned int *)&ObpRemoveObjectList);
      while ( v11 == 1 && __strex(0, (unsigned int *)&ObpRemoveObjectList) );
      __dmb(0xBu);
      if ( v11 == 1 )
        break;
    }
  }
  __dmb(0xFu);
  result = &ObpRemoveObjectWait;
  if ( ObpRemoveObjectWait )
    result = (int *)ExfUnblockPushLock((int)&ObpRemoveObjectWait, 0);
  return result;
}
