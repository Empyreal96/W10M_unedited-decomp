// MiDeleteSystemPte 
 
int __fastcall MiDeleteSystemPte(unsigned int *a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // r5
  int v6; // r8
  int v8; // r6
  unsigned int v9; // r1
  int v10; // r0
  int v11; // r0
  int v12; // r5
  int v13; // r0
  int v14; // r8
  int v15; // r6
  int v16; // r0
  unsigned __int8 *v17; // r1
  unsigned int v18; // r2
  int v19; // r3
  int v20; // r2
  char v21; // r3
  int v22; // r3
  int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r0
  unsigned __int8 *v26; // r1
  unsigned int v27; // r2
  int v28; // r3
  int v29; // r3
  unsigned int *v30; // r2
  unsigned int v31; // r0
  unsigned int v32; // r0
  int result; // r0
  _DWORD *v34; // r2
  int v35; // [sp+8h] [bp-28h]

  v4 = (_DWORD *)a4;
  v35 = a2;
  v6 = a2;
  v8 = 0;
  while ( 1 )
  {
    v9 = *a1;
    if ( !*a1 )
      break;
    if ( (v9 & 2) != 0 )
    {
      v12 = MmPfnDatabase + 24 * (v9 >> 12);
      if ( v12 == dword_6348F0 )
      {
        if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
        {
          *a1 = 0;
        }
        else
        {
          __dmb(0xBu);
          *a1 = 0;
          if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
          {
            v13 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v13, (_DWORD *)(v13 + 4 * ((unsigned __int16)a1 & 0xFFF)), 0);
          }
        }
      }
      else
      {
        v14 = *(_DWORD *)(v12 + 20) & 0xFFFFF;
        v15 = MmPfnDatabase + 24 * v14;
        if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
        {
          *a1 = 0;
        }
        else
        {
          __dmb(0xBu);
          *a1 = 0;
          if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
          {
            v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * ((unsigned __int16)a1 & 0xFFF)), 0);
          }
        }
        v17 = (unsigned __int8 *)(v12 + 15);
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 | 0x80, v17) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v18 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
            v19 = *(_DWORD *)(v12 + 12);
            __dmb(0xBu);
          }
          while ( (v19 & 0x80000000) != 0 );
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 | 0x80, v17) );
        }
        v20 = *(_DWORD *)(v12 + 12) | 0x40000000;
        v21 = *(_BYTE *)(v12 + 18);
        *(_DWORD *)(v12 + 12) = v20;
        v22 = v21 & 7;
        if ( v22 != 6 )
          KeBugCheckEx(78, 153, (v12 - MmPfnDatabase) / 24, v22, v20 & 0x3FFFFFFF);
        if ( MiUpdateShareCount(v12, -1) )
          v23 = 2;
        else
          v23 = MiPfnShareCountIsZero(v12, 0);
        if ( v23 == 3 )
          ++a3[1];
        __dmb(0xBu);
        v24 = (unsigned int *)(v12 + 12);
        if ( v14 == 0xFFFFF )
        {
          do
            v32 = __ldrex(v24);
          while ( __strex(v32 & 0x7FFFFFFF, v24) );
        }
        else
        {
          do
            v25 = __ldrex(v24);
          while ( __strex(v25 & 0x7FFFFFFF, v24) );
          v26 = (unsigned __int8 *)(v15 + 15);
          do
            v27 = __ldrex(v26);
          while ( __strex(v27 | 0x80, v26) );
          while ( 1 )
          {
            __dmb(0xBu);
            if ( !(v27 >> 7) )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
              v28 = *(_DWORD *)(v15 + 12);
              __dmb(0xBu);
            }
            while ( (v28 & 0x80000000) != 0 );
            do
              v27 = __ldrex(v26);
            while ( __strex(v27 | 0x80, v26) );
          }
          v29 = *(_BYTE *)(v15 + 18) & 7;
          if ( v29 != 6 )
            KeBugCheckEx(78, 153, (v15 - MmPfnDatabase) / 24, v29, *(_DWORD *)(v15 + 12) & 0x3FFFFFFF);
          if ( !MiUpdateShareCount(v15, -1) )
            MiPfnShareCountIsZero(v15, 0);
          __dmb(0xBu);
          v30 = (unsigned int *)(v15 + 12);
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 & 0x7FFFFFFF, v30) );
        }
        v6 = v35;
        v8 = 1;
      }
      MiInsertTbFlushEntry(v6, (_DWORD)a1 << 10, 1, 0);
      v4 = (_DWORD *)a4;
LABEL_53:
      if ( v8 != 1 )
        break;
      goto LABEL_54;
    }
    if ( (v9 & 0x800) == 0 )
    {
      MiReleasePageFileSpace((int)MiSystemPartition, v9, 1, a4);
      if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
      {
        *a1 = 0;
      }
      else
      {
        __dmb(0xBu);
        *a1 = 0;
        if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
        {
          v11 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v11, (_DWORD *)(v11 + 4 * ((unsigned __int16)a1 & 0xFFF)), 0);
        }
      }
      v8 = 1;
      goto LABEL_53;
    }
    v10 = MiDeleteTransitionPte(a1, 1, (int)a3);
    if ( v10 != 1 )
    {
      if ( v10 == 3 )
        ++a3[1];
LABEL_54:
      ++a3[3];
      ++*a3;
      break;
    }
  }
  result = (((unsigned int)a1 >> 10) & 0x3FFFFC) - 0x40000000;
  if ( (((unsigned int)a1 >> 10) & 0x3FFFFC) != 3148800
    && (*(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)result >> 12) + 12) & 0x3FFFFFFF) == 1 )
  {
    v34 = (_DWORD *)(result << 10);
    do
    {
      if ( *v34 && (*v34 & 2) == 0 )
        break;
      ++v34;
    }
    while ( ((unsigned __int16)v34 & 0xFFF) != 0 );
    if ( ((unsigned __int16)v34 & 0xFFF) == 0 )
    {
      result = MiDeleteSystemPte(result, v6, a3, v4);
      *v4 = 1;
    }
  }
  return result;
}
