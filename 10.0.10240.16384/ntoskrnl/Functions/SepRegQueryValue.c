// SepRegQueryValue 
 
int __fastcall SepRegQueryValue(int a1, unsigned __int16 *a2, int a3, unsigned int a4, _DWORD *a5)
{
  int v7; // r4
  char v9[8]; // [sp+8h] [bp-78h] BYREF
  int v10; // [sp+1Ch] [bp-64h]
  int v11; // [sp+20h] [bp-60h]
  int v12[23]; // [sp+24h] [bp-5Ch] BYREF

  RtlInitUnicodeString((unsigned int)v9, a2);
  v7 = ZwQueryValueKey();
  if ( v7 >= 0 )
  {
    if ( v10 == a3 && v11 == a4 )
    {
      if ( a3 == 3 )
      {
        memmove((int)a5, (int)v12, a4);
      }
      else if ( a3 == 4 && a4 >= 4 )
      {
        *a5 = v12[0];
      }
      else
      {
        v7 = -1073741811;
      }
    }
    else
    {
      v7 = -1073741788;
    }
  }
  return v7;
}
