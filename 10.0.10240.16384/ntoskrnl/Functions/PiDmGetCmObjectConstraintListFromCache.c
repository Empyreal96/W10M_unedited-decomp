// PiDmGetCmObjectConstraintListFromCache 
 
int __fastcall PiDmGetCmObjectConstraintListFromCache(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r3
  int v8; // r3
  _DWORD v10[6]; // [sp+10h] [bp-18h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v7 = PiDmListDefs[5 * a1 + 2];
  if ( v7 == 3 )
  {
    v8 = 3;
LABEL_3:
    v10[2] = v8;
    return ((int (__fastcall *)(int, int, int, _DWORD *, int, int, int))PiDmGetObjectConstraintList)(
             a1,
             a2,
             5 * a1,
             v10,
             a5,
             a6,
             a7);
  }
  if ( v7 == 1 )
  {
    v8 = 1;
    goto LABEL_3;
  }
  return sub_7C8D38();
}
