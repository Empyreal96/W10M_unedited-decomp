// EtwGetProviderIdFromHandle 
 
int __fastcall EtwGetProviderIdFromHandle(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r6
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v15[6]; // [sp+8h] [bp-18h] BYREF

  v15[0] = a3;
  v15[1] = (int)a4;
  v4 = 0;
  if ( (_BYTE)a3 )
  {
    v4 = ObReferenceObjectByHandle(a1, 2048, EtwpRegistrationObjectType, 1, v15, 0);
    if ( v4 >= 0 )
    {
      v7 = v15[0];
      v8 = *(_DWORD *)(*(_DWORD *)(v15[0] + 16) + 16);
      v9 = *(_DWORD *)(*(_DWORD *)(v15[0] + 16) + 20);
      v10 = *(_DWORD *)(*(_DWORD *)(v15[0] + 16) + 24);
      *a4 = *(_DWORD *)(*(_DWORD *)(v15[0] + 16) + 12);
      a4[1] = v8;
      a4[2] = v9;
      a4[3] = v10;
      ObfDereferenceObjectWithTag(v7);
    }
  }
  else if ( a1 && EtwpReferenceGuidEntry(*(_DWORD *)(a1 + 16)) )
  {
    v11 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 16);
    v12 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 20);
    v13 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 24);
    *a4 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 12);
    a4[1] = v11;
    a4[2] = v12;
    a4[3] = v13;
    EtwpUnreferenceGuidEntry(*(_DWORD *)(a1 + 16));
  }
  else
  {
    v4 = -1073741816;
  }
  return v4;
}
