// RtlStringCbCatExA 
 
int __fastcall RtlStringCbCatExA(int a1, int a2, int a3, _DWORD *a4, int *a5)
{
  int result; // r0
  int v8; // r2
  int v9; // r4
  _BYTE *v10; // r6
  int v11[6]; // [sp+8h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = (int)a4;
  result = sub_43E028(a1, 0x100u);
  if ( result < 0 )
  {
    v8 = 0;
  }
  else
  {
    result = sub_555F7C(a1);
    v8 = v11[0];
  }
  if ( result >= 0 )
  {
    v9 = 256 - v8;
    v10 = (_BYTE *)(v8 + a1);
    if ( v8 != 255 && v8 != 256 )
    {
      v11[0] = 0;
      result = sub_4E1E80(v10, v9, v11, (int)", ");
      v10 += v11[0];
      v9 -= v11[0];
      if ( result < 0 && result != -2147483643 )
        return result;
    }
    else
    {
      if ( !a1 )
        return -1073741811;
      result = -2147483643;
    }
    if ( a4 )
      *a4 = v10;
    if ( a5 )
      *a5 = v9;
  }
  return result;
}
