// PiDmGetObjectList 
 
int __fastcall PiDmGetObjectList(int a1, int a2, int a3, _WORD *a4, unsigned int a5, unsigned int *a6)
{
  int result; // r0
  int v8; // r3
  unsigned int v9; // r3
  _DWORD v10[4]; // [sp+0h] [bp-28h] BYREF
  unsigned int v11; // [sp+10h] [bp-18h]

  v10[2] = a4;
  v10[3] = a5;
  *a6 = 0;
  v10[0] = a2;
  v10[1] = a3;
  v11 = 0;
  if ( a5 )
    *a4 = 0;
  result = PiDmEnumObjectsWithCallback(a1, PiDmGetObjectListCallback, v10);
  if ( result >= 0 )
  {
    v8 = v11;
    *a6 = v11;
    if ( v8 )
    {
      v9 = v8 + 1;
      *a6 = v9;
      if ( a4 && a5 >= v9 )
        a4[v9 - 1] = 0;
      else
        result = -1073741789;
    }
  }
  return result;
}
