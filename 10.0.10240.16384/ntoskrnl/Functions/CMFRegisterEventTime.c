// CMFRegisterEventTime 
 
int __fastcall CMFRegisterEventTime(int a1)
{
  int v2; // r5
  _DWORD *v3; // r0
  char v5[8]; // [sp+18h] [bp-60h] BYREF
  char v6[8]; // [sp+28h] [bp-50h] BYREF
  int v7; // [sp+30h] [bp-48h]
  int v8; // [sp+34h] [bp-44h]
  char *v9; // [sp+38h] [bp-40h]
  int v10; // [sp+3Ch] [bp-3Ch]
  int v11; // [sp+40h] [bp-38h]
  int v12; // [sp+44h] [bp-34h]
  char v13[8]; // [sp+48h] [bp-30h] BYREF
  int v14; // [sp+50h] [bp-28h] BYREF
  int v15; // [sp+5Ch] [bp-1Ch]

  RtlInitUnicodeString((unsigned int)v13, L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\CMF\\SqmData");
  v7 = 24;
  v8 = 0;
  v10 = 576;
  v9 = v13;
  v11 = 0;
  v12 = 0;
  v2 = ZwCreateKey();
  if ( v2 >= 0 )
  {
    v3 = KeQuerySystemTime(&v14);
    if ( a1 != 1 )
      return sub_81B748(v3);
    RtlInitUnicodeString((unsigned int)v5, L"CMFStartTime");
    if ( ZwQueryValueKey() >= 0 && v15 == 11 )
    {
      RtlInitUnicodeString((unsigned int)v6, L"CMFLastStartTime");
      ZwSetValueKey();
    }
    RtlInitUnicodeString((unsigned int)v5, L"SystemStartTime");
    if ( ZwQueryValueKey() >= 0 && v15 == 11 )
    {
      RtlInitUnicodeString((unsigned int)v6, L"SystemLastStartTime");
      ZwSetValueKey();
    }
    v2 = ZwSetValueKey();
    ZwClose();
  }
  return v2;
}
