// CcScheduleReadAheadEx 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcScheduleReadAheadEx(int result, int a2, unsigned int a3)
{
  unsigned int v3; // r8
  int v4; // r10
  _DWORD *v5; // r6
  int v6; // r5
  int v7; // r4 OVERLAPPED
  int v8; // r3
  int v9; // r7
  int v10; // r3
  unsigned int *v11; // r6
  __int64 v12; // kr08_8
  unsigned int v13; // r2
  int v14; // r3
  int v15; // r0
  int v16; // r2
  int v17; // r0
  int v18; // r9
  unsigned int v19; // lr
  unsigned int v20; // r0
  unsigned int v21; // r2
  int v22; // r0
  __int64 v23; // kr20_8
  int v24; // lr
  unsigned int v25; // r2
  int v26; // r1
  unsigned int v27; // r5
  unsigned int v28; // r2
  unsigned int v29; // r1
  unsigned int v30; // r3
  int v31; // r7
  int v32; // r5
  int v33; // r0
  int v34; // r7
  __int64 v35; // kr30_8
  int v36; // r0
  unsigned int v37; // r1
  __int64 v38; // kr38_8
  unsigned int v39; // r0
  int v40; // r1
  int v41; // r5
  unsigned int v42; // r2
  unsigned int v43; // [sp+10h] [bp-48h]
  int v44; // [sp+14h] [bp-44h]
  int v46; // [sp+1Ch] [bp-3Ch]
  unsigned int v47; // [sp+20h] [bp-38h]
  int v48; // [sp+2Ch] [bp-2Ch]
  unsigned int v49; // [sp+30h] [bp-28h]
  int v50; // [sp+34h] [bp-24h]

  v46 = 0;
  v3 = a3;
  v43 = a3;
  v4 = result;
  v5 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v6 = (v5[240] >> 9) & 7;
  if ( (*(_DWORD *)(v5[84] + 192) & 0x100000) != 0 )
    v6 = 0;
  if ( v6 < 2 && v5 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v5[250] )
    v6 = 2;
  *(_QWORD *)(&v7 - 1) = *(_QWORD *)(result + 20);
  v9 = *(_DWORD *)(v8 + 4);
  v50 = v9;
  if ( !v7 )
    return result;
  if ( !v9 )
    return result;
  v10 = *(_DWORD *)(v9 + 96);
  if ( (v10 & 1) != 0 )
    return result;
  if ( (v10 & 0x2000) != 0 )
    return result;
  if ( (*(_DWORD *)(result + 44) & 0x100000) != 0 )
    return result;
  if ( v6 < 2 )
    return result;
  result = CcCanIWriteStream(result, 0x1000000u, 0, 4);
  if ( !result || CcQueueThrottle )
    return result;
  v11 = (unsigned int *)(v7 + 80);
  v12 = *(_QWORD *)a2 + v3;
  v44 = (*(_DWORD *)(v7 + 4) + v3) & ~*(_DWORD *)(v7 + 4);
  v49 = *(_DWORD *)a2 + v3;
  v48 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54A758();
  do
    v13 = __ldrex(v11);
  while ( __strex(1u, v11) );
  __dmb(0xBu);
  if ( v13 )
    KxWaitForSpinLockAndAcquire((unsigned int *)(v7 + 80));
  if ( (*(_DWORD *)v7 & 0x20000) == 0 )
    *(_DWORD *)v7 |= 0x20000u;
  v14 = *(_DWORD *)(*(_DWORD *)(v7 + 8) + 44);
  if ( (v14 & 0x20) != 0 )
  {
    v18 = 1;
    goto LABEL_26;
  }
  if ( (v14 & 0x100000) != 0 )
    goto LABEL_36;
  if ( *(_DWORD *)(a2 + 4) == *(_DWORD *)(v7 + 44) )
  {
    v15 = *(_DWORD *)(v7 + 40);
    if ( ((unsigned int)(*(_DWORD *)a2 - v15) <= 0x200 || (unsigned int)(v15 - *(_DWORD *)a2) <= 0x200)
      && *(_DWORD *)(v7 + 28) == *(_DWORD *)(v7 + 36) )
    {
      v16 = *(_DWORD *)(v7 + 24);
      v17 = *(_DWORD *)(v7 + 32);
      if ( (unsigned int)(v16 - v17) <= 0x200 || (unsigned int)(v17 - v16) <= 0x200 )
      {
        v18 = 2;
LABEL_26:
        v19 = v43;
        v20 = *(_DWORD *)(v7 + 68);
        v21 = *(_DWORD *)(v7 + 64);
        if ( (__int64)(v43 + (unsigned __int64)(unsigned int)(2 * v44) + v12) < __SPAIR64__(v20, v21) )
        {
LABEL_27:
          if ( (dword_682610 & 0x20000) != 0 )
            CcPerfLogScheduleReadAhead(0, v4, a2, v19, v44, v18, v46);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v11);
          }
          else
          {
            __dmb(0xBu);
            *v11 = 0;
          }
          v22 = v48;
          return KfLowerIrql(v22);
        }
        v24 = *(_DWORD *)(v7 + 64);
        *(_DWORD *)(v7 + 56) = v12 & 0xFFFFF000;
        *(_DWORD *)(v7 + 60) = HIDWORD(v12);
        if ( __SPAIR64__(HIDWORD(v12), (unsigned int)v12 & 0xFFFFF000) >= __SPAIR64__(v20, v21) )
          v24 = (v49 + v44 - 1) & ~(v44 - 1);
        v25 = *(_DWORD *)(v7 + 48) + 1;
        *(_DWORD *)(v7 + 48) = v25;
        v26 = v44;
        if ( v18 == 1 || v25 >= 3 )
          v26 = 2 * v44;
        v27 = v24 - (v12 & 0xFFFFF000) + v26;
        if ( v25 >= 3 )
        {
          v37 = *(_DWORD *)(v7 + 88);
          if ( v37 )
          {
            v39 = _rt_udiv64(100i64, v25 * v43 * (unsigned __int64)v37);
            if ( v40 )
              v39 = -1;
            if ( v39 > v27 )
              v27 = v39;
          }
        }
        v19 = v43;
        v46 = 1;
        *(_DWORD *)(v7 + 52) = v27;
        goto LABEL_43;
      }
    }
  }
  v23 = *(_QWORD *)(v7 + 32);
  if ( *(_QWORD *)a2 - v23 != v23 - *(_QWORD *)(v7 + 16) )
  {
LABEL_36:
    v19 = v43;
    v18 = 0;
    *(_DWORD *)(v7 + 48) = 0;
    *(_DWORD *)(v7 + 64) = 0;
    *(_DWORD *)(v7 + 68) = 0;
    *(_DWORD *)(v7 + 72) = 0;
    *(_DWORD *)(v7 + 76) = 0;
    goto LABEL_27;
  }
  v18 = 3;
  v38 = 2i64 * *(_QWORD *)a2 - v23;
  v19 = v43;
  if ( v38 < 0 )
    goto LABEL_27;
  v19 = v43 + (v38 & 0xFFF);
  *(_DWORD *)(v7 + 52) = (v19 + 4095) & 0xFFFFF000;
  v46 = 1;
  v43 = v19;
  *(_DWORD *)(v7 + 56) = v38 & 0xFFFFF000;
  *(_DWORD *)(v7 + 60) = HIDWORD(v38);
LABEL_43:
  if ( (*(_DWORD *)v7 & 0x10000) != 0 )
  {
    if ( (*(_DWORD *)(v9 + 96) & 0x10000000) != 0 )
    {
      CcChargeThreadForReadAhead(v4);
      v19 = v43;
    }
    goto LABEL_27;
  }
  *(_DWORD *)v7 |= 0x10000u;
  v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v29 = (*(_DWORD *)(v28 + 0x3C0) >> 12) & 7;
  if ( (*(_DWORD *)(*(_DWORD *)(v28 + 0x150) + 192) & 0x100000) != 0 && v29 >= 2 )
    v29 = 2;
  *(_DWORD *)v7 ^= (*(_DWORD *)v7 ^ (v29 << 18)) & 0x1C0000;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v7 + 80);
  }
  else
  {
    __dmb(0xBu);
    *v11 = 0;
  }
  KfLowerIrql(v48);
  v30 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v31 = *(_DWORD *)(v30 + 2864);
  v47 = v30;
  ++*(_DWORD *)(v31 + 12);
  v32 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v31);
  if ( !v32 )
  {
    ++*(_DWORD *)(v31 + 16);
    v34 = *(_DWORD *)(v47 + 2868);
    ++*(_DWORD *)(v34 + 12);
    v32 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v34);
    if ( !v32 )
    {
      v35 = *(_QWORD *)(v34 + 32);
      v36 = *(_DWORD *)(v34 + 28);
      ++*(_DWORD *)(v34 + 16);
      v32 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v34 + 40))(v36, HIDWORD(v35), v35);
      if ( !v32 )
      {
        v41 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v7 + 80);
        }
        else
        {
          do
            v42 = __ldrex(v11);
          while ( __strex(1u, v11) );
          __dmb(0xBu);
          if ( v42 )
            KxWaitForSpinLockAndAcquire((unsigned int *)(v7 + 80));
        }
        *(_DWORD *)v7 &= 0xFFFEFFFF;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v7 + 80);
        }
        else
        {
          __dmb(0xBu);
          *v11 = 0;
        }
        v22 = v41;
        return KfLowerIrql(v22);
      }
    }
  }
  *(_DWORD *)v32 = *(_DWORD *)(v47 + 1428);
  if ( (dword_682610 & 0x20000) != 0 )
    CcPerfLogScheduleReadAhead(v32, v4, a2, v43, v44, v18, 1);
  if ( (*(_DWORD *)(v50 + 96) & 0x10000000) != 0 )
    CcChargeThreadForReadAhead(v4);
  ObfReferenceObjectWithTag(v4);
  v33 = KeAcquireQueuedSpinLock(5);
  ++*(_DWORD *)(v50 + 4);
  *(_DWORD *)(v50 + 96) |= 0x4000u;
  KeReleaseQueuedSpinLock(5, v33);
  *(_DWORD *)(v7 + 100) = v32;
  *(_BYTE *)(v32 + 64) = 1;
  *(_DWORD *)(v32 + 8) = v4;
  return CcPostWorkQueue(v32, &CcExpressWorkQueue);
}
