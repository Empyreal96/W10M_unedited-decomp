// IopAddRelationToList 
 
int __fastcall IopAddRelationToList(int a1, int a2, int a3, int a4)
{
  int v7; // r2
  int v8; // r1
  int result; // r0
  int v10; // [sp+0h] [bp-18h] BYREF
  int v11; // [sp+4h] [bp-14h]

  v10 = a3;
  v11 = a4;
  if ( a2 )
    v7 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
  else
    v7 = 0;
  if ( !v7 )
    return -1073741810;
  if ( PipIsDeviceInDeviceObjectList(*(_DWORD *)a1, a2, &v10) )
    return sub_7DFAA0();
  result = PipDeviceObjectListAdd(a1, v8, a3, a4, v10, v11);
  if ( result >= 0 )
    *(_BYTE *)(a1 + 4) = 0;
  return result;
}
