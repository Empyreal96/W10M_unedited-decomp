// RtlGetExtendedContextLength 
 
int __fastcall RtlGetExtendedContextLength(int a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  int v7; // r0
  int v8; // r2
  int v9; // [sp+0h] [bp-18h] BYREF
  int v10; // [sp+4h] [bp-14h] BYREF
  int v11[4]; // [sp+8h] [bp-10h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v9 = 0;
  v10 = 0;
  result = RtlpValidateContextFlags(a1, v11);
  if ( result >= 0 )
  {
    v7 = RtlpGetLegacyContextLength(a1, &v9, &v10);
    v8 = v9 + 24;
    if ( (v11[0] & 2) != 0 )
    {
      result = sub_547994(v7, v10, v8);
    }
    else
    {
      *a2 = v8 + v10 - 1;
      result = 0;
    }
  }
  return result;
}
