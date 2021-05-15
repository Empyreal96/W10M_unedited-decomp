// SmRereferenceProcessObject 
 
int __fastcall SmRereferenceProcessObject(int a1, int a2, char a3, _DWORD *a4)
{
  int result; // r0
  _DWORD *v6; // [sp+8h] [bp-8h] BYREF

  v6 = a4;
  result = ObReferenceObjectByHandle(a1, 0x2000, PsProcessType, a3, &v6, 0);
  *a4 = v6;
  return result;
}
