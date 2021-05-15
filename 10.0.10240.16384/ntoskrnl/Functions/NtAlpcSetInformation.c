// NtAlpcSetInformation 
 
int __fastcall NtAlpcSetInformation(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int *v5; // r9
  unsigned int v6; // r5
  int v7; // r4
  int v8; // r5
  _DWORD *v9; // r8
  int v10; // r1
  _DWORD *v11; // r5
  int v12; // r2
  int v13; // r0
  unsigned __int8 *v14; // r4
  int v15; // r0
  int v16; // r6
  unsigned int v17; // r2
  unsigned int v18; // r1
  unsigned int *v19; // r6
  int v20; // r0
  int v21; // r4
  unsigned int v22; // r2
  unsigned int v23; // r1
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r2
  unsigned int v27; // r2
  int v28; // r0
  int v29; // r6
  unsigned int v30; // r2
  unsigned int v31; // r1
  __int16 v32; // r3
  int v34; // [sp+8h] [bp-68h] BYREF
  char v35; // [sp+Ch] [bp-64h]
  int v36; // [sp+10h] [bp-60h]
  unsigned int v37; // [sp+14h] [bp-5Ch]
  _DWORD *v38; // [sp+18h] [bp-58h]
  int v39; // [sp+1Ch] [bp-54h]
  _DWORD _20[26]; // [sp+20h] [bp-50h] BYREF

  _20[22] = a1;
  _20[24] = a3;
  _20[25] = a4;
  v5 = (int *)a3;
  v39 = a2;
  _20[23] = a2;
  v34 = a1;
  v36 = a1;
  v37 = a3;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  if ( a1 && (a3 || a2 == 7 || a2 == 10) )
  {
    v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v35 = v8;
    v9 = (_DWORD *)a3;
    v38 = (_DWORD *)a3;
    if ( a4 && v8 )
    {
      if ( a4 > 0x2C )
      {
        v7 = -1073741820;
        goto LABEL_92;
      }
      if ( a3 >= MmUserProbeAddress )
      {
        v5 = (int *)MmUserProbeAddress;
        v37 = MmUserProbeAddress;
      }
      memmove((int)_20, (int)v5, a4);
      v9 = _20;
      v38 = _20;
      a1 = v34;
    }
    a1 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v8, &v34);
    v7 = a1;
    if ( a1 >= 0 )
    {
      switch ( v39 )
      {
        case 1:
          if ( a4 != 44 )
          {
            v7 = -1073741820;
            goto LABEL_90;
          }
          v10 = *v9;
          v11 = (_DWORD *)v34;
          if ( (*v9 & 0xFE00FFFF) != 0 )
            goto LABEL_26;
          v12 = *(_DWORD *)(v34 + 152);
          if ( ((v10 ^ v12) & 0x40000) != 0 )
            goto LABEL_26;
          *(_DWORD *)(v34 + 152) = v12 & 0xFE00FFFF | v10;
          goto LABEL_91;
        case 2:
          v11 = (_DWORD *)v34;
          if ( a4 == 8 )
          {
            v13 = AlpcpAssociateIoCompletionPort(v34, v9[1], *v9);
            goto LABEL_23;
          }
          v7 = -1073741820;
          goto LABEL_91;
        case 5:
          v11 = (_DWORD *)v34;
          if ( a4 == 8 )
            goto LABEL_43;
          goto LABEL_26;
        case 6:
          v11 = (_DWORD *)v34;
          if ( (*(_DWORD *)(v34 + 244) & 6) != 2 || a4 != 16 )
            goto LABEL_26;
          v13 = AlpcpInitializeCompletionList(v34, *v9, v9[1], v9[2], v9[3], 0);
LABEL_23:
          v7 = v13;
          goto LABEL_91;
        case 7:
          v11 = (_DWORD *)v34;
          if ( a4 )
            goto LABEL_26;
          v14 = (unsigned __int8 *)(v34 + 208);
          v15 = KeAbPreAcquire(v34 + 208, 0, 0);
          v16 = v15;
          do
            v17 = __ldrex(v14);
          while ( __strex(v17 | 1, v14) );
          __dmb(0xBu);
          if ( (v17 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v11 + 52, v15, (unsigned int)(v11 + 52));
          if ( v16 )
            *(_BYTE *)(v16 + 14) |= 1u;
          if ( v11[53] )
            AlpcpFreeCompletionList(v11);
          __dmb(0xBu);
          do
            v18 = __ldrex((unsigned int *)v14);
          while ( __strex(v18 - 1, (unsigned int *)v14) );
          goto LABEL_39;
        case 8:
          if ( a4 != 4 )
            goto LABEL_89;
          v11 = (_DWORD *)v34;
          if ( *v9 )
          {
            v19 = (unsigned int *)(v34 + 208);
            v24 = KeAbPreAcquire(v34 + 208, 0, 0);
            v25 = v24;
            do
              v26 = __ldrex(v19);
            while ( !v26 && __strex(0x11u, v19) );
            __dmb(0xBu);
            if ( v26 )
              ExfAcquirePushLockSharedEx(v11 + 52, v24, (unsigned int)(v11 + 52));
            if ( v25 )
              *(_BYTE *)(v25 + 14) |= 1u;
            if ( v11[53] )
            {
              AlpcpAdjustCompletionListConcurrencyCount(v11, *v9);
              v7 = 0;
            }
            else
            {
              v7 = -1073741811;
            }
            __dmb(0xBu);
            do
              v27 = __ldrex(v19);
            while ( v27 == 17 && __strex(0, v19) );
            if ( v27 != 17 )
              ExfReleasePushLockShared(v11 + 52);
LABEL_59:
            KeAbPostRelease((unsigned int)v19);
          }
          else
          {
LABEL_26:
            v7 = -1073741811;
          }
LABEL_91:
          a1 = ObfDereferenceObject((int)v11);
          break;
        case 9:
          if ( v8 )
            goto LABEL_89;
          ObfReferenceObject(*v5);
          v11 = (_DWORD *)v34;
          v14 = (unsigned __int8 *)(v34 + 208);
          v28 = KeAbPreAcquire(v34 + 208, 0, 0);
          v29 = v28;
          do
            v30 = __ldrex(v14);
          while ( __strex(v30 | 1, v14) );
          __dmb(0xBu);
          if ( (v30 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v14, v28, (unsigned int)v14);
          if ( v29 )
            *(_BYTE *)(v29 + 14) |= 1u;
          v11[54] = *v5;
          v11[55] = v5[1];
          __dmb(0xBu);
          do
            v18 = __ldrex((unsigned int *)v14);
          while ( __strex(v18 - 1, (unsigned int *)v14) );
LABEL_39:
          if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v14);
          KeAbPostRelease((unsigned int)v14);
LABEL_43:
          v7 = 0;
          goto LABEL_91;
        case 10:
          v11 = (_DWORD *)v34;
          if ( a4 )
            goto LABEL_26;
          v19 = (unsigned int *)(v34 + 208);
          v20 = KeAbPreAcquire(v34 + 208, 0, 0);
          v21 = v20;
          do
            v22 = __ldrex((unsigned __int8 *)v19);
          while ( __strex(v22 | 1, (unsigned __int8 *)v19) );
          __dmb(0xBu);
          if ( (v22 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v11 + 52, v20, (unsigned int)(v11 + 52));
          if ( v21 )
            *(_BYTE *)(v21 + 14) |= 1u;
          if ( v11[53] )
          {
            v11[61] &= 0xFFFEFFFF;
            v7 = 0;
          }
          else
          {
            v7 = -1073741811;
          }
          __dmb(0xBu);
          do
            v23 = __ldrex(v19);
          while ( __strex(v23 - 1, v19) );
          if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
            ExfTryToWakePushLock(v11 + 52);
          goto LABEL_59;
        default:
LABEL_89:
          v7 = -1073741811;
LABEL_90:
          v11 = (_DWORD *)v34;
          goto LABEL_91;
      }
    }
  }
  else
  {
    v7 = -1073741811;
  }
LABEL_92:
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = *(_WORD *)(v31 + 0x134) + 1;
  *(_WORD *)(v31 + 308) = v32;
  if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v7;
}
