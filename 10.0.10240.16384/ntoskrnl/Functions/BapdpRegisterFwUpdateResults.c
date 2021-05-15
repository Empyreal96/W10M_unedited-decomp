// BapdpRegisterFwUpdateResults 
 
__int64 *__fastcall BapdpRegisterFwUpdateResults(__int64 *result, unsigned int a2)
{
  __int64 *v2; // r5
  __int64 v3; // kr10_8
  unsigned __int64 v4; // r2
  int v5; // r7
  unsigned int v6; // r8
  int v7; // r4
  char v8[8]; // [sp+20h] [bp-48h] BYREF
  _DWORD v9[2]; // [sp+28h] [bp-40h] BYREF
  int v10; // [sp+30h] [bp-38h]
  int v11; // [sp+34h] [bp-34h]
  char *v12; // [sp+38h] [bp-30h]
  int v13; // [sp+3Ch] [bp-2Ch]
  int v14; // [sp+40h] [bp-28h]
  int v15; // [sp+44h] [bp-24h]

  v2 = result;
  if ( result )
  {
    if ( a2 )
    {
      v3 = *result;
      result = (__int64 *)*((_DWORD *)result + 1);
      if ( *v2 )
      {
        v4 = 24 * __PAIR64__((unsigned int)result + ((_DWORD)v3 != 0) - 1, (int)v3 - 1) + 32;
        result = 0;
        if ( a2 >= v4 )
        {
          RtlInitUnicodeString(
            (unsigned int)v8,
            L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\FirmwareResources");
          v10 = 24;
          v11 = 0;
          v12 = v8;
          v14 = 0;
          v15 = 0;
          v13 = 576;
          if ( ZwOpenKey() >= 0 )
          {
            v5 = (int)(v2 + 1);
            v6 = 0;
            if ( *((_DWORD *)v2 + 1) || *(_DWORD *)v2 )
            {
              do
              {
                if ( RtlStringFromGUID(v5, (int)v9) < 0 )
                  break;
                RtlInitUnicodeString((unsigned int)v8, (unsigned __int16 *)v9[1]);
                v10 = 24;
                v11 = 0;
                v12 = v8;
                v13 = 576;
                v14 = 0;
                v15 = 0;
                v7 = ZwCreateKey();
                RtlFreeAnsiString(v9);
                if ( v7 < 0 )
                  break;
                RtlInitUnicodeString((unsigned int)v8, L"LastAttemptVersion");
                ZwSetValueKey();
                RtlInitUnicodeString((unsigned int)v8, L"LastAttemptStatus");
                ZwSetValueKey();
                ZwClose();
                v5 += 24;
                ++v6;
              }
              while ( v6 < (unsigned __int64)*v2 );
            }
          }
          result = 0;
        }
      }
    }
  }
  return result;
}
