// PipDeviceObjectListIndexOf 
 
int __fastcall PipDeviceObjectListIndexOf(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // r0
  int v7; // r3
  int v8; // t1
  int v9; // r3

  result = 0;
  if ( a3 <= 0 )
  {
LABEL_5:
    result = -1;
    if ( a4 )
    {
      v9 = 0;
LABEL_8:
      *a4 = v9;
      return result;
    }
  }
  else
  {
    v7 = a1;
    while ( 1 )
    {
      v8 = *(_DWORD *)(v7 + 16);
      v7 += 16;
      if ( a2 == v8 )
        break;
      if ( ++result >= a3 )
        goto LABEL_5;
    }
    if ( a4 )
    {
      v9 = a1 + 16 * (result + 1);
      goto LABEL_8;
    }
  }
  return result;
}
