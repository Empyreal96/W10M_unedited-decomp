// ExpReleaseResourceForThreadLite 
 
int __fastcall ExpReleaseResourceForThreadLite(int a1, int a2)
{
  int result; // r0
  unsigned int *v5; // r6
  unsigned int v6; // r1
  int *v7; // r9
  int v8; // r2
  unsigned int v9; // r3
  int v10; // r3
  int v11; // r2
  __int16 v12; // r3
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r1
  int v16; // r0
  int v17; // r2
  unsigned int v18; // r1
  int v19; // r2
  unsigned int v20; // lr
  unsigned int v21; // r3
  unsigned int v22; // r3
  int v23; // r3
  unsigned int v24; // r1
  __int16 v25; // r1
  int v26; // r2
  int v27; // r6
  int v28; // r0
  int v29; // r3
  int v30; // r0
  int v31; // lr
  _DWORD *v32[2]; // [sp+8h] [bp-30h] BYREF
  _DWORD v33[2]; // [sp+10h] [bp-28h] BYREF
  char v34; // [sp+18h] [bp-20h]

  __mrc(15, 0, 13, 0, 3);
  if ( (dword_682604 & 0x20000) != 0 )
    return sub_52E500();
  v5 = (unsigned int *)(a1 + 52);
  v33[0] = 0;
  v33[1] = a1 + 52;
  __dmb(0xBu);
  v34 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireQueuedSpinLockInstrumented(v33, a1 + 52);
  }
  else
  {
    do
      v6 = __ldrex(v5);
    while ( __strex((unsigned int)v33, v5) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForLockOwnerShip(v33);
  }
  if ( (*(_WORD *)(a1 + 14) & 0x80) == 0 )
  {
    if ( *(_DWORD *)(a1 + 24) == a2 )
    {
      v7 = (int *)(a1 + 24);
    }
    else
    {
      v18 = 1;
      if ( (a2 & 3) == 0 )
        v18 = *(unsigned __int8 *)(a2 + 401);
      v19 = *(_DWORD *)(a1 + 8);
      if ( !v19 )
        KeBugCheckEx(227, a1, a2);
      v20 = *(_DWORD *)(v19 + 4);
      if ( v18 < v20 && *(_DWORD *)(v19 + 8 * v18) == a2 )
      {
        v7 = (int *)(v19 + 8 * v18);
      }
      else
      {
        v24 = v19 + 8 * v20;
        v7 = (int *)(v19 + 8);
        if ( v19 + 8 >= v24 )
LABEL_61:
          KeBugCheckEx(227, a1, a2);
        while ( *v7 != a2 )
        {
          v7 += 2;
          if ( (unsigned int)v7 >= v24 )
            goto LABEL_61;
        }
      }
    }
    v8 = v7[1] & 3 | (4 * (((unsigned int)v7[1] >> 2) - 1));
    v32[0] = (_DWORD *)v8;
    v7[1] = v8;
    if ( (v8 & 0xFFFFFFFC) != 0 )
    {
      result = KeReleaseInStackQueuedSpinLock(v33);
      v22 = (unsigned int)KeGetPcr();
      ++*(_DWORD *)((v22 & 0xFFFFF000) + 0x1430);
      return result;
    }
    if ( (v8 & 1) != 0 )
    {
      if ( (v8 & 2) != 0 )
      {
        v31 = *v7 & 0xFFFFFFFC;
      }
      else
      {
        v31 = *v7;
        if ( (*v7 & 3) != 0 )
          v31 = 0;
      }
      PsBoostThreadIoEx(v31, 1, 0);
      v7[1] &= 0xFFFFFFFE;
    }
    if ( (v7[1] & 2) != 0 )
    {
      ObDereferenceObjectDeferDeleteWithTag(*v7 & 0xFFFFFFFC);
      v7[1] &= 0xFFFFFFFD;
    }
    *v7 = 0;
    v9 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v9 & 0xFFFFF000) + 0x1430);
    v10 = *(_DWORD *)(a1 + 32) - 1;
    *(_DWORD *)(a1 + 32) = v10;
    if ( v10 )
      return KeReleaseInStackQueuedSpinLock(v33);
    v11 = *(_DWORD *)(a1 + 44);
    if ( !v11 )
    {
      v12 = *(_WORD *)(a1 + 14) & 0xFB;
LABEL_17:
      *(_WORD *)(a1 + 12) = 0;
      *(_WORD *)(a1 + 14) = v12;
      return KeReleaseInStackQueuedSpinLock(v33);
    }
    v28 = *(unsigned __int16 *)(a1 + 14) | 0x80;
    v29 = *(_DWORD *)(a1 + 28) & 3 | 4;
    *(_DWORD *)(a1 + 24) = 1;
    *(_DWORD *)(a1 + 28) = v29;
    *(_DWORD *)(a1 + 44) = v11 - 1;
    *(_WORD *)(a1 + 14) = v28;
    *(_DWORD *)(a1 + 32) = 1;
    if ( v11 == 1 && !*(_DWORD *)(a1 + 40) )
      *(_WORD *)(a1 + 14) = v28 & 0xFB;
    v32[0] = (_DWORD *)*(unsigned __int8 *)(a1 + 15);
    ExpUnlockResource(v28, v33);
    return KeSetEventBoostPriorityEx(*(_DWORD *)(a1 + 20), a1 + 24, (int *)v32, 0, 0);
  }
  v13 = *(_DWORD *)(a1 + 28) & 3 | (4 * ((*(_DWORD *)(a1 + 28) >> 2) - 1));
  *(_DWORD *)(a1 + 28) = v13;
  if ( (v13 & 0xFFFFFFFC) != 0 )
  {
    result = KeReleaseInStackQueuedSpinLock(v33);
    v21 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v21 & 0xFFFFF000) + 0x142C);
    return result;
  }
  if ( (v13 & 1) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 28) & 2) != 0 )
    {
      v30 = *(_DWORD *)(a1 + 24) & 0xFFFFFFFC;
    }
    else
    {
      v30 = *(_DWORD *)(a1 + 24);
      if ( (v30 & 3) != 0 )
        v30 = 0;
    }
    PsBoostThreadIoEx(v30, 1, 0);
    *(_DWORD *)(a1 + 28) &= 0xFFFFFFFE;
  }
  if ( (*(_DWORD *)(a1 + 28) & 2) != 0 )
  {
    ObDereferenceObjectDeferDeleteWithTag(*(_DWORD *)(a1 + 24) & 0xFFFFFFFC);
    *(_DWORD *)(a1 + 28) &= 0xFFFFFFFD;
  }
  v14 = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 32) = v14 - 1;
  v15 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  ++*(_DWORD *)(v15 + 5164);
  v16 = *(_DWORD *)(a1 + 40);
  if ( !v16 )
  {
    v17 = *(_DWORD *)(a1 + 44);
    if ( !v17 )
    {
      v12 = *(_WORD *)(a1 + 14) & 0x7B;
      goto LABEL_17;
    }
    v23 = *(_DWORD *)(a1 + 28) & 3 | 4;
    *(_DWORD *)(a1 + 24) = 1;
    *(_DWORD *)(a1 + 28) = v23;
    *(_DWORD *)(a1 + 44) = v17 - 1;
    *(_DWORD *)(a1 + 32) = 1;
    if ( v17 == 1 )
      *(_WORD *)(a1 + 14) &= 0xFBu;
    v32[0] = (_DWORD *)*(unsigned __int8 *)(a1 + 15);
    ExpUnlockResource(1, v33);
    return KeSetEventBoostPriorityEx(*(_DWORD *)(a1 + 20), a1 + 24, (int *)v32, 0, 0);
  }
  v25 = *(_WORD *)(a1 + 14);
  *(_DWORD *)(a1 + 32) = v16;
  v26 = *(_DWORD *)(a1 + 44);
  *(_WORD *)(a1 + 14) = v25 & 0xFF7F;
  *(_DWORD *)(a1 + 40) = 0;
  if ( !v26 )
    *(_WORD *)(a1 + 14) = v25 & 0x7B;
  v27 = *(unsigned __int8 *)(a1 + 15);
  v32[0] = *(_DWORD **)(a1 + 16);
  *(_DWORD *)(a1 + 16) = 0;
  ExpUnlockResource(v16, v33);
  return KeWakeWaitChain(v32, v27, 1);
}
