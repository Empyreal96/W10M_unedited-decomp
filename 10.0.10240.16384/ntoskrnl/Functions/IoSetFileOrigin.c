// IoSetFileOrigin 
 
int __fastcall IoSetFileOrigin(int a1, int a2)
{
  int v2; // r2
  bool v3; // zf
  int v4; // r1
  unsigned int v5; // r3

  v2 = -1073741776;
  v3 = a2 == 0;
  v4 = *(_DWORD *)(a1 + 44);
  if ( v3 )
  {
    if ( (v4 & 0x1000000) != 0 )
    {
      v5 = v4 & 0xFEFFFFFF;
      goto LABEL_6;
    }
  }
  else if ( (v4 & 0x1000000) == 0 )
  {
    v5 = v4 | 0x1000000;
LABEL_6:
    v2 = 0;
    *(_DWORD *)(a1 + 44) = v5;
    return v2;
  }
  return v2;
}
