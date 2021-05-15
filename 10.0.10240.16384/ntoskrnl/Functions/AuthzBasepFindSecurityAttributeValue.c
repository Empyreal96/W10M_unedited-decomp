// AuthzBasepFindSecurityAttributeValue 
 
int __fastcall AuthzBasepFindSecurityAttributeValue(int a1, int a2, __int64 *a3, int a4, unsigned __int16 a5)
{
  int v5; // r1
  int *v6; // r6
  int v8; // r5
  int *v10; // r7
  int *v11; // r9
  __int64 v12; // kr00_8
  bool v13; // zf
  __int16 *v14; // r1
  int v15; // r2
  __int64 v16; // kr08_8
  unsigned int v17; // r0
  __int16 v19; // [sp+8h] [bp-30h] BYREF
  __int16 v20; // [sp+Ah] [bp-2Eh]
  int v21; // [sp+Ch] [bp-2Ch]
  __int16 v22[2]; // [sp+10h] [bp-28h] BYREF
  int v23; // [sp+14h] [bp-24h]

  v5 = a4;
  v6 = 0;
  v8 = 0;
  if ( *(_DWORD *)(a1 + 44) != a1 + 44 )
    return sub_52ACA4();
  v10 = *(int **)(a1 + 56);
  v11 = (int *)(a1 + 56);
  while ( v10 != v11 )
  {
    v6 = v10 - 2;
    if ( (v10[2] & 1) != 0 || !a5 )
      goto LABEL_14;
    if ( a5 <= 2u )
      goto LABEL_11;
    if ( a5 == 3 )
    {
      v14 = (__int16 *)(v10 + 4);
      v19 = *(_WORD *)a3;
      v20 = v19;
      v21 = *((_DWORD *)a3 + 1);
    }
    else
    {
      if ( a5 != 4 )
      {
        switch ( a5 )
        {
          case 5u:
            goto LABEL_24;
          case 6u:
LABEL_11:
            v12 = *((_QWORD *)v10 + 2);
            if ( a3 != (__int64 *)v12 )
              goto LABEL_14;
            v13 = v5 == HIDWORD(v12);
            break;
          case 0x10u:
LABEL_24:
            v15 = *((_DWORD *)a3 + 1);
            if ( v15 != v10[5] )
              goto LABEL_14;
            v13 = memcmp(*(_DWORD *)a3, v10[4], v15) == 0;
            break;
          default:
            goto LABEL_14;
        }
        if ( v13 )
          goto LABEL_19;
        goto LABEL_14;
      }
      v16 = *a3;
      v17 = v10[5];
      v19 = *((_WORD *)a3 + 4);
      v20 = v19;
      v21 = *((_DWORD *)a3 + 3);
      v22[0] = *((_WORD *)v10 + 12);
      v22[1] = v22[0];
      v23 = v10[7];
      if ( v16 != __PAIR64__(v17, v10[4]) )
        goto LABEL_14;
      v14 = v22;
    }
    if ( AuthzBasepEqualUnicodeString((int)&v19, (int)v14) )
LABEL_19:
      v8 = 1;
LABEL_14:
    v10 = (int *)*v10;
    v5 = a4;
    if ( v8 )
      break;
  }
  if ( !v8 )
    v6 = 0;
  return (int)v6;
}
