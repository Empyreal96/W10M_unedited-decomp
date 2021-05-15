// EtwpRealtimeSaveBuffer 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpRealtimeSaveBuffer(int a1, int a2)
{
  signed __int64 v2; // kr08_8
  unsigned int v4; // r5
  unsigned int v5; // r0
  int v6; // r3
  unsigned int v7; // r7 OVERLAPPED
  unsigned int v8; // r8 OVERLAPPED
  int v10; // r5
  __int64 v11; // kr20_8
  unsigned int v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // kr04_4
  int v16; // r3
  __int64 v17; // kr30_8
  __int64 v18; // kr38_8
  __int64 v19; // kr40_8
  unsigned __int64 v21; // [sp+20h] [bp-28h]

  v2 = *(_QWORD *)(a1 + 296);
  v4 = *(_DWORD *)(a1 + 292);
  v5 = *(_DWORD *)(a1 + 288);
  v6 = a2;
  *(_QWORD *)&v7 = *(_QWORD *)(a1 + 304);
  v21 = __PAIR64__(v4, v5);
  if ( __SPAIR64__(v4, v5) >= v2 )
  {
    if ( (signed __int64)(__PAIR64__(v4, *(_DWORD *)(a2 + 48)) + v5) > *(_QWORD *)(a1 + 320) )
      return sub_81A33C();
    if ( __SPAIR64__(v4, v5) >= v2 )
      goto LABEL_6;
    v6 = a2;
  }
  if ( (__int64)(__PAIR64__(v4, *(_DWORD *)(v6 + 48)) + v5) >= v2 )
  {
    ++*(_DWORD *)(a1 + 188);
    *(_DWORD *)(a1 + 352) = 2;
    v17 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
    if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_BACKING_FILE_FULL) )
      EtwpEventWriteTemplateBackingFile(v17, HIDWORD(v17));
    return -1073741432;
  }
LABEL_6:
  v10 = ZwWriteFile();
  if ( v10 < 0 )
  {
    ++*(_DWORD *)(a1 + 188);
    *(_DWORD *)(a1 + 352) = 2;
    v19 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
    if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_WRITE_FAILED) )
      EtwpEventWriteTemplateAdmin(v19, HIDWORD(v19), ETW_EVENT_WRITE_FAILED);
  }
  else
  {
    v11 = v21 + *(unsigned int *)(a2 + 48);
    *(_QWORD *)(a1 + 288) = v11;
    if ( __SPAIR64__(v8, v7) <= v11 )
    {
      v8 = HIDWORD(v11);
      v7 = v11;
    }
    v12 = *(_DWORD *)(a1 + 316);
    v13 = *(_DWORD *)(a1 + 312);
    *(_QWORD *)(a1 + 304) = *(_QWORD *)&v7;
    v14 = *(_DWORD *)(a2 + 48);
    v15 = v13;
    *(_DWORD *)(a1 + 312) = v13 + v14;
    v16 = *(_DWORD *)(a1 + 328);
    *(_DWORD *)(a1 + 316) = (__PAIR64__(v12, v15) + v14) >> 32;
    *(_DWORD *)(a1 + 328) = v16 + 1;
    if ( !EtwpIsRealtimeLogfileSpaceAvailable(a1) && *(int *)(a1 + 16) >= 0 )
    {
      *(_DWORD *)(a1 + 16) = -1073741432;
      v18 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
      if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_BACKING_FILE_FULL) )
        EtwpEventWriteTemplateBackingFile(v18, HIDWORD(v18));
    }
  }
  return v10;
}
