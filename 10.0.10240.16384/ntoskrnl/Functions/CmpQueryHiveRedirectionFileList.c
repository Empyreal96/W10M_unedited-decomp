// CmpQueryHiveRedirectionFileList 
 
int __fastcall CmpQueryHiveRedirectionFileList(int a1, unsigned __int16 *a2)
{
  int v3; // r2
  int v4; // r3
  unsigned int v6; // r1
  unsigned int v7; // [sp+14h] [bp-234h]
  char v8[8]; // [sp+30h] [bp-218h] BYREF
  char v9[516]; // [sp+44h] [bp-204h] BYREF

  if ( !CmpHiveRedirectionFileListHandle )
  {
    RtlInitUnicodeString(
      (unsigned int)v8,
      L"\\registry\\machine\\system\\currentcontrolset\\control\\hiveredirectionlist");
    if ( ZwCreateKey() < 0 )
      return 0;
    __dmb(0xBu);
    do
      v6 = __ldrex((unsigned int *)&CmpHiveRedirectionFileListHandle);
    while ( !v6 && __strex(v7, (unsigned int *)&CmpHiveRedirectionFileListHandle) );
    __dmb(0xBu);
    if ( v6 )
      return sub_7EA054();
  }
  return ZwQueryValueKey() >= 0 && !RtlAppendUnicodeToString(a2, (int)v9, v3, v4);
}
