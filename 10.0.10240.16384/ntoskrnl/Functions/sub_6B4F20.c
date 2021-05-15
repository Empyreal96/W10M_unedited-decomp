// sub_6B4F20 
 
int __fastcall sub_6B4F20(int a1, int *a2)
{
  int v3; // r6
  unsigned int v4; // r9
  unsigned int v5; // r8
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r5
  int v10; // r4
  int v11; // r0
  int v12; // r10
  unsigned int v13; // r5
  int v14; // r2
  unsigned int v15; // r8
  unsigned int v16; // r2
  unsigned int v18; // [sp+8h] [bp-68h] BYREF
  int v19; // [sp+Ch] [bp-64h]
  unsigned int v20; // [sp+10h] [bp-60h] BYREF
  int *v21; // [sp+14h] [bp-5Ch]
  int v22; // [sp+18h] [bp-58h]
  unsigned int v23; // [sp+1Ch] [bp-54h]
  int v24; // [sp+20h] [bp-50h]
  int v25; // [sp+24h] [bp-4Ch]
  unsigned int v26; // [sp+28h] [bp-48h]
  int v27; // [sp+2Ch] [bp-44h]
  int v28; // [sp+30h] [bp-40h]
  int v29; // [sp+34h] [bp-3Ch]
  int v30; // [sp+38h] [bp-38h]
  unsigned int v31; // [sp+40h] [bp-30h]
  int v32; // [sp+44h] [bp-2Ch]
  int v33; // [sp+48h] [bp-28h]
  int v34; // [sp+4Ch] [bp-24h]
  int v35; // [sp+50h] [bp-20h]
  int anonymous18; // [sp+78h] [bp+8h]
  int *anonymous19; // [sp+7Ch] [bp+Ch]

  anonymous18 = a1;
  v21 = a2;
  anonymous19 = a2;
  v3 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v4 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v5 = 0;
  v18 = 0;
  v20 = 0;
  v25 = 0;
  if ( !a2 )
  {
    v3 = -1073741789;
    goto LABEL_27;
  }
  if ( (unsigned int)(a2 + 5) > MmUserProbeAddress || a2 + 5 < a2 )
    *(_BYTE *)MmUserProbeAddress = 0;
  v6 = a2[1];
  v7 = a2[2];
  v8 = a2[3];
  v31 = *a2;
  v32 = v6;
  v33 = v7;
  v34 = v8;
  v35 = a2[4];
  __dmb(0xBu);
  v26 = v31;
  v27 = v32;
  v28 = v33;
  v29 = v34;
  v30 = v35;
  v9 = v33;
  v10 = v31;
  if ( v33 && (v33 + v31 > MmUserProbeAddress || v33 + v31 < v31) )
    *(_BYTE *)MmUserProbeAddress = 0;
  if ( !v10 || !v9 )
  {
    v3 = -1073741789;
    v19 = -1073741789;
    goto LABEL_17;
  }
  v23 = v9;
  v24 = v9;
  v11 = ExAllocatePoolWithTag(1, v9, 542329939);
  v4 = v11;
  v22 = v11;
  if ( !v11 )
  {
    v3 = -1073741801;
    v19 = -1073741801;
LABEL_17:
    v12 = v27;
    v13 = v29;
    goto LABEL_18;
  }
  memmove(v11, v10, v9);
  v12 = v27;
  v13 = v29;
  if ( v27 )
  {
    v14 = v29;
    v25 = v29;
    goto LABEL_19;
  }
LABEL_18:
  v14 = 0;
LABEL_19:
  if ( v3 < 0 )
    goto LABEL_27;
  v3 = sub_6B50D4(v4, v23, v14, &v18, &v20);
  v19 = v3;
  if ( v3 >= 0 )
  {
    if ( v12 )
    {
      v15 = v20;
      v23 = v20;
      if ( v13 >= v20 )
      {
        ProbeForWrite(v12, v20, 1);
        v16 = v15;
        v5 = v18;
        memmove(v12, v18, v16);
        __dmb(0xBu);
        v21[3] = v23;
        goto LABEL_27;
      }
      v3 = -1073741789;
      v19 = -1073741789;
    }
    else
    {
      __dmb(0xBu);
      v21[3] = v20;
    }
  }
  v5 = v18;
LABEL_27:
  if ( v4 )
    ExFreePoolWithTag(v4);
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v3;
}
