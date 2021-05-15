// SepSecureBootSetRegistryKey 
 
int __fastcall SepSecureBootSetRegistryKey(int a1)
{
  int v3; // r4
  unsigned int v4; // r2
  int v5; // [sp+18h] [bp-40h]
  __int16 v6; // [sp+20h] [bp-38h] BYREF
  int v7; // [sp+22h] [bp-36h]
  __int16 v8; // [sp+26h] [bp-32h]
  int v9; // [sp+28h] [bp-30h]
  int v10; // [sp+2Ch] [bp-2Ch]
  int *v11; // [sp+30h] [bp-28h]
  int v12; // [sp+34h] [bp-24h]
  int v13; // [sp+38h] [bp-20h]
  int v14; // [sp+3Ch] [bp-1Ch]

  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( (dword_641868 & 8) == 0 )
    return sub_96DA3C();
  v9 = 24;
  v10 = 0;
  v11 = &dword_405DB0;
  v12 = 576;
  v13 = 0;
  v14 = 0;
  v3 = ZwCreateKey();
  if ( v3 >= 0 )
  {
    v9 = 24;
    v12 = 576;
    v10 = 0;
    v11 = &dword_405DA8;
    v13 = 0;
    v14 = 0;
    v3 = ZwCreateKey();
    if ( v3 >= 0 )
    {
      if ( (dword_641868 & 8) == 0 )
      {
LABEL_11:
        if ( a1 )
        {
          v3 = RtlStringFromGUID(a1 + 4, (int)&v6);
          if ( v3 >= 0 )
          {
            v3 = ZwSetValueKey();
            if ( v3 >= 0 )
              v3 = ZwSetValueKey();
          }
        }
        goto LABEL_15;
      }
      v5 = dword_641868 & 1;
      v3 = ZwSetValueKey();
      if ( v3 >= 0 )
      {
        if ( v5 )
        {
          __dmb(0xBu);
          do
            v4 = __ldrex((unsigned __int8 *)0xFFFF92F0);
          while ( __strex(v4 | 0x80, (unsigned __int8 *)0xFFFF92F0) );
          __dmb(0xBu);
        }
        goto LABEL_11;
      }
    }
  }
LABEL_15:
  RtlFreeAnsiString(&v6);
  return v3;
}
