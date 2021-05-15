// CmpTraceHiveRestoreStart 
 
int __fastcall CmpTraceHiveRestoreStart(int a1, int a2)
{
  int v3; // r5
  int v4; // r6
  int result; // r0
  int v6; // r1
  int *v7; // r2
  int *v8; // r2
  __int16 v9; // [sp+8h] [bp-68h] BYREF
  int v10; // [sp+10h] [bp-60h] BYREF
  int v11; // [sp+14h] [bp-5Ch]
  _DWORD v12[4]; // [sp+18h] [bp-58h] BYREF
  int var48[21]; // [sp+28h] [bp-48h] BYREF
  int varsC; // [sp+7Ch] [bp+Ch] BYREF

  var48[20] = a1;
  varsC = a2;
  v12[0] = 285212711;
  v12[1] = 393476;
  v12[2] = 0;
  v12[3] = 0x40000000;
  v3 = dword_92026C;
  v4 = EtwpRegTraceHandle;
  result = EtwEventEnabled(EtwpRegTraceHandle, dword_92026C, (int)v12);
  if ( result )
  {
    v6 = 0;
    if ( a1 )
    {
      v11 = 0;
      v10 = 0;
      result = CmpQueryNameString(a1, (unsigned __int16 *)&v10);
      if ( result < 0 )
        return result;
      v3 = dword_92026C;
      v4 = EtwpRegTraceHandle;
      var48[0] = v11;
      var48[1] = 0;
      var48[2] = (unsigned __int16)v10;
      var48[3] = 0;
      v6 = 1;
    }
    v9 = 0;
    v7 = &var48[4 * v6];
    *v7 = (int)&v9;
    v7[2] = 2;
    v7[1] = 0;
    v7[3] = 0;
    v8 = &var48[4 * v6 + 4];
    *v8 = (int)&varsC;
    v8[1] = 0;
    v8[2] = 4;
    v8[3] = 0;
    result = EtwWrite(v4, v3, (int)v12, 0);
    if ( a1 )
      result = RtlFreeAnsiString(&v10);
  }
  return result;
}
