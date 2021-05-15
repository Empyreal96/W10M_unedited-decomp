// MiPurgeImageSection 
 
int __fastcall MiPurgeImageSection(unsigned int *a1)
{
  int result; // r0
  int v3; // r9
  unsigned int v4; // r10
  unsigned int v5; // r1
  __int16 v6; // r3
  unsigned int v7; // r8
  unsigned int v8; // r3
  unsigned int v9; // r3
  unsigned int v10; // r6
  unsigned int v11; // r3
  int v12; // r0
  int v13; // r3
  unsigned int v14; // r5
  int v15; // r4
  unsigned int *v16; // r2
  unsigned int v17; // r0
  int v18; // r7
  unsigned int v19; // r8
  int v20; // r3
  unsigned int v21; // r3
  int v22; // r5
  __int16 v23; // lr
  int v24; // r0
  unsigned int *v25; // r2
  unsigned int v26; // r4
  int v27; // r4
  unsigned __int8 *v28; // r3
  unsigned int v29; // r1
  unsigned __int8 *v30; // r1
  int v31; // r3
  unsigned int v32; // r2
  unsigned int *v33; // r2
  unsigned int v34; // r4
  unsigned int v35; // r3
  int v36; // r4
  int v37; // r0
  char v38[4]; // [sp+8h] [bp-48h] BYREF
  int v39; // [sp+Ch] [bp-44h]
  int v40; // [sp+10h] [bp-40h]
  unsigned int v41; // [sp+14h] [bp-3Ch]
  unsigned int v42; // [sp+18h] [bp-38h]
  unsigned int v43; // [sp+1Ch] [bp-34h]
  unsigned int *v44; // [sp+20h] [bp-30h]
  unsigned int v45; // [sp+24h] [bp-2Ch]
  int v46; // [sp+28h] [bp-28h]
  int v47; // [sp+2Ch] [bp-24h]
  unsigned int v48; // [sp+30h] [bp-20h]

  result = 0;
  v3 = 17;
  v40 = 0;
  v44 = a1;
  v38[0] = 17;
  v4 = (unsigned int)(a1 + 20);
  if ( a1 != (unsigned int *)-80 )
  {
    v41 = 0x3FFFFF;
    while ( 1 )
    {
      v5 = *(unsigned __int16 *)(v4 + 18);
      if ( (v5 & 2) != 0 )
      {
        v6 = *(_WORD *)(v4 + 16);
        v43 = 0;
        v47 = v6 & 0x3E;
        v7 = 16 * v47;
        v42 = 0;
        v8 = *(_DWORD *)(v4 + 20);
        v39 = 16 * v47;
        if ( v8 )
        {
          v7 = v4 & 0xFFFFFC00 | ((v4 & 0x7F8 | 0x800) >> 1);
          v9 = *(_DWORD *)(v4 + 24);
          v39 = v7;
          v43 = (v9 << 9) | (v5 >> 4);
        }
        v10 = *(_DWORD *)(v4 + 4);
        v11 = v10 + 4 * *(_DWORD *)(v4 + 28);
        v48 = v11;
        while ( v10 < v11 )
        {
          v45 = v10 & 0xFFF;
          if ( (v10 & 0xFFF) == 0 || v3 == 17 )
          {
            if ( v3 != 17 )
              MiUnlockProtoPoolPage(result, v3);
            while ( 1 )
            {
              v40 = MiLockProtoPoolPage(v10, v38);
              if ( v40 )
                break;
              MmAccessFault(1, v10, 0, 0);
            }
            v3 = (unsigned __int8)v38[0];
          }
          v12 = MiLockLeafPage((unsigned int *)v10, 0);
          v14 = *(_DWORD *)v10;
          v15 = v12;
          if ( !*(_DWORD *)v10 )
          {
            result = v40;
            break;
          }
          if ( v12 )
          {
            if ( (*(_BYTE *)(v12 + 18) & 0x10) != 0 || (*(_DWORD *)(v12 + 8) & 0x400) == 0 )
            {
              if ( (*(_DWORD *)(v12 + 8) & 0x400) != 0 )
                MiDereferenceControlAreaPfn(v44, 0, 2);
              v18 = 0;
              v19 = 0;
              v46 = *(_DWORD *)(v15 + 20) & 0xFFFFF;
              if ( *(_WORD *)(v15 + 16) )
              {
                *(_DWORD *)(v15 + 12) |= 0x40000000u;
                if ( (*(_BYTE *)(v15 + 18) & 0x20) != 0 && (*(_BYTE *)(v15 + 18) & 8) == 0 )
                {
                  v18 = *(_DWORD *)v15 - 16;
                  if ( *(_DWORD *)(*(_DWORD *)v15 - 8) == *(_DWORD *)v15 - 8 )
                    v18 = 0;
                }
                if ( (*(_DWORD *)(v15 + 8) & 0x400) == 0 )
                  MiChargeCommit((int)MiSystemPartition, 1u, 4);
              }
              else
              {
                MiUnlinkPageFromList(v15, 0);
                v20 = *(_DWORD *)(v15 + 8);
                if ( (v20 & 0x400) == 0 )
                {
                  v19 = *(_DWORD *)(v15 + 8);
                  if ( (v20 & 0x10) == 0 && (v20 & 8) == 0 )
                    v19 = 0;
                }
                MiInsertPageInFreeOrZeroedList(v14 >> 12, 2);
              }
              if ( v10 + 0x40000000 > v41 )
              {
                *(_DWORD *)v10 = v39;
              }
              else
              {
                v21 = *(_DWORD *)v10;
                v22 = 0;
                __dmb(0xBu);
                v23 = v39;
                *(_DWORD *)v10 = v39;
                if ( (v21 & 2) == 0 && (v23 & 2) != 0 )
                  v22 = 1;
                if ( v10 + 1070596096 <= 0xFFF )
                {
                  v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v24, (_DWORD *)(v24 + 4 * v45), v23);
                }
                if ( v22 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
              __dmb(0xBu);
              v25 = (unsigned int *)(v15 + 12);
              do
                v26 = __ldrex(v25);
              while ( __strex(v26 & 0x7FFFFFFF, v25) );
              if ( v18 )
                MiInvalidateCollidedIos(v18);
              v27 = MmPfnDatabase + 24 * v46;
              v28 = (unsigned __int8 *)(v27 + 15);
              do
                v29 = __ldrex(v28);
              while ( __strex(v29 | 0x80, v28) );
              __dmb(0xBu);
              if ( v29 >> 7 )
              {
                v30 = (unsigned __int8 *)(v27 + 15);
                do
                {
                  do
                  {
                    __dmb(0xAu);
                    __yield();
                    v31 = *(_DWORD *)(v27 + 12);
                    __dmb(0xBu);
                  }
                  while ( v31 < 0 );
                  do
                    v32 = __ldrex(v30);
                  while ( __strex(v32 | 0x80, v30) );
                  __dmb(0xBu);
                }
                while ( v32 >> 7 );
              }
              if ( (*(_BYTE *)(v27 + 18) & 7) != 6 )
                KeBugCheckEx(
                  78,
                  153,
                  (v27 - MmPfnDatabase) / 24,
                  *(_BYTE *)(v27 + 18) & 7,
                  *(_DWORD *)(v27 + 12) & 0x3FFFFFFF);
              if ( !MiUpdateShareCount(v27, -1) )
                MiPfnShareCountIsZero(v27, 0);
              __dmb(0xBu);
              v33 = (unsigned int *)(v27 + 12);
              do
                v34 = __ldrex(v33);
              while ( __strex(v34 & 0x7FFFFFFF, v33) );
              if ( v19 )
                MiReleasePageFileInfo((int)MiSystemPartition, v19, 1, 0);
            }
            else
            {
              __dmb(0xBu);
              v16 = (unsigned int *)(v12 + 12);
              do
                v17 = __ldrex(v16);
              while ( __strex(v17 & 0x7FFFFFFF, v16) );
            }
          }
          else if ( (v14 & 0x400) == 0 && v14 != 768 )
          {
            MiReleasePageFileSpace((int)MiSystemPartition, *(_DWORD *)v10, 1, v13);
            if ( v10 + 0x40000000 > v41 )
            {
              *(_DWORD *)v10 = v7;
            }
            else
            {
              v35 = *(_DWORD *)v10;
              v36 = 0;
              __dmb(0xBu);
              *(_DWORD *)v10 = v7;
              if ( (v35 & 2) == 0 && (v7 & 2) != 0 )
                v36 = 1;
              if ( v10 + 1070596096 <= 0xFFF )
              {
                v37 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v37, (_DWORD *)(v37 + 4 * (v10 & 0xFFF)), v7);
              }
              if ( v36 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
            }
          }
          v10 += 4;
          v42 += 4096;
          if ( v42 < v43 )
          {
            v7 = v39;
          }
          else
          {
            v7 = 16 * v47;
            v39 = 16 * v47;
          }
          v11 = v48;
          result = v40;
        }
        if ( v3 != 17 )
        {
          result = MiUnlockProtoPoolPage(result, v3);
          v3 = 17;
          v38[0] = 17;
        }
      }
      v4 = *(_DWORD *)(v4 + 8);
      if ( !v4 )
        break;
      result = v40;
    }
  }
  return result;
}
