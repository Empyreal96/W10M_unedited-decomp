// ExpWnfGetPermanentDataStoreHandleByScopeId 
 
int __fastcall ExpWnfGetPermanentDataStoreHandleByScopeId(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // [sp+10h] [bp-30h] BYREF
  char v6[8]; // [sp+18h] [bp-28h] BYREF
  int v7; // [sp+20h] [bp-20h]
  int v8; // [sp+24h] [bp-1Ch]
  char *v9; // [sp+28h] [bp-18h]
  int v10; // [sp+2Ch] [bp-14h]
  int v11; // [sp+30h] [bp-10h]
  int v12; // [sp+34h] [bp-Ch]

  if ( a1 || a4 )
    return sub_818828();
  result = ExpWnfGetNameStoreRegistryRoot(1, &v5);
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v6, L"Data");
    v7 = 24;
    v8 = v5;
    v10 = 576;
    v9 = v6;
    v11 = 0;
    v12 = 0;
    result = ZwCreateKey();
    if ( result >= 0 )
      result = 0;
  }
  return result;
}
