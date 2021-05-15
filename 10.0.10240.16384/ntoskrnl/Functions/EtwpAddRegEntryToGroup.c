// EtwpAddRegEntryToGroup 
 
int __fastcall EtwpAddRegEntryToGroup(int a1, unsigned int a2, int a3, unsigned int a4, unsigned int *a5)
{
  int v7; // r7
  int v9; // r0
  int v10; // r6
  int v11; // r4
  unsigned __int8 v12; // r10
  char v13; // r8
  int v14; // r2
  int v15; // r9
  int v16; // r3
  unsigned int *v17; // r8
  _DWORD *v18; // r9
  int v19; // r0
  _DWORD *v20; // r6
  int v21; // r0
  void (__fastcall *v22)(GUID *, int, _DWORD); // r8
  unsigned int v23; // r4
  __int64 v24; // r0
  int v25; // r2
  int v26; // r1
  unsigned __int8 v27; // r4
  int v28; // r0
  int v29; // r3
  _DWORD *v30; // r10
  _DWORD *v31; // r4
  unsigned int v32; // r0
  unsigned int v33; // r1
  int v34; // r0
  int v35; // r3
  _DWORD *v36; // r0
  unsigned int v37; // r4
  unsigned int v38; // r1
  int v39; // r0
  int v40; // r2
  int v41; // r1
  int v42; // [sp+0h] [bp-88h]
  int v43; // [sp+4h] [bp-84h]
  int v44; // [sp+8h] [bp-80h]
  char v45[4]; // [sp+18h] [bp-70h] BYREF
  int v46; // [sp+1Ch] [bp-6Ch]
  _DWORD *v47; // [sp+20h] [bp-68h]
  unsigned int *v48; // [sp+24h] [bp-64h]
  _DWORD *v49; // [sp+28h] [bp-60h]
  int v50; // [sp+30h] [bp-58h] BYREF
  int v51[7]; // [sp+34h] [bp-54h] BYREF
  _DWORD v52[14]; // [sp+50h] [bp-38h] BYREF

  v48 = a5;
  v49 = (_DWORD *)a3;
  v47 = 0;
  v7 = EtwpFindGuidEntryByGuid(a2, 2);
  if ( !v7 )
    return sub_8081DC();
  *a5 = 120;
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  if ( *(_DWORD *)(a1 + 20) )
  {
LABEL_31:
    v10 = 0;
    goto LABEL_18;
  }
  v9 = EtwpGetSchematizedFilterSize(*(_DWORD *)(a1 + 16));
  v46 = v9;
  if ( v9 )
    *a5 += v9 + 16;
  if ( (*(_BYTE *)(a1 + 50) & 2) == 0 || *a5 <= a4 )
  {
    EtwpReferenceGuidEntry(v7);
    HIDWORD(v24) = v7 + 28;
    *(_DWORD *)(a1 + 20) = v7;
    LODWORD(v24) = *(_DWORD *)(v7 + 28);
    v25 = a1 + 8;
    *(_QWORD *)(a1 + 8) = v24;
    if ( *(_DWORD *)(v24 + 4) != v7 + 28 )
      __fastfail(3u);
    *(_DWORD *)(v24 + 4) = v25;
    *(_DWORD *)HIDWORD(v24) = v25;
    if ( *(_DWORD *)(v7 + 56) )
    {
      v11 = 0;
      v12 = 0;
      v13 = 0;
      do
      {
        v14 = v7 + 32 * v11;
        if ( *(_DWORD *)(v14 + 88) )
        {
          v20 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(*(unsigned __int16 *)(v14 + 94), 0);
          if ( EtwpIsGuidAllowed(v20 + 161, *(_DWORD *)(a1 + 16) + 12) )
          {
            v21 = v20[143] ? EtwpAccessCheckFromState(*(_DWORD *)(a1 + 16) + 12) : -1073741790;
            if ( v21 >= 0 )
              v13 += 1 << v11;
          }
          EtwpReleaseLoggerContext(v20, 0);
        }
        v11 = ++v12;
      }
      while ( v12 < 8u );
      v10 = 0;
      v45[0] = v13;
      EtwpApplyScopeFilters(a1, 0, 2, v45, v42, v43, v44);
      v15 = v46;
      v16 = (unsigned __int8)(v45[0] & v13);
      v17 = v48;
      *(_BYTE *)(a1 + 52) = v16;
      if ( v16 )
      {
        if ( (*(_BYTE *)(a1 + 50) & 0x20) != 0 )
        {
          v26 = 0;
          v27 = 0;
          v46 = 0;
          do
          {
            if ( ((1 << v26) & *(unsigned __int8 *)(a1 + 52)) != 0 )
            {
              v28 = EtwpAcquireLoggerContextByLoggerId(*(unsigned __int16 *)(*(_DWORD *)(a1 + 20) + 32 * v26 + 94), 0);
              v29 = *(unsigned __int8 *)(a1 + 50);
              v30 = (_DWORD *)v28;
              if ( (v29 & 1) != 0 )
              {
                EtwpProviderArrivalCallback(v28, 0, a1, v29);
              }
              else
              {
                v31 = (_DWORD *)(*(_DWORD *)(a1 + 40) + 172);
                __pld(v31);
                v32 = *v31 & 0xFFFFFFFE;
                do
                  v33 = __ldrex(v31);
                while ( v33 == v32 && __strex(v32 + 2, v31) );
                __dmb(0xBu);
                if ( v33 == v32 )
                  v34 = 1;
                else
                  v34 = ExfAcquireRundownProtection(v31);
                if ( v34 )
                {
                  KiStackAttachProcess(*(_DWORD *)(a1 + 40), 0, (int)v52);
                  EtwpProviderArrivalCallback((int)v30, 1, a1, v35);
                  KiUnstackDetachProcess((unsigned int)v52, 0);
                  v36 = (_DWORD *)(*(_DWORD *)(a1 + 40) + 172);
                  __pld(v36);
                  v37 = *v36 & 0xFFFFFFFE;
                  __dmb(0xBu);
                  do
                    v38 = __ldrex(v36);
                  while ( v38 == v37 && __strex(v37 - 2, v36) );
                  if ( v38 != v37 )
                    ExfReleaseRundownProtection((unsigned __int8 *)v36);
                }
                v27 = v46;
              }
              EtwpReleaseLoggerContext(v30, 0);
            }
            v26 = ++v27;
            v46 = v27;
          }
          while ( v27 < 8u );
          v17 = v48;
        }
        if ( (*(_BYTE *)(a1 + 50) & 1) != 0 )
        {
          v22 = *(void (__fastcall **)(GUID *, int, _DWORD))(a1 + 44);
          if ( v22 )
          {
            v50 = 0;
            v23 = 0;
            memset(v51, 0, sizeof(v51));
            EtwpComputeRegEntryEnableInfo(a1, &v50);
            if ( v15 )
            {
              v39 = ExAllocatePoolWithTag(1, v15, 1182233669);
              v23 = v39;
              if ( v39 )
              {
                v47 = v52;
                v40 = *(unsigned __int8 *)(a1 + 51);
                v41 = *(_DWORD *)(a1 + 16);
                v52[0] = v39;
                v52[1] = 0;
                v52[2] = v15;
                v52[3] = 0x80000000;
                EtwpCopySchematizedFilters(v39, v41, v40);
              }
            }
            v22(&NullGuid, 1, LOBYTE(v51[0]));
            if ( v23 )
              ExFreePoolWithTag(v23);
          }
        }
        else
        {
          v18 = v49;
          EtwpComputeRegEntryEnableInfo(a1, v49 + 18);
          *v17 = 120;
          v19 = EtwpGetSchematizedFilterSize(*(_DWORD *)(a1 + 16));
          if ( v19 )
          {
            *v17 = v19 + 136;
            v18[32] = v19;
            v18[33] = 0x80000000;
            v18[30] = 136;
            v18[31] = 0;
            EtwpCopySchematizedFilters(v18 + 34, *(_DWORD *)(a1 + 16), *(unsigned __int8 *)(a1 + 51));
            v18[29] = 1;
          }
          else
          {
            v18[29] = 0;
          }
        }
        goto LABEL_18;
      }
      *v17 = 0;
    }
    else
    {
      *a5 = 0;
    }
    goto LABEL_31;
  }
  v10 = -1073741789;
LABEL_18:
  KeReleaseMutex((int)&EtwpNotificationMutex);
  EtwpUnreferenceGuidEntry(v7);
  return v10;
}
