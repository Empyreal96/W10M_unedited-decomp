// AuthzBasepIsValidExpression 
 
int __fastcall AuthzBasepIsValidExpression(int a1, int a2, int a3, _BYTE *a4)
{
  unsigned int v4; // r7
  unsigned int v7; // r2
  int v9; // r1
  unsigned int v10; // r2
  bool v11; // zf
  int v12; // r3
  unsigned int v13; // r0

  v4 = 0;
  *a4 = 0;
  if ( a3 )
  {
    while ( *(_DWORD *)(a2 + 12) )
    {
      if ( !AuthzBasepSupportSetOperation(a1) )
        return sub_51745C();
      ++v4;
      a2 += 28;
      if ( v4 >= v7 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    if ( AuthzBasepSupportSetOperation(a1)
      || v10 != 2
      || *(_WORD *)v9 == 4
      || !*(_WORD *)v9
      || *(_DWORD *)(v9 + 40) != 1
      || !*(_BYTE *)(v9 + 32) )
    {
      switch ( a1 )
      {
        case 128:
        case 129:
        case 130:
        case 131:
        case 132:
        case 133:
        case 134:
        case 136:
        case 142:
        case 143:
          if ( v10 != 2 || *(_DWORD *)(v9 + 12) == 1 )
            return 0;
          if ( a1 != 136 && a1 != 143 || *(_DWORD *)(v9 + 40) != 1 )
            return 1;
          v11 = *(_BYTE *)(v9 + 32) == 0;
          return !v11;
        case 135:
        case 141:
          if ( v10 != 1 )
            return 0;
          v12 = *(_DWORD *)(v9 + 12);
          if ( v12 == 1 || v12 == 3 )
            return 0;
          v11 = v12 == 5;
          return !v11;
        case 137:
        case 138:
        case 139:
        case 140:
        case 144:
        case 145:
        case 146:
        case 147:
          if ( v10 != 1 )
            return 0;
          if ( *(_DWORD *)(v9 + 12) != 1 && *(_WORD *)v9 != 5 )
            JUMPOUT(0x51746A);
          return 1;
        case 160:
        case 161:
          v13 = 0;
          if ( !v10 )
            return 1;
          break;
        case 162:
          if ( v10 == 2 )
            return 0;
          if ( v10 != 1 )
            return 1;
          v11 = *(_DWORD *)(v9 + 12) == 1;
          return !v11;
        default:
          return 1;
      }
      while ( *(_DWORD *)(v9 + 12) != 1 )
      {
        ++v13;
        v9 += 28;
        if ( v13 >= v10 )
          return 1;
      }
    }
  }
  return 0;
}
