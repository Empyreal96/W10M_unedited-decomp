// sub_7DD684 
 
int __fastcall sub_7DD684(int a1, int a2, int a3, char a4)
{
  unsigned __int16 *v5; // r2
  unsigned int v6; // r0
  int v7; // r4
  int v8; // r5
  int v9; // r6
  __int64 v10; // kr00_8
  int v11; // r9
  int v12; // r8
  int v13; // r1
  int v14; // r4
  int v15; // r7
  _DWORD *v16; // r0
  int v17; // r2
  char v18; // r4
  int v19; // r7
  unsigned int v20; // r3
  unsigned int v21; // r2
  unsigned __int8 *v22; // r5
  int v23; // r0
  int v24; // r6
  unsigned int v25; // r2
  int v26; // r2
  int v27; // r1
  unsigned int v28; // r2
  int v29; // r0
  unsigned int v30; // r1
  int v31; // r3
  int v32; // r5
  int v33; // r10
  int v34; // r4
  bool v35; // zf
  int v36; // r1
  unsigned int v37; // r0
  int v38; // r5
  unsigned int *v39; // r4
  int v40; // r1
  unsigned int v41; // r0
  unsigned int v42; // r2
  int v43; // r0
  unsigned int v44; // r1
  int v45; // r3
  int v46; // [sp+8h] [bp-70h]
  int v47; // [sp+Ch] [bp-6Ch]
  int v48; // [sp+10h] [bp-68h] BYREF
  int v49; // [sp+14h] [bp-64h]
  int v50; // [sp+18h] [bp-60h]
  int v51[4]; // [sp+20h] [bp-58h] BYREF
  int v52; // [sp+30h] [bp-48h]
  int v53; // [sp+38h] [bp-40h] BYREF
  int v54; // [sp+3Ch] [bp-3Ch]
  unsigned __int8 v55; // [sp+4Ah] [bp-2Eh]
  unsigned __int8 v56; // [sp+4Bh] [bp-2Dh]
  int v57; // [sp+4Ch] [bp-2Ch]
  int (*v58)(void); // [sp+74h] [bp-4h]

  v34 = v33 - *(unsigned __int8 *)((a4 & 3) + a3);
  if ( v34 )
  {
    if ( *(_DWORD *)(*(_DWORD *)v34 + 152) )
    {
      if ( *(_WORD *)(v34 + 4) == 4 )
      {
        v5 = *(unsigned __int16 **)(v34 + 8);
        if ( v5[1] == 58 )
        {
          v6 = RtlUpcaseUnicodeChar(*v5);
          if ( v6 <= 0x5A && v6 >= 0x41 )
          {
            *(_DWORD *)(v32 + 16) = v6 - 64;
            v15 = 0;
            v49 = *(_DWORD *)v34;
            v46 = 0;
            v47 = 0;
            v55 = 0;
            v53 = 0;
            v54 = 0;
            v57 = -60876;
            v56 = 0;
            if ( PsGetSiloObject(-1, (int)&ObpDirectoryObjectType, (int)&v48, -60876) < 0 )
            {
              v7 = ObpRootDirectoryObject;
              v48 = ObpRootDirectoryObject;
              if ( ObpRootDirectoryObject )
                ObfReferenceObject(ObpRootDirectoryObject);
            }
            else
            {
              v7 = v48;
            }
            v10 = *(_QWORD *)(v32 + 8);
            v8 = *(_DWORD *)(v32 + 12);
            v9 = v10;
            v11 = v7;
            v52 = v10;
            PsGetMonitorContextServerSilo(ObSiloMonitor, -1, v51);
            v12 = v51[0];
LABEL_11:
            if ( (v8 & 7) != 0 || (v13 = **(_DWORD **)v12) == 0 )
            {
              v14 = (unsigned __int16)v52;
            }
            else
            {
              v14 = (unsigned __int16)v52;
              if ( (unsigned __int16)v52 >= 8u )
              {
                if ( *(_DWORD *)v8 == *(_DWORD *)ObpDosDevicesShortNamePrefix )
                {
                  v15 = v46;
                  if ( *(_DWORD *)(v8 + 4) == *(_DWORD *)&ObpDosDevicesShortNamePrefix[2] )
                  {
                    v8 += 8;
                    v14 = (unsigned __int16)(v52 - 8);
                    LOWORD(v52) = v52 - 8;
                    v9 = v52;
                    v11 = v13;
                  }
                }
                else
                {
                  v15 = v46;
                }
              }
            }
            while ( 1 )
            {
              if ( *(_WORD *)v8 == 92 )
              {
                v8 += 2;
                v14 = (unsigned __int16)(v14 - 2);
                LOWORD(v52) = v14;
                v9 = v52;
              }
              v51[0] = v9;
              v51[1] = v8;
              if ( v14 )
              {
                do
                {
                  if ( *(_WORD *)v8 == 92 )
                    break;
                  v14 = (unsigned __int16)(v14 - 2);
                  v8 += 2;
                  LOWORD(v52) = v14;
                }
                while ( v14 );
                v9 = v52;
              }
              LOWORD(v51[0]) -= v14;
              if ( !LOWORD(v51[0]) )
                break;
              if ( v11 == v49 )
              {
                v55 = 1;
                v56 = 1;
              }
              else
              {
                v47 = 0;
                v15 = 0;
              }
              v46 = v15;
              v16 = (_DWORD *)ObpLookupDirectoryEntry(v11, (unsigned __int16 *)v51, 0, 0, (int)&v53);
              if ( v11 == v49 )
              {
                v56 = v15;
                v55 = v47;
              }
              else
              {
                v15 = v56;
                v46 = v56;
                v47 = v55;
              }
              if ( !v16 )
                goto LABEL_32;
              v17 = ObTypeIndexTable[*((unsigned __int8 *)v16 - 12) ^ (unsigned __int8)((unsigned __int16)((_WORD)v16 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
              if ( v17 != ObpDirectoryObjectType )
              {
                if ( v17 == ObpSymbolicLinkObjectType && !v16[4] )
                {
                  if ( v50 )
                  {
                    v8 = v16[3];
                    v9 = v16[2];
                    --v50;
                    v52 = v9;
                    v11 = v48;
                    goto LABEL_11;
                  }
                  v16 = 0;
                }
LABEL_32:
                v18 = 1;
                v19 = *(_DWORD *)(*(_DWORD *)(v33 - ObpInfoMaskToOffset[*(_BYTE *)(v33 + 14) & 3]) + 152);
                if ( v16
                  && ObTypeIndexTable[*((unsigned __int8 *)v16 - 12) ^ (unsigned __int8)((unsigned __int16)((_WORD)v16 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie] == IoDeviceObjectType )
                {
                  v20 = v16[11];
                  if ( v20 > 0x13 )
                  {
                    if ( v20 == 20 )
                      goto LABEL_79;
                    if ( v20 != 36 )
                    {
                      v35 = v20 == 40;
                      goto LABEL_76;
                    }
                    v18 = 6;
                  }
                  else
                  {
                    if ( v20 < 0x12 )
                    {
                      if ( v20 < 2 )
                        goto LABEL_77;
                      if ( v20 <= 3 )
                      {
                        v18 = 5;
                        goto LABEL_42;
                      }
                      if ( v20 <= 6 )
                        goto LABEL_77;
                      if ( v20 <= 9 )
                      {
                        if ( (v16[8] & 1) != 0 )
                          v18 = 2;
                        else
                          v18 = 3;
                        goto LABEL_42;
                      }
                      v35 = v20 == 16;
LABEL_76:
                      if ( !v35 )
                      {
LABEL_77:
                        v18 = 0;
                        goto LABEL_42;
                      }
                    }
LABEL_79:
                    v18 = 4;
                  }
                }
LABEL_42:
                v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                --*(_WORD *)(v21 + 310);
                v22 = (unsigned __int8 *)(v12 + 112);
                v23 = KeAbPreAcquire(v12 + 112, 0, 0);
                v24 = v23;
                do
                  v25 = __ldrex(v22);
                while ( __strex(v25 | 1, v22) );
                __dmb(0xBu);
                if ( (v25 & 1) != 0 )
                  ExfAcquirePushLockExclusiveEx((_DWORD *)(v12 + 112), v23, v12 + 112);
                if ( v24 )
                  *(_BYTE *)(v24 + 14) |= 1u;
                v26 = *(_DWORD *)(v51[2] + 16);
                *(_BYTE *)(v26 + v19 + 19) = v18;
                v27 = 1 << (v26 - 1);
                *(_DWORD *)(v19 + 16) |= v27;
                if ( v19 == *(_DWORD *)v12 )
                  *(_DWORD *)(v12 + 4) |= v27;
                else
                  ++*(_DWORD *)(v12 + 4 * v26 + 4);
                __pld(v22);
                v36 = *(_DWORD *)v22;
                if ( (*(_DWORD *)v22 & 0xFFFFFFF0) <= 0x10 )
                  v37 = 0;
                else
                  v37 = v36 - 16;
                if ( (v36 & 2) != 0 )
                  goto LABEL_85;
                __dmb(0xBu);
                do
                  v28 = __ldrex((unsigned int *)v22);
                while ( v28 == v36 && __strex(v37, (unsigned int *)v22) );
                if ( v28 != v36 )
LABEL_85:
                  ExfReleasePushLock((_DWORD *)(v12 + 112), v36);
                v29 = KeAbPostRelease(v12 + 112);
                v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                v31 = (__int16)(*(_WORD *)(v30 + 0x136) + 1);
                *(_WORD *)(v30 + 310) = v31;
                if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 )
                  KiCheckForKernelApcDelivery(v29);
                break;
              }
              v11 = (int)v16;
            }
            if ( v47 )
            {
              v38 = v53;
              v39 = (unsigned int *)(v53 + 148);
              __pld((void *)(v53 + 148));
              v40 = *v39;
              if ( (*v39 & 0xFFFFFFF0) <= 0x10 )
                v41 = 0;
              else
                v41 = v40 - 16;
              if ( (v40 & 2) != 0 )
                goto LABEL_97;
              __dmb(0xBu);
              do
                v42 = __ldrex(v39);
              while ( v42 == v40 && __strex(v41, v39) );
              if ( v42 != v40 )
LABEL_97:
                ExfReleasePushLock(v39, v40);
              KeAbPostRelease((unsigned int)v39);
              v43 = ObfDereferenceObject(v38);
              v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v45 = (__int16)(*(_WORD *)(v44 + 0x134) + 1);
              *(_WORD *)(v44 + 308) = v45;
              if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 && !*(_WORD *)(v44 + 310) )
                KiCheckForKernelApcDelivery(v43);
            }
            if ( v54 )
              ObfDereferenceObject(v54);
            ObfDereferenceObject(v48);
            PsDereferenceMonitorContextServerSilo(v12);
          }
        }
      }
    }
  }
  return v58();
}
