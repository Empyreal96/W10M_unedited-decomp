// SepReferenceTokenByHandle 
 
int __fastcall SepReferenceTokenByHandle(int a1, int a2, char a3, _DWORD *a4, _BYTE *a5, _DWORD *a6)
{
  int result; // r0
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = (int)a4;
  *a5 = 0;
  *a6 = 0;
  if ( a1 == -4 || a1 == -5 || a1 == -6 )
  {
    if ( (a2 & 0xFFFFFFE7) != 0 )
      result = sub_52C6A8();
    else
      result = SepReferenceTokenUsingPseudoHandle();
  }
  else
  {
    result = ObReferenceObjectByHandle(a1, a2, SeTokenObjectType, a3, v8, 0);
    *a4 = v8[0];
  }
  return result;
}
