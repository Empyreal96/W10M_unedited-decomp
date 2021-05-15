// EtwpNotifyGuid 
 
int __fastcall EtwpNotifyGuid(int *a1, char a2)
{
  unsigned int v3; // r3
  int v4; // r6
  int v5; // r9
  int v7; // r0
  int v8; // r3
  int v9; // r8
  int v10; // r7
  int v11; // r0
  int v12; // r10
  int v13; // r4
  int v14; // r8
  int *v15; // r7
  int v16; // r9
  int v17; // r10
  int v18; // r0
  bool v19; // zf
  int v20; // r2
  int v21; // [sp+8h] [bp-30h] BYREF
  int v22; // [sp+Ch] [bp-2Ch]
  int v23; // [sp+10h] [bp-28h] BYREF
  int v24; // [sp+14h] [bp-24h]
  int v25; // [sp+18h] [bp-20h]

  v22 = 0;
  v23 = 0;
  v3 = a1[1];
  v4 = 0;
  v5 = a2;
  v21 = 0;
  if ( v3 > 0x10000 )
    return sub_8084BC();
  v7 = PsGetCurrentThreadProcessId();
  v8 = *a1;
  a1[9] = v7;
  if ( v8 == 4 )
  {
    v9 = 128;
    v10 = 0;
    v13 = EtwpCheckGuidAccess((int)PrivateLoggerSecurityGuid, 128, 0, 4);
    if ( v13 < 0 )
      return v13;
  }
  else
  {
    v9 = 4;
    v10 = 1;
  }
  v24 = a1[8];
  a1[5] = 0;
  v11 = EtwpFindGuidEntryByGuid((unsigned int)(a1 + 10), v10);
  v12 = v11;
  v25 = v11;
  if ( !v11 )
    return -1073741163;
  if ( !v5 || (v13 = EtwpAccessCheck(*(_DWORD *)(v11 + 36), v9, 0), v13 >= 0) )
  {
    KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
    v14 = v12 + 28;
    if ( *(_DWORD *)(v12 + 28) == v12 + 28 )
    {
      v13 = -1073741162;
    }
    else
    {
      if ( *((_BYTE *)a1 + 12) != 1 )
        goto LABEL_10;
      v13 = EtwpCreateUmReplyObject(v12, &v23, &v21);
      v4 = v21;
      if ( v13 >= 0 )
      {
        a1[6] = v21;
LABEL_10:
        v13 = EtwpAllocDataBlock(a1[1], a1, &v21);
        if ( v13 < 0 )
        {
          v13 = -1073741801;
        }
        else
        {
          v15 = *(int **)(v12 + 28);
          if ( v15 != (int *)v14 )
          {
            v16 = v24;
            v17 = 0;
            do
            {
              if ( (*((_BYTE *)v15 + 50) & 2) != 0
                && (*((_BYTE *)v15 + 50) & 0x40) == 0
                && (!v16 || PsGetProcessId(v15[10]) == v16) )
              {
                v18 = EtwpSendDataBlock(v15, v21);
                if ( v18 < 0 )
                  v13 = v18;
                else
                  ++v17;
              }
              v15 = (int *)*v15;
            }
            while ( v15 != (int *)v14 );
            v19 = v17 == 0;
            v22 = v17;
            v12 = v25;
            if ( !v19 )
              v13 = 0;
          }
          EtwpUnreferenceDataBlock(v21);
          v20 = v23;
          a1[5] = v22;
          *((_QWORD *)a1 + 3) = v20;
        }
        goto LABEL_22;
      }
    }
LABEL_22:
    KeReleaseMutex((int)&EtwpNotificationMutex);
    if ( v4 )
      ObfDereferenceObject(v4);
  }
  EtwpUnreferenceGuidEntry(v12);
  return v13;
}
