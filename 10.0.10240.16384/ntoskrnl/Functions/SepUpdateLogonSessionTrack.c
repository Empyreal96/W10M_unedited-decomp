// SepUpdateLogonSessionTrack 
 
int __fastcall SepUpdateLogonSessionTrack(int a1)
{
  int v2; // r6
  int v3; // r4
  int v4; // r2
  int v5; // r7
  int *v6; // r4
  unsigned int v7; // r0
  int v8; // r0
  __int16 v9; // r3
  __int16 v10; // r3
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3

  v2 = 0;
  v3 = *(_DWORD *)a1 & 0xF;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = 7 * (v3 & 3);
  ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (v3 & 3), 1, v4, v3 & 3);
  v6 = *(int **)(SepLogonSessions + 4 * v3);
  if ( v6 )
  {
    while ( *(_DWORD *)a1 != v6[1] || *(_DWORD *)(a1 + 4) != v6[2] )
    {
      v6 = (int *)*v6;
      if ( !v6 )
        goto LABEL_15;
    }
    v7 = v6[10];
    if ( v7 )
    {
      ExFreePoolWithTag(v7);
      v6[10] = 0;
      v6[12] = 0;
    }
    v8 = ExAllocatePoolWithTag(
           1,
           *(unsigned __int16 *)(a1 + 16) + ((*(unsigned __int16 *)(a1 + 8) + 5) & 0xFFFFFFFC) + 2,
           1934386515);
    if ( v8 )
    {
      v6[10] = v8;
      v6[12] = ((*(unsigned __int16 *)(a1 + 8) + 5) & 0xFFFFFFFC) + v8;
      memmove(v8, a1 + 24, *(unsigned __int16 *)(a1 + 8));
      v9 = *(_WORD *)(a1 + 8);
      *((_WORD *)v6 + 18) = v9;
      *((_WORD *)v6 + 19) = v9 + 2;
      *(_WORD *)(v6[10] + 2 * (*((unsigned __int16 *)v6 + 18) >> 1)) = 0;
      memmove(v6[12], ((*(unsigned __int16 *)(a1 + 8) + 3) & 0xFFFFFFFC) + a1 + 24, *(unsigned __int16 *)(a1 + 16));
      v10 = *(_WORD *)(a1 + 16);
      *((_WORD *)v6 + 22) = v10;
      *((_WORD *)v6 + 23) = v10 + 2;
      *(_WORD *)(v6[12] + 2 * (*((unsigned __int16 *)v6 + 22) >> 1)) = 0;
    }
    else
    {
      v2 = -1073741670;
    }
    v11 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v5);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(_WORD *)(v12 + 0x134) + 1;
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 )
      return sub_7E9D40(v11);
  }
  else
  {
LABEL_15:
    v15 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v5);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    v2 = -1073741729;
  }
  return v2;
}
