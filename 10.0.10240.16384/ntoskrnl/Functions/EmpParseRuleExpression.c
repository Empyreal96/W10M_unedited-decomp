// EmpParseRuleExpression 
 
int __fastcall EmpParseRuleExpression(int a1, int a2, _DWORD *a3)
{
  _BYTE *v4; // r7
  _DWORD *v6; // r0
  _DWORD *v7; // r5
  int v8; // r3
  int v9; // r3
  int v10; // r7
  unsigned int v11; // r2
  int v12; // r10
  unsigned int v13; // r0
  int v14; // r3
  unsigned int v15; // r1
  unsigned int *v16; // lr
  unsigned int v17; // t1
  unsigned int v18; // r1
  unsigned int *v19; // lr
  unsigned int v20; // t1
  unsigned int v21; // r9
  int *v22; // r0
  _DWORD *v23; // r0
  int v24; // r1
  int *v25; // r0
  _DWORD *v26; // r0
  int v27; // r8
  int v28; // r0
  int v29; // r2
  _DWORD *v30; // r2
  _DWORD *v31; // r1
  unsigned int *v32; // r9
  int v33; // lr
  unsigned int v34; // r1
  unsigned int v35; // t1
  int v36; // r1
  int v37; // r3
  unsigned int *v38; // [sp+8h] [bp-40h] BYREF
  unsigned int v39; // [sp+Ch] [bp-3Ch] BYREF
  _DWORD *v40; // [sp+10h] [bp-38h] BYREF
  int v41; // [sp+14h] [bp-34h]
  int v42; // [sp+18h] [bp-30h]
  int v43; // [sp+1Ch] [bp-2Ch]
  unsigned int v44; // [sp+20h] [bp-28h]
  int v45; // [sp+24h] [bp-24h]

  v42 = 0;
  v43 = a1;
  v4 = (_BYTE *)EmpInfParseGetValueFromSectionAndKeyName(a1, "Rule", a2);
  if ( v4 )
  {
    v6 = (_DWORD *)ExAllocatePoolWithTag(1, 8, 1953713477);
    v7 = v6;
    if ( v6 )
    {
      *v6 = 0;
      v6[1] = 0;
    }
    while ( 1 )
    {
      v8 = (char)*v4;
      if ( v8 != 37 && v8 != 63 )
        break;
      if ( EmpParseRuleTerm(v43, v4, &v40, (int *)&v38, &v39) < 0 )
        goto LABEL_30;
      v9 = (char)*v4;
      v10 = (int)v40;
      v41 = v9;
      if ( v9 == 63 )
      {
        v12 = v40[10];
        v11 = v40[9];
      }
      else
      {
        v12 = v40[9];
        v11 = v40[8];
      }
      v13 = v12 + v11;
      if ( v12 + v11 > v39 )
        goto LABEL_30;
      v14 = (int)v38;
      v15 = 0;
      if ( v11 )
      {
        v16 = v38;
        do
        {
          v17 = *v16++;
          if ( v17 >= a3[8] )
            goto LABEL_30;
          ++v15;
        }
        while ( v15 < v11 );
        v14 = (int)v38;
      }
      v18 = v11;
      if ( v11 < v13 )
      {
        v19 = (unsigned int *)(v14 + 4 * v11);
        while ( 1 )
        {
          v20 = *v19++;
          if ( v20 >= a3[9] )
            break;
          if ( ++v18 >= v13 )
            goto LABEL_20;
        }
LABEL_30:
        if ( v7 )
        {
          if ( v7[1] )
            JUMPOUT(0x96BBD8);
          ExFreePoolWithTag((unsigned int)v7);
        }
        JUMPOUT(0x96BBF8);
      }
LABEL_20:
      v21 = v39;
      if ( v13 < v39 )
      {
        v44 = a3[10];
        v32 = &v38[v13];
        v33 = 0;
        do
        {
          v35 = *v32++;
          v34 = v35;
          if ( v35 >= v44 )
            goto LABEL_30;
          v36 = *(_DWORD *)(a3[11] + 4 * v34);
          v37 = v41 == 63 ? v40[v33 + 12] : *(_DWORD *)(v40[11] + v33 * 4);
          if ( v36 != v37 )
            goto LABEL_30;
          ++v13;
          ++v33;
        }
        while ( v13 < v39 );
        v21 = v39;
      }
      if ( v41 == 63 )
      {
        v25 = (int *)ExAllocatePoolWithTag(1, 8, 1953058117);
        if ( !v25 )
          goto LABEL_30;
        *v25 = v10;
        v25[1] = a3[12];
        a3[12] = v25 + 1;
        if ( !EmpInfParseSearchDependencyList(v10 + 32, a3) )
        {
          v26 = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1953058117);
          if ( !v26 )
            goto LABEL_30;
          *v26 = a3;
          v26[1] = *(_DWORD *)(v10 + 32);
          *(_DWORD *)(v10 + 32) = v26 + 1;
        }
        v24 = 0;
      }
      else
      {
        v22 = (int *)ExAllocatePoolWithTag(1, 12, 1953058117);
        if ( !v22 )
          goto LABEL_30;
        *v22 = v10;
        v22[1] = a3[13];
        a3[13] = v22 + 1;
        if ( !EmpInfParseSearchDependencyList(v10 + 28, a3) )
        {
          v23 = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1953058117);
          if ( !v23 )
            goto LABEL_30;
          *v23 = a3;
          v23[1] = *(_DWORD *)(v10 + 28);
          *(_DWORD *)(v10 + 28) = v23 + 1;
        }
        v24 = 1;
      }
      EmpRuleParserStackPush(v7, v24, v10, v38, v21);
      v4 = (_BYTE *)CmpGetSectionLineIndex(v43, "Rule", v45, ++v42);
      if ( !v4 )
      {
        if ( *v7 == 1 )
        {
          ExAllocatePoolWithTag(1, 16, 1953058117);
          if ( v7[1] )
            JUMPOUT(0x96BB9C);
        }
        goto LABEL_30;
      }
    }
    if ( (v8 == 38 || v8 == 124) && *v7 >= 2u )
    {
      v27 = ExAllocatePoolWithTag(1, 28, 1953713477);
      if ( v27 )
      {
        *(_DWORD *)(v27 + 4) = ExAllocatePoolWithTag(1, 16, 1953713477);
        v28 = ExAllocatePoolWithTag(1, 16, 1953713477);
        v29 = *(_DWORD *)(v27 + 4);
        *(_DWORD *)(v27 + 16) = v28;
        if ( v29 )
        {
          if ( v28 )
          {
            *(_BYTE *)v27 = *v4;
            *(_DWORD *)(v29 + 8) = 0;
            *(_DWORD *)(*(_DWORD *)(v27 + 4) + 12) = 0;
            *(_DWORD *)(*(_DWORD *)(v27 + 16) + 8) = 0;
            *(_DWORD *)(*(_DWORD *)(v27 + 16) + 12) = 0;
            v30 = (_DWORD *)v7[1];
            v31 = *(_DWORD **)(v27 + 16);
            if ( v30 )
            {
              v7[1] = *v30;
              --*v7;
              v31[1] = *(v30 - 3);
              *(_DWORD *)(v27 + 24) = *(v30 - 2);
              *(_DWORD *)(v27 + 20) = *(v30 - 1);
              *v31 = *(v30 - 4);
              ExFreePoolWithTag((unsigned int)(v30 - 4));
              if ( v7[1] )
                JUMPOUT(0x96BB58);
            }
          }
        }
      }
    }
    goto LABEL_30;
  }
  return sub_96BB54();
}
