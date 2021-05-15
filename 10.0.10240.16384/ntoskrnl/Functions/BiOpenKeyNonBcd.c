// BiOpenKeyNonBcd 
 
int __fastcall BiOpenKeyNonBcd(int a1, unsigned __int16 *a2, int a3, _DWORD *a4)
{
  int v6; // r4
  _DWORD _8[22]; // [sp+8h] [bp-40h] BYREF

  _8[21] = a4;
  _8[20] = a3;
  _8[19] = a2;
  _8[18] = a1;
  RtlInitUnicodeString((unsigned int)_8, a2);
  _8[2] = 24;
  _8[3] = a1;
  _8[5] = 576;
  _8[4] = _8;
  _8[6] = 0;
  _8[7] = 0;
  v6 = ZwOpenKey();
  if ( v6 >= 0 )
    *a4 = 0;
  if ( v6 == -1073741443 )
    __debugbreak();
  return v6;
}
