// RtlGenerateQpcToIncrementConstants 
 
int __fastcall RtlGenerateQpcToIncrementConstants(int a1, _BYTE *a2, int a3, int a4)
{
  __int64 v5; // r0
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  v5 = RtlpComputeFraction(dword_989680, a1, v7);
  if ( SLOBYTE(v7[0]) >= 0 )
    *a2 = v7[0];
  else
    LODWORD(v5) = sub_50B604(v5, HIDWORD(v5));
  return v5;
}
