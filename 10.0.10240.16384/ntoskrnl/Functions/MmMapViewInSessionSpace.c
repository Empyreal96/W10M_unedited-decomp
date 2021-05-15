// MmMapViewInSessionSpace 
 
int __fastcall MmMapViewInSessionSpace(int a1, int a2, int a3)
{
  _DWORD v4[2]; // [sp+8h] [bp-8h] BYREF

  v4[0] = 0;
  v4[1] = 0;
  return MmMapViewInSessionSpaceEx(a1, a2, a3, v4);
}
