// CmpTraceHiveSaveStart 
 
unsigned __int16 *__fastcall CmpTraceHiveSaveStart(int a1)
{
  unsigned __int16 *result; // r0
  unsigned int v3; // r4
  int v4; // r2
  __int16 v5; // [sp+8h] [bp-50h] BYREF
  _DWORD v6[18]; // [sp+10h] [bp-48h] BYREF

  v6[0] = 285212713;
  v6[1] = 459012;
  v6[2] = 0;
  v6[3] = 0x40000000;
  result = (unsigned __int16 *)EtwEventEnabled(EtwpRegTraceHandle, dword_92026C, (int)v6);
  if ( result )
  {
    v5 = 0;
    result = (unsigned __int16 *)CmpConstructName(a1);
    v3 = (unsigned int)result;
    if ( result )
    {
      v4 = *result;
      v6[4] = *((_DWORD *)result + 1);
      v6[5] = 0;
      v6[6] = v4;
      v6[7] = 0;
      v6[8] = &v5;
      v6[9] = 0;
      v6[10] = 2;
      v6[11] = 0;
      EtwWrite(EtwpRegTraceHandle, dword_92026C, (int)v6, 0);
      result = (unsigned __int16 *)ExFreePoolWithTag(v3);
    }
  }
  return result;
}
