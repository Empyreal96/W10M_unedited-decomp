// IoVolumeDeviceToGuid 
 
int __fastcall IoVolumeDeviceToGuid(int a1, _BYTE *a2)
{
  int v3; // r5
  unsigned int v5; // r4
  __int16 v6; // [sp+0h] [bp-20h] BYREF
  __int16 v7; // [sp+2h] [bp-1Eh]
  unsigned int v8; // [sp+4h] [bp-1Ch]
  unsigned __int16 v9; // [sp+8h] [bp-18h] BYREF
  __int16 v10; // [sp+Ah] [bp-16h]
  unsigned int v11; // [sp+Ch] [bp-14h]

  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v3 = IoVolumeDeviceToGuidPath(a1, &v6);
  if ( v3 >= 0 )
  {
    v5 = v8;
    v9 = v6 - 20;
    v10 = v7 - 20;
    v11 = v8 + 20;
    v3 = RtlGUIDFromString(&v9, a2);
    ExFreePoolWithTag(v5);
  }
  return v3;
}
