// ExGetSessionPoolTagInfo 
 
int __fastcall ExGetSessionPoolTagInfo(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r6
  int v5; // r9
  int v6; // r4
  _DWORD *v7; // r8
  int v8; // r10
  int v9; // r5
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r2
  _DWORD *v15; // r6
  _DWORD *v16; // r10
  int v18; // [sp+0h] [bp-70h]
  int v19; // [sp+4h] [bp-6Ch] BYREF
  int v20; // [sp+8h] [bp-68h]
  int v21; // [sp+Ch] [bp-64h]
  int v22; // [sp+10h] [bp-60h]
  _DWORD *v23; // [sp+14h] [bp-5Ch]
  int v24; // [sp+18h] [bp-58h]
  int v25; // [sp+1Ch] [bp-54h] BYREF
  unsigned int v26; // [sp+20h] [bp-50h]
  unsigned int v27; // [sp+24h] [bp-4Ch]
  _DWORD *v28; // [sp+28h] [bp-48h]
  int v29; // [sp+2Ch] [bp-44h]
  _DWORD *v30; // [sp+30h] [bp-40h]
  _DWORD _38[20]; // [sp+38h] [bp-38h] BYREF

  _38[16] = a1;
  _38[17] = a2;
  v28 = (_DWORD *)a4;
  _38[19] = a4;
  v23 = (_DWORD *)a3;
  _38[18] = a3;
  v29 = a2;
  v4 = a1;
  v26 = 0;
  v5 = 0;
  v21 = 0;
  v18 = 0;
  v22 = 0;
  v6 = 0;
  if ( !MmAcquireSessionPoolRundown(1) )
    return -1073741558;
  v7 = (_DWORD *)ExpSessionPoolTrackTable;
  v27 = ExpSessionPoolTrackTable + 28 * ExpSessionPoolTrackTableSize;
  KeAcquireInStackQueuedSpinLock(&ExpTaggedPoolLock, _38);
  MmGetSessionPoolTracking(&v25, &v19);
  KeReleaseInStackQueuedSpinLock(_38);
  v8 = v19;
  if ( v19 )
  {
    v9 = ExAllocatePoolWithTag(512, 28 * v19, 1868983881);
    v24 = v9;
    if ( !v9 )
    {
      MmAcquireSessionPoolRundown(0);
      return -1073741670;
    }
    KeAcquireInStackQueuedSpinLock(&ExpTaggedPoolLock, _38);
    MmGetSessionPoolTracking(&v25, &v19);
    memmove(v9, v25, 28 * v8);
    KeReleaseInStackQueuedSpinLock(_38);
  }
  else
  {
    v9 = 0;
    v24 = 0;
  }
  v10 = v27;
  v11 = v29;
  while ( (unsigned int)v7 < v10 )
  {
    if ( *v7 )
    {
      v21 = ++v5;
      v12 = v26 + 28;
      v26 = v12;
      _38[3] = v12;
      if ( v12 < 0x1C )
      {
        v6 = -1073741675;
        v20 = -1073741675;
        break;
      }
      if ( v12 <= v11 )
      {
        v22 = ++v18;
        *v4 = *v7;
        v4[1] = v7[4];
        v4[2] = v7[5];
        v4[3] = v7[6];
        v4[4] = v7[1];
        v4[5] = v7[2];
        v4[6] = v7[3];
        v13 = v4[2];
        if ( v4[1] < v13 )
          v4[1] = v13;
        v14 = v4[5];
        if ( v4[4] < v14 )
          v4[4] = v14;
        v4 += 7;
        _38[5] = v4;
      }
      else
      {
        v6 = -1073741820;
        v20 = -1073741820;
      }
    }
    v7 += 7;
    v30 = v7;
    if ( v7 == (_DWORD *)v10 && v8 )
    {
      v7 = (_DWORD *)v9;
      v30 = (_DWORD *)v9;
      v10 = v9 + 28 * v8;
      _38[4] = v10;
      v8 = 0;
      v19 = 0;
    }
  }
  v15 = v28;
  v16 = v23;
  MmAcquireSessionPoolRundown(0);
  if ( v9 )
    ExFreePoolWithTag(v9, 0);
  *v16 = v18;
  *v15 = v5;
  return v6;
}
