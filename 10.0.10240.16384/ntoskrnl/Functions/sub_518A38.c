// sub_518A38 
 
void __fastcall sub_518A38(int a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r6
  void (__fastcall *v5)(int, int); // r7
  int v6; // r8

  VfDevObjPreAddDevice(v4, v3, a3, v6);
  v5(v3, v4);
  VfDevObjPostAddDevice(v4, v3);
  JUMPOUT(0x4D97CE);
}
