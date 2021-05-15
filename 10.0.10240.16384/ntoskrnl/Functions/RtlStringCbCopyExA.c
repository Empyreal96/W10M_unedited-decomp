// RtlStringCbCopyExA 
 
int __fastcall RtlStringCbCopyExA(_BYTE *a1, int a2, int a3, int a4, _DWORD *a5)
{
  int result; // r0
  int v7; // r1
  int v8; // [sp+8h] [bp-8h] BYREF

  v8 = a4;
  result = sub_43E028((int)a1, 0x100u);
  if ( result < 0 )
  {
    *a1 = 0;
  }
  else
  {
    v8 = 0;
    result = sub_4E1E80(a1, v7, &v8, byte_97D48D);
    if ( result >= 0 )
    {
      if ( a5 )
        *a5 = 256 - v8;
    }
    else
    {
      result = sub_54D6E0();
    }
  }
  return result;
}
