// AlpcpMapLegacyPortRemoteView 
 
int __fastcall AlpcpMapLegacyPortRemoteView(_DWORD *a1, int a2, _DWORD *a3)
{
  int v3; // r6
  _DWORD *v5; // r8
  unsigned __int8 *v6; // r10
  int v7; // r0
  unsigned int v8; // r4
  unsigned int *v10; // r1
  unsigned int v11; // r0
  int v12; // r0
  int v13; // r10
  _DWORD *v14; // r2
  int v15; // r9
  int v16; // r7
  unsigned int *v17; // r4
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r0
  int v21; // r0
  unsigned int *v22; // r2
  unsigned int v23; // r1
  int v24; // r1
  int v27[8]; // [sp+10h] [bp-20h] BYREF

  v3 = *(_DWORD *)(a2 + 20);
  v5 = *(_DWORD **)(v3 + 8);
  v6 = (unsigned __int8 *)(v5 - 1);
  v7 = KeAbPreAcquire((unsigned int)(v5 - 1), 0, 0);
  do
    v8 = __ldrex(v6);
  while ( __strex(v8 | 1, v6) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_81AE04(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  *((_BYTE *)v5 - 16) |= 1u;
  __dmb(0xBu);
  v10 = v5 - 3;
  do
  {
    v11 = __ldrex(v10);
    v12 = v11 + 0x10000;
  }
  while ( __strex(v12, v10) );
  __dmb(0xBu);
  if ( v12 <= 0 )
    KeBugCheckEx(24, 0, (int)v5, 38, v12);
  v13 = AlpcpCreateView(v5, a1, v27);
  if ( v13 < 0 )
  {
    v15 = a2;
  }
  else
  {
    *a3 = 0;
    a3[1] = 0;
    v14 = (_DWORD *)v27[0];
    a3[2] = 0;
    *a3 = 12;
    a3[2] = v14[5];
    a3[1] = v14[6];
    v15 = a2;
    *(_DWORD *)(a2 + 20) = v14;
    ++v14[10];
    --*(_DWORD *)(v3 + 40);
  }
  v16 = 0;
  if ( (*(_BYTE *)(v5 - 4) & 1) != 0 )
  {
    v16 = 0x10000 - *((__int16 *)v5 - 7);
    *((_BYTE *)v5 - 16) &= 0xFEu;
    *((_WORD *)v5 - 7) = 0;
  }
  v17 = v5 - 1;
  __dmb(0xBu);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 - 1, v17) );
  if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
    ExfTryToWakePushLock(v5 - 1);
  KeAbPostRelease((unsigned int)(v5 - 1));
  if ( v16 > 0 )
  {
    __dmb(0xBu);
    v19 = v5 - 3;
    do
    {
      v20 = __ldrex(v19);
      v21 = v20 - v16;
    }
    while ( __strex(v21, v19) );
    __dmb(0xBu);
    if ( v21 <= 0 )
    {
      if ( v21 )
        KeBugCheckEx(24, 0, (int)v5, 40, v21);
      AlpcpDestroyBlob((int)v5);
    }
  }
  if ( *(_DWORD *)(v15 + 20) != v3 )
  {
    __dmb(0xBu);
    v22 = (unsigned int *)(v3 - 12);
    do
    {
      v23 = __ldrex(v22);
      v24 = v23 - 1;
    }
    while ( __strex(v24, v22) );
    __dmb(0xBu);
    if ( v24 <= 0 )
    {
      if ( v24 )
        KeBugCheckEx(24, 0, v3, 33, v24);
      AlpcpDestroyBlob(v3);
    }
  }
  return v13;
}
