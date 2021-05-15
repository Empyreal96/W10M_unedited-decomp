// PnpDetermineResourceListSize 
 
int __fastcall PnpDetermineResourceListSize(int *a1)
{
  int result; // r0
  int v3; // r1
  _DWORD *v4; // r2
  int v5; // r7
  int v6; // r4
  _BYTE *v7; // r5

  if ( !a1 )
    return 0;
  v3 = *a1;
  result = 4;
  v4 = a1 + 1;
  if ( *a1 )
  {
    while ( 1 )
    {
      v5 = v4[3];
      v6 = 16;
      v7 = v4 + 4;
      if ( v5 )
        break;
LABEL_9:
      result += v6;
      v4 = (_DWORD *)((char *)v4 + v6);
      if ( !--v3 )
        return result;
    }
    while ( *v7 != 5 )
    {
      v6 += 16;
      v7 += 16;
      if ( !--v5 )
        goto LABEL_9;
    }
    result = sub_7E1444();
  }
  return result;
}
