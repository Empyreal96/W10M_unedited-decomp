// PopFxAcpiDispatchNotification 
 
int __fastcall PopFxAcpiDispatchNotification(int *a1)
{
  char v1; // r5
  int result; // r0
  int v4; // r1
  int v5; // r0
  char v6[3]; // [sp+9h] [bp-17h] BYREF
  int v7; // [sp+Ch] [bp-14h] BYREF
  int v8[4]; // [sp+10h] [bp-10h] BYREF

  v1 = 0;
  v6[0] = 0;
  if ( PopFxAcpiValidateParameters() )
  {
    v4 = *a1;
    if ( *a1 == 1 )
    {
      result = PopFxAcpiPrepareDevice(*(_DWORD *)a1[2], a1[2], v8, v6);
      if ( result >= 0 )
      {
        a1[5] = v8[0];
        *((_BYTE *)a1 + 24) = v6[0];
      }
    }
    else if ( v4 == 2 )
    {
      PopPluginAcpiNotificationStrict(a1[5], 2, a1[2]);
      result = 0;
    }
    else if ( v4 == 3 )
    {
      result = PopFxAcpiRegisterDevice(*(_DWORD *)a1[2], a1[5], a1[2], &v7, v8);
      if ( result >= 0 )
      {
        a1[6] = v7;
        a1[7] = v8[0];
      }
    }
    else
    {
      v5 = a1[1];
      if ( v4 != 4 )
      {
        result = PopFxAcpiForwardNotification(v5, v4, a1[2]);
        v1 = 0;
        goto LABEL_15;
      }
      result = PopFxAcpiUnregisterDevice(v5, a1[2]);
    }
    v1 = 1;
    goto LABEL_15;
  }
  result = -1073741823;
LABEL_15:
  *((_BYTE *)a1 + 16) = v1;
  return result;
}
