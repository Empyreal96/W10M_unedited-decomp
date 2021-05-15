// IopCopyOffloadCapable 
 
int __fastcall IopCopyOffloadCapable(_DWORD *a1, int a2)
{
  int v3; // r0
  int result; // r0
  int v5; // [sp+0h] [bp-8h] BYREF

  v5 = 0;
  if ( (a1[11] & 0x800) != 0 )
    v3 = IoGetAttachedDevice(a1[1]);
  else
    v3 = IoGetRelatedDeviceObject(a1);
  result = FsRtlGetSupportedFeatures(v3, &v5);
  if ( result >= 0 )
  {
    if ( a2 == 606820 )
    {
      if ( (v5 & 1) == 0 )
        result = -1073700191;
    }
    else if ( (v5 & 2) == 0 )
    {
      result = -1073700190;
    }
  }
  return result;
}
