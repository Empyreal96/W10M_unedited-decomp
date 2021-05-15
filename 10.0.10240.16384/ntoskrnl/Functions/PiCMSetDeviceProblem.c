// PiCMSetDeviceProblem 
 
int __fastcall PiCMSetDeviceProblem(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int result; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r1
  int v13; // r2
  int v14; // r0
  int v15; // r2
  int v16; // r0
  int v17; // r4
  char v18[4]; // [sp+8h] [bp-1B8h] BYREF
  int v19; // [sp+Ch] [bp-1B4h]
  unsigned __int16 v20[200]; // [sp+10h] [bp-1B0h] BYREF
  int v21; // [sp+1A0h] [bp-20h]
  int v22; // [sp+1A4h] [bp-1Ch]

  *a6 = 0;
  result = PiCMCaptureProblemInputData(a1, a2, (int)a3, (int)v18);
  if ( result >= 0 )
  {
    if ( PiAuDoesClientHaveAccess(4, v9, v10, v11) && (v14 = PiAuDoesClientHavePrivilege(10, v12, v13)) != 0 )
    {
      if ( v20[0] && a3 && a4 >= 8 && (v17 = v19, (unsigned int)(v19 - 1) <= 1) )
      {
        v16 = CmValidateDeviceName(v14, v20, v15, v19 - 1);
        if ( v16 >= 0 )
          v16 = PiCMSetProblem(v20, v21, v17);
      }
      else
      {
        v16 = -1073741811;
      }
    }
    else
    {
      v16 = -1073741790;
    }
    result = PiCMReturnBasicResultData(v16, v22, a3, a4, a6);
  }
  return result;
}
