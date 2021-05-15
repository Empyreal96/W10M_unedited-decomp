// CmpAddAcpiAliasEntry 
 
int __fastcall CmpAddAcpiAliasEntry(int a1, int a2, int a3, unsigned __int16 *a4)
{
  unsigned int v6; // r6
  int v7; // r4
  int v8; // r0
  int v10; // [sp+0h] [bp-68h]
  int v11; // [sp+4h] [bp-64h]
  char *v12; // [sp+8h] [bp-60h]
  char v13; // [sp+1Ch] [bp-4Ch] BYREF
  int v14; // [sp+20h] [bp-48h]
  char v15[8]; // [sp+28h] [bp-40h] BYREF
  int v16; // [sp+30h] [bp-38h]
  int v17; // [sp+34h] [bp-34h]
  char *v18; // [sp+38h] [bp-30h]
  int v19; // [sp+3Ch] [bp-2Ch]
  int v20; // [sp+40h] [bp-28h]
  int v21; // [sp+44h] [bp-24h]

  v14 = a3;
  v6 = 0;
  RtlInitUnicodeString((unsigned int)v15, L"AcpiAlias");
  v16 = 24;
  v17 = a1;
  v20 = 0;
  v21 = 0;
  v18 = v15;
  v19 = 576;
  v7 = ZwOpenKey();
  if ( v7 == -1073741772 )
  {
    v11 = 0;
    v10 = 0;
    v12 = &v13;
    v7 = ZwCreateKey();
  }
  if ( v7 >= 0 )
  {
    while ( 1 )
    {
      swprintf_s((int)a4, 128, (int)L"%04d", ++v6, v10, v11, v12);
      RtlInitUnicodeString((unsigned int)v15, a4);
      v16 = 24;
      v17 = 0;
      v18 = v15;
      v19 = 576;
      v20 = 0;
      v21 = 0;
      v8 = ZwOpenKey();
      v7 = v8;
      if ( v8 < 0 )
        break;
      ZwClose();
      if ( v6 >= 0xC8 )
        goto LABEL_9;
    }
    if ( v8 == -1073741772 )
      v7 = 0;
LABEL_9:
    if ( v7 >= 0 )
    {
      v7 = ZwCreateKey();
      if ( v7 >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v15, L"DockingState");
        ZwSetValueKey();
        RtlInitUnicodeString((unsigned int)v15, L"AcpiSerialNumber");
        ZwSetValueKey();
        RtlInitUnicodeString((unsigned int)v15, L"ProfileNumber");
        v7 = ZwSetValueKey();
      }
    }
  }
  return v7;
}
