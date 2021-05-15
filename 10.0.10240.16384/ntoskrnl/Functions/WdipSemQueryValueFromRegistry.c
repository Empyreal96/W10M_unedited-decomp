// WdipSemQueryValueFromRegistry 
 
int __fastcall WdipSemQueryValueFromRegistry(int a1, unsigned __int16 *a2, int a3, unsigned int a4, _BYTE *a5, unsigned int *a6)
{
  int v8; // r4
  int v9; // r0
  unsigned int v10; // r5
  char v12[8]; // [sp+10h] [bp-B8h] BYREF
  int v13; // [sp+1Ch] [bp-ACh]
  unsigned int v14; // [sp+20h] [bp-A8h]
  char v15[164]; // [sp+24h] [bp-A4h] BYREF

  if ( !a1 || !a2 || !a5 || !a6 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)v12, a2);
  v9 = ZwQueryValueKey();
  v8 = v9;
  if ( v9 != -1073741772 && v9 >= 0 )
  {
    v10 = v14;
    if ( v14 <= a4 && v13 == a3 )
    {
      memset(a5, 0, a4);
      memmove((int)a5, (int)v15, v10);
      *a6 = v10;
    }
    else
    {
      v8 = -1073741823;
    }
  }
  return v8;
}
