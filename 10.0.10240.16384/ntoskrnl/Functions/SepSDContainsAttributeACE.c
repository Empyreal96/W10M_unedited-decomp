// SepSDContainsAttributeACE 
 
BOOL __fastcall SepSDContainsAttributeACE(int a1, int a2)
{
  BOOL v2; // r4
  int v4; // [sp+0h] [bp-10h] BYREF
  int v5; // [sp+4h] [bp-Ch] BYREF
  unsigned int v6; // [sp+8h] [bp-8h] BYREF

  v4 = a2;
  v5 = 0;
  v6 = 0;
  LOBYTE(v4) = 0;
  v2 = 0;
  if ( RtlGetSaclSecurityDescriptor(a1, &v4, &v5, (bool *)&v4 + 1) >= 0 && (_BYTE)v4 )
    v2 = RtlFindAceByType(v5, 18, &v6) != 0;
  return v2;
}
