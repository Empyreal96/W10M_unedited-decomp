// SepAdtInitializeBounds 
 
int SepAdtInitializeBounds()
{
  int result; // r0
  unsigned int v1; // [sp+8h] [bp-18h] BYREF
  unsigned int v2; // [sp+Ch] [bp-14h]

  result = SepAdtRegNotifyHandle;
  if ( SepAdtRegNotifyHandle )
  {
    result = SepRegQueryValue(SepAdtRegNotifyHandle, L"Bounds", 3, 8u, &v1);
    if ( result >= 0 && v2 < v1 && v2 >= 0x10 && v1 - v2 >= 0x10 )
    {
      SepAdtMaxListLength = v1;
      SepAdtMinListLength = v2;
    }
  }
  return result;
}
