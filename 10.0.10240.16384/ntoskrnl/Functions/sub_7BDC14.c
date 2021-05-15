// sub_7BDC14 
 
void __fastcall sub_7BDC14(int a1, int a2, int a3)
{
  unsigned int *v3; // r4
  int v4; // r5
  _DWORD *v5; // r7
  int v6; // r8
  int v7; // r6
  int v8; // r3
  int v9; // r0
  _DWORD *v10; // r5
  _DWORD *v11; // r1
  unsigned int v12; // r2
  int v13; // r1

  if ( a3 )
    v7 = 12 * (a3 - 1) + 20;
  else
    v7 = 8;
  if ( a1 )
  {
    if ( v4 )
      v8 = 12 * (v4 - 1) + 20;
    else
      v8 = 8;
  }
  else
  {
    v8 = 0;
  }
  v9 = ExAllocatePoolWithTag(1, v8 + v7, 1917871443);
  v10 = (_DWORD *)v9;
  if ( v9 )
  {
    v11 = (_DWORD *)*v3;
    if ( *v3 )
    {
      if ( *v11 )
        v12 = 12 * (*v11 - 1) + 20;
      else
        v12 = 8;
    }
    else
    {
      v12 = 0;
    }
    memmove(v9, (int)v11, v12);
    SepConcatenatePrivileges(v10, v13, v5);
    if ( *(_BYTE *)(v6 + 11) )
      ExFreePoolWithTag(*v3);
    *v3 = (unsigned int)v10;
    *(_BYTE *)(v6 + 11) = 1;
    JUMPOUT(0x6F3AE6);
  }
  JUMPOUT(0x6F3AE8);
}
