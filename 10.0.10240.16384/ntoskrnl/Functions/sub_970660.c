// sub_970660 
 
void __fastcall sub_970660(int a1, int a2, int a3, unsigned int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, char a17, int a18, int a19, int a20, char a21, int a22, unsigned __int16 a23)
{
  int v23; // r5
  int v24; // r6
  int v25; // r1
  int v26; // r0

  if ( a4 >= 0x80 )
    goto LABEL_20;
  *(_WORD *)(v23 + 4) = a4;
  v25 = *(unsigned __int16 *)(v24 + 2282);
  *(_WORD *)(v23 + 6) = v25;
  v26 = ExAllocatePoolWithTag(1, v25, 1348953677);
  *(_DWORD *)(v23 + 8) = v26;
  if ( v26 )
  {
    if ( RtlStringCbCopyW(v26, *(unsigned __int16 *)(v23 + 6)) >= 0
      && RtlStringCbPrintfW(&a23, 0x200u, (int)L"%s%s", (int)L"\\registry\\machine\\") >= 0
      && RtlInitUnicodeStringEx((int)&a17, &a23) >= 0
      && ZwOpenKey() >= 0
      && ZwOpenKey() >= 0 )
    {
      ZwClose();
      *(_DWORD *)v23 |= 1u;
      RtlInitUnicodeStringEx((int)&a21, L"LastProfile");
      if ( ZwSetValueKey() >= 0 && RtlInitUnicodeStringEx((int)&a17, L"Current") >= 0 )
      {
        if ( ZwOpenKeyEx() < 0 )
        {
LABEL_13:
          if ( ZwCreateKey() >= 0
            && RtlStringCbPrintfW(&a23, 0x200u, (int)L"%s%s%wZ", (int)L"\\registry\\machine\\") >= 0 )
          {
            wcslen(&a23);
            ZwSetValueKey();
          }
          goto LABEL_16;
        }
        if ( ZwDeleteKey() >= 0 )
        {
          ZwClose();
          a9 = 0;
          goto LABEL_13;
        }
      }
    }
  }
LABEL_16:
  if ( a9 )
    ZwClose();
  if ( a10 )
    ZwClose();
LABEL_20:
  JUMPOUT(0x9646F8);
}
