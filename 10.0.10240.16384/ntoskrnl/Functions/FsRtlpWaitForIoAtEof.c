// FsRtlpWaitForIoAtEof 
 
int __fastcall FsRtlpWaitForIoAtEof(int a1, int a2, int a3, int a4)
{
  _DWORD *v7; // r8
  _DWORD *v8; // r7
  int v9; // r4
  int v11; // r2
  int v12; // r5
  _DWORD *v13; // r2
  _DWORD *v14; // r3
  _DWORD *v15; // r2
  _DWORD *v16; // r1
  _DWORD *v17; // r2
  unsigned int *v18; // r5
  unsigned int v19; // r7
  unsigned int v20; // r1
  unsigned int v21; // r7
  int v22; // r5
  int v23; // r1
  unsigned int v24; // r2
  int v25; // r0
  int v26; // r3
  int v27; // [sp+8h] [bp-58h]
  _DWORD v28[2]; // [sp+10h] [bp-50h] BYREF
  char v29[4]; // [sp+18h] [bp-48h] BYREF
  int v30; // [sp+1Ch] [bp-44h]
  int v31[6]; // [sp+20h] [bp-40h] BYREF
  int v32; // [sp+38h] [bp-28h]

  v7 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v8 = *(_DWORD **)a1;
  v9 = (v7[240] >> 9) & 7;
  if ( (*(_DWORD *)(v7[84] + 192) & 0x100000) != 0 )
    return sub_54B8A8();
  if ( ((v7[240] >> 9) & 7u) >= 2 )
    goto LABEL_4;
  if ( v7 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v7[250] )
    v9 = 2;
  if ( v9 >= 2 )
LABEL_4:
    v9 = 2;
  if ( !*(_BYTE *)(a1 + 20) && v9 > 1 )
  {
    v11 = (v8[240] >> 9) & 7;
    if ( (*(_DWORD *)(v8[84] + 192) & 0x100000) != 0 )
      v11 = 0;
    if ( v11 < 2 )
    {
      if ( v8 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v8[250] )
        v11 = 2;
      if ( v11 < 2 )
      {
        PsBoostThreadIoEx((int)v8, 0, 0);
        IoBoostThreadIoPriority((int)v8, v9, 0);
        *(_BYTE *)(a1 + 20) = 1;
      }
    }
  }
  v12 = KeQueryPriorityThread(v7);
  if ( v12 >= 15 )
    v12 = 15;
  if ( v12 > *(_DWORD *)(a1 + 16) )
  {
    *(_DWORD *)(a1 + 16) = v12;
    if ( v12 > KeQueryPriorityThread(v8) )
      KeSetPriorityBoost((int)v8, v12, v13, v14);
  }
  v15 = *(_DWORD **)(a1 + 8);
  v16 = (_DWORD *)(a1 + 4);
  while ( v15 != v16 )
  {
    v25 = v15[9];
    if ( v12 > v25 )
      goto LABEL_39;
    if ( v15[10] >= v9 )
      break;
    if ( v12 > v25 )
LABEL_39:
      v25 = v12;
    v26 = v15[10];
    v15[9] = v25;
    if ( v9 > v26 )
      v26 = v9;
    v15[10] = v26;
    v15 = (_DWORD *)v15[1];
  }
  v29[0] = 1;
  v29[1] = 0;
  v29[2] = 4;
  v30 = 0;
  v17 = *(_DWORD **)(a1 + 8);
  v31[1] = (int)v31;
  v31[2] = a3;
  v31[0] = (int)v31;
  v31[4] = (int)v7;
  v31[5] = v12;
  v32 = v9;
  v31[3] = a4;
  v28[0] = a1 + 4;
  v28[1] = v17;
  if ( (_DWORD *)*v17 != v16 )
    __fastfail(3u);
  *v17 = v28;
  *(_DWORD *)(a1 + 8) = v28;
  v18 = *(unsigned int **)(*(_DWORD *)(a1 + 12) + 40);
  v19 = v18[7];
  v18[1] = 0;
  __dmb(0xBu);
  do
    v20 = __ldrex(v18);
  while ( !v20 && __strex(1u, v18) );
  if ( v20 )
    ExpReleaseFastMutexContended(v18, v20);
  KfLowerIrql((unsigned __int8)v19);
  KeAbPostRelease((unsigned int)v18);
  KeWaitForSingleObject((unsigned int)v29, 0, 0, 0, 0);
  v21 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 40);
  v22 = KeAbPreAcquire(v21, 0, 0);
  v23 = KfRaiseIrql(1);
  v27 = v23;
  do
    v24 = __ldrex((unsigned __int8 *)v21);
  while ( __strex(v24 & 0xFE, (unsigned __int8 *)v21) );
  __dmb(0xBu);
  if ( (v24 & 1) == 0 )
  {
    ExpAcquireFastMutexContended(v21, v22);
    v23 = v27;
  }
  if ( v22 )
    *(_BYTE *)(v22 + 14) |= 1u;
  *(_DWORD *)(v21 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v21 + 28) = v23;
  if ( a4 >= 0 && __SPAIR64__(a4, a3) <= *(_QWORD *)(*(_DWORD *)(a1 + 12) + 32) )
    return 0;
  if ( v9 < 2 && !*(_BYTE *)(a1 + 20) && v32 >= 2 )
  {
    PsBoostThreadIoEx((int)v7, 0, 0);
    *(_BYTE *)(a1 + 20) = 1;
  }
  return 1;
}
