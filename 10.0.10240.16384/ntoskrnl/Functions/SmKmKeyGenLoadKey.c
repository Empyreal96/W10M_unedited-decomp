// SmKmKeyGenLoadKey 
 
int __fastcall SmKmKeyGenLoadKey(int a1, _DWORD *a2, _DWORD *a3)
{
  int v5; // r1
  int v6; // r4
  unsigned __int16 *v7; // r4
  unsigned int v8; // r2
  int v10[12]; // [sp+18h] [bp-148h] BYREF
  char v11[280]; // [sp+48h] [bp-118h] BYREF

  v10[2] = 24;
  v10[3] = 0;
  v10[4] = a1;
  v10[5] = 576;
  v10[6] = 0;
  v10[7] = 0;
  v6 = ZwOpenKey();
  if ( v6 >= 0 )
  {
    v7 = (unsigned __int16 *)a2[2];
    if ( v7 )
      sub_5B3C84(v7, v5, v10);
    v6 = ZwQueryValueKey();
    if ( v6 >= 0 )
    {
      if ( a3 )
      {
        if ( v10[10] == 3 && (v8 = a2[4], v10[11] == v8) )
        {
          memmove(a2[3], (int)v11, v8);
          v6 = 0;
          *a3 = 0;
        }
        else
        {
          v6 = -1073741772;
        }
      }
      else
      {
        v6 = 0;
      }
    }
  }
  return v6;
}
