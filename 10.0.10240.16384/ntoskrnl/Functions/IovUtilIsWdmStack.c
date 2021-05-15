// IovUtilIsWdmStack 
 
BOOL __fastcall IovUtilIsWdmStack(int a1)
{
  int v1; // r0
  BOOL v2; // r4
  int v3; // r2

  v1 = IovUtilGetBottomDeviceObject(a1);
  v2 = PpvUtilIsPdo(v1);
  ObfDereferenceObject(v3);
  return v2;
}
