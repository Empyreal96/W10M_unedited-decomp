// PiDqActionDataGetAllPropertiesInAllLanguages 
 
int __fastcall PiDqActionDataGetAllPropertiesInAllLanguages(int a1, int a2, int a3, int a4, int *a5, int *a6, unsigned int *a7)
{
  _DWORD *v8; // r6
  unsigned int v9; // r5
  int v10; // r10
  int v11; // r4
  _DWORD *v12; // r9
  int v13; // r2
  int v14; // r1
  int v15; // r3
  unsigned __int16 *v16; // r9
  int v17; // r1
  unsigned int v18; // r3
  int v19; // r1
  unsigned int v20; // r3
  _DWORD *v21; // r9
  int v22; // r2
  int v24; // [sp+18h] [bp-38h] BYREF
  unsigned __int16 *v25; // [sp+1Ch] [bp-34h] BYREF
  int v26; // [sp+20h] [bp-30h]
  _DWORD *v27; // [sp+24h] [bp-2Ch]
  unsigned int v28; // [sp+28h] [bp-28h]
  int v29; // [sp+2Ch] [bp-24h]
  int v30; // [sp+30h] [bp-20h]

  v8 = 0;
  v9 = 0;
  v10 = a3;
  if ( a2 == 1 )
    v10 = 0;
  v24 = 0;
  v25 = 0;
  v29 = a2;
  v26 = a4;
  v27 = 0;
  v11 = PiDqOpenObjectRegKey(a2, a4, a3, 1, 0, a1, &v24);
  if ( v11 >= 0 )
  {
    v11 = PiDqPnPGetObjectPropertyKeys(a4, v10, v24);
    if ( v11 >= 0 && (v30 = 0, v28) )
    {
      v8 = v27;
      v12 = v27;
      while ( 1 )
      {
        v11 = PiDqPnPGetObjectPropertyLocales(v26, v10, v24, v12, &v25);
        if ( v11 < 0 )
          break;
        if ( !*a7 )
        {
          v13 = v28;
          v14 = *a6;
          *a7 = v28;
          v11 = PiDqGrowPropertyArray(a5, v14, v13);
          if ( v11 < 0 )
            break;
        }
        v9 = (unsigned int)v25;
        v15 = *v25;
        v16 = v25;
        while ( v15 )
        {
          v17 = *a6;
          v18 = *a7;
          if ( *a6 == *a7 )
          {
            *a7 = 2 * v18;
            v11 = PiDqGrowPropertyArray(a5, v17, 2 * v18);
            if ( v11 < 0 )
              goto LABEL_23;
          }
          v11 = PiDqPnPGetObjectProperty(v26, v10, v24, v27, v29, (int)v16, (_DWORD *)(*a5 + 40 * *a6));
          if ( v11 < 0 )
            goto LABEL_23;
          ++*a6;
          v16 += wcslen(v16) + 1;
          v15 = *v16;
        }
        ExFreePoolWithTag(v9);
        v19 = *a6;
        v20 = *a7;
        v9 = 0;
        v25 = 0;
        if ( v19 != v20 || (*a7 = 2 * v20, v11 = PiDqGrowPropertyArray(a5, v19, 2 * v20), v11 >= 0) )
        {
          v21 = v27;
          v11 = PiDqPnPGetObjectProperty(v26, v10, v24, v27, v29, 0, (_DWORD *)(*a5 + 40 * *a6));
          if ( v11 >= 0 )
          {
            v22 = v30;
            v12 = v21 + 5;
            ++*a6;
            v30 = v22 + 1;
            v27 = v12;
            if ( v22 + 1 < v28 )
              continue;
          }
        }
        goto LABEL_23;
      }
      v9 = (unsigned int)v25;
    }
    else
    {
      v8 = v27;
    }
  }
LABEL_23:
  if ( v24 )
    ZwClose();
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  if ( v9 )
    ExFreePoolWithTag(v9);
  return v11;
}
