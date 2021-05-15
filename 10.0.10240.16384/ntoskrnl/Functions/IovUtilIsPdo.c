// IovUtilIsPdo 
 
BOOL __fastcall IovUtilIsPdo(int a1)
{
  int v2; // r0
  BOOL v3; // r4
  int v4; // r2

  v2 = IovUtilGetBottomDeviceObject(a1);
  if ( v2 == a1 )
  {
    v3 = PpvUtilIsPdo(v2);
    ObfDereferenceObject(v4);
  }
  else
  {
    ObfDereferenceObject(v2);
    v3 = 0;
  }
  return v3;
}
