// PopTraceThermalStandbyInitiated 
 
int __fastcall PopTraceThermalStandbyInitiated(int result)
{
  int v1; // r5
  int v2; // [sp+8h] [bp-48h] BYREF
  _DWORD v3[16]; // [sp+10h] [bp-40h] BYREF

  v1 = result;
  if ( (unsigned int)dword_6163C8 > 5 )
  {
    result = TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64);
    if ( result )
    {
      v3[8] = &v2;
      v3[9] = 0;
      v3[10] = 4;
      v3[11] = 0;
      v2 = v1;
      result = TlgWrite(&dword_6163C8, (unsigned __int8 *)dword_414494, 0, 0, 3, v3);
    }
  }
  return result;
}
