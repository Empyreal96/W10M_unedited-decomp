// AdtpAppendZString 
 
int __fastcall AdtpAppendZString(int a1, _BYTE *a2, unsigned __int16 *a3, _DWORD *a4)
{
  int v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[1] = (int)a3;
  v8[2] = (int)a4;
  RtlInitUnicodeString((unsigned int)v8, a3);
  return AdtpAppendString(a1, a2, v8, a4);
}
