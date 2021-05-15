// sub_80D8B8 
 
void __fastcall sub_80D8B8(int a1, int a2)
{
  unsigned __int16 *v2; // r4
  int v3; // r0
  int v4; // r5
  int v5; // r1
  unsigned __int16 v6; // r3

  v3 = ExAllocatePoolWithTag(1, 16 * (a2 + 8), 1281520193);
  v4 = v3;
  if ( v3 )
  {
    v5 = *((_DWORD *)v2 + 1);
    if ( v5 )
    {
      memmove(v3, v5, 16 * *v2);
      ExFreePoolWithTag(*((_DWORD *)v2 + 1));
    }
    v6 = v2[1];
    *((_DWORD *)v2 + 1) = v4;
    v2[1] = v6 + 8;
    JUMPOUT(0x794DEA);
  }
  JUMPOUT(0x794E0A);
}
