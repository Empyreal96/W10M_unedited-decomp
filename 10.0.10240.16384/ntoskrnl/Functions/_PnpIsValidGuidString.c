// _PnpIsValidGuidString 
 
BOOL __fastcall PnpIsValidGuidString(unsigned __int16 *a1)
{
  unsigned __int16 v2[4]; // [sp+0h] [bp-28h] BYREF
  char v3; // [sp+8h] [bp-20h] BYREF

  return RtlInitUnicodeStringEx((int)v2, a1) >= 0 && (v2[1] & 0xFFFE) == 78 && RtlGUIDFromString(v2, &v3) >= 0;
}
