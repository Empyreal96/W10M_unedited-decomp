// ExAllocatePoolWithQuotaTag 
 
int __fastcall ExAllocatePoolWithQuotaTag(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // r7
  int v4; // r9
  unsigned int v5; // r4
  unsigned int v6; // r4
  int v7; // r6
  int v8; // r0
  int v9; // r5
  int v11; // r7
  int v12; // r0
  int v13; // r1
  __int16 v14; // r2
  int v15; // r1
  int v16; // r10
  int v17; // r2
  unsigned __int8 v18; // lr
  unsigned int *v19; // r4
  unsigned int v20; // r9
  unsigned int v21; // r3
  unsigned int v22; // r0
  unsigned int v23; // r2
  unsigned int *v24; // lr
  unsigned int v25; // r4
  unsigned int *v26; // r1
  int v27; // r4
  unsigned int v28; // r3
  unsigned int v29; // r4
  unsigned int v30; // r0
  unsigned int *v31; // lr
  int v32; // r4
  unsigned int v33; // r1
  unsigned int v34; // r2
  unsigned int v35; // r1
  unsigned int v36; // r2
  unsigned int *v37; // r2
  unsigned int v38; // r0
  int v39; // r7
  unsigned int *v40; // r0
  unsigned int v41; // r1
  unsigned int v42; // [sp+8h] [bp-38h] BYREF
  int v43; // [sp+Ch] [bp-34h]
  int v44; // [sp+10h] [bp-30h]
  int v45; // [sp+14h] [bp-2Ch]
  int v46; // [sp+18h] [bp-28h]
  int v47; // [sp+1Ch] [bp-24h]
  int v48; // [sp+20h] [bp-20h]

  v3 = 1;
  v46 = 1;
  v47 = a3;
  v4 = a3;
  v5 = a1;
  if ( (a1 & 8) != 0 )
  {
    v3 = 0;
    v46 = 0;
    v5 = a1 & 0xFFFFFFF7;
  }
  v6 = v5 + 8;
  v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( a2 > 0xFF4 || v7 == PsInitialSystemProcess )
    v6 -= 8;
  else
    a2 += 4;
  v8 = ExAllocatePoolWithTag(v6, a2, a3);
  v9 = v8;
  if ( (v8 & 0xFFF) == 0 )
  {
    if ( !v8 && v3 )
      RtlRaiseStatus(-1073741670);
    return v9;
  }
  if ( ExpSpecialAllocations )
    return sub_50A3F4();
  if ( (v6 & 8) != 0 )
  {
    v11 = v8 - 8;
    v12 = 0;
    v13 = *(_WORD *)(v9 - 6) & 0x1FF;
    *(_DWORD *)(v9 - 8 + 8 * v13 - 4) = ExpPoolQuotaCookie ^ (v9 - 8);
    v14 = *(_WORD *)(v9 - 6);
    v48 = 0;
    if ( (v14 & 0x800) != 0 )
    {
      v12 = v11 - 8 * (*(_WORD *)v11 & 0x1FF);
      v48 = v12;
      *(_DWORD *)(v12 + 8 * (*(_WORD *)(v12 + 2) & 0x1FF) - 4) = ExpPoolQuotaCookie ^ v12;
      v13 = *(_WORD *)(v12 + 2) & 0x1FF;
    }
    v15 = 8 * v13;
    v43 = v15;
    if ( v7 != PsInitialSystemProcess )
    {
      v16 = (v6 & 1) != 0;
      v17 = *(_DWORD *)(v7 + 332);
      __dmb(0xBu);
      v18 = PspResourceFlags[8 * v16];
      v19 = (unsigned int *)(v17 + (v16 << 8));
      v20 = *v19;
      v45 = v18;
      __dmb(0xBu);
      __dmb(0xFu);
      while ( 2 )
      {
        v21 = v19[32];
        v42 = v21;
        __dmb(0xBu);
        while ( 1 )
        {
          v22 = v20 + v15;
          if ( v20 + v15 < v20 )
          {
LABEL_59:
            v32 = *(_DWORD *)&PspResourceFlags[8 * v16 + 4];
            goto LABEL_27;
          }
          if ( v22 <= v21 )
            break;
          if ( (v18 & 1) == 0 || !v19[34] )
            goto LABEL_59;
          __dmb(0xBu);
          v37 = v19 + 33;
          do
            v38 = __ldrex(v37);
          while ( __strex(0, v37) );
          v44 = v38;
          __dmb(0xBu);
          v11 = v9 - 8;
          if ( v38 )
          {
            __dmb(0xBu);
            v39 = v44;
            v40 = v19 + 32;
            do
              v41 = __ldrex(v40);
            while ( __strex(v41 + v39, v40) );
            __dmb(0xBu);
            v21 = v39 + v41;
            v15 = v43;
            v42 = v21;
            v11 = v9 - 8;
          }
          else
          {
            if ( !PspExpandQuota(v16, v19, v20, v15, &v42) )
              goto LABEL_59;
            v21 = v42;
            v15 = v43;
            v18 = v45;
          }
        }
        __dmb(0xBu);
        do
          v23 = __ldrex(v19);
        while ( v23 == v20 && __strex(v22, v19) );
        __dmb(0xBu);
        if ( v23 != v20 )
        {
          v20 = v23;
          continue;
        }
        break;
      }
      v24 = v19 + 1;
      v25 = v19[1];
      __dmb(0xBu);
      if ( v22 > v25 )
      {
        do
        {
          v35 = v25;
          __dmb(0xBu);
          do
            v36 = __ldrex(v24);
          while ( v36 == v25 && __strex(v22, v24) );
          v25 = v36;
          __dmb(0xBu);
        }
        while ( v36 != v35 && v22 > v36 );
      }
      if ( (v45 & 4) != 0 )
      {
        __dmb(0xBu);
        v26 = (unsigned int *)(v7 + 4 * (v16 + 52));
        v27 = v43;
        do
          v28 = __ldrex(v26);
        while ( __strex(v28 + v27, v26) );
        __dmb(0xBu);
        v29 = v27 + v28;
        v30 = *(_DWORD *)(v7 + 4 * (v16 + 54));
        v31 = (unsigned int *)(v7 + 4 * (v16 + 54));
        __dmb(0xBu);
        if ( v29 > v30 )
        {
          do
          {
            v33 = v30;
            __dmb(0xBu);
            do
              v34 = __ldrex(v31);
            while ( v34 == v30 && __strex(v29, v31) );
            v30 = v34;
            __dmb(0xBu);
          }
          while ( v34 != v33 && v29 > v34 );
        }
      }
      v32 = 0;
LABEL_27:
      if ( v32 < 0 )
      {
        ExFreePoolWithTag(v9, v47);
        if ( v46 )
          RtlRaiseStatus(v32);
        return 0;
      }
      v4 = v47;
      v12 = v48;
    }
    *(_DWORD *)(v11 + 8 * (*(_WORD *)(v11 + 2) & 0x1FF) - 4) = ExpPoolQuotaCookie ^ v11 ^ v7;
    if ( v12 )
      *(_DWORD *)(v12 + 8 * (*(_WORD *)(v12 + 2) & 0x1FF) - 4) = ExpPoolQuotaCookie ^ v12 ^ v7;
    ObfReferenceObjectWithTag(v7, v4);
  }
  return v9;
}
