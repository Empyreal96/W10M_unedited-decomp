// PipHardwareConfigClearStartOverrideCallback 
 
int __fastcall PipHardwareConfigClearStartOverrideCallback(int *a1, int a2, int a3, unsigned __int16 *a4)
{
  char v8[8]; // [sp+18h] [bp-228h] BYREF
  char v9[544]; // [sp+20h] [bp-220h] BYREF

  if ( RtlStringCchPrintfExW((int)v9, 260, 0, 0, 2048, L"%s\\%s") >= 0
    && PnpCtxRegOpenKey(a1, a2, (int)v9, 0) >= 0
    && RtlInitUnicodeStringEx((int)v8, a4) >= 0 )
  {
    ZwDeleteValueKey();
  }
  return 0;
}
