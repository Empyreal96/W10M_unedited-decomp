// PiDmObjectUpdateCachedObjectProperty 
 
int __fastcall PiDmObjectUpdateCachedObjectProperty(int result, int a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8)
{
  int v8; // r10
  unsigned int v9; // r6
  int v10; // r9
  unsigned int v11; // r4
  unsigned int *v12; // r5
  int v13; // r7
  unsigned int v14; // r1
  unsigned int v15; // t1
  int v16; // r3
  unsigned __int8 *v17; // r5
  int v18; // r0
  unsigned int v19; // r2
  unsigned __int8 *v20; // r1
  int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3
  unsigned int v27; // [sp+8h] [bp-30h] BYREF
  unsigned int v28; // [sp+Ch] [bp-2Ch] BYREF
  unsigned int *v29; // [sp+10h] [bp-28h] BYREF
  int v30; // [sp+14h] [bp-24h]

  v27 = 0;
  v30 = a2;
  v8 = result;
  if ( !a4 )
  {
    result = PiDmGetCacheKeys(result, &v29, (int *)&v28);
    v9 = v28;
    if ( v28 )
    {
      v10 = (int)v29;
      v11 = 0;
      v12 = v29;
      v13 = *(_DWORD *)(a5 + 16);
      while ( 1 )
      {
        v15 = *v12;
        v12 += 4;
        v14 = v15;
        if ( v13 == *(_DWORD *)(v15 + 16) )
        {
          result = memcmp(a5, v14, 16);
          if ( !result )
            break;
        }
        if ( ++v11 >= v9 )
        {
          v11 = -1;
          break;
        }
      }
      if ( v11 < v9 )
      {
        result = PiDmGetObject(v8, v30, (int *)&v27);
        if ( result >= 0 )
        {
          v16 = __mrc(15, 0, 13, 0, 3);
          --*(_WORD *)((v16 & 0xFFFFFFC0) + 0x134);
          v17 = (unsigned __int8 *)v27;
          v18 = KeAbPreAcquire(v27, 0, 0);
          do
            v19 = __ldrex(v17);
          while ( __strex(v19 | 1, v17) );
          __dmb(0xBu);
          if ( (v19 & 1) != 0 )
          {
            result = sub_7C69C8(v18);
          }
          else
          {
            if ( v18 )
              *(_BYTE *)(v18 + 14) |= 1u;
            v20 = &v17[20 * v11];
            if ( !*((_DWORD *)v20 + 16) )
              PiDmCacheDataEncode(
                a6,
                a7,
                a8,
                *(_DWORD *)(v10 + 16 * v11 + 4),
                *(_DWORD *)(v10 + 16 * v11 + 8),
                v20 + 64);
            __pld(v17);
            v21 = *(_DWORD *)v17;
            if ( (*(_DWORD *)v17 & 0xFFFFFFF0) > 0x10 )
              v22 = v21 - 16;
            else
              v22 = 0;
            if ( (v21 & 2) != 0 )
              goto LABEL_31;
            __dmb(0xBu);
            do
              v23 = __ldrex((unsigned int *)v17);
            while ( v23 == v21 && __strex(v22, (unsigned int *)v17) );
            if ( v23 != v21 )
LABEL_31:
              ExfReleasePushLock(v17, v21);
            v24 = KeAbPostRelease((unsigned int)v17);
            v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v26 = *(_WORD *)(v25 + 0x134) + 1;
            *(_WORD *)(v25 + 308) = v26;
            if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
              KiCheckForKernelApcDelivery(v24);
            result = PiDmObjectRelease((int)v17);
          }
        }
      }
    }
  }
  return result;
}
