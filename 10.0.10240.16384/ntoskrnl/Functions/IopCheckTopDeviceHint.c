// IopCheckTopDeviceHint 
 
int __fastcall IopCheckTopDeviceHint(int *a1, _DWORD *a2, int a3, unsigned __int16 *a4)
{
  int v5; // r6
  int result; // r0
  int v9; // r0
  int v10; // r4
  unsigned __int16 *v11; // r0
  int v12; // r3
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a3;
  v13[1] = (int)a4;
  v5 = *a1;
  if ( a3 )
    return -1073741811;
  if ( *(_DWORD *)(v5 + 44) != 8 )
    return sub_8010FC();
  if ( IopVerifyDeviceObjectOnStack(*a1, a2[26], 1) )
  {
    result = 0;
    *a1 = a2[26];
  }
  else
  {
    v9 = a2[25];
    if ( v9 && FsRtlFindExtraCreateParameter(v9, (unsigned int)&GUID_ECP_IO_DEVICE_HINT, v13, 0) >= 0 )
    {
      ObfReferenceObject(v5);
      v10 = v13[0];
      v11 = (unsigned __int16 *)(v13[0] + 4);
      *(_DWORD *)v13[0] = v5;
      RtlCopyUnicodeString(v11, a4);
      *(_DWORD *)(v10 - 16) |= 8u;
    }
    v12 = a2[22];
    if ( (v12 & 0x10) != 0 )
    {
      result = -1073740952;
      a2[22] = v12 & 0xFFFFFFEF;
    }
    else
    {
      result = -1073740951;
    }
  }
  return result;
}
