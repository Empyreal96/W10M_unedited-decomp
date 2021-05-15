// DrvDbBuildDeviceIdDriverInfMatch 
 
int __fastcall DrvDbBuildDeviceIdDriverInfMatch(int a1, unsigned __int8 *a2, _WORD *a3, int a4)
{
  int v5; // r0
  int result; // r0
  int v7; // [sp+10h] [bp-18h] BYREF
  int v8[5]; // [sp+14h] [bp-14h] BYREF

  v5 = *a2;
  v7 = 0;
  v8[0] = 0;
  if ( !v5 )
    return RtlStringCchCopyExW(a3, a4, &dword_8CE900);
  if ( v5 > 2 )
    return sub_7E4190();
  result = RtlStringCchPrintfExW((int)a3, a4, v8, &v7, 2048, L"%ws\\%X");
  if ( result >= 0 && a2[1] != 255 )
    JUMPOUT(0x7E41AC);
  return result;
}
