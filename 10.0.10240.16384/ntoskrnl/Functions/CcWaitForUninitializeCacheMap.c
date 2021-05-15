// CcWaitForUninitializeCacheMap 
 
int __fastcall CcWaitForUninitializeCacheMap(int result, int a2)
{
  int v2; // r5
  int v3; // r10
  _DWORD *v4; // r4
  _DWORD *v5; // r6
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r1
  _DWORD *v10; // r2
  int *v11; // r9
  int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned int v17; // r2
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r9
  unsigned int v21; // r1
  int v22; // r6
  int v23; // r0
  int v24; // r1
  int **v25; // r2
  unsigned int v26; // r3
  unsigned __int8 v27; // [sp+8h] [bp-50h]
  int v28; // [sp+Ch] [bp-4Ch]
  unsigned int v29; // [sp+10h] [bp-48h]
  int v30; // [sp+14h] [bp-44h]
  int v31[2]; // [sp+18h] [bp-40h] BYREF
  _DWORD v32[2]; // [sp+20h] [bp-38h] BYREF
  int *v33; // [sp+28h] [bp-30h] BYREF
  _BYTE v34[4]; // [sp+2Ch] [bp-2Ch] BYREF
  int v35; // [sp+30h] [bp-28h]
  _DWORD _34[10]; // [sp+34h] [bp-24h] BYREF
  int anonymous2; // [sp+60h] [bp+8h]
  int anonymous3; // [sp+64h] [bp+Ch]

  anonymous3 = a2;
  v2 = result;
  v31[0] = result;
  anonymous2 = result;
  v3 = 0;
  v27 = 0;
  v28 = 0;
  v4 = 0;
  v29 = 0;
  if ( !*(_DWORD *)(*(_DWORD *)(result + 20) + 4) )
    return result;
  v34[0] = 0;
  v34[1] = 0;
  v34[2] = 4;
  v35 = 0;
  _34[1] = _34;
  _34[0] = _34;
  v30 = KeAcquireQueuedSpinLock(5);
  v5 = *(_DWORD **)(*(_DWORD *)(v2 + 20) + 4);
  if ( v5 )
  {
    if ( (_DWORD *)v5[36] == v5 + 36 )
    {
      v6 = v5[24];
      if ( (v6 & 0x100) == 0 )
      {
        v3 = 1;
        v27 = 1;
        v5[24] = v6 | 0x10000;
        v33 = (int *)v5[44];
        v5[44] = (char *)&v33 + 1;
        v7 = v5[24];
        if ( (v7 & 0x20) == 0 )
        {
          v5[24] = v7 | 0x20;
          v28 = 1;
          goto LABEL_23;
        }
        if ( v5[88] )
        {
          KeAcquireQueuedSpinLockAtDpcLevel(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
          v8 = v5[88];
          if ( v8 )
          {
            v4 = (_DWORD *)(v8 & 0xFFFFFFFE);
            v29 = v8 & 0xFFFFFFFE;
            v9 = *(_DWORD *)(v8 & 0xFFFFFFFE);
            v10 = *(_DWORD **)((v8 & 0xFFFFFFFE) + 4);
            if ( *(_DWORD *)(v9 + 4) != (v8 & 0xFFFFFFFE) || (_DWORD *)*v10 != v4 )
              __fastfail(3u);
            *v10 = v9;
            *(_DWORD *)(v9 + 4) = v10;
            v4[1] = 0;
            *v4 = 0;
            v5[88] = 0;
            v28 = 1;
          }
          v11 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(v11);
            goto LABEL_23;
          }
          v12 = *v11;
          if ( *v11 )
            goto LABEL_21;
          v13 = (unsigned int *)v11[1];
          __dmb(0xBu);
          do
            v14 = __ldrex(v13);
          while ( (int *)v14 == v11 && __strex(0, v13) );
          if ( (int *)v14 != v11 )
          {
            v12 = KxWaitForLockChainValid(v11);
LABEL_21:
            *v11 = 0;
            __dmb(0xBu);
            v15 = (unsigned int *)(v12 + 4);
            do
              v16 = __ldrex(v15);
            while ( __strex(v16 ^ 1, v15) );
            goto LABEL_23;
          }
        }
      }
    }
  }
LABEL_23:
  result = KeReleaseQueuedSpinLock(5, v30);
  if ( v28 )
  {
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v17 + 308);
    v32[1] = v4;
    result = CcWriteBehind((int)v5, (int)v32);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      result = KiCheckForKernelApcDelivery(result);
    v20 = anonymous2;
    v3 = v27;
    v4 = (_DWORD *)v29;
  }
  else
  {
    v20 = v31[0];
  }
  if ( v4 )
  {
    v21 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v22 = *(_DWORD *)(v21 + 1456);
    ++*(_DWORD *)(v22 + 20);
    if ( *(unsigned __int16 *)(v22 + 4) < (unsigned int)*(unsigned __int16 *)(v22 + 8)
      || (++*(_DWORD *)(v22 + 24),
          v22 = *(_DWORD *)(v21 + 1460),
          ++*(_DWORD *)(v22 + 20),
          *(unsigned __int16 *)(v22 + 4) < (unsigned int)*(unsigned __int16 *)(v22 + 8)) )
    {
      result = RtlpInterlockedPushEntrySList((unsigned __int64 *)v22, v4);
    }
    else
    {
      ++*(_DWORD *)(v22 + 24);
      result = (*(int (__fastcall **)(_DWORD *))(v22 + 44))(v4);
    }
  }
  if ( v3 )
  {
    v31[0] = -1705032704;
    v31[1] = -2;
    result = KeWaitForSingleObject((unsigned int)v34, 0, 0, 0, v31);
    if ( result == 258 )
    {
      v23 = KeAcquireQueuedSpinLock(5);
      v24 = *(_DWORD *)(*(_DWORD *)(v20 + 20) + 4);
      if ( v24 )
      {
        v25 = (int **)(v24 + 176);
        if ( *(_DWORD *)(v24 + 176) )
        {
          while ( 1 )
          {
            v26 = (unsigned int)*v25;
            if ( *v25 == (int *)((char *)&v33 + 1) )
              break;
            v25 = (int **)(v26 & 0xFFFFFFFE);
            if ( !*(_DWORD *)(v26 & 0xFFFFFFFE) )
              goto LABEL_43;
          }
          *v25 = v33;
        }
LABEL_43:
        *(_DWORD *)(v24 + 96) &= 0xFFFEFFFF;
        result = KeReleaseQueuedSpinLock(5, v23);
      }
      else
      {
        KeReleaseQueuedSpinLock(5, v23);
        result = KeWaitForSingleObject((unsigned int)v34, 0, 0, 0, 0);
      }
    }
  }
  return result;
}
