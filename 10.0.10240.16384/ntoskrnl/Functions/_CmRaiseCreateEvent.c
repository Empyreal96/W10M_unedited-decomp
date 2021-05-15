// _CmRaiseCreateEvent 
 
int __fastcall CmRaiseCreateEvent(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v7; // r1
  int (__fastcall *v8)(int, int, int, int, int *); // lr
  int v9[8]; // [sp+10h] [bp-20h] BYREF

  result = CmMapCmObjectTypeToPnpObjectType(a3);
  v8 = *(int (__fastcall **)(int, int, int, int, int *))(a1 + 156);
  if ( v8 )
  {
    v9[0] = a4;
    result = v8(a1, v7, result, 2, v9);
  }
  if ( *(_DWORD *)(a1 + 164) )
    result = sub_7EF33C(result);
  return result;
}
