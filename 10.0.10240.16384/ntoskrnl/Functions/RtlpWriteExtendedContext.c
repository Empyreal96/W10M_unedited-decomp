// RtlpWriteExtendedContext 
 
int __fastcall RtlpWriteExtendedContext(int a1, int a2, _DWORD *a3, int a4, int a5)
{
  int result; // r0
  char v9; // r5
  int v10; // [sp+8h] [bp-20h] BYREF
  int v11[7]; // [sp+Ch] [bp-1Ch] BYREF

  v11[0] = (int)a3;
  v11[1] = a4;
  v10 = 0;
  result = RtlpValidateContextFlags(a4, v11);
  if ( result >= 0 )
  {
    RtlpGetLegacyContextLength(a4, 0, &v10);
    v9 = v11[0];
    if ( (v11[0] & 1) != 0 )
      ProbeForWrite(a3[2] + a2, a3[3], v10);
    if ( (v9 & 2) != 0 )
      ProbeForWrite(a3[4] + a2, a3[5], 64);
    result = RtlpCopyExtendedContext(1, a2, (int)a3, a4, a5, 0);
  }
  return result;
}
