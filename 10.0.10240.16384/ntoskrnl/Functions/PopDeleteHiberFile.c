// PopDeleteHiberFile 
 
int __fastcall PopDeleteHiberFile(int a1)
{
  unsigned int v1; // r5
  int result; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  unsigned __int16 v6[2]; // [sp+Ch] [bp-78h] BYREF
  int v7; // [sp+10h] [bp-74h]
  int v8; // [sp+14h] [bp-70h]
  unsigned __int16 v9[4]; // [sp+1Ch] [bp-68h] BYREF
  int v10; // [sp+24h] [bp-60h]
  int v11; // [sp+28h] [bp-5Ch]
  unsigned __int16 *v12; // [sp+2Ch] [bp-58h]
  int v13; // [sp+30h] [bp-54h]
  int v14; // [sp+34h] [bp-50h]
  int v15; // [sp+38h] [bp-4Ch]

  v1 = 0;
  v7 = 0;
  v8 = 0;
  if ( !a1 )
  {
    RtlInitUnicodeString((unsigned int)v9, L"\\hiberfil.sys");
    v6[0] = 0;
    v6[1] = v9[0] + IoArcBootDeviceName;
    result = ExAllocatePoolWithTag(257, (unsigned __int16)(v9[0] + IoArcBootDeviceName), 1919052136);
    v7 = result;
    if ( !result )
      return result;
    RtlAppendUnicodeStringToString(v6, (unsigned __int16 *)&IoArcBootDeviceName);
    v3 = RtlAppendUnicodeStringToString(v6, v9);
    v4 = PopCreateHiberFileSecurityDescriptor(v3);
    v10 = 24;
    v11 = 0;
    v13 = 576;
    v12 = v6;
    v1 = v4;
    v14 = v4;
    v15 = 0;
  }
  v5 = ZwDeleteFile();
  if ( v5 < 0 && v5 != -1073741772 )
    return sub_7F1320();
  if ( v1 )
    ExFreePoolWithTag(v1);
  result = v7;
  if ( v7 )
    result = ExFreePoolWithTag(v7);
  return result;
}
