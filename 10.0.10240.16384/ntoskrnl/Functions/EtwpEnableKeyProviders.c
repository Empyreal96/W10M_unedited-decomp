// EtwpEnableKeyProviders 
 
int __fastcall EtwpEnableKeyProviders(int a1, unsigned __int16 *a2, int a3)
{
  unsigned int v5; // r4
  unsigned int v6; // r4
  int result; // r0
  unsigned __int16 *v8; // r7
  int v9; // r3
  int v10; // r5
  int v11; // r0
  int v12; // r1
  unsigned int v13; // r3
  int v14; // r4
  unsigned __int16 *v16; // [sp+14h] [bp-4Ch]
  char v17[8]; // [sp+20h] [bp-40h] BYREF
  int v18; // [sp+28h] [bp-38h]
  int v19; // [sp+2Ch] [bp-34h]
  char *v20; // [sp+30h] [bp-30h]
  int v21; // [sp+34h] [bp-2Ch]
  int v22; // [sp+38h] [bp-28h]
  int v23; // [sp+3Ch] [bp-24h]

  v5 = wcslen(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\");
  v6 = wcslen(a2) + v5 + 1;
  result = ExAllocatePoolWithTag(1, 2 * v6, 1350005829);
  v8 = (unsigned __int16 *)result;
  v16 = (unsigned __int16 *)result;
  if ( result )
  {
    RtlStringCbCopyW(result, 2 * v6);
    RtlStringCbCatW(v8, 2 * v6, (int)a2, v9);
    RtlInitUnicodeString((unsigned int)v17, v8);
    v18 = 24;
    v19 = 0;
    v21 = 576;
    v20 = v17;
    v22 = 0;
    v23 = 0;
    if ( ZwOpenKey() >= 0 )
    {
      v10 = 0;
      do
      {
        v11 = ZwEnumerateKey();
        v13 = *(_DWORD *)(a3 + 12);
        v14 = v11;
        if ( v13 >= 0x108 )
          return sub_810EF0();
        if ( v11 < 0 )
        {
          if ( v11 != -2147483622 )
          {
            RtlNtStatusToDosError(v11, v12);
            RtlWriteRegistryValue(2, (int)a2, L"EnableStatus");
          }
        }
        else
        {
          *(_WORD *)(a3 + 2 * (v13 >> 1) + 16) = 0;
          EtwpEnableAutoLoggerProviders(a1, a3 + 16, a2);
        }
        ++v10;
      }
      while ( v14 >= 0 );
      ZwClose();
      v8 = v16;
    }
    result = ExFreePoolWithTag((unsigned int)v8);
  }
  return result;
}
