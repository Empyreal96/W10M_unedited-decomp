// MiInsertNonPagedPoolOnSlist 
 
int __fastcall MiInsertNonPagedPoolOnSlist(unsigned int *a1, unsigned int a2)
{
  unsigned int *v2; // r7
  int v3; // r2
  unsigned int v4; // r4
  int v6; // r0
  int v7; // r5
  int v8; // lr
  int v9; // r6
  unsigned int *v10; // r2
  unsigned int v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  int v14; // r2
  int v15; // lr
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v19; // r0
  int v20; // r0
  unsigned int v21; // r3
  int v22; // r0
  int v23; // r3
  unsigned int *v24; // r2
  unsigned int v25; // r4
  int v26; // r1
  unsigned int v27; // r2
  int v28; // r0
  unsigned __int8 *v29; // r1
  unsigned int v30; // r2
  unsigned int v31; // r1
  char v32[4]; // [sp+8h] [bp-40h] BYREF
  unsigned int *v33; // [sp+Ch] [bp-3Ch]
  int v34; // [sp+10h] [bp-38h]
  unsigned int v35; // [sp+14h] [bp-34h]
  int v36; // [sp+18h] [bp-30h]
  unsigned int v37; // [sp+1Ch] [bp-2Ch]
  int v38; // [sp+20h] [bp-28h]
  int v39; // [sp+24h] [bp-24h]

  v2 = (unsigned int *)((((unsigned int)a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v3 = ((unsigned int)a1 >> 20) & 0xFFC;
  v4 = *(_DWORD *)(v3 - 1070596096);
  v35 = a2;
  v33 = (unsigned int *)(v3 - 1070596096);
  if ( (v4 & 0x400) == 0 )
  {
    v6 = MiLockNonPagedPoolPte((((unsigned int)a1 >> 10) & 0x3FFFFC) - 0x40000000, v32);
    v4 = *v2;
    v7 = v6;
    if ( (*v2 & 0x100) != 0 )
    {
      v4 &= 0xFFFFFEFF;
      __dmb(0xBu);
      do
        v27 = __ldrex(v2);
      while ( __strex(v4, v2) );
      __dmb(0xBu);
    }
    v8 = (unsigned __int8)v32[0];
LABEL_4:
    if ( (*(_DWORD *)(v7 + 12) & 0x3FFFFFFF) != 1 )
      KeBugCheckEx(78, 153, (v7 - MmPfnDatabase) / 24);
    if ( *(_WORD *)(v7 + 16) != 1 )
      KeBugCheckEx(78, 154, (v7 - MmPfnDatabase) / 24);
    v9 = 512;
    if ( (v4 & 1) == 0 )
      v9 = 0;
    v34 = *(_DWORD *)(v7 + 20) >> 28;
    __dmb(0xBu);
    v10 = (unsigned int *)(v7 + 12);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0x7FFFFFFF, v10) );
    KfLowerIrql(v8);
    v12 = v35;
    if ( v35 > 3 )
      return v9;
    v13 = v35 - 1;
    v14 = (v9 & 0x200) != 0 ? v13 + 22 * v34 + 4 : v35 + 22 * v34;
    v15 = dword_6337E8 + 8 * v14;
    v16 = MiState[v13 + 1];
    v17 = *(unsigned __int16 *)(v15 + 4);
    v38 = v15;
    if ( v17 >= v16 )
      return v9;
    v36 = 1;
    v37 = 1;
    if ( v35 > 1 )
    {
      do
      {
        if ( ((unsigned __int16)++v2 & 0xFFF) != 0 )
        {
          v19 = *v33;
        }
        else
        {
          v19 = v33[1];
          ++v33;
          if ( (v19 & 0x400) != 0 )
            v7 = MmPfnDatabase + 24 * (v19 >> 12) - 24;
        }
        if ( (v19 & 0x400) != 0 )
        {
          v22 = 17;
          v32[0] = 17;
          v7 += 24;
        }
        else
        {
          v20 = MiLockNonPagedPoolPte(v2, v32);
          v21 = *v2;
          v7 = v20;
          if ( (*v2 & 0x100) != 0 )
          {
            __dmb(0xBu);
            do
              v31 = __ldrex(v2);
            while ( __strex(v21 & 0xFFFFFEFF, v2) );
            __dmb(0xBu);
          }
          v22 = (unsigned __int8)v32[0];
        }
        if ( (*(_DWORD *)(v7 + 12) & 0x3FFFFFFF) != 1 )
          KeBugCheckEx(78, 153, (v7 - MmPfnDatabase) / 24);
        if ( *(_WORD *)(v7 + 16) != 1 )
          KeBugCheckEx(78, 154, (v7 - MmPfnDatabase) / 24);
        v23 = *(_DWORD *)(v7 + 20) >> 28;
        v39 = v23;
        if ( v22 != 17 )
        {
          __dmb(0xBu);
          v24 = (unsigned int *)(v7 + 12);
          do
            v25 = __ldrex(v24);
          while ( __strex(v25 & 0x7FFFFFFF, v24) );
          KfLowerIrql(v22);
          v12 = v35;
          v23 = v39;
        }
        if ( v23 == v34 )
        {
          v26 = v36;
        }
        else
        {
          v26 = 0;
          v36 = 0;
        }
        ++v37;
      }
      while ( v37 < v12 );
      if ( !v26 )
        return v9;
      v15 = v38;
    }
    *a1 = dword_634C80 ^ (unsigned int)a1;
    RtlpInterlockedPushEntrySList((unsigned __int64 *)v15, a1 + 2);
    return 1;
  }
  v7 = MmPfnDatabase + 24 * ((((unsigned int)a1 >> 12) & 0x3FF) + (v4 >> 12));
  v28 = KfRaiseIrql(2);
  v8 = v28;
  v29 = (unsigned __int8 *)(v7 + 15);
  do
    v30 = __ldrex(v29);
  while ( __strex(v30 | 0x80, v29) );
  __dmb(0xBu);
  if ( !(v30 >> 7) )
  {
    v32[0] = v28;
    goto LABEL_4;
  }
  return sub_54BCE8();
}
