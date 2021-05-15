// SepRegOpenKey 
 
int __fastcall SepRegOpenKey(unsigned __int16 *a1, int a2, _DWORD *a3)
{
  _DWORD v5[10]; // [sp+0h] [bp-28h] BYREF

  RtlInitUnicodeString((unsigned int)v5, a1);
  v5[2] = 24;
  v5[3] = 0;
  v5[5] = 576;
  v5[4] = v5;
  v5[6] = 0;
  v5[7] = 0;
  *a3 = 0;
  return ZwOpenKey();
}
