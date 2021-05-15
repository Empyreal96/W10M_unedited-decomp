// RtlIsNormalizedString 
 
int __fastcall RtlIsNormalizedString(int a1, unsigned __int16 *a2, int a3, char *a4)
{
  int v6; // r4
  int result; // r0
  char *v8; // [sp+0h] [bp-10h] BYREF

  v8 = a4;
  v6 = a3;
  if ( !a2 || !a4 || a3 < -1 || !a1 )
    return -1073741811;
  result = RtlpGetNormalization(a1, &v8);
  if ( result >= 0 )
  {
    if ( v6 == -1 )
      v6 = wcslen(a2) + 1;
    result = Normalization__IsNormalized((int)v8, a2, v6, a4);
  }
  return result;
}
