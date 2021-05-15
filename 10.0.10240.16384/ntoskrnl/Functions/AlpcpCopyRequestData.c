// AlpcpCopyRequestData 
 
int __fastcall AlpcpCopyRequestData(int a1, int a2, int *a3, int a4, unsigned int a5, int a6, unsigned int a7)
{
  unsigned int v7; // r5
  unsigned int v8; // r9
  unsigned int v9; // r10
  unsigned int v10; // r3
  _DWORD *v11; // r6
  _DWORD *v12; // r2
  int v13; // r0
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int *v18; // r5
  int v19; // r3
  int v20; // r5
  _DWORD *v21; // r4
  int v22; // r1
  int v23; // r9
  unsigned int *v24; // r6
  unsigned int v25; // r1
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // r0
  unsigned int *v29; // r2
  unsigned int *v30; // r3
  int v31; // lr
  int v32; // r9
  unsigned int *v33; // r8
  unsigned int v34; // r1
  unsigned int *v35; // r2
  unsigned int v36; // r0
  int v37; // r0
  int v38; // r10
  int v39; // r0
  int v40; // r0
  int v41; // r2
  int v42; // r9
  unsigned int *v43; // r8
  unsigned int v44; // r1
  unsigned int *v45; // r2
  unsigned int v46; // r0
  int v47; // r0
  int v49; // [sp+14h] [bp-5Ch] BYREF
  int v50; // [sp+18h] [bp-58h]
  int v51; // [sp+1Ch] [bp-54h]
  unsigned int v52; // [sp+20h] [bp-50h]
  int v53; // [sp+24h] [bp-4Ch] BYREF
  _DWORD *v54; // [sp+28h] [bp-48h] BYREF
  int v55; // [sp+38h] [bp-38h] BYREF
  int v56; // [sp+3Ch] [bp-34h]
  int v57; // [sp+40h] [bp-30h]
  int v58; // [sp+44h] [bp-2Ch]
  int v59; // [sp+48h] [bp-28h]
  int v60; // [sp+4Ch] [bp-24h]
  int varg_r0; // [sp+78h] [bp+8h]
  int varg_r1; // [sp+7Ch] [bp+Ch]
  int *varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  v52 = a4;
  varg_r3 = a4;
  v7 = (unsigned int)a3;
  v49 = a2;
  varg_r1 = a2;
  v53 = a1;
  LOBYTE(varg_r0) = a1;
  v51 = 0;
  v54 = 0;
  v50 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v50 )
  {
    v8 = a6;
    v9 = a5;
    if ( a1 )
    {
      v10 = MmUserProbeAddress;
      if ( a6 && (a5 + a6 > MmUserProbeAddress || a5 + a6 < a5) )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v10 = MmUserProbeAddress;
      }
    }
    else
    {
      ProbeForWrite(a5, a6, 1);
      v10 = MmUserProbeAddress;
    }
    if ( v7 >= v10 )
      v7 = v10;
    memmove((int)&v55, v7, 0x18u);
    v11 = (_DWORD *)a7;
    if ( a7 )
    {
      v12 = (_DWORD *)a7;
      if ( a7 >= MmUserProbeAddress )
        v12 = (_DWORD *)MmUserProbeAddress;
      *v12 = *v12;
    }
    v13 = v49;
  }
  else
  {
    v14 = *a3;
    v15 = a3[1];
    v16 = a3[2];
    v17 = *(_DWORD *)(v7 + 12);
    v18 = (int *)(v7 + 16);
    v55 = v14;
    v56 = v15;
    v57 = v16;
    v58 = v17;
    v19 = v18[1];
    v59 = *v18;
    v60 = v19;
    v11 = (_DWORD *)a7;
    v8 = a6;
    v9 = a5;
    v13 = v49;
  }
  if ( HIWORD(v56) )
  {
    v20 = ObReferenceObjectByHandle(v13, 1, AlpcPortObjectType, v50, (int)&v49, 0);
    if ( v20 < 0 )
      return v20;
    v20 = AlpcpLookupMessage(v49, v59, v60, &v54);
    if ( v20 >= 0 )
    {
      v21 = v54;
      v22 = v54[4];
      if ( v22 )
      {
        v20 = -1073741811;
        if ( *((_WORD *)v54 + 63) && (v29 = (_DWORD *)((char *)v54 + *((__int16 *)v54 + 63) + 120), *v29 > v52) )
        {
          v30 = &v29[2 * v52];
          v31 = v30[1];
          if ( v30[2] >= v8 )
            v20 = 0;
        }
        else
        {
          v31 = v51;
        }
        if ( v20 >= 0 )
        {
          if ( v53 )
          {
            v39 = __mrc(15, 0, 13, 0, 3);
            v40 = MmCopyVirtualMemory(
                    *(_DWORD *)((v39 & 0xFFFFFFC0) + 0x74),
                    v9,
                    *(_DWORD *)(v22 + 336),
                    v31,
                    v8,
                    v50,
                    (unsigned int *)&v53);
          }
          else
          {
            v41 = __mrc(15, 0, 13, 0, 3);
            v40 = MmCopyVirtualMemory(
                    *(_DWORD *)(v21[4] + 336),
                    v31,
                    *(_DWORD *)((v41 & 0xFFFFFFC0) + 0x74),
                    v9,
                    v8,
                    v50,
                    (unsigned int *)&v53);
          }
          v20 = v40;
          v52 = v40;
          if ( v40 >= 0 && v11 )
          {
            *v11 = v53;
            v38 = v49;
          }
          else
          {
            v38 = v49;
          }
          if ( AlpcpMessageLogEnabled )
            AlpcpEnterStateChangeEventMessageLog(v21);
          v42 = 0;
          if ( (*(_BYTE *)(v21 - 4) & 1) != 0 )
          {
            v42 = 0x10000 - *((__int16 *)v21 - 7);
            *((_BYTE *)v21 - 16) &= 0xFEu;
            *((_WORD *)v21 - 7) = 0;
          }
          v43 = v21 - 1;
          __dmb(0xBu);
          do
            v44 = __ldrex(v43);
          while ( __strex(v44 - 1, v43) );
          if ( (v44 & 2) != 0 && (v44 & 4) == 0 )
            ExfTryToWakePushLock(v21 - 1);
          KeAbPostRelease((unsigned int)(v21 - 1));
          if ( v42 > 0 )
          {
            __dmb(0xBu);
            v45 = v21 - 3;
            do
            {
              v46 = __ldrex(v45);
              v47 = v46 - v42;
            }
            while ( __strex(v47, v45) );
            __dmb(0xBu);
            if ( v47 <= 0 )
            {
              if ( v47 )
                KeBugCheckEx(24, 0, (int)v21, 40, v47);
              AlpcpDestroyBlob((int)v21);
            }
          }
          goto LABEL_84;
        }
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v54);
        v32 = 0;
        if ( (*(_BYTE *)(v21 - 4) & 1) != 0 )
        {
          v32 = 0x10000 - *((__int16 *)v21 - 7);
          *((_BYTE *)v21 - 16) &= 0xFEu;
          *((_WORD *)v21 - 7) = 0;
        }
        v33 = v21 - 1;
        __dmb(0xBu);
        do
          v34 = __ldrex(v33);
        while ( __strex(v34 - 1, v33) );
        if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
          ExfTryToWakePushLock(v21 - 1);
        KeAbPostRelease((unsigned int)(v21 - 1));
        if ( v32 > 0 )
        {
          __dmb(0xBu);
          v35 = v21 - 3;
          do
          {
            v36 = __ldrex(v35);
            v37 = v36 - v32;
          }
          while ( __strex(v37, v35) );
          __dmb(0xBu);
          if ( v37 <= 0 )
          {
            if ( v37 )
              KeBugCheckEx(24, 0, (int)v21, 40, v37);
            AlpcpDestroyBlob((int)v21);
          }
        }
      }
      else
      {
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v54);
        v23 = 0;
        if ( (*(_BYTE *)(v21 - 4) & 1) != 0 )
        {
          v23 = 0x10000 - *((__int16 *)v21 - 7);
          *((_BYTE *)v21 - 16) &= 0xFEu;
          *((_WORD *)v21 - 7) = 0;
        }
        v24 = v21 - 1;
        __dmb(0xBu);
        do
          v25 = __ldrex(v24);
        while ( __strex(v25 - 1, v24) );
        if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
          ExfTryToWakePushLock(v21 - 1);
        KeAbPostRelease((unsigned int)(v21 - 1));
        if ( v23 > 0 )
        {
          __dmb(0xBu);
          v26 = v21 - 3;
          do
          {
            v27 = __ldrex(v26);
            v28 = v27 - v23;
          }
          while ( __strex(v28, v26) );
          __dmb(0xBu);
          if ( v28 <= 0 )
          {
            if ( v28 )
              KeBugCheckEx(24, 0, (int)v21, 40, v28);
            AlpcpDestroyBlob((int)v21);
          }
        }
        v20 = -1073741790;
      }
    }
    v38 = v49;
LABEL_84:
    ObfDereferenceObject(v38);
    return v20;
  }
  return -1073741811;
}
