// PspSendProcessNotificationToJobChain 
 
int __fastcall PspSendProcessNotificationToJobChain(int a1, char a2, int a3, int a4)
{
  unsigned int v6; // r4
  _DWORD *v7; // r3
  int v8; // r3
  int v9; // r5
  int v10; // r0
  _DWORD *v11; // r2
  _DWORD *v12; // r3
  _DWORD *v14; // r3
  int v15; // r2
  int v16; // r3
  _DWORD *v17; // r5
  int v18; // r0
  __int16 v19; // r3
  int v20; // r2
  int *v21; // r1
  int v22; // r3
  _DWORD *v23; // t1
  int v24; // r2
  int *v25; // r1
  _DWORD *v26; // t1
  _DWORD *v27; // [sp+0h] [bp-28h]
  int v28; // [sp+4h] [bp-24h]
  int v29[8]; // [sp+8h] [bp-20h] BYREF

  v29[0] = a3;
  v29[1] = a4;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_DWORD **)(a1 + 288);
  __dmb(0xBu);
  v27 = v7;
  __dmb(0xBu);
  v8 = v7[144];
  __dmb(0xBu);
  v28 = v8;
  v9 = v8;
  __dmb(0xBu);
  if ( v6 )
  {
    v8 = *(__int16 *)(v6 + 310) - 1;
    *(_WORD *)(v6 + 310) = v8;
  }
  v10 = ExAcquireResourceExclusiveLite(v9 + 32, 1, a3, v8);
  v11 = v27;
  __dmb(0xBu);
  v12 = *(_DWORD **)(a1 + 288);
  __dmb(0xBu);
  if ( v11 != v12 )
    return sub_7E86F8(v10);
  v14 = v27;
  __dmb(0xBu);
  v15 = v28;
  __dmb(0xBu);
  v16 = v14[144];
  __dmb(0xBu);
  if ( v15 != v16 )
    return sub_7E86F8(v10);
  v17 = v27;
  __dmb(0xBu);
  v29[0] = v28;
  __dmb(0xBu);
  while ( v17 )
  {
    v20 = 0;
    v21 = v29;
    while ( 1 )
    {
      v23 = (_DWORD *)*v21++;
      v22 = (int)v23;
      if ( v17 == v23 )
        break;
      if ( ++v20 )
      {
        ExAcquireResourceExclusiveLite((int)(v17 + 8), 1, v20, v22);
        break;
      }
    }
    if ( v17[53] && ((1 << a2) & v17[107]) != 0 )
      PspSendJobNotification((int)v17);
    v24 = 0;
    v25 = v29;
    while ( 1 )
    {
      v26 = (_DWORD *)*v25++;
      if ( v17 == v26 )
        break;
      if ( ++v24 )
      {
        ExReleaseResourceLite((int)(v17 + 8));
        break;
      }
    }
    v17 = (_DWORD *)v17[143];
  }
  v18 = ExReleaseResourceLite(v28 + 32);
  if ( v6 )
  {
    v19 = *(_WORD *)(v6 + 310) + 1;
    *(_WORD *)(v6 + 310) = v19;
    if ( !v19 && *(_DWORD *)(v6 + 100) != v6 + 100 )
      KiCheckForKernelApcDelivery(v18);
  }
  return (int)v27;
}
