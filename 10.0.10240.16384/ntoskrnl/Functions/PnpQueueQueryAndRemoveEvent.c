// PnpQueueQueryAndRemoveEvent 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpQueueQueryAndRemoveEvent(int a1, _DWORD *a2, _WORD *a3, _DWORD *a4, char a5, int a6)
{
  unsigned int v7; // r6
  unsigned __int16 *v8; // r5
  unsigned int v9; // r9
  unsigned __int16 *v11; // r7
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r0
  int v16; // r7
  _DWORD *v17; // r8
  int v18; // r4
  int v19; // r6
  int v20; // r10
  int v21; // r4
  _DWORD *v22; // r9
  _DWORD *v23; // r8
  unsigned int *v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r1
  unsigned int *v27; // r1
  unsigned int v28; // r2
  unsigned int v29; // r2
  __int16 v30; // r0
  int v31; // r1
  _WORD *v32; // r2
  unsigned int v33; // r2
  _WORD *v34; // r3
  unsigned int v35; // r2
  int v36; // r3
  int v37; // r3
  int v38; // r2
  int v39; // r3
  int v40; // r5 OVERLAPPED
  int v41; // r6 OVERLAPPED
  int v42; // [sp+28h] [bp-D8h] BYREF
  unsigned __int16 *v43; // [sp+2Ch] [bp-D4h] BYREF
  _DWORD *v44; // [sp+30h] [bp-D0h]
  int v45; // [sp+34h] [bp-CCh] BYREF
  int v46; // [sp+38h] [bp-C8h]
  _WORD *v47; // [sp+3Ch] [bp-C4h] BYREF
  int v48; // [sp+40h] [bp-C0h]
  _DWORD *v49; // [sp+44h] [bp-BCh]
  unsigned int v50; // [sp+48h] [bp-B8h] BYREF
  int v51; // [sp+4Ch] [bp-B4h] BYREF
  char v52[48]; // [sp+50h] [bp-B0h] BYREF
  int *v53; // [sp+80h] [bp-80h]
  int v54; // [sp+84h] [bp-7Ch]
  int v55; // [sp+88h] [bp-78h]
  int v56; // [sp+8Ch] [bp-74h]
  int v57; // [sp+90h] [bp-70h]
  int v58; // [sp+94h] [bp-6Ch]
  unsigned int v59; // [sp+98h] [bp-68h]
  int v60; // [sp+9Ch] [bp-64h]
  int *v61; // [sp+A0h] [bp-60h]
  int v62; // [sp+A4h] [bp-5Ch]
  int v63; // [sp+A8h] [bp-58h]
  int v64; // [sp+ACh] [bp-54h]
  int *v65; // [sp+B0h] [bp-50h]
  int v66; // [sp+B4h] [bp-4Ch]
  int v67; // [sp+B8h] [bp-48h]
  int v68; // [sp+BCh] [bp-44h]
  int v69; // [sp+C0h] [bp-40h]
  int v70; // [sp+C4h] [bp-3Ch]
  int v71; // [sp+C8h] [bp-38h]
  int v72; // [sp+CCh] [bp-34h]
  _WORD **v73; // [sp+D0h] [bp-30h]
  int v74; // [sp+D4h] [bp-2Ch]
  int v75; // [sp+D8h] [bp-28h]
  int v76; // [sp+DCh] [bp-24h]

  v47 = a3;
  v7 = 0;
  v8 = 0;
  v44 = a4;
  v45 = a5 & 8;
  v49 = a2;
  v50 = 0;
  v43 = (unsigned __int16 *)a1;
  v9 = 0;
  v48 = 0;
  *a2 = 0;
  if ( (a5 & 8) != 0 )
    return sub_7DE748();
  v11 = v43;
  v12 = PnpDeviceObjectFromDeviceInstance((int)v43);
  v13 = a6;
  v46 = v12;
  if ( v12 )
  {
    v14 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 20);
    if ( v14 )
    {
      if ( v14 == IopRootDeviceNode )
      {
        v21 = -1073741790;
      }
      else
      {
        if ( !*a4 )
        {
          v8 = 0;
          v17 = 0;
          v42 = 0;
          v16 = 1;
          goto LABEL_9;
        }
        v15 = ExAllocatePoolWithTag(1, *a4 + 12, 538996816);
        v9 = v15;
        v42 = v15;
        if ( v15 )
        {
          v8 = (unsigned __int16 *)(v15 + 4);
          *(_DWORD *)(v15 + 8) = v15 + 12;
          v16 = 0;
          v13 = a6;
          *(_WORD *)(v15 + 6) = *a4;
          *(_WORD *)(v15 + 4) = 0;
          v48 = 1;
          v17 = (_DWORD *)v15;
LABEL_9:
          if ( v45 && v13 )
            v16 = 1;
          if ( (a5 & 2) != 0 )
          {
            v18 = 22;
          }
          else
          {
            if ( v45 )
            {
              v18 = 47;
              v19 = 1;
LABEL_14:
              KeInitializeEvent((int)v52, 0, 0);
              v20 = v46;
              v21 = PnpSetTargetDeviceRemove(v46, 0, (a5 & 0xB) != 0, v19, v16, v18, v52, 0, 0, &v51, v17, v8, &v50);
              if ( v21 < 0 )
              {
                v7 = v50;
              }
              else
              {
                v21 = KeWaitForSingleObject((unsigned int)v52, 0, 0, (_DWORD *)1, 0);
                v7 = v50;
                if ( v21 != 257 )
                  goto LABEL_16;
                if ( PnpRemoveEventFromQueue(v50) )
                {
                  v21 = -1073741536;
                }
                else
                {
                  __dmb(0xBu);
                  v27 = (unsigned int *)(v7 + 36);
                  do
                    v28 = __ldrex(v27);
                  while ( __strex(1u, v27) );
                  __dmb(0xBu);
                  if ( v28 )
                  {
                    v21 = KeWaitForSingleObject((unsigned int)v52, 0, 0, 0, 0);
LABEL_16:
                    if ( v21 >= 0 )
                      v21 = v51;
                    v22 = v49;
                    if ( v17 )
                      *v49 = *v17;
                    v23 = v44;
                    if ( v8 )
                    {
                      if ( *v8 )
                      {
                        if ( (unsigned int)*v8 >= *v44 )
                          *v8 = *v44 - 2;
                        memmove((int)v47, *((_DWORD *)v8 + 1), *v8);
                        v47[*v8 >> 1] = 0;
                      }
                      *v23 = *v8;
                    }
                    if ( *v22 == 6 )
                    {
                      v30 = (__int16)v47;
                      if ( v47 )
                      {
                        v31 = 0;
                        v32 = v47;
                        if ( *v47 )
                        {
                          while ( *v32 != 92 || ++v31 != 3 )
                          {
                            if ( !*++v32 )
                              goto LABEL_64;
                          }
                          *v32 = 0;
LABEL_64:
                          if ( v31 == 3 )
                            *v23 = (unsigned __int16)((_WORD)v32 - v30);
                        }
                      }
                    }
                    goto LABEL_24;
                  }
                  v21 = -1073741536;
                  *(_BYTE *)(v7 + 40) = 1;
                  __dmb(0xBu);
                  do
                    v29 = __ldrex(v27);
                  while ( __strex(0, v27) );
                  __dmb(0xBu);
                  v48 = 0;
                }
              }
LABEL_24:
              v9 = v42;
              v11 = v43;
              goto LABEL_25;
            }
            v18 = 21;
          }
          v19 = 0;
          goto LABEL_14;
        }
        v21 = -1073741670;
      }
    }
    else
    {
      v21 = -1073741810;
    }
    v20 = v46;
LABEL_25:
    ObfDereferenceObject(v20);
    if ( v7 )
    {
      __dmb(0xBu);
      v24 = (unsigned int *)(v7 + 32);
      do
      {
        v25 = __ldrex(v24);
        v26 = v25 - 1;
      }
      while ( __strex(v26, v24) );
      __dmb(0xBu);
      if ( !v26 )
        ExFreePoolWithTag(v7);
    }
    v13 = a6;
    goto LABEL_31;
  }
  v21 = -1073741810;
LABEL_31:
  if ( v45 )
  {
    v33 = v13 ? 0x80000000 : 0;
    v45 = v21;
    v34 = (_WORD *)(*v49 | v33);
    v35 = *v11;
    v47 = v34;
    LOWORD(v42) = v35 >> 1;
    v53 = &v42;
    v54 = 0;
    v55 = 2;
    v56 = 0;
    v36 = *((_DWORD *)v11 + 1);
    v59 = v35;
    v57 = v36;
    v58 = 0;
    v60 = 0;
    v61 = &v45;
    v62 = 0;
    v63 = 4;
    v64 = 0;
    v37 = v8 ? *v8 >> 1 : 0;
    v38 = v37;
    LOWORD(v43) = v37;
    v65 = (int *)&v43;
    v66 = 0;
    v67 = 2;
    v68 = 0;
    v39 = v8 ? *((_DWORD *)v8 + 1) : 0;
    v69 = v39;
    v70 = 0;
    v71 = 2 * v38;
    v72 = 0;
    v73 = &v47;
    v74 = 0;
    v75 = 4;
    v76 = 0;
    *(_QWORD *)&v40 = PnpEtwHandle;
    if ( PnpEtwHandle )
    {
      if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceEject_Stop) )
        EtwWrite(v40, v41, (int)KMPnPEvt_DeviceEject_Stop, 0);
    }
  }
  if ( v48 )
    ExFreePoolWithTag(v9);
  return v21;
}
