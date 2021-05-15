// PiDqObjectManagerEnumerateAndRegisterQuery 
 
int __fastcall PiDqObjectManagerEnumerateAndRegisterQuery(_DWORD *a1, _DWORD *a2)
{
  int v4; // r4
  _DWORD *v5; // r1
  int v6; // r3
  int *v7; // r8
  unsigned int v8; // r9
  int v9; // r2
  int v10; // r3
  int *v11; // r4
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r2
  int *v16; // r5
  char *v17; // r3
  int v18; // r0
  int v19; // r0
  int v21; // r0
  int v22; // r2
  int v23; // r3
  unsigned int v24; // r2
  int v25; // r0
  _DWORD *v26; // r1
  unsigned int *v27; // r2
  unsigned int v28; // r1
  int v29; // r0
  unsigned int v30; // r1
  int v31; // r3
  unsigned __int16 *v32; // r5
  unsigned __int16 *v33; // r8
  int i; // r3
  int v35; // r0
  int v36; // r2
  int v37; // r3
  unsigned int *v38; // [sp+8h] [bp-D0h] BYREF
  int *v39; // [sp+Ch] [bp-CCh] BYREF
  int v40; // [sp+10h] [bp-C8h]
  int v41; // [sp+18h] [bp-C0h] BYREF
  int v42[10]; // [sp+1Ch] [bp-BCh] BYREF
  int v43; // [sp+48h] [bp-90h] BYREF
  _DWORD v44[7]; // [sp+4Ch] [bp-8Ch] BYREF
  char v45[112]; // [sp+68h] [bp-70h] BYREF

  v38 = 0;
  v40 = *(_DWORD *)(a2[3] + 32);
  v4 = 0;
  v43 = 0;
  memset(v44, 0, 24);
  v41 = 0;
  memset(v42, 0, sizeof(v42));
  if ( (v40 & 1) != 0 )
  {
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v24 + 308);
    ExAcquireResourceSharedLite((int)a1, 1);
    v25 = PiDqObjectManagerLockData(a1);
    if ( (a1[31] & 2) != 0 )
    {
      v4 = -1073741670;
    }
    else
    {
      v26 = (_DWORD *)a1[27];
      *a2 = a1 + 26;
      a2[1] = v26;
      if ( (_DWORD *)*v26 != a1 + 26 )
        sub_7C75BC(v25);
      *v26 = a2;
      a1[27] = a2;
      ++a1[30];
      __dmb(0xBu);
      v27 = a2 + 28;
      do
        v28 = __ldrex(v27);
      while ( __strex(v28 + 1, v27) );
      __dmb(0xBu);
    }
    PiDqObjectManagerUnlockData(a1);
    if ( v4 < 0 )
      goto LABEL_59;
  }
  PiDqQueryLock(a2);
  v5 = (_DWORD *)a2[3];
  v6 = v5[5];
  switch ( v6 )
  {
    case 0:
      v7 = &PiDqQueryConstraintData;
      v8 = 0;
      v4 = -1073741823;
      do
      {
        v9 = *v7;
        v10 = a1[32];
        v39 = v7;
        if ( v9 == v10 )
        {
          v11 = (int *)v7[1];
          v12 = v11[1];
          v13 = v11[2];
          v14 = v11[3];
          v43 = *v11;
          v44[0] = v12;
          v44[1] = v13;
          v44[2] = v14;
          v15 = a2[3];
          v44[3] = v11[4];
          v4 = ConstraintEval(*(_DWORD *)(v15 + 52), *(_DWORD *)(v15 + 56), &v43, v7[2], &v41);
          if ( v4 != -1073741823 )
            break;
        }
        ++v8;
        v7 += 6;
      }
      while ( v8 < 5 );
      if ( v4 < 0 )
      {
        if ( v4 != -1073741823 )
          goto LABEL_19;
        v4 = PiDmEnumObjectsWithCallback(a1[32], PiDqEnumQueryObjectsCallback, a2);
        goto LABEL_16;
      }
      v16 = v39;
      if ( v42[7] != v39[3] )
        break;
      if ( v42[7] == 13 )
      {
        v4 = PnpStringFromGuid(v42[9], (int)v45);
        if ( v4 < 0 )
          goto LABEL_19;
        v17 = v45;
      }
      else
      {
        v17 = (char *)(v42[7] == 18 ? v42[9] : 0);
      }
      v18 = PiDmGetObject(v39[4], (int)v17, (int *)&v38);
      v4 = v18;
      if ( v18 == -1073741772 )
        break;
      if ( v18 < 0 )
        goto LABEL_19;
      v19 = PiDmListEnumObjectsWithCallback(v16[5], v38, (int)PiDqEnumQueryObjectsCallback, (int)a2);
      goto LABEL_14;
    case 1:
      v21 = PiDmGetObject(a1[32], v5[6], (int *)&v38);
      v4 = v21;
      if ( v21 != -1073741772 )
      {
        if ( v21 < 0 )
          goto LABEL_19;
        if ( !PiDmObjectIsEnumerable(v38) )
          goto LABEL_15;
        v19 = PiDqQueryEnumObject((int)a2, (int)v38, v22, v23);
LABEL_14:
        v4 = v19;
LABEL_15:
        PiDmObjectRelease((int)v38);
LABEL_16:
        if ( v4 < 0 )
          goto LABEL_19;
        break;
      }
      break;
    case 2:
      v32 = (unsigned __int16 *)v5[7];
      if ( *v32 )
      {
        while ( 2 )
        {
          v33 = &v32[wcslen(v32) + 1];
          for ( i = *v33; i; i = *v33 )
          {
            if ( !wcsicmp((int)v32, v33) )
              goto LABEL_56;
            v33 += wcslen(v33) + 1;
          }
          v35 = PiDmGetObject(a1[32], (int)v32, (int *)&v38);
          v4 = v35;
          if ( v35 != -1073741772 )
          {
            if ( v35 < 0 )
              goto LABEL_19;
            if ( PiDmObjectIsEnumerable(v38) )
              v4 = PiDqQueryEnumObject((int)a2, (int)v38, v36, v37);
            PiDmObjectRelease((int)v38);
            v38 = 0;
            if ( v4 < 0 )
              goto LABEL_19;
          }
LABEL_56:
          v32 += wcslen(v32) + 1;
          if ( *v32 )
            continue;
          break;
        }
      }
      break;
  }
  v4 = PiDqQueryActionQueueEntryCreate(0, 0, 0, (int)&v39);
  if ( v4 >= 0 )
  {
    PiDqQueryAppendActionEntry(a2, v39);
    a2[29] |= 0x20u;
  }
LABEL_19:
  PiDqQueryUnlock(a2);
  if ( v4 < 0 )
  {
LABEL_59:
    PiDqQueryLock(a2);
    PiDqQueryMakeInconsistent(a2);
    PiDqQueryUnlock(a2);
  }
  if ( (v40 & 1) != 0 )
  {
    v29 = ExReleaseResourceLite((int)a1);
    v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v31 = (__int16)(*(_WORD *)(v30 + 0x134) + 1);
    *(_WORD *)(v30 + 308) = v31;
    if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
      KiCheckForKernelApcDelivery(v29);
  }
  return v4;
}
