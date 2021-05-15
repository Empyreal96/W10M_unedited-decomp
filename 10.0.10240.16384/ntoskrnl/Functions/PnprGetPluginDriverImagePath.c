// PnprGetPluginDriverImagePath 
 
int __fastcall PnprGetPluginDriverImagePath(unsigned int a1)
{
  int v2; // r5
  int v3; // r4
  int v4; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r7
  char *v8; // r0
  char *v9; // r6
  int v11; // [sp+Ch] [bp-4Ch]
  int v12; // [sp+10h] [bp-48h] BYREF
  char v13[8]; // [sp+18h] [bp-40h] BYREF
  char v14[8]; // [sp+20h] [bp-38h] BYREF
  int v15; // [sp+28h] [bp-30h]
  int v16; // [sp+2Ch] [bp-2Ch]
  char *v17; // [sp+30h] [bp-28h]
  int v18; // [sp+34h] [bp-24h]
  int v19; // [sp+38h] [bp-20h]
  int v20; // [sp+3Ch] [bp-1Ch]

  v2 = 0;
  v3 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, &v12);
  if ( v3 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v14, L"Control\\Pnp");
    v15 = 24;
    v16 = v12;
    v18 = 576;
    v17 = v14;
    v19 = 0;
    v20 = 0;
    v3 = ZwOpenKey();
    if ( v3 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v13, L"ReplaceDriver");
      v4 = ZwQueryValueKey();
      v3 = v4;
      if ( v4 == -2147483643 || v4 == -1073741789 )
      {
        v2 = ExAllocatePoolWithTag(1, v11, 1366322768);
        if ( v2 )
        {
          v3 = ZwQueryValueKey();
          if ( v3 >= 0 )
          {
            v5 = *(_DWORD *)(v2 + 4);
            if ( (v5 == 1 || v5 == 2) && (v6 = *(_DWORD *)(v2 + 8), (v6 & 1) == 0) )
            {
              v7 = (unsigned int)(v6 + 26) >> 1;
              v8 = (char *)ExAllocatePoolWithTag(1, 2 * v7, 1366322768);
              v9 = v8;
              if ( a1 )
              {
                wcscpy_s(v8, v7, (char *)L"\\systemroot\\");
                wcsncat_s(v9, v7, (char *)(v2 + 12), *(_DWORD *)(v2 + 8) >> 1);
                RtlInitUnicodeString(a1, (unsigned __int16 *)v9);
              }
              else
              {
                v3 = -1073741670;
                if ( v8 )
                  ExFreePoolWithTag((unsigned int)v8);
              }
            }
            else
            {
              v3 = -1073741811;
            }
          }
        }
        else
        {
          v3 = -1073741670;
        }
      }
      else if ( v4 >= 0 )
      {
        v3 = -1073741823;
      }
    }
  }
  if ( v2 )
    ExFreePoolWithTag(v2);
  return v3;
}
