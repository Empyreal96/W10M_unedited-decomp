// KsepDbQueryRegistryDeviceDataList 
 
int __fastcall KsepDbQueryRegistryDeviceDataList(unsigned __int16 *a1, int a2, unsigned int a3, _DWORD *a4)
{
  int v5; // r4
  int v6; // r0
  int v7; // r6
  int v8; // r7
  unsigned int v9; // r5
  int v10; // r8
  int v11; // r9
  int v12; // r0
  unsigned int v13; // r4
  int v15; // [sp+8h] [bp-38h] BYREF
  unsigned int v16; // [sp+Ch] [bp-34h]
  unsigned int v17; // [sp+10h] [bp-30h] BYREF
  _DWORD *v18; // [sp+14h] [bp-2Ch]
  int v19; // [sp+18h] [bp-28h] BYREF
  int v20; // [sp+1Ch] [bp-24h]

  v18 = a4;
  v19 = 0;
  v20 = 0;
  v15 = 0;
  v16 = a3;
  v5 = KsepStringTransform((unsigned __int16 *)&v19, a1);
  if ( v5 >= 0 )
  {
    v6 = KsepRegistryOpenKey(
           L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Device",
           v20,
           &v15);
    v7 = v15;
    if ( v6 >= 0 )
    {
      v5 = KsepRegistryQueryKeyInformation(v15, &v15, &v17);
      if ( v5 >= 0 )
      {
        v8 = KsepPoolAllocatePaged(v15);
        if ( v8 )
        {
          if ( KsepPoolAllocatePaged(v17) )
          {
            v9 = 0;
            v10 = 0;
            v11 = a2;
            while ( 1 )
            {
              v12 = KsepRegistryEnumValue(v7, v10, v15, v8, &v17);
              v5 = v12;
              if ( v12 == -2147483622 )
                break;
              if ( v12 < 0 )
                goto LABEL_18;
              v13 = v17;
              v9 += v17;
              if ( v9 <= v16 )
              {
                memmove(v11, v8, v17);
                v11 += v13;
              }
              ++v10;
            }
            *v18 = v9 + 2;
            if ( v9 + 2 <= v16 )
            {
              *(_WORD *)(a2 + 2 * (v9 >> 1)) = 0;
              v5 = 0;
            }
            else
            {
              v5 = -1073741789;
            }
          }
          else
          {
            v5 = -1073741801;
          }
LABEL_18:
          KsepPoolFreePaged(v8);
        }
        else
        {
          v5 = -1073741801;
        }
      }
    }
    else
    {
      v5 = -1073741275;
    }
    if ( v7 )
      KsepRegistryCloseKey(v7);
  }
  KsepStringFree(&v19);
  return v5;
}
