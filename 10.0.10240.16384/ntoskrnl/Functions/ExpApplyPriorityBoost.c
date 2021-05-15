// ExpApplyPriorityBoost 
 
int __fastcall ExpApplyPriorityBoost(int result, __int16 a2, int a3)
{
  int v3; // r4
  int v5; // r6
  bool v6; // cc
  BOOL v7; // r9
  BOOL v8; // r8
  int v9; // r0
  int v10; // r2
  char v11; // r3
  unsigned int v12; // r5
  int v13; // r3
  signed int v14; // r0
  __int16 v15; // r3
  unsigned int v16; // r3
  int *v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r3
  int v20; // r5
  int v21; // r5
  signed int v22; // r0
  unsigned int v23; // r3
  int v24; // r3
  int v25; // [sp+0h] [bp-40h]
  unsigned int v26; // [sp+4h] [bp-3Ch]
  unsigned int v27; // [sp+8h] [bp-38h]
  int *v28; // [sp+Ch] [bp-34h]
  int v29; // [sp+10h] [bp-30h]
  char v30[40]; // [sp+18h] [bp-28h] BYREF

  v3 = result;
  if ( (*(_WORD *)(result + 14) & 8) != 0 )
    return result;
  v5 = (*(_DWORD *)(a3 + 960) >> 9) & 7;
  if ( (*(_DWORD *)(*(_DWORD *)(a3 + 336) + 192) & 0x100000) != 0 )
    v5 = 0;
  v6 = v5 <= 2;
  if ( v5 < 2 )
  {
    if ( a3 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(a3 + 1000) )
      v5 = 2;
    v6 = v5 <= 2;
  }
  if ( v6 )
    v5 = 2;
  v7 = (a2 & 0xFF00) != 0;
  v8 = (a2 & 4) != 0;
  v25 = 0;
  v9 = ExpLockResource(result, v30);
  if ( v8 )
    *(_WORD *)(v3 + 14) |= 4u;
  if ( v7 )
  {
    v10 = *(char *)(a3 + 123);
    if ( v10 > *(unsigned __int8 *)(v3 + 15) )
    {
      v11 = *(_BYTE *)(a3 + 123);
      if ( (unsigned __int8)v10 >= 0xFu )
        v11 = 15;
      *(_BYTE *)(v3 + 15) = v11;
    }
  }
  if ( (*(_DWORD *)(v3 + 28) & 2) != 0 )
  {
    v12 = *(_DWORD *)(v3 + 24) & 0xFFFFFFFC;
  }
  else
  {
    v12 = *(_DWORD *)(v3 + 24);
    if ( (v12 & 3) != 0 )
      goto LABEL_25;
  }
  if ( v12 )
  {
    if ( v8
      && (*(_DWORD *)(v3 + 28) & 1) == 0
      && ((*(_DWORD *)(*(_DWORD *)(v12 + 336) + 192) & 0x100000) != 0 || ((*(_DWORD *)(v12 + 960) >> 9) & 7u) < 2) )
    {
      v25 = 4;
      v9 = PsBoostThreadIoEx(v12, 0, 0);
      *(_DWORD *)(v3 + 28) |= 1u;
    }
    if ( v7 )
    {
      v13 = v25;
      if ( *(unsigned __int8 *)(v3 + 15) > *(char *)(v12 + 123) )
      {
        v13 = v25 | 0xFF00;
        v25 |= 0xFF00u;
      }
    }
    else
    {
      v13 = v25;
    }
    if ( v13 )
    {
      v14 = ObfReferenceObject(v12);
      ExpUnlockResource(v14, v30);
      v15 = v25;
      if ( (v25 & 4) != 0 )
      {
        ++ExpResourceIoBoosted;
        IoBoostThreadIoPriority(v12, v5, 0);
        v15 = v25;
      }
      if ( (v15 & 0xFF00) != 0 )
      {
        v16 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v16 & 0xFFFFF000) + 0x14A8);
        KeSetPriorityBoost(v12, *(unsigned __int8 *)(v3 + 15));
      }
      v25 = 0;
      ObDereferenceObjectDeferDeleteWithTag(v12);
      v9 = ExpLockResource(v3, v30);
    }
  }
LABEL_25:
  if ( (*(_WORD *)(v3 + 14) & 0x80) != 0 )
    return ExpUnlockResource(v9, v30);
  v17 = *(int **)(v3 + 8);
  if ( !v17 )
    return ExpUnlockResource(v9, v30);
  v18 = 1;
  v29 = 1;
  v27 = v17[1];
  if ( v27 <= 1 )
    return ExpUnlockResource(v9, v30);
  v19 = v17[1];
  while ( 1 )
  {
    v17 += 2;
    v20 = v17[1];
    v28 = v17;
    if ( (v20 & 2) != 0 )
      break;
    v9 = *v17;
    v26 = *v17;
    if ( (*v17 & 3) == 0 && v9 )
    {
      if ( v8
        && (v20 & 1) == 0
        && ((*(_DWORD *)(*(_DWORD *)(v9 + 336) + 192) & 0x100000) != 0 || ((*(_DWORD *)(v9 + 960) >> 9) & 7u) < 2) )
      {
        v21 = v25 | 4;
        v25 |= 4u;
        PsBoostThreadIoEx(v9, 0, 0);
        v18 = v29;
        v9 = v26;
        v28[1] |= 1u;
      }
      else
      {
        v21 = v25;
      }
      if ( v7 && *(unsigned __int8 *)(v3 + 15) > *(char *)(v9 + 123) )
      {
        v21 |= 0xFF00u;
        v25 = v21;
      }
      if ( v21 )
      {
        v22 = ObfReferenceObject(v9);
        ExpUnlockResource(v22, v30);
        if ( (v21 & 4) != 0 )
        {
          ++ExpResourceIoBoostedShared;
          IoBoostThreadIoPriority(v26, v5, 0);
        }
        if ( (v21 & 0xFF00) != 0 )
        {
          v23 = (unsigned int)KeGetPcr();
          ++*(_DWORD *)((v23 & 0xFFFFF000) + 0x14AC);
          KeSetPriorityBoost(v26, *(unsigned __int8 *)(v3 + 15));
        }
        ObDereferenceObjectDeferDeleteWithTag(v26);
        v25 = 0;
        v9 = ExpLockResource(v3, v30);
        v24 = *(_DWORD *)(v3 + 8);
        if ( !v24 || *(_DWORD *)(v24 + 4) != v27 )
          return ExpUnlockResource(v9, v30);
        v18 = v29;
      }
      v19 = v27;
      v17 = v28;
    }
    v29 = ++v18;
    if ( v18 >= v19 )
      return ExpUnlockResource(v9, v30);
  }
  return sub_54A868();
}
