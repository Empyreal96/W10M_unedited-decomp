// KsepGetShimCallbacksForDriver 
 
int __fastcall KsepGetShimCallbacksForDriver(int a1, int a2)
{
  int v5; // r4
  int v6; // r0
  int v7; // r2
  int v8; // r2
  int v9; // r9
  unsigned int v10; // r2
  unsigned int v11; // r2
  char *v12; // r3
  _DWORD *v13; // r2
  int v14; // r1
  int v15; // r5
  _DWORD *v16; // r2
  _DWORD *v17; // r2
  int v18; // r1
  _DWORD *v19; // r4
  unsigned int v20; // r3
  int v21; // r1
  unsigned int v22; // r2
  unsigned int v23; // r2
  int v24; // r2
  char *v25; // r3
  __int16 v26; // r3
  unsigned int v27; // r2
  unsigned int v28; // r2
  int v29; // r1
  char *v30; // r2
  unsigned int v31; // r2
  unsigned int v32; // r2
  char *v33; // r3
  unsigned int v34; // r2
  unsigned int v35; // r2
  char *v36; // r3
  unsigned int v37; // r2
  unsigned int v38; // r2
  char *v39; // r3
  unsigned int v40; // r2
  unsigned int v41; // r2
  char *v42; // r3
  int v43; // r3
  unsigned int v44; // r1
  unsigned int v45; // r1
  char *v46; // r3
  int v47; // [sp+0h] [bp-30h] BYREF
  int v48; // [sp+4h] [bp-2Ch]
  int v49; // [sp+8h] [bp-28h]
  int v50; // [sp+Ch] [bp-24h]

  v47 = 0;
  if ( !a2 )
    return sub_7CC1F8(4, -1073740768);
  memset((_BYTE *)a2, 0, 128);
  if ( KsepIsModuleShimmed(&KseEngine, a1, &v47) )
  {
    v7 = *(_DWORD *)(v47 + 16);
    v6 = *(_DWORD *)(v47 + 12);
    v50 = v7;
    v47 = v6;
    if ( !v6 )
    {
LABEL_62:
      v5 = 0;
      __dmb(0xBu);
      do
      {
        v44 = __ldrex(KsepHistoryMessagesIndex);
        v45 = v44 + 1;
      }
      while ( __strex(v45, KsepHistoryMessagesIndex) );
      __dmb(0xBu);
      v46 = (char *)&KsepHistoryMessages + 8 * (v45 & 0x3F);
      *((_DWORD *)v46 + 1) = 0;
      *((_WORD *)v46 + 1) = 7;
      *(_WORD *)v46 = 930;
      if ( (KsepDebugFlag & 1) != 0 )
        KsepDebugPrint(9, (int)"KSE: GetShimCallbacks succeeded\n");
      KsepLogInfo(9, (int)"KSE: GetShimCallbacks succeeded\n");
      return v5;
    }
    while ( 1 )
    {
      v8 = *(_DWORD *)(v7 + 48);
      if ( (*(_DWORD *)(v8 + 16) & 4) == 0 )
      {
        v9 = *(_DWORD *)(v8 + 8);
        if ( !v9 )
        {
          __dmb(0xBu);
          do
          {
            v10 = __ldrex(&KsepHistoryErrorsIndex);
            v11 = v10 + 1;
          }
          while ( __strex(v11, &KsepHistoryErrorsIndex) );
          __dmb(0xBu);
          v12 = (char *)&KsepHistoryErrors[4 * (v11 & 0x3F)];
          *((_WORD *)v12 + 1) = 7;
          *(_WORD *)v12 = 806;
          *((_DWORD *)v12 + 1) = -1073740768;
          if ( (KsepDebugFlag & 4) != 0 )
          {
            RtlAssert((int)"CurrentShim != NULL", (int)"minkernel\\ntos\\kshim\\kseloader.c", 806, 0);
            v6 = v47;
          }
        }
        v13 = *(_DWORD **)(v9 + 24);
        v14 = 0;
        v49 = 0;
        if ( *v13 != 4 )
          break;
      }
LABEL_61:
      v7 = v50 + 52;
      v47 = --v6;
      v50 += 52;
      if ( !v6 )
        goto LABEL_62;
    }
    v15 = 0;
    while ( 1 )
    {
      v16 = &v13[v15];
      if ( *v16 == 3 )
      {
        v17 = (_DWORD *)v16[2];
        v48 = 0;
        if ( *v17 != 2 )
          break;
      }
LABEL_59:
      ++v14;
      v13 = *(_DWORD **)(v9 + 24);
      v15 = 3 * v14;
      v43 = v13[3 * v14];
      v49 = v14;
      if ( v43 == 4 )
      {
        v6 = v47;
        goto LABEL_61;
      }
    }
    v18 = 0;
    while ( 1 )
    {
      v19 = &v17[v18];
      v20 = v17[v18 + 1];
      switch ( v20 )
      {
        case 1u:
          if ( *(_DWORD *)a2 )
          {
            __dmb(0xBu);
            do
            {
              v40 = __ldrex(&KsepHistoryErrorsIndex);
              v41 = v40 + 1;
            }
            while ( __strex(v41, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v24 = v41 & 0x3F;
            v42 = (char *)&KsepHistoryErrors[4 * v24];
            *((_DWORD *)v42 + 1) = -1073741823;
            *((_WORD *)v42 + 1) = 7;
            v26 = 834;
            goto LABEL_53;
          }
          *(_DWORD *)a2 = v19[2];
          break;
        case 2u:
          if ( *(_DWORD *)(a2 + 4) )
          {
            __dmb(0xBu);
            do
            {
              v37 = __ldrex(&KsepHistoryErrorsIndex);
              v38 = v37 + 1;
            }
            while ( __strex(v38, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v24 = v38 & 0x3F;
            v39 = (char *)&KsepHistoryErrors[4 * v24];
            *((_DWORD *)v39 + 1) = -1073741823;
            *((_WORD *)v39 + 1) = 7;
            v26 = 849;
            goto LABEL_53;
          }
          *(_DWORD *)(a2 + 4) = v19[2];
          break;
        case 3u:
          if ( *(_DWORD *)(a2 + 8) )
          {
            __dmb(0xBu);
            do
            {
              v34 = __ldrex(&KsepHistoryErrorsIndex);
              v35 = v34 + 1;
            }
            while ( __strex(v35, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v24 = v35 & 0x3F;
            v36 = (char *)&KsepHistoryErrors[4 * v24];
            *((_DWORD *)v36 + 1) = -1073741823;
            *((_WORD *)v36 + 1) = 7;
            v26 = 864;
            goto LABEL_53;
          }
          *(_DWORD *)(a2 + 8) = v19[2];
          break;
        case 4u:
          if ( *(_DWORD *)(a2 + 12) )
          {
            __dmb(0xBu);
            do
            {
              v31 = __ldrex(&KsepHistoryErrorsIndex);
              v32 = v31 + 1;
            }
            while ( __strex(v32, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v24 = v32 & 0x3F;
            v33 = (char *)&KsepHistoryErrors[4 * v24];
            *((_DWORD *)v33 + 1) = -1073741823;
            *((_WORD *)v33 + 1) = 7;
            v26 = 879;
            goto LABEL_53;
          }
          *(_DWORD *)(a2 + 12) = v19[2];
          break;
        default:
          if ( v20 < 0x64 || v20 >= 0x80 )
          {
            __dmb(0xBu);
            do
            {
              v27 = __ldrex(&KsepHistoryErrorsIndex);
              v28 = v27 + 1;
            }
            while ( __strex(v28, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v29 = v28 & 0x3F;
            v30 = (char *)&KsepHistoryErrors[4 * v29];
            *((_DWORD *)v30 + 1) = -1073741811;
            *((_WORD *)v30 + 1) = 7;
            *(_WORD *)v30 = 910;
            if ( (KsepDebugFlag & 2) != 0 )
              KsepDebugPrint(9, (int)"KSE: Invalid callback code encountered: %u\n");
            KsepLogError(9, (int)"KSE: Invalid callback code encountered: %u\n", v19[1]);
            break;
          }
          v21 = a2 + 4 * v20;
          if ( *(_DWORD *)(v21 - 384) )
          {
            __dmb(0xBu);
            do
            {
              v22 = __ldrex(&KsepHistoryErrorsIndex);
              v23 = v22 + 1;
            }
            while ( __strex(v23, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v24 = v23 & 0x3F;
            v25 = (char *)&KsepHistoryErrors[4 * v24];
            *((_DWORD *)v25 + 1) = -1073741823;
            *((_WORD *)v25 + 1) = 7;
            v26 = 897;
LABEL_53:
            KsepHistoryErrors[4 * v24] = v26;
            if ( (KsepDebugFlag & 2) != 0 )
              KsepDebugPrint(9, (int)"KSE: Two shims are hooking same callback! \n");
            KsepLogError(9, (int)"KSE: Two shims are hooking same callback! \n");
            break;
          }
          *(_DWORD *)(v21 - 384) = v19[2];
          break;
      }
      ++v48;
      v18 = 4 * v48;
      v17 = *(_DWORD **)(*(_DWORD *)(v9 + 24) + v15 * 4 + 8);
      if ( v17[4 * v48] == 2 )
      {
        v14 = v49;
        goto LABEL_59;
      }
    }
  }
  return -1073741275;
}
