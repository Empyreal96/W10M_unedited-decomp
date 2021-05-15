// IovpExamineDevObjForwarding 
 
int __fastcall IovpExamineDevObjForwarding(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v7; // r0
  int v8; // [sp+0h] [bp-8h] BYREF

  v8 = a4;
  if ( !a2 )
  {
    v5 = IovUtilGetUpperDeviceObject(a1);
    if ( !v5 )
      return 1;
    ObfDereferenceObject(v5);
    return 4;
  }
  IovUtilRelateDeviceObjects(a1, a2, &v8);
  switch ( v8 )
  {
    case 0:
      return 2;
    case 1:
      return 3;
    case 2:
      return 2;
    case 3:
    case 4:
      return 3;
  }
  if ( v8 != 5 )
    return 2;
  v7 = IovUtilGetUpperDeviceObject(a1);
  if ( !v7 )
    return 5;
  ObfDereferenceObject(v7);
  return 6;
}
