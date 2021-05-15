// PiDmObjectGetAggregatedBooleanPropertyData 
 
int __fastcall PiDmObjectGetAggregatedBooleanPropertyData(int a1, int a2, int a3, int a4, unsigned int a5, _DWORD *a6, char *a7, int a8, _DWORD *a9)
{
  int v9; // r7
  int v10; // r8
  int v12; // r4
  int v13; // r6
  int *i; // r5
  unsigned int v15; // r0
  int v16; // lr
  int *v17; // r9
  int v18; // r6
  unsigned __int8 *v19; // r4
  int v20; // r3
  int v21; // r0
  int v22; // r5
  unsigned int v23; // r2
  char v24; // r5
  int v25; // r1
  unsigned int v26; // r0
  unsigned int v27; // r2
  int v28; // r0
  unsigned int v29; // r1
  __int16 v30; // r3
  int v31; // r3
  unsigned __int8 *v32; // r8
  unsigned __int8 *v33; // r10
  int v34; // r3
  int v35; // r0
  int v36; // r3
  char v37[4]; // [sp+20h] [bp-38h] BYREF
  int v38; // [sp+24h] [bp-34h]
  unsigned __int8 *v39; // [sp+28h] [bp-30h] BYREF
  char *v40; // [sp+2Ch] [bp-2Ch]
  int v41; // [sp+30h] [bp-28h] BYREF
  int v42[9]; // [sp+34h] [bp-24h] BYREF

  v38 = 0;
  v41 = a1;
  v42[0] = a2;
  v9 = -1073741802;
  v39 = 0;
  v40 = a7;
  if ( a7 )
  {
    v10 = a8;
    if ( !a8 )
      return sub_7C6868();
  }
  else
  {
    v10 = 0;
  }
  if ( !a4 && a1 < 6 )
  {
    v12 = 0;
    v13 = *(_DWORD *)(a5 + 16);
    for ( i = PiDmAggregatedBooleanDefs; ; i += 7 )
    {
      v15 = i[4];
      if ( *(_DWORD *)(v15 + 16) == v13 && !memcmp(v15, a5, 16) )
      {
        v16 = v41;
        if ( v41 == i[3] )
          break;
      }
      if ( (unsigned int)++v12 >= 3 )
        return v9;
    }
    v17 = &PiDmAggregatedBooleanDefs[7 * v12];
    if ( v17 )
    {
      *a6 = 17;
      *a9 = 1;
      if ( v10 )
      {
        v9 = PiDmGetObject(v16, v42[0], (int *)&v39);
        if ( v9 >= 0 )
        {
          v18 = v17[6];
          v19 = v39;
          v20 = __mrc(15, 0, 13, 0, 3);
          --*(_WORD *)((v20 & 0xFFFFFFC0) + 0x134);
          v21 = KeAbPreAcquire((unsigned int)v19, 0, 0);
          v22 = v21;
          do
            v23 = __ldrex(v19);
          while ( __strex(v23 | 1, v19) );
          __dmb(0xBu);
          if ( (v23 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v19, v21, (unsigned int)v19);
          if ( v22 )
            *(_BYTE *)(v22 + 14) |= 1u;
          v24 = -1;
          if ( *(_DWORD *)&v19[v18] != 0x80000000 )
          {
LABEL_23:
            if ( *(int *)&v19[v18] <= 0 )
              v24 = 0;
            v9 = 0;
            *v40 = v24;
LABEL_26:
            __pld(v19);
            v25 = *(_DWORD *)v19;
            if ( (*(_DWORD *)v19 & 0xFFFFFFF0) > 0x10 )
              v26 = v25 - 16;
            else
              v26 = 0;
            if ( (v25 & 2) != 0 )
              goto LABEL_38;
            __dmb(0xBu);
            do
              v27 = __ldrex((unsigned int *)v19);
            while ( v27 == v25 && __strex(v26, (unsigned int *)v19) );
            if ( v27 != v25 )
LABEL_38:
              ExfReleasePushLock(v19, v25);
            v28 = KeAbPostRelease((unsigned int)v19);
            v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v30 = *(_WORD *)(v29 + 0x134) + 1;
            *(_WORD *)(v29 + 308) = v30;
            if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
              KiCheckForKernelApcDelivery(v28);
            PiDmObjectRelease(v19);
            return v9;
          }
          v31 = PiDmListDefs[5 * v17[5] + 1];
          v32 = *(unsigned __int8 **)&v19[v31];
          v33 = &v19[v31];
          if ( v32 == &v19[v31] )
          {
            v36 = 0;
LABEL_50:
            *(_DWORD *)&v19[v18] = v36;
            goto LABEL_23;
          }
          while ( 1 )
          {
            v34 = PiDmListDefs[5 * v17[5] + 3];
            v35 = PnpGetObjectProperty(
                    PiPnpRtlCtx,
                    *(_DWORD *)&v32[-v34 + 12],
                    *(_DWORD *)&v32[-v34 + 20],
                    0,
                    0,
                    v17[1],
                    (int)v42,
                    (int)v37,
                    1,
                    (int)&v41,
                    0);
            v9 = v35;
            if ( v35 < 0 )
            {
              if ( v35 != -1073741275 )
                goto LABEL_26;
            }
            else if ( v42[0] == 17 )
            {
              v36 = v38;
              if ( v37[0] == -1 )
                v36 = ++v38;
              goto LABEL_47;
            }
            v36 = v38;
LABEL_47:
            v32 = *(unsigned __int8 **)v32;
            if ( v32 == v33 )
              goto LABEL_50;
          }
        }
      }
      else
      {
        v9 = -1073741789;
      }
    }
  }
  return v9;
}
