// CmpLinkHiveToMaster 
 
int __fastcall CmpLinkHiveToMaster(unsigned __int16 *a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, int a7, int a8, char a9)
{
  int v13; // r2
  BOOL v14; // r6
  int v15; // r3
  int v16; // r9
  int v17; // r2
  int v18; // r5
  int v19; // r0
  int v20; // r2
  int v21; // r0
  int v22; // r7
  int v23; // r0
  unsigned int v24; // r1
  unsigned int v25; // r1
  int v26; // r0
  int v27; // r8
  int v28; // r3
  int v29; // r2
  int v30; // r3
  int v32; // [sp+10h] [bp-A0h] BYREF
  unsigned __int16 *v33; // [sp+14h] [bp-9Ch]
  int v34; // [sp+18h] [bp-98h]
  int v35; // [sp+1Ch] [bp-94h]
  int v36; // [sp+20h] [bp-90h]
  _DWORD v37[6]; // [sp+28h] [bp-88h] BYREF
  int v38; // [sp+40h] [bp-70h]
  int v39[19]; // [sp+44h] [bp-6Ch] BYREF

  v33 = a1;
  v38 = 0;
  memset(v39, 0, sizeof(v39));
  v13 = *(_DWORD *)(a3 + 92);
  v34 = 0;
  v14 = (v13 & 0x20) != 0;
  if ( (v13 & 0x20) == 0 )
  {
    *(_DWORD *)(a3 + 92) = v13 | 0x20;
    *(_DWORD *)(a3 + 3268) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  }
  if ( CmpInitializeKcbCache(a3, a5) >= 0 )
  {
    v38 = 67;
    v39[8] = a3;
    v15 = a4 ? -1 : *(_DWORD *)(*(_DWORD *)(a3 + 32) + 36);
    v39[7] = v15;
    v37[0] = 24;
    v37[1] = a2;
    v37[2] = a1;
    v37[3] = 576;
    v37[4] = a8;
    v37[5] = 0;
    if ( ObOpenObjectByName(v37, CmKeyObjectType, 0) >= 0 )
    {
      v16 = ExAllocatePoolWithTag(1, 514, 1902660931);
      if ( v16 )
      {
        v17 = 0;
        v36 = 0;
        if ( a2 )
        {
          if ( ZwQueryObject() < 0 )
            goto LABEL_26;
          v17 = v36;
        }
        v18 = *v33 + v17 + 4;
        v19 = ExAllocatePoolWithTag(1, v18, 1885883715);
        v34 = v19;
        if ( v19 )
        {
          *(_WORD *)(a3 + 1984) = 0;
          *(_WORD *)(a3 + 1986) = v18;
          *(_DWORD *)(a3 + 1988) = v19;
          if ( a2 )
          {
            RtlAppendUnicodeToString((unsigned __int16 *)(a3 + 1984), *(_DWORD *)(v16 + 4), v20, v19);
            RtlAppendUnicodeToString((unsigned __int16 *)(a3 + 1984), (int)L"\\", v29, v30);
          }
          RtlAppendUnicodeStringToString((unsigned __int16 *)(a3 + 1984), v33);
          v21 = ObReferenceObjectByHandle(v35, 0, CmKeyObjectType, 0, &v32, 0);
          v22 = v32;
          if ( v21 >= 0 )
          {
            v23 = CmpParseCacheAddHive(a3, *(_DWORD *)(v32 + 4));
            if ( v23 >= 0 )
            {
              *(_BYTE *)(a3 + 73) = 0;
              __dmb(0xBu);
              do
              {
                v24 = __ldrex(&CmHiveIdentity);
                v25 = v24 + 1;
              }
              while ( __strex(v25, &CmHiveIdentity) );
              __dmb(0xBu);
              *(_DWORD *)(a3 + 1860) = v25;
              if ( !a9 )
                CmpLockRegistry(v23, v25);
              v26 = CmpReportNotify(
                      *(_DWORD *)(v22 + 4),
                      *(_DWORD *)(*(_DWORD *)(v22 + 4) + 20),
                      *(_DWORD *)(*(_DWORD *)(v22 + 4) + 24),
                      0,
                      1,
                      0);
              v27 = a6;
              if ( a6 )
              {
                CmpLockKcbExclusive(*(_DWORD *)(v22 + 4));
                CmpReferenceKeyControlBlock(*(_DWORD *)(v22 + 4));
                *(_DWORD *)(a3 + 2528) = *(_DWORD *)(v22 + 4);
                if ( a7 )
                  JUMPOUT(0x7D2936);
                v26 = CmpUnlockKcb(*(_DWORD *)(v22 + 4));
                v27 = a6;
              }
              if ( CmpTraceRoutine )
                JUMPOUT(0x7D2948);
              if ( !a9 )
                CmpUnlockRegistry(v26);
              ObfDereferenceObject(v22);
              v32 = 0;
              ZwClose();
              if ( v27 )
                *(_BYTE *)(a3 + 2532) = 1;
            }
          }
LABEL_26:
          if ( !v14 )
          {
            v28 = *(_DWORD *)(a3 + 92);
            *(_DWORD *)(a3 + 3268) = 0;
            *(_DWORD *)(a3 + 92) = v28 & 0xFFFFFFDF;
          }
          ExFreePoolWithTag(v16);
          JUMPOUT(0x7D2954);
        }
      }
      JUMPOUT(0x7D2930);
    }
  }
  return sub_7D291C();
}
