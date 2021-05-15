// EtwpUseDescriptorTypeUm 
 
int __fastcall EtwpUseDescriptorTypeUm(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r3
  int v7; // r0
  int v9[4]; // [sp+8h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v5 = ObReferenceObjectByHandle(*(_DWORD *)a1, 2048, EtwpRegistrationObjectType, 1, (int)v9, 0);
  if ( v5 >= 0 )
  {
    v6 = *(unsigned __int8 *)(a1 + 8);
    v7 = v9[0];
    if ( v6 == 1 || !*(_BYTE *)(a1 + 8) )
      *(_BYTE *)(v9[0] + 53) = v6;
    else
      v5 = -1073741811;
    ObfDereferenceObject(v7);
  }
  return v5;
}
