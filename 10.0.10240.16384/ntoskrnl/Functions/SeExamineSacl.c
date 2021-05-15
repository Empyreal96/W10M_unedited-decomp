// SeExamineSacl 
 
unsigned __int16 *__fastcall SeExamineSacl(unsigned __int16 *result, int a2, int a3, int a4, unsigned __int8 a5, _BYTE *a6, _BYTE *a7)
{
  int v7; // r7
  unsigned __int16 *v8; // r5
  int v9; // r8
  int v10; // r10
  unsigned __int16 *v11; // r6
  unsigned int v12; // r2
  unsigned __int8 *v13; // r4
  int v14; // r5
  int v15; // r3
  unsigned __int16 *v16; // r8
  int v17; // r10
  int v18; // lr
  _DWORD *v19; // r3
  int v20; // r6
  int v21; // r0
  int v22; // r1
  int v23; // r3
  unsigned int v24; // [sp+20h] [bp-48h]
  int v25; // [sp+24h] [bp-44h]
  int v27; // [sp+2Ch] [bp-3Ch]
  int v28; // [sp+30h] [bp-38h] BYREF
  int v29; // [sp+34h] [bp-34h] BYREF
  int v30; // [sp+38h] [bp-30h]
  unsigned int v31; // [sp+3Ch] [bp-2Ch]
  int v32; // [sp+40h] [bp-28h]
  int v33; // [sp+44h] [bp-24h]

  v7 = 0;
  v8 = result;
  v27 = 0;
  v28 = 0;
  *a6 = 0;
  *a7 = 0;
  v29 = -1;
  v30 = a4;
  v32 = a2;
  if ( result )
  {
    v31 = result[2];
    if ( v31 )
    {
      v9 = a5;
      v10 = 0;
      v25 = 0;
      if ( (a4 & 0x2000000) != 0 )
      {
        if ( a5 )
          v10 = 64;
        else
          v10 = 128;
        v25 = v10;
      }
      result = **(unsigned __int16 ***)(a3 + 148);
      v11 = (unsigned __int16 *)SeWorldSid;
      if ( *result == *(unsigned __int16 *)SeAnonymousLogonSid )
      {
        result = (unsigned __int16 *)memcmp(
                                       (unsigned int)result,
                                       SeAnonymousLogonSid,
                                       4 * (*(unsigned __int8 *)(SeAnonymousLogonSid + 1) + 2));
        if ( !result )
          v27 = 4 * (*((unsigned __int8 *)v11 + 1) + 2);
      }
      v12 = 0;
      v24 = 0;
      v13 = (unsigned __int8 *)(v8 + 4);
      while ( 1 )
      {
        if ( *a6 )
        {
LABEL_51:
          if ( v7 )
          {
            AuthzBasepFreeSecurityAttributesList(v7);
            result = (unsigned __int16 *)ExFreePoolWithTag(v7);
          }
          return result;
        }
        v14 = v13[1];
        if ( (v14 & 8) == 0 )
        {
          v15 = *v13;
          if ( v15 == 2 )
          {
            result = (unsigned __int16 *)SepSidInToken(a3, 0, (int)(v13 + 8), 1, 0);
            if ( !result )
            {
              if ( !v27 )
                goto LABEL_49;
              if ( *v11 != *((unsigned __int16 *)v13 + 4) )
                goto LABEL_49;
              result = (unsigned __int16 *)memcmp((unsigned int)v11, (unsigned int)(v13 + 8), v27);
              if ( result )
                goto LABEL_49;
            }
            if ( (*((_DWORD *)v13 + 1) & v30) != 0 )
            {
              if ( ((v14 & 0x40) == 0 || !v9) && ((v14 & 0x80) == 0 || v9) )
                goto LABEL_49;
            }
            else if ( (v14 & v10) == 0 )
            {
              goto LABEL_49;
            }
            *a6 = 1;
LABEL_49:
            v12 = v24;
            goto LABEL_50;
          }
          if ( v15 == 13 )
          {
            v16 = (unsigned __int16 *)(v13 + 8);
            v17 = v13[9] + 2;
            v33 = *((_DWORD *)v13 + 1);
            if ( v32 && !v7 )
            {
              result = (unsigned __int16 *)AuthzBasepInitializeResourceClaimsFromSacl(v32, (int)&v28);
              v7 = v28;
              v12 = v24;
              v11 = (unsigned __int16 *)SeWorldSid;
            }
            v18 = *((unsigned __int16 *)v13 + 1);
            if ( v18 - 4 * v17 - 8 <= 0 )
            {
              v9 = a5;
              v10 = v25;
              goto LABEL_50;
            }
            v19 = *(_DWORD **)(a3 + 636);
            if ( v19 )
              v20 = v19[75];
            else
              v20 = 0;
            if ( v19 )
              v21 = v19[73];
            else
              v21 = 0;
            if ( v19 )
              v22 = v19[74];
            else
              v22 = 0;
            if ( v19 )
              v23 = v19[72];
            else
              v23 = 0;
            result = (unsigned __int16 *)AuthzBasepEvaluateAceCondition(
                                           a3,
                                           *(_DWORD *)(a3 + 476),
                                           v7,
                                           v23,
                                           v22,
                                           v21,
                                           v20,
                                           &v16[2 * v17],
                                           v18 - 4 * v17 - 8,
                                           1u,
                                           0,
                                           &v29);
            if ( v29 != 1 && v29 != -1 )
            {
              v11 = (unsigned __int16 *)SeWorldSid;
              goto LABEL_47;
            }
            result = (unsigned __int16 *)SepSidInToken(a3, 0, (int)(v13 + 8), 1, 0);
            v11 = (unsigned __int16 *)SeWorldSid;
            if ( result
              || v27
              && *(unsigned __int16 *)SeWorldSid == *v16
              && (result = (unsigned __int16 *)memcmp(SeWorldSid, (unsigned int)(v13 + 8), v27)) == 0 )
            {
              v9 = a5;
              if ( (v33 & v30) == 0 )
              {
                v12 = v24;
                v10 = v25;
                if ( (v14 & v25) != 0 )
                  *a6 = 1;
                goto LABEL_50;
              }
              if ( (v14 & 0x40) != 0 && a5 || (v14 & 0x80) != 0 && !a5 )
                *a6 = 1;
            }
            else
            {
LABEL_47:
              v9 = a5;
            }
            v10 = v25;
            goto LABEL_49;
          }
        }
LABEL_50:
        v24 = ++v12;
        v13 += *((unsigned __int16 *)v13 + 1);
        if ( v12 >= v31 )
          goto LABEL_51;
      }
    }
  }
  return result;
}
