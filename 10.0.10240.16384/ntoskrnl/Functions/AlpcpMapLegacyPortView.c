// AlpcpMapLegacyPortView 
 
int __fastcall AlpcpMapLegacyPortView(int a1, _DWORD *a2, int a3)
{
  int v4; // r6
  int v8; // r3
  int v9; // r4
  unsigned int v10; // r8
  int v11; // r5
  int v12; // r3
  int v13; // r5
  _DWORD *v14; // r6
  int v15; // r9
  unsigned __int8 *v16; // r8
  int v17; // r0
  int v18; // r5
  unsigned int v19; // r2
  unsigned int *v20; // r1
  unsigned int v21; // r0
  int v22; // r0
  int v23; // r8
  int v24; // r7
  unsigned int *v25; // r6
  unsigned int v26; // r1
  unsigned int *v27; // r2
  unsigned int v28; // r5
  int v29; // r5
  unsigned int *v30; // r2
  unsigned int v31; // r1
  int v32; // r1
  int v33; // r0
  int v34; // [sp+8h] [bp-40h] BYREF
  int v35; // [sp+Ch] [bp-3Ch] BYREF
  _DWORD *v36; // [sp+10h] [bp-38h] BYREF
  int v37[2]; // [sp+18h] [bp-30h] BYREF
  unsigned int v38; // [sp+20h] [bp-28h]

  v4 = a2[1];
  if ( !v4 )
    return sub_7F3EA8();
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = ObReferenceObjectByHandle(v4, 6, MmSectionObjectType, v8, &v34);
  if ( v9 >= 0 )
  {
    v9 = MmGetSectionInformation(v34, 0, v37);
    if ( v9 >= 0 )
    {
      if ( (v37[1] & 0x800000) != 0 )
      {
        v9 = -1073741637;
      }
      else
      {
        v10 = (a2[2] + AlpcpViewGranularity - 1) & ~(AlpcpViewGranularity - 1);
        v11 = (a2[3] + AlpcpViewGranularity - 1) & ~(AlpcpViewGranularity - 1);
        if ( v11 + v10 < v10 )
        {
          v9 = -1073741811;
        }
        else if ( v11 + v10 > v38 )
        {
          v9 = -1073741670;
        }
        else
        {
          if ( !v11 )
            v11 = v38 - v10;
          v9 = AlpcpCreateSection(a1, 0, 0, v4, v38, &v35, v34);
          if ( v9 < 0 )
            goto LABEL_30;
          v12 = v11;
          v13 = v35;
          v9 = AlpcpCreateSectionView(v35, a1, v10, v12, &v36);
          if ( v9 < 0 )
          {
            __dmb(0xBu);
            v30 = (unsigned int *)(v13 - 12);
            do
            {
              v31 = __ldrex(v30);
              v32 = v31 - 1;
            }
            while ( __strex(v32, v30) );
            __dmb(0xBu);
            if ( v32 > 0 )
              goto LABEL_30;
            if ( v32 )
              KeBugCheckEx(24, 0, v13, 33, v32);
            v33 = v13;
          }
          else
          {
            v14 = v36;
            *a2 = 24;
            a2[4] = v14[5];
            a2[3] = v14[6];
            a2[5] = 0;
            *(_DWORD *)(a3 + 20) = v14;
            v15 = v14[2];
            v16 = (unsigned __int8 *)(v15 - 4);
            v17 = KeAbPreAcquire(v15 - 4, 0, 0);
            v18 = v17;
            do
              v19 = __ldrex(v16);
            while ( __strex(v19 | 1, v16) );
            __dmb(0xBu);
            if ( (v19 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx((_DWORD *)(v15 - 4), v17, v15 - 4);
            if ( v18 )
              *(_BYTE *)(v18 + 14) |= 1u;
            *(_BYTE *)(v15 - 16) |= 1u;
            __dmb(0xBu);
            v20 = (unsigned int *)(v15 - 12);
            do
            {
              v21 = __ldrex(v20);
              v22 = v21 + 0x10000;
            }
            while ( __strex(v22, v20) );
            __dmb(0xBu);
            if ( v22 <= 0 )
              KeBugCheckEx(24, 0, v15, 38, v22);
            v23 = 0;
            ++v14[10];
            v24 = v14[2];
            if ( (*(_BYTE *)(v24 - 16) & 1) != 0 )
            {
              v23 = 0x10000 - *(__int16 *)(v24 - 14);
              *(_BYTE *)(v24 - 16) &= 0xFEu;
              *(_WORD *)(v24 - 14) = 0;
            }
            v25 = (unsigned int *)(v24 - 4);
            __dmb(0xBu);
            do
              v26 = __ldrex(v25);
            while ( __strex(v26 - 1, v25) );
            if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
              ExfTryToWakePushLock((unsigned int *)(v24 - 4));
            KeAbPostRelease(v24 - 4);
            if ( v23 <= 0 )
              goto LABEL_30;
            __dmb(0xBu);
            v27 = (unsigned int *)(v24 - 12);
            do
            {
              v28 = __ldrex(v27);
              v29 = v28 - v23;
            }
            while ( __strex(v29, v27) );
            __dmb(0xBu);
            if ( v29 > 0 )
              goto LABEL_30;
            if ( v29 )
              KeBugCheckEx(24, 0, v24, 40, v29);
            v33 = v24;
          }
          AlpcpDestroyBlob(v33);
        }
      }
    }
LABEL_30:
    ObfDereferenceObject(v34);
  }
  return v9;
}
