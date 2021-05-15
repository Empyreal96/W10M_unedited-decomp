// IoSynchronousCallDriver 
 
int __fastcall IoSynchronousCallDriver(int a1, int a2)
{
  int v3; // r4
  int result; // r0
  int v5; // r3
  unsigned __int8 *v6; // r3
  int v7; // r2
  int v8; // r3
  char v9[4]; // [sp+8h] [bp-20h] BYREF
  int v10; // [sp+Ch] [bp-1Ch]
  int v11[6]; // [sp+10h] [bp-18h] BYREF

  v9[0] = 0;
  v10 = 0;
  v3 = *(_DWORD *)(a2 + 96);
  v11[1] = (int)v11;
  v9[1] = 0;
  v9[2] = 4;
  v11[0] = (int)v11;
  *(_DWORD *)(v3 - 8) = SmKmGenericCompletion;
  *(_DWORD *)(v3 - 4) = v9;
  *(_BYTE *)(v3 - 37) = -32;
  if ( pIofCallDriver )
    return sub_529C4C();
  v5 = (char)(*(_BYTE *)(a2 + 35) - 1);
  *(_BYTE *)(a2 + 35) = v5;
  if ( v5 <= 0 )
    KeBugCheckEx(53, a2, 0);
  v6 = (unsigned __int8 *)(*(_DWORD *)(a2 + 96) - 40);
  *(_DWORD *)(a2 + 96) = v6;
  v7 = *v6;
  *((_DWORD *)v6 + 6) = a1;
  if ( v7 == 22 && ((v8 = v6[1], v8 == 2) || v8 == 3) )
    result = IopPoHandleIrp(a2);
  else
    result = (*(int (__fastcall **)(int, int))(*(_DWORD *)(a1 + 8) + 4 * v7 + 56))(a1, a2);
  if ( result == 259 )
  {
    KeWaitForSingleObject(v9, 5, 0);
    result = *(_DWORD *)(a2 + 24);
  }
  return result;
}
