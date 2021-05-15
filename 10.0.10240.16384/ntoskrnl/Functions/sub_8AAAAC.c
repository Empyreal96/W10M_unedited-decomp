// sub_8AAAAC 
 
int __fastcall sub_8AAAAC(int a1, int a2)
{
  int result; // r0
  unsigned __int16 *v5; // r1
  int v6; // [sp+8h] [bp-20h] BYREF
  _DWORD v7[2]; // [sp+10h] [bp-18h] BYREF
  int v8; // [sp+18h] [bp-10h]

  sub_8AA934(a2);
  result = sub_8AAB70(a1, 0, DEVPKEY_Device_InstanceId, 18, a2);
  if ( result >= 0 )
  {
    if ( sub_8AACAC(a1, 0, DEVPKEY_Device_ClassGuid, 13, 16, a2 + 12) < 0 )
    {
      *(_DWORD *)(a2 + 12) = 0;
      *(_DWORD *)(a2 + 16) = 0;
      *(_DWORD *)(a2 + 20) = 0;
      *(_DWORD *)(a2 + 24) = 0;
    }
    result = sub_8AACAC(a1, 0, DEVPKEY_Device_RemovalPolicy, 7, 4, &v6);
    if ( result >= 0 )
    {
      v5 = *(unsigned __int16 **)(a2 + 8);
      *(_BYTE *)(a2 + 30) = v6;
      v7[0] = 0;
      v7[1] = 0;
      v8 = 0;
      RtlInitUnicodeString((unsigned int)v7, v5);
      result = ZwPlugPlayControl();
      if ( result >= 0 )
      {
        *(_DWORD *)(a2 + 32) = v8;
        result = sub_8AAB70(a1, 0, DEVPKEY_Device_HardwareIds, 8210, a2 + 48);
        if ( result >= 0 || result == -1073741772 )
          result = 0;
      }
    }
  }
  return result;
}
