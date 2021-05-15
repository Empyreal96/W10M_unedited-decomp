// sub_6E34A4 
 
int __fastcall sub_6E34A4(int a1, char a2, char a3)
{
  unsigned int v5; // r0
  unsigned int v6; // r9
  int v7; // r4
  int v8; // r0
  int v9; // r4
  int *v10; // r2
  int v11; // r1
  int v12; // r4
  int *v13; // r0
  int v14; // r1
  int v15; // r9
  int v16; // r2
  int v17; // r2
  int v18; // r2
  int v19; // r2
  unsigned int v20; // r0
  int v22; // [sp+0h] [bp-30h]
  int v23; // [sp+4h] [bp-2Ch] BYREF
  int v24; // [sp+8h] [bp-28h]
  int *v25; // [sp+Ch] [bp-24h]

  v5 = 0;
  v24 = 0;
  v6 = 0;
  v25 = 0;
  if ( !a1 )
  {
    v7 = -1073741811;
    goto LABEL_38;
  }
  if ( (a3 & 1) == 0 && !dword_922C44 )
  {
    v7 = 0;
    goto LABEL_38;
  }
  v8 = KeAbPreAcquire((unsigned int)&dword_922C04, 0, 0);
  v9 = v8;
  v10 = &dword_922C04;
  do
    v11 = __ldrex((unsigned __int8 *)&dword_922C04);
  while ( __strex(v11 | 1, (unsigned __int8 *)&dword_922C04) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_922C04, v8, (unsigned int)&dword_922C04);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  if ( dword_922BEC )
  {
    v23 = *(_DWORD *)dword_922BEC;
    v22 = sub_6E2544(&v23, v11, (int)v10, v23);
    if ( v22 >= 0 )
    {
      v12 = v23;
      goto LABEL_20;
    }
  }
  else
  {
    v12 = ExAllocatePoolWithTag(1, 48, 542329939);
    v24 = v12;
    if ( v12 && (v13 = (int *)ExAllocatePoolWithTag(1, 4, 542329939), v15 = (int)v13, (v25 = v13) != 0) )
    {
      *v13 = v12;
      v23 = v12;
      *(_DWORD *)v12 = 0;
      *(_DWORD *)(v12 + 4) = 0;
      *(_DWORD *)(v12 + 16) = 0;
      *(_DWORD *)(v12 + 20) = 0;
      *(_DWORD *)(v12 + 8) = 4;
      *(_DWORD *)(v12 + 24) = 0;
      *(_DWORD *)(v12 + 28) = 0;
      *(_DWORD *)(v12 + 32) = 0;
      *(_DWORD *)(v12 + 36) = 0;
      *(_BYTE *)(v12 + 40) = 1;
      v22 = sub_7B38FC(v13, v14);
      if ( v22 >= 0 )
      {
        dword_922BEC = v15;
        v24 = 0;
        v25 = 0;
LABEL_20:
        if ( (a2 & 1) != 0 )
        {
          v16 = *(_DWORD *)(a1 + 4);
          *(_DWORD *)v12 = *(_DWORD *)a1;
          *(_DWORD *)(v12 + 4) = v16;
        }
        if ( (a2 & 2) != 0 )
          *(_DWORD *)(v12 + 8) = *(_DWORD *)(a1 + 8);
        if ( (a2 & 4) != 0 )
        {
          v17 = *(_DWORD *)(a1 + 20);
          *(_DWORD *)(v12 + 16) = *(_DWORD *)(a1 + 16);
          *(_DWORD *)(v12 + 20) = v17;
        }
        if ( (a2 & 8) != 0 )
        {
          v18 = *(_DWORD *)(a1 + 28);
          *(_DWORD *)(v12 + 24) = *(_DWORD *)(a1 + 24);
          *(_DWORD *)(v12 + 28) = v18;
        }
        if ( (a2 & 0x10) != 0 )
        {
          v19 = *(_DWORD *)(a1 + 36);
          *(_DWORD *)(v12 + 32) = *(_DWORD *)(a1 + 32);
          *(_DWORD *)(v12 + 36) = v19;
        }
        if ( (a2 & 0x20) != 0 )
          *(_BYTE *)(v12 + 40) = *(_BYTE *)(a1 + 40);
        goto LABEL_32;
      }
    }
    else
    {
      v22 = -1073741801;
    }
  }
LABEL_32:
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)&dword_922C04);
  while ( __strex(v20 - 1, (unsigned int *)&dword_922C04) );
  if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_922C04);
  KeAbPostRelease((unsigned int)&dword_922C04);
  v7 = v22;
  v5 = v24;
  v6 = (unsigned int)v25;
LABEL_38:
  if ( v5 )
    ExFreePoolWithTag(v5);
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v7;
}
