// WdipSemOpenRegistryKey 
 
int __fastcall WdipSemOpenRegistryKey(unsigned __int16 *a1, int a2, int a3)
{
  _DWORD v5[10]; // [sp+0h] [bp-28h] BYREF

  if ( !a1 || !a3 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)v5, a1);
  v5[2] = 24;
  v5[3] = a2;
  v5[5] = 576;
  v5[4] = v5;
  v5[6] = 0;
  v5[7] = 0;
  return ZwOpenKey();
}
