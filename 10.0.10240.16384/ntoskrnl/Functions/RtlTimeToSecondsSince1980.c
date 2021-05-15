// RtlTimeToSecondsSince1980 
 
int __fastcall RtlTimeToSecondsSince1980(int *a1, _DWORD *a2)
{
  __int64 v4; // [sp+10h] [bp-10h] BYREF

  RtlExtendedMagicDivide(&v4, (int)a2, *a1, a1[1], -444972355, -692087595, 23);
  if ( (unsigned __int64)(v4 - 0x2C8DF3700i64) >> 32 )
    return 0;
  *a2 = v4 + 924895488;
  return 1;
}
