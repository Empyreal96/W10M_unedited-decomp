// SepGetLogonSessionAccountInfo 
 
int __fastcall SepGetLogonSessionAccountInfo(_DWORD *a1, _DWORD *a2, _DWORD *a3, int *a4)
{
  int v5; // r6
  int v8; // r7
  unsigned int v9; // r5
  int v10; // r0
  int v11; // r4
  int v13; // r5
  int v14; // r6
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r0
  int v19; // r0
  unsigned int v20; // r0
  unsigned int v21; // r0
  int v23; // [sp+4h] [bp-24h]

  v5 = *a1 & 0xF;
  v8 = 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v23 = 7 * (v5 & 3);
  v10 = ExAcquireResourceSharedLite((int)&SepRmDbLock + 56 * (v5 & 3), 1);
  v11 = *(_DWORD *)(SepLogonSessions + 4 * v5);
  if ( !v11 )
    JUMPOUT(0x815F24);
  if ( *a1 != *(_DWORD *)(v11 + 4) || a1[1] != *(_DWORD *)(v11 + 8) )
    return sub_815F1C(v10);
  v13 = 0;
  *a2 = *(_DWORD *)(v11 + 36);
  a2[1] = *(_DWORD *)(v11 + 40);
  *a3 = *(_DWORD *)(v11 + 44);
  a3[1] = *(_DWORD *)(v11 + 48);
  a2[1] = 0;
  a3[1] = 0;
  if ( *(_DWORD *)(v11 + 40)
    && (v18 = ExAllocatePoolWithTag(1, *(unsigned __int16 *)(v11 + 38), 1799447891), (a2[1] = v18) == 0)
    || *(_DWORD *)(v11 + 48)
    && (v19 = ExAllocatePoolWithTag(1, *(unsigned __int16 *)(v11 + 46), 1799447891), (a3[1] = v19) == 0) )
  {
    v8 = -1073741670;
  }
  v14 = *(_DWORD *)(v11 + 32);
  if ( v8 < 0 )
    goto LABEL_21;
  if ( a4 )
  {
    if ( v14 )
    {
      v13 = ExAllocatePoolWithTag(1, 4 * (*(unsigned __int8 *)(**(_DWORD **)(v14 + 148) + 1) + 2), 1767073107);
      if ( !v13 )
        v8 = -1073741670;
    }
  }
  if ( v8 < 0 )
  {
LABEL_21:
    v20 = a2[1];
    if ( v20 )
      ExFreePoolWithTag(v20);
    v21 = a3[1];
    if ( v21 )
      ExFreePoolWithTag(v21);
    if ( v13 )
      ExFreePoolWithTag(v13);
  }
  else
  {
    memmove(a2[1], *(_DWORD *)(v11 + 40), *(unsigned __int16 *)(v11 + 38));
    memmove(a3[1], *(_DWORD *)(v11 + 48), *(unsigned __int16 *)(v11 + 46));
    if ( v13 )
    {
      memmove(v13, **(_DWORD **)(v14 + 148), 4 * (*(unsigned __int8 *)(**(_DWORD **)(v14 + 148) + 1) + 2));
      *a4 = v13;
    }
  }
  v15 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v23);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return v8;
}
