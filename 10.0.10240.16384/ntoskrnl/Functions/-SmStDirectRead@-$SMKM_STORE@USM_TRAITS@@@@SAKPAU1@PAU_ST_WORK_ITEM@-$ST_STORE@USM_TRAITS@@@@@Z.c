// -SmStDirectRead@-$SMKM_STORE@USM_TRAITS@@@@SAKPAU1@PAU_ST_WORK_ITEM@-$ST_STORE@USM_TRAITS@@@@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStDirectRead(int a1, int *a2)
{
  int *v2; // r5
  unsigned int v4; // r7
  int v5; // r3
  int v6; // r0
  int *v7; // r9
  int v8; // r8
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int *v13; // r5
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r4
  int v19; // r3
  int *v20; // [sp+8h] [bp-68h]
  _DWORD v21[3]; // [sp+10h] [bp-60h] BYREF
  int v22; // [sp+1Ch] [bp-54h]
  int v23; // [sp+20h] [bp-50h]
  int v24; // [sp+24h] [bp-4Ch]
  int v25; // [sp+28h] [bp-48h]
  int v26; // [sp+2Ch] [bp-44h]
  int v27; // [sp+30h] [bp-40h]
  int v28; // [sp+34h] [bp-3Ch]
  char v29[56]; // [sp+38h] [bp-38h] BYREF

  v2 = a2;
  v20 = a2;
  v4 = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
  {
    v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v6 = PsInitialSystemProcess;
    if ( v5 != PsInitialSystemProcess )
    {
      v7 = a2;
LABEL_4:
      v8 = (int)v20;
      goto LABEL_5;
    }
  }
  else
  {
    v6 = PsInitialSystemProcess;
  }
  KiStackAttachProcess(v6, 0, (int)v29);
  v4 = 2;
  v7 = (int *)ST_STORE<SM_TRAITS>::StAcquireReadContext(a1);
  if ( !v7 )
    goto LABEL_4;
  v4 = 3;
  v10 = v20[1];
  v11 = v20[2];
  v12 = v20[3];
  v13 = v2 + 4;
  v23 = *v20;
  v24 = v10;
  v25 = v11;
  v26 = v12;
  v14 = *v13;
  v15 = v13[1];
  v2 = v20;
  v27 = v14;
  v28 = v15;
  v21[0] = a1;
  v21[1] = v20;
  v21[2] = v7;
  v8 = KeExpandKernelStackAndCalloutEx((int)SMKM_STORE<SM_TRAITS>::SmStDirectReadCallout, (int)v21, 0x2000, 0, 0);
  if ( v8 >= 0 )
  {
    if ( v22 == -1073741550 )
    {
      v16 = v24;
      v17 = v25;
      v18 = v26;
      *v20 = v23;
      v20[1] = v16;
      v20[2] = v17;
      v20[3] = v18;
      v19 = v28;
      v20[4] = v27;
      v20[5] = v19;
      v2 = v20;
    }
    else
    {
      v4 = 7;
      v8 = v22;
    }
  }
LABEL_5:
  if ( (v4 & 1) != 0 )
    ST_STORE<SM_TRAITS>::StReleaseReadContext(a1, v7);
  if ( ((v4 >> 2) & 1) != 0 )
    SMKM_STORE<SM_TRAITS>::SmStDirectReadComplete(a1, v2, v8);
  if ( (v4 & 2) != 0 )
    KiUnstackDetachProcess((unsigned int)v29, 0);
  return (v4 >> 2) & 1;
}
