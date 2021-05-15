// _CmRaiseDeleteEvent 
 
int *__fastcall CmRaiseDeleteEvent(int *a1, int a2, int a3, int a4)
{
  int v7; // r0
  int v8; // r1
  void (__fastcall *v9)(int *, int, int, int); // r7
  int *v11; // [sp+0h] [bp-20h]
  int v12[6]; // [sp+8h] [bp-18h] BYREF

  v11 = a1;
  v12[0] = a3;
  v12[1] = a4;
  v7 = CmMapCmObjectTypeToPnpObjectType(a3);
  PnpObjectRaiseDeleteEvent(a1, v8, v7);
  v9 = (void (__fastcall *)(int *, int, int, int))a1[41];
  if ( v9 )
  {
    v12[0] = 0;
    v11 = v12;
    v9(a1, a2, a3, 3);
  }
  return v11;
}
