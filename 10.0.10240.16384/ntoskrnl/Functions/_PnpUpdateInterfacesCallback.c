// _PnpUpdateInterfacesCallback 
 
int __fastcall PnpUpdateInterfacesCallback(int a1, int a2, int a3, int a4)
{
  void (__fastcall *v5)(int, int, int, int, int *); // r4
  int result; // r0
  int v7[8]; // [sp+10h] [bp-20h] BYREF

  if ( *(_BYTE *)(a4 + 16) )
  {
    v5 = *(void (__fastcall **)(int, int, int, int, int *))a4;
    v7[0] = 0;
    v5(a1, a2, 3, 5, v7);
  }
  if ( *(_DWORD *)(a4 + 4) )
    result = sub_81A5A4();
  else
    result = 0;
  return result;
}
