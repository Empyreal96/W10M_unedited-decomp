// PiCMGetObjectProperty 
 
int __fastcall PiCMGetObjectProperty(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v8; // r5
  char v10[4]; // [sp+30h] [bp-58h] BYREF
  int v11; // [sp+34h] [bp-54h]
  int v12; // [sp+3Ch] [bp-4Ch]
  int v13; // [sp+5Ch] [bp-2Ch]
  int v14; // [sp+64h] [bp-24h]

  *a6 = 0;
  v8 = PiCMCapturePropertyInputData(a1, a2, a3, v10);
  if ( v8 >= 0 )
  {
    if ( v12 && !v11 && !v13 )
      return sub_7C6DBC();
    v8 = PiCMReturnBufferResultData(-1073741811, 0, 0, 0, 0, v14, a3, a4, a6);
  }
  PiCMReleasePropertyInputData(v10);
  return v8;
}
