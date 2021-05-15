// IopGetDriverPathInformation 
 
int __fastcall IopGetDriverPathInformation(int a1, int a2, int a3)
{
  unsigned int v4; // r1
  int result; // r0
  int v7; // r0
  int v8; // r3
  int v9; // r2
  int v10; // r0
  int v11; // [sp+10h] [bp-18h] BYREF
  __int16 v12[2]; // [sp+18h] [bp-10h] BYREF
  int v13; // [sp+1Ch] [bp-Ch]

  v4 = *(_DWORD *)(a2 + 4);
  if ( a3 - 8 < v4 )
    return -1073741811;
  v13 = a2 + 8;
  v12[0] = v4;
  v12[1] = v4;
  result = ObReferenceObjectByName(v12, 64, 0, 0, IoDriverObjectType, 0, 0, &v11);
  if ( result >= 0 )
  {
    v7 = KeAcquireQueuedSpinLock(10);
    v8 = *(_DWORD *)(a1 + 8);
    v9 = v7;
    if ( v8 && (v10 = *(_DWORD *)(v8 + 8)) != 0 && IopVerifyDriverObjectOnStack(v10, v11, v9) )
      *(_BYTE *)a2 = 1;
    else
      *(_BYTE *)a2 = IopVerifyDriverObjectOnStack(*(_DWORD *)(a1 + 4), v11, v9);
    KeReleaseQueuedSpinLock(10, v9);
    ObfDereferenceObjectWithTag(v11);
    result = 0;
  }
  return result;
}
