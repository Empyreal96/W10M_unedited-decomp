// WmipReceiveNotifications 
 
int __fastcall WmipReceiveNotifications(_DWORD *a1, int *a2, int a3)
{
  _DWORD *v3; // r7
  unsigned int v4; // r6
  int v7; // r3
  int v8; // r2
  int v9; // r1
  unsigned int v10; // r5
  unsigned int v11; // r9
  int *v12; // r3
  int v13; // r0
  int v14; // r10
  _DWORD *v15; // r0
  int v16; // r2
  char *v17; // r1
  _DWORD *v18; // t1
  unsigned int v19; // r9
  int v20; // r2
  unsigned int v21; // r0
  char *v22; // r7
  _DWORD *v23; // t1
  _DWORD *v24; // r6
  _DWORD *v25; // r1
  int v26; // r6
  unsigned int *v27; // r9
  unsigned int v28; // r1
  char *v29; // r6
  int v30; // t1
  unsigned int v31; // r8
  unsigned int v32; // r6
  char *v33; // r10
  unsigned int v34; // r6
  int v35; // r0
  int v36; // t1
  unsigned int v37; // r2
  int v38; // [sp+10h] [bp-E0h]
  int v39; // [sp+14h] [bp-DCh]
  int v40; // [sp+18h] [bp-D8h]
  int v42; // [sp+20h] [bp-D0h]
  __int64 v43; // [sp+24h] [bp-CCh]
  char *v44; // [sp+2Ch] [bp-C4h]
  _DWORD *v45; // [sp+30h] [bp-C0h] BYREF
  int *v46; // [sp+34h] [bp-BCh]
  unsigned int v47; // [sp+38h] [bp-B8h]
  char v48[16]; // [sp+40h] [bp-B0h] BYREF
  char v49[160]; // [sp+50h] [bp-A0h] BYREF

  v3 = a1;
  v4 = *a1;
  v40 = -1073741811;
  v47 = *a2;
  if ( v4 > 0x10 )
    return sub_51B854();
  KeWaitForSingleObject(&WmipSMMutex, 0, 0);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v43 = 0i64;
  v42 = 0;
  v38 = 0;
  v39 = 0;
  v11 = 0;
  if ( v4 )
  {
    v44 = v49;
    v12 = v3 + 2;
    while ( 1 )
    {
      v13 = *v12;
      v46 = v12 + 2;
      v14 = ObReferenceObjectByHandle(v13, 4, WmipGuidObjectType, 1, &v45, 0);
      v40 = v14;
      if ( v14 < 0 )
        break;
      v15 = v45;
      v16 = 0;
      if ( v10 )
      {
        v17 = v49;
        while ( 1 )
        {
          v18 = *(_DWORD **)v17;
          v17 += 8;
          if ( v45 == v18 )
            break;
          if ( ++v16 >= v10 )
            goto LABEL_10;
        }
        ObfDereferenceObjectWithTag(v45);
        v8 = v38;
        v9 = v39;
      }
      else
      {
LABEL_10:
        if ( v45[12] )
          v42 = 1;
        ++v10;
        *(_DWORD *)v44 = v45;
        v44 += 8;
        if ( v15[15] && v15[18] )
          HIDWORD(v43) = 1;
        if ( v15[20] && v15[23] )
          LODWORD(v43) = 1;
        v8 = v38 + ((v15[18] + 7) & 0xFFFFFFF8);
        v38 = v8;
        v9 = v39 + ((v15[23] + 7) & 0xFFFFFFF8);
        v39 = v9;
      }
      ++v11;
      v12 = v46;
      if ( v11 >= v4 )
      {
        v7 = v42;
        goto LABEL_17;
      }
    }
  }
  else
  {
LABEL_17:
    v19 = v9 + v8;
    if ( v7 == 1 && v10 )
    {
      v33 = v49;
      v34 = v10;
      do
      {
        v36 = *(_DWORD *)v33;
        v33 += 8;
        v35 = v36;
        if ( *(_DWORD *)(v36 + 48) )
          WmipCompleteGuidIrpWithError(v35);
        --v34;
      }
      while ( v34 );
    }
    if ( v43 )
    {
      v31 = v47;
      if ( v19 > v47 )
      {
        v3[11] = 32;
        v3[12] = v19;
        *v3 = 56;
        *a2 = 56;
      }
      else
      {
        v32 = v47;
        if ( HIDWORD(v43) )
        {
          WmipCopyFromEventQueues(v49, v10, v3);
          v3 = (_DWORD *)((char *)v3 + v39);
          v32 = v31 - v39;
        }
        if ( (_DWORD)v43 )
        {
          WmipCopyFromEventQueues(v49, v10, v3);
          v32 -= v39;
        }
        *a2 = v31 - v32;
      }
      v14 = v40;
    }
    else
    {
      v20 = a3 + 64;
      v21 = 0;
      *(_DWORD *)(a3 + 64) = a3 + 64;
      *(_DWORD *)(a3 + 68) = a3 + 64;
      if ( v10 )
      {
        v22 = v49;
        do
        {
          v23 = *(_DWORD **)v22;
          v22 += 8;
          v23[12] = a3;
          v24 = *(_DWORD **)(a3 + 68);
          v25 = v23 + 13;
          v23[13] = v20;
          v23[14] = v24;
          if ( *v24 != v20 )
            __fastfail(3u);
          ++v21;
          *v24 = v25;
          *(_DWORD *)(a3 + 68) = v25;
        }
        while ( v21 < v10 );
      }
      v26 = 0;
      v14 = 259;
      *(_BYTE *)(*(_DWORD *)(a3 + 96) + 3) |= 1u;
      KeAcquireInStackQueuedSpinLock(&WmipCancelSpinLock, v48);
      __dmb(0xBu);
      v27 = (unsigned int *)(a3 + 56);
      do
        v28 = __ldrex(v27);
      while ( __strex((unsigned int)WmipNotificationIrpCancel, v27) );
      __dmb(0xBu);
      if ( *(_BYTE *)(a3 + 36) )
      {
        WmipClearIrpObjectList(a3, v28, WmipNotificationIrpCancel);
        v14 = -1073741536;
        __dmb(0xBu);
        do
          v37 = __ldrex(v27);
        while ( __strex(0, v27) );
        __dmb(0xBu);
        if ( v37 )
          v26 = 1;
      }
      KeReleaseInStackQueuedSpinLock(v48);
      if ( v26 )
      {
        *(_DWORD *)(a3 + 24) = -1073741536;
        *(_DWORD *)(a3 + 28) = 0;
        pIofCompleteRequest(a3, 0);
      }
      *a2 = 0;
    }
  }
  KeReleaseMutex(&WmipSMMutex, 0);
  if ( v10 )
  {
    v29 = v49;
    do
    {
      v30 = *(_DWORD *)v29;
      v29 += 8;
      ObfDereferenceObjectWithTag(v30);
      --v10;
    }
    while ( v10 );
  }
  return v14;
}
