// RtlNormalizeString 
 
int __fastcall RtlNormalizeString(int a1, int a2, int a3, int a4, int *a5)
{
  int result; // r0
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = a4;
  if ( !a2 || a3 < -1 || !a1 || *a5 < 0 )
    return -1073741811;
  result = RtlpGetNormalization(a1, v9);
  if ( result >= 0 )
    result = RtlpNormalizeStringWorker(v9[0], a2, a3, a4);
  return result;
}
