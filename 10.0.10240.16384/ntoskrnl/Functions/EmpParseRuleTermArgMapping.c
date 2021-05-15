// EmpParseRuleTermArgMapping 
 
int __fastcall EmpParseRuleTermArgMapping(char *a1, unsigned int *a2, int a3, int a4, int a5)
{
  int v5; // lr
  int v6; // r2
  int v7; // r1
  int v8; // r6
  int v10; // r5
  char *v11; // r0
  int v12; // r4
  int v13; // r9
  unsigned int v14; // r8
  int v15; // r10
  unsigned int v17; // r0
  unsigned int *v18; // r3
  int v19; // r3
  bool v20; // zf
  int v21; // r3
  unsigned int v22; // r0
  int v23; // r3
  bool v24; // zf
  bool v25; // zf
  unsigned int v26; // r6
  unsigned int v27; // r0
  int v28; // r3
  bool v29; // zf
  int v30; // [sp+0h] [bp-38h]
  char *v31; // [sp+4h] [bp-34h] BYREF
  int v32; // [sp+8h] [bp-30h]
  unsigned int v33; // [sp+Ch] [bp-2Ch]
  unsigned int *v34; // [sp+10h] [bp-28h]
  unsigned int *v35; // [sp+14h] [bp-24h]
  int v36; // [sp+18h] [bp-20h]

  v5 = a3;
  v32 = a3;
  v6 = 0;
  v30 = 0;
  v34 = a2;
  v7 = a5;
  v8 = a4;
  v33 = v5 + a4 + a5;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v36 = a4;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v31 = 0;
  if ( !v34 )
    return sub_96BEAC();
  v35 = v34;
  while ( 2 )
  {
    if ( v10 )
      return 0;
    switch ( v12 )
    {
      case 0:
        v20 = *a1 == 40;
        goto LABEL_14;
      case 1:
        if ( *a1 == 41 )
        {
          v12 = 3;
          goto LABEL_10;
        }
        if ( v14 >= v33 )
          goto LABEL_61;
        v17 = strtoul(a1, &v31, 10);
        v18 = v35;
        v6 = v30;
        v5 = v32;
        *v35 = v17;
        v11 = v31;
        v7 = a5;
        if ( a1 != v31 )
        {
          v12 = 2;
          v35 = v18 + 1;
          ++v14;
          goto LABEL_10;
        }
        goto LABEL_63;
      case 2:
        v19 = *a1;
        if ( v19 == 41 )
        {
          v12 = 3;
          goto LABEL_17;
        }
        v20 = v19 == 46;
LABEL_14:
        if ( v20 )
        {
          v12 = 1;
          goto LABEL_17;
        }
        goto LABEL_59;
      case 3:
        if ( *a1 )
        {
          v24 = *a1 == 40;
          goto LABEL_28;
        }
        if ( v14 != v5 )
          goto LABEL_59;
        v29 = v8 == 0;
        goto LABEL_56;
      case 4:
        if ( *a1 == 41 )
        {
          v12 = 6;
          goto LABEL_10;
        }
        if ( v15 + v14 >= v33 )
          goto LABEL_61;
        v22 = strtoul(a1, &v31, 10);
        v6 = v30;
        v5 = v32;
        v34[v15 + v14] = v22;
        v11 = v31;
        v7 = a5;
        if ( a1 != v31 )
        {
          v12 = 5;
          ++v15;
          goto LABEL_10;
        }
        goto LABEL_63;
      case 5:
        v23 = *a1;
        if ( v23 == 41 )
        {
          v12 = 6;
          goto LABEL_17;
        }
        v24 = v23 == 46;
LABEL_28:
        if ( v24 )
        {
          v12 = 4;
          goto LABEL_17;
        }
        goto LABEL_59;
      case 6:
        if ( *a1 )
        {
          v25 = *a1 == 40;
          goto LABEL_36;
        }
        if ( v14 != v5 )
          goto LABEL_59;
        v29 = v15 == v8;
LABEL_56:
        if ( !v29 || v7 )
          goto LABEL_59;
        goto LABEL_43;
      case 7:
        if ( *a1 == 41 )
        {
          v12 = 9;
        }
        else
        {
          v26 = v15 + v6 + v14;
          if ( v26 >= v33 )
          {
LABEL_61:
            v10 = 1;
LABEL_43:
            v13 = 1;
            goto LABEL_17;
          }
          v27 = strtoul(a1, &v31, 10);
          v6 = v30;
          v5 = v32;
          v34[v26] = v27;
          v11 = v31;
          if ( a1 == v31 )
          {
            v7 = a5;
LABEL_63:
            v10 = 1;
          }
          else
          {
            v12 = 8;
            v6 = ++v30;
            v7 = a5;
          }
        }
LABEL_10:
        if ( v11 )
        {
          a1 = v11;
          v11 = 0;
          v31 = 0;
          goto LABEL_18;
        }
LABEL_17:
        ++a1;
LABEL_18:
        v8 = v36;
        if ( !v13 )
          continue;
        if ( v10 )
          return 0;
        v21 = 1;
        break;
      case 8:
        v28 = *a1;
        if ( v28 == 41 )
        {
          v12 = 9;
        }
        else
        {
          v25 = v28 == 46;
LABEL_36:
          if ( v25 )
            v12 = 7;
          else
LABEL_59:
            v10 = 1;
        }
        goto LABEL_17;
      case 9:
        if ( *a1 )
          goto LABEL_59;
        if ( v14 == v5 && v15 == v8 && v6 == v7 )
          goto LABEL_43;
        goto LABEL_63;
      default:
        goto LABEL_17;
    }
    return v21;
  }
}
