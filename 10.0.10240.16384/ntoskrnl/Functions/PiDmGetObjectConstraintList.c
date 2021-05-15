// PiDmGetObjectConstraintList 
 
int __fastcall PiDmGetObjectConstraintList(int a1, int a2, int a3, int a4, _WORD *a5, unsigned int a6, unsigned int *a7)
{
  int v9; // r0
  unsigned int *v10; // r6
  int v12; // r4
  unsigned int v13; // r3
  unsigned int *v14; // [sp+0h] [bp-38h] BYREF
  int (__fastcall *v15)(int, _DWORD *, _BYTE *); // [sp+8h] [bp-30h] BYREF
  int v16; // [sp+Ch] [bp-2Ch]
  _WORD *v17; // [sp+10h] [bp-28h]
  unsigned int v18; // [sp+14h] [bp-24h]
  unsigned int v19; // [sp+18h] [bp-20h]

  *a7 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  if ( a6 )
    *a5 = 0;
  v9 = PiDmGetObject(PiDmListDefs[5 * a1], a2, (int *)&v14);
  v10 = v14;
  if ( v9 < 0 )
    return sub_7C8D5C();
  v15 = PiDmCmObjectMatchCallback;
  v16 = a4;
  v18 = a6;
  v19 = 0;
  v17 = a5;
  v12 = PiDmListEnumObjectsWithCallback(a1, v14, (int)PiDmGetObjectListCallback, (int)&v15);
  if ( v12 >= 0 )
  {
    *a7 = v19;
    if ( *a7 )
    {
      v13 = *a7 + 1;
      *a7 = v13;
      if ( a5 && a6 >= v13 )
        a5[v13 - 1] = 0;
      else
        v12 = -1073741789;
    }
  }
  if ( v10 )
    PiDmObjectRelease((int)v10);
  return v12;
}
