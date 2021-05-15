// SeGetLogonSessionToken 
 
int __fastcall SeGetLogonSessionToken(int a1, char a2, _DWORD *a3)
{
  int v4; // r6
  int v5; // r4
  int v6; // r5
  int v7; // r3
  int v9; // [sp+10h] [bp-38h] BYREF
  int v10; // [sp+14h] [bp-34h] BYREF
  int v11[12]; // [sp+18h] [bp-30h] BYREF

  v4 = a2;
  v5 = ObReferenceObjectByHandle(a1, 8, SeTokenObjectType, a2, (int)&v9, 0);
  if ( v5 >= 0 )
  {
    v6 = v9;
    if ( *(_DWORD *)(*(_DWORD *)(v9 + 192) + 32) )
    {
      v11[0] = 24;
      v11[1] = 0;
      if ( v4 )
        v7 = 0;
      else
        v7 = 512;
      v11[3] = v7;
      v11[2] = 0;
      v11[4] = 0;
      v11[5] = 0;
      v5 = SepDuplicateToken(*(_DWORD *)(*(_DWORD *)(v9 + 192) + 32), (int)v11, 0, 1, 0, 0, 0, &v9);
      if ( v5 >= 0 )
      {
        v5 = ObInsertObject(v9, 0, 983551, 0, 0, (int)&v10);
        if ( v5 >= 0 )
          *a3 = v10;
      }
    }
    else
    {
      v5 = -1073741700;
    }
    ObfDereferenceObject(v6);
  }
  return v5;
}
