// PnpOpenFirstMatchingSubKey 
 
int __fastcall PnpOpenFirstMatchingSubKey(unsigned __int16 *a1, int a2, int a3, int a4, _DWORD *a5)
{
  unsigned __int16 *v5; // r4
  int v7; // r6
  _DWORD v9[14]; // [sp+0h] [bp-38h] BYREF

  v5 = a1;
  if ( !a1 || !a2 || !a5 )
    return -1073741811;
  v7 = -1073741772;
  *a5 = 0;
  while ( *v5 )
  {
    RtlInitUnicodeString((unsigned int)v9, v5);
    v9[2] = 24;
    v9[3] = a2;
    v9[5] = 576;
    v9[4] = v9;
    v9[6] = 0;
    v9[7] = 0;
    *a5 = 0;
    v7 = ZwOpenKey();
    if ( v7 >= 0 )
      break;
    *a5 = 0;
    v5 += wcslen(v5) + 1;
  }
  return v7;
}
