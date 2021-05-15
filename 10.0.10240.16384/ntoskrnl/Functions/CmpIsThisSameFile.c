// CmpIsThisSameFile 
 
int __fastcall CmpIsThisSameFile(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r2
  int v7; // r3
  int v9[4]; // [sp+8h] [bp-10h] BYREF

  v9[0] = a4;
  v5 = 0;
  if ( ObReferenceObjectByHandle(a2, 0, *(_DWORD *)CmIoFileObjectType, 0, v9, 0) < 0 )
    return 0;
  v6 = *(_DWORD *)(a1 + 20);
  if ( v6 )
  {
    v7 = *(_DWORD *)(v9[0] + 20);
    if ( v6 == v7 )
    {
      if ( v7 )
        v5 = 1;
    }
  }
  ObfDereferenceObject(v9[0]);
  return v5;
}
