// PiDqActionDataGetAllPropertiesInBestLanguage 
 
int __fastcall PiDqActionDataGetAllPropertiesInBestLanguage(int a1, int a2, int a3, int a4, unsigned __int16 *a5, int *a6, int *a7, unsigned int *a8)
{
  unsigned int v9; // r5
  int v10; // r8
  int v11; // r4
  unsigned int v12; // r0
  int v13; // r1
  int *v14; // lr
  unsigned int v15; // r2
  unsigned int v16; // r6
  unsigned __int16 *v17; // r1
  _DWORD *v18; // r7
  int v20; // [sp+18h] [bp-30h] BYREF
  unsigned int v21; // [sp+1Ch] [bp-2Ch]
  _DWORD *v22; // [sp+20h] [bp-28h]
  int v23; // [sp+24h] [bp-24h]

  v9 = 0;
  v10 = a3;
  if ( a2 == 1 )
    v10 = 0;
  v20 = 0;
  v22 = 0;
  v23 = a2;
  v11 = PiDqOpenObjectRegKey(a2, a4, a3, 1, 0, a1, &v20);
  if ( v11 >= 0 )
  {
    v11 = PiDqPnPGetObjectPropertyKeys(a4, v10, v20);
    if ( v11 >= 0 )
    {
      v12 = v21;
      v13 = *a7;
      v14 = a6;
      v15 = *a7 + v21;
      if ( *a8 < v15 )
      {
        *a8 = v15;
        v11 = PiDqGrowPropertyArray(a6, v13, v15);
        if ( v11 < 0 )
          goto LABEL_13;
        v12 = v21;
        v14 = a6;
      }
      v16 = 0;
      if ( v12 )
      {
        v9 = (unsigned int)v22;
        v17 = a5;
        v18 = v22;
        do
        {
          v11 = PiDqPnPGetObjectPropertyInBestLocale(a4, v10, v20, v18, v23, v17, *v14 + 40 * *a7);
          if ( v11 < 0 )
            break;
          ++v16;
          v17 = a5;
          ++*a7;
          v14 = a6;
          v18 += 5;
        }
        while ( v16 < v21 );
        goto LABEL_14;
      }
    }
LABEL_13:
    v9 = (unsigned int)v22;
  }
LABEL_14:
  if ( v20 )
    ZwClose();
  if ( v9 )
    ExFreePoolWithTag(v9);
  return v11;
}
