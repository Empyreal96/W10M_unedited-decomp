// sub_808718 
 
int __fastcall sub_808718(int a1)
{
  int v1; // r4
  unsigned int v2; // r1
  unsigned int v3; // r1
  int v4; // r0
  __int64 v5; // r2
  __int64 v6; // r2
  int v7; // r1
  int v8; // r0
  unsigned int *v9; // r0
  unsigned int v10; // r6
  unsigned int v11; // r5
  unsigned int v13; // r1
  int v14; // r4
  int v15; // r5
  unsigned int v16; // r6
  int v17; // r7
  char v18; // r8
  int v19; // r9
  int v20; // r10
  int v21; // r7
  int v22; // r8
  int v23; // r10
  int v24; // [sp+10h] [bp-60h] BYREF
  int v25; // [sp+14h] [bp-5Ch] BYREF
  unsigned int v26; // [sp+18h] [bp-58h] BYREF
  int v27; // [sp+1Ch] [bp-54h]
  __int64 v28; // [sp+20h] [bp-50h]
  int v29; // [sp+28h] [bp-48h]
  int v30; // [sp+2Ch] [bp-44h]
  int v31; // [sp+30h] [bp-40h]
  __int64 v32; // [sp+38h] [bp-38h] BYREF
  int v33; // [sp+40h] [bp-30h]
  int v34; // [sp+44h] [bp-2Ch]
  int (__fastcall *v35)(int); // [sp+6Ch] [bp-4h]

  if ( v14 >= 0 )
    v14 = 0;
  if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(a1 + 1000) )
    v14 = 2;
  if ( v14 < 2 )
  {
    v21 = 0;
    v22 = 1075380276;
    goto LABEL_45;
  }
  v1 = 1;
  __dmb(0xBu);
  do
  {
    v2 = __ldrex(dword_6373B0);
    v3 = v2 + 1;
  }
  while ( __strex(v3, dword_6373B0) );
  __dmb(0xBu);
  if ( v3 < dword_637108 )
  {
    v4 = PfSnCheckActionsNeeded(v20, v17, a1, &v25, &v32);
    v19 = v4;
    if ( (v18 & 2) != 0 )
    {
      v19 = v4 & 0xFFFFFFFD;
      v23 = 9;
    }
    else
    {
      v23 = v32;
    }
    if ( (v19 & 2) != 0 )
    {
      if ( PfSnGetPrefetchInstructions(v27, v17, &v26) >= 0 )
      {
        KeQuerySystemTime(&v32);
        v16 = v26;
        v6 = *(_QWORD *)(v26 + 200);
        v28 = v32 - *(_QWORD *)(v26 + 128);
        if ( v28 < v6 )
        {
          v21 = v25;
          if ( v25 != 22 )
          {
            v19 &= 0xFFFFFFFE;
            v21 = 11;
          }
        }
        else
        {
          v21 = v25;
        }
        v5 = *(_QWORD *)(v26 + 192);
        if ( v28 < v5 && v23 != 22 )
          v19 &= 0xFFFFFFFD;
        v29 = *(_DWORD *)(v26 + 208);
LABEL_23:
        if ( (v18 & 4) != 0 )
        {
          v19 &= 0xFFFFFFFE;
          v21 = 8;
        }
        if ( (v19 & 1) != 0 )
        {
          if ( (v18 & 1) != 0 )
            v7 = v31;
          else
            v7 = 0;
          v8 = PfSnBeginTrace(v27, v30, v33, v7, (v18 & 8) != 0, (unsigned int *)&v24);
          if ( v8 >= 0 )
            goto LABEL_29;
          switch ( v8 )
          {
            case -1073741618:
              v21 = 16;
LABEL_29:
              v15 = v24;
              goto LABEL_30;
            case -1073741670:
              v21 = 17;
              goto LABEL_29;
            case -1072037882:
              v21 = 18;
              goto LABEL_29;
            case -1073741791:
              v21 = 19;
              goto LABEL_29;
          }
          v15 = v24;
          if ( v8 == -1073741661 )
            v21 = 20;
          else
            v21 = 21;
        }
LABEL_30:
        if ( (v19 & 2) != 0 )
        {
          HIDWORD(v5) = *(_DWORD *)(v16 + 216);
          if ( (v5 & 0x300000000i64) != 0 )
            v18 |= 0x10u;
          if ( PfSnPrefetchScenario(v16, v18, v5, HIDWORD(v5)) >= 0 )
            v1 = 0;
          v16 = 0;
        }
        v22 = 0;
        if ( !v1 )
          goto LABEL_37;
        goto LABEL_48;
      }
      v16 = v26;
      v19 &= 0xFFFFFFFD;
    }
    v21 = v25;
    goto LABEL_23;
  }
  v21 = 1;
  v22 = -1073741631;
LABEL_48:
  __dmb(0xBu);
  do
    v13 = __ldrex(dword_6373B0);
  while ( __strex(v13 - 1, dword_6373B0) );
  __dmb(0xBu);
LABEL_37:
  if ( v16 )
    ExFreePoolWithTag(v16);
  if ( v15 )
  {
    v22 = PfSnStartTraceTimer(v15);
    v9 = (unsigned int *)(v15 + 268);
    __pld((void *)(v15 + 268));
    v10 = *(_DWORD *)(v15 + 268) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v11 = __ldrex(v9);
    while ( v11 == v10 && __strex(v10 - 2, v9) );
    if ( v11 != v10 )
      ExfReleaseRundownProtection((unsigned __int8 *)v9);
  }
LABEL_45:
  PfSnLogScenarioDecision(v27, v30, v19, v21);
  *(_BYTE *)(v31 + 346) = v34;
  return v35(v22);
}
