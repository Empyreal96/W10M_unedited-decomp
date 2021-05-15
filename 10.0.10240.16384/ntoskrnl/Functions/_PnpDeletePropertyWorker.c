// _PnpDeletePropertyWorker 
 
int __fastcall PnpDeletePropertyWorker(int *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v10; // r0
  int v11; // r4
  int v12; // r5
  int v13; // [sp+4h] [bp-BCh]
  int v14; // [sp+38h] [bp-88h] BYREF
  char v15[8]; // [sp+40h] [bp-80h] BYREF
  unsigned __int16 v16[60]; // [sp+48h] [bp-78h] BYREF

  v14 = 0;
  if ( a5 || a7 )
    return -1073741811;
  if ( a3 )
    return sub_7EFFF4();
  if ( RtlStringCchPrintfExW((int)v16, 48, 0, 0, 2048, L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}\\%04lX") < 0 )
    return -1073741595;
  v10 = PnpOpenPropertiesKey(a1, a2, v16, 6, 0, v13, &v14);
  v11 = v10;
  if ( v10 == -1073741772 )
    goto LABEL_15;
  if ( v10 >= 0 )
  {
    v12 = RtlInitUnicodeStringEx((int)v15, 0);
    if ( v12 >= 0 )
      v12 = ZwDeleteValueKey();
    ZwClose();
    if ( v12 != -1073741772 && v12 != -1073741444 )
    {
      if ( v12 < 0 )
        v11 = v12;
      return v11;
    }
LABEL_15:
    v11 = -1073741275;
  }
  return v11;
}
