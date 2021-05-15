// KsepLogEtwMessage 
 
int __fastcall KsepLogEtwMessage(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int *v6; // r2
  char var110[276]; // [sp+28h] [bp-110h] BYREF
  int varg_r0; // [sp+140h] [bp+8h]
  int varg_r1; // [sp+144h] [bp+Ch]
  int varg_r2; // [sp+148h] [bp+10h]
  int varg_r3; // [sp+14Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  result = HIDWORD(KseEtwHandle) | KseEtwHandle;
  if ( KseEtwHandle )
  {
    result = RtlStringCbVPrintfA(var110, 0x100u);
    if ( result >= 0 )
    {
      strlen((unsigned int)var110);
      if ( a2 )
        v6 = KShimInfoMessage;
      else
        v6 = KShimErrorMessage;
      result = EtwWrite(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)v6, 0);
    }
  }
  return result;
}
