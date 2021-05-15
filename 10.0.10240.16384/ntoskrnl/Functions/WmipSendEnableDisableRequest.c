// WmipSendEnableDisableRequest 
 
int __fastcall WmipSendEnableDisableRequest(int a1, _DWORD *a2, int a3)
{
  int v4; // r3
  int v5; // lr
  int v6; // r10
  BOOL v7; // r9
  int v8; // r5
  unsigned int v9; // r8
  _DWORD *v11; // r4
  _DWORD *v12; // r1
  char *v13; // r10
  int v14; // r2
  int v15; // r0
  int v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r3
  char *v20; // r5
  _DWORD *v21; // t1
  int v22; // [sp+8h] [bp-160h]
  int v23; // [sp+10h] [bp-158h] BYREF
  int v24[12]; // [sp+18h] [bp-150h] BYREF
  char v25[288]; // [sp+48h] [bp-120h] BYREF

  v4 = a2[2];
  v22 = a3;
  v5 = a3;
  v6 = a1;
  v23 = a1;
  if ( (v4 & 1) != 0 )
    return 0;
  v7 = a1 == 4 || a1 == 6;
  if ( a3 )
    v8 = 0x2000;
  else
    v8 = 0x4000;
  v9 = 0;
  if ( a2[5] > 0x40u )
    return sub_815A6C();
  v11 = (_DWORD *)a2[8];
  v12 = a2 + 8;
  if ( v11 == a2 + 8 )
    goto LABEL_22;
  v13 = v25;
  while ( v9 < a2[5] )
  {
    v14 = v11[2];
    if ( (v14 & 0x1000) != 0 || !v5 && (v14 & 4) == 0 )
      goto LABEL_20;
    v15 = v11[8];
    if ( (*(_DWORD *)(v15 + 8) & 0x20000000) != 0 )
      goto LABEL_20;
    if ( v7 )
    {
      if ( (v14 & v8) != 0 )
        goto LABEL_17;
    }
    else if ( (v14 & v8) == 0 )
    {
LABEL_32:
      v16 = v11[2] & ~v8;
      goto LABEL_19;
    }
    *(_DWORD *)v13 = v15;
    WmipReferenceEntry(v15);
    v5 = v22;
    ++v9;
    v13 += 4;
    v12 = a2 + 8;
LABEL_17:
    if ( !v7 )
      goto LABEL_32;
    v16 = v11[2] | v8;
LABEL_19:
    v11[2] = v16;
LABEL_20:
    v11 = (_DWORD *)*v11;
    if ( v11 == v12 )
      break;
  }
  v6 = v23;
LABEL_22:
  KeReleaseMutex((int)&WmipSMMutex);
  if ( v9 )
  {
    memset(v24, 0, sizeof(v24));
    v17 = a2[11];
    v18 = a2[12];
    v19 = a2[13];
    v24[6] = a2[10];
    v24[7] = v17;
    v24[8] = v18;
    v24[9] = v19;
    v24[0] = 48;
    v20 = v25;
    do
    {
      v21 = *(_DWORD **)v20;
      v20 += 4;
      WmipSendWmiIrp(v6, v21[7], (int)&v24[6], 48, (int)v24, &v23);
      WmipUnreferenceEntry((int *)&WmipDSChunkInfo, v21);
      --v9;
    }
    while ( v9 );
  }
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  return 0;
}
