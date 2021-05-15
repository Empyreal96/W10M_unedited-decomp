// sub_529614 
 
void __fastcall sub_529614(unsigned int a1)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r2
  int v4; // r6
  int v5; // r3
  int v6; // r3
  int v7; // r2
  char v8; // r3
  int v9; // r3

  while ( 1 )
  {
    v3 = __clz(__rbit(a1));
    v4 = 1 << v3;
    if ( *(_DWORD *)(v1 + 4 * v3 + 24) )
    {
      v5 = PopPowerRequestAttributes[2 * v3];
      if ( (v4 & v2) != 0 )
      {
        v6 = v5 - 1;
        PopPowerRequestAttributes[2 * v3] = v6;
        if ( !v3 || v3 == 3 || !v6 )
        {
          v7 = v3 + v1;
          v8 = *(_BYTE *)(v7 + 52) - 1;
LABEL_12:
          *(_BYTE *)(v7 + 52) = v8;
          goto LABEL_13;
        }
      }
      else if ( v5 != -1 )
      {
        v9 = v5 + 1;
        PopPowerRequestAttributes[2 * v3] = v9;
        if ( !v3 || v3 == 3 || v9 == 1 )
        {
          v7 = v3 + v1;
          v8 = *(_BYTE *)(v7 + 52) + 1;
          goto LABEL_12;
        }
      }
    }
LABEL_13:
    a1 &= ~v4;
    if ( !a1 )
      JUMPOUT(0x4669E0);
  }
}
