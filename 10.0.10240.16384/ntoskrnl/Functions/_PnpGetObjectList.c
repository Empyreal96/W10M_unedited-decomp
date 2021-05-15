// _PnpGetObjectList 
 
int __fastcall PnpGetObjectList(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int (__fastcall *v10)(int, _DWORD, int, int, int, int *); // r5
  int result; // r0
  int v12; // [sp+10h] [bp-48h] BYREF
  _DWORD v13[9]; // [sp+14h] [bp-44h] BYREF

  v12 = 0;
  memset(v13, 0, sizeof(v13));
  v10 = *(int (__fastcall **)(int, _DWORD, int, int, int, int *))(a1 + 152);
  v13[3] = a5;
  v13[4] = a6;
  v13[5] = a7;
  v13[6] = a8;
  v13[1] = 0;
  v13[2] = 0;
  if ( !v10 || v10(a1, 0, a2, 5, 1, &v12) == -1073741822 )
    result = PnpGetObjectListDispatch(a1, a2);
  else
    result = sub_815CB4();
  return result;
}
